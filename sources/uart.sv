module uart_transmitter #(
    parameter int unsigned BAUDE_RATE = 115200,
    parameter int unsigned CLK_FREQ   = 125000000
)(
    input  logic       clk,
    input  logic       rst,
    input  logic [7:0] tx_data, 
    input  logic       tx_en,   

    output logic       tx_o,    
    output logic       tx_busy
);

    localparam int unsigned CLKS_PER_BIT = CLK_FREQ / BAUDE_RATE;

    typedef enum logic {
        IDLE,
        TRANSMIT
    } state_t;

    state_t state;

    logic [9:0]      shift_reg;
    int unsigned     baud_counter;
    logic [3:0]      bit_counter;

    always_ff @(posedge clk) begin
        if (!rst) begin
            state <= IDLE;
            tx_o <= 1'b1; // Idle HIGH
            tx_busy <= 1'b0;
            baud_counter <= 0;
            bit_counter <= 0;
            shift_reg <= 10'b1111111111;
        end else begin
            case (state)
                IDLE: begin
                    tx_o <= 1'b1;
                    tx_busy <= 1'b0;
                    baud_counter <= 0;
                    bit_counter <= 0;

                    if (tx_en) begin
                        // Frame: [Stop (1) | Data [7:0] | Start (0)]
                        $display("SENDING CHAR : %c",tx_data);
                        shift_reg <= {1'b1, tx_data, 1'b0};
                        tx_busy <= 1'b1;
                        state <= TRANSMIT;
                    end
                end

                TRANSMIT: begin
                    tx_busy <= 1'b1;
                    tx_o <= shift_reg[bit_counter];

                    if (baud_counter < CLKS_PER_BIT - 1) begin
                        baud_counter <= baud_counter + 1;
                    end else begin
                        baud_counter <= 0;
                        if (bit_counter < 9) begin
                            bit_counter <= bit_counter + 1'b1;
                        end else begin
                            bit_counter <= 0;
                            tx_o <= 1'b1; // Drive HIGH on stop bit completion
                            tx_busy <= 1'b0;
                            state <= IDLE;
                        end
                    end
                end

                default: state <= IDLE;
            endcase
        end
    end

endmodule