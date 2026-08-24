module uart_transmitter #(
    parameter int unsigned BAUDE_RATE = 115200,
    parameter int unsigned CLK_FREQ = 125000000)
(
    input logic clk,
    input logic rst,
    
    input logic [7:0] tx_data, // recieve data to transmit
    input logic tx_en, // enable

    output logic tx_o, // output
    output logic tx_busy
   
);

integer hold_value = CLK_FREQ / BAUDE_RATE;
integer hold_counter;

// set up my shift reg
logic  [9:0] shift_reg;
// 0 : start bit
// 1-8 : data bits
// 9 : stop bit

// logic [7:0] debug_reg;



// UART FSM
typedef enum logic [1:0]{
    IDLE  = 2'b00,
    DATA = 2'b01,
    START = 2'b10
} state_t;

integer bit_counter;
integer bit_counter_next;

state_t cur_state;
state_t next_state;

integer debug_counter;

always @ (posedge clk) begin
  // If reset is asserted, go back to IDLE state
  if (!rst) begin
    //$display("HERE");
    
    cur_state <= IDLE;
    bit_counter <=0;

  // Else transition to the next state
  end else begin
    cur_state <= next_state;
    bit_counter <= bit_counter_next;
  end
end

// Combinational always block for next state logic
always @(posedge clk) begin
  
  
    // Default next state assignment
    //next_state = IDLE;
    //$display("NEXT STATE : %d",next_state);

    case (cur_state)
        IDLE: begin
                hold_counter =0;
                tx_busy = 0;
                bit_counter = 0;
                shift_reg='0;
                debug_counter =0;
                //$display("ENABLE : %d",tx_en);
                if (tx_en) begin
                  tx_busy = 1;
                  //$display("HOLD VALUE = %d ",hold_value);
                  $display("LETTER TO BE SENT : %c",tx_data);
                  next_state = DATA; // Transition to START on tx_en
                end
                //next_state = IDLE;
              end

        DATA: begin

                shift_reg[0]=1; // start bit
                shift_reg[1]=tx_data[7];
                shift_reg[2]=tx_data[6];
                shift_reg[3]=tx_data[5];
                shift_reg[4]=tx_data[4];
                shift_reg[5]=tx_data[3];
                shift_reg[6]=tx_data[2];
                shift_reg[7]=tx_data[1];
                shift_reg[8]=tx_data[0];
                shift_reg[9]=1;

                // DEBUG
                // debug_reg[0]=shift_reg[8];
                // debug_reg[1]=shift_reg[7];
                // debug_reg[2]=shift_reg[6];
                // debug_reg[3]=shift_reg[5];
                // debug_reg[4]=shift_reg[4];
                // debug_reg[5]=shift_reg[3];
                // debug_reg[6]=shift_reg[2];
                // debug_reg[7]=shift_reg[1];

                // $display("DEBUG : %c",debug_reg);
                //$display("bit_counter next : %d",bit_counter_next);
                //$display("bit_counter : %d",bit_counter);
                //$display("START SEND");
                
                next_state = START; // Transition to START on tx_en
              end

        START:  begin
          //$display("LETTER IN SHIFT REG : %c",shift_reg[8:1]);
                
                tx_o = shift_reg[bit_counter];
                debug_counter ++;
                hold_counter ++;
                if(hold_counter >= 1080) begin
                  //$display("HOLD COUNTER : %d ",hold_counter);

                end

                if (hold_counter==hold_value & bit_counter != 9) begin
                  hold_counter=0;
                  
                  
                  bit_counter_next = bit_counter + 1;
                  //$display("BIT COUNTER : %d ",bit_counter);
                end
                
                if (bit_counter == 9 & hold_counter==hold_value) begin
                  //$display("DONE BIT ");
                  next_state = IDLE; // Transition to STATE_2 if input_signal is low
                  tx_o = 0;
                  tx_busy = 0;
                  hold_counter=0;
                  bit_counter_next = 0;
                end
                //next_state = START;
                end

        default:  next_state = IDLE; // Fallback to default state
    endcase
end

endmodule