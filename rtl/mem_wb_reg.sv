// instruction fetch stage

// return the control signals, correct outputs (...)

module mem_wb_reg (
    input  logic        clk,
    input  logic        rst_n,

    input  logic        stall,

    input logic [4:0]  rd_mem,
    input logic [31:0] pc_mem,
    //input logic        mem_r_mem, 
    input logic        mem_w_mem, 
    input logic        reg_write_mem, 
    input logic [2:0]  wb_sel_mem,
    input logic [31:0] alu_result_mem,
    input logic [31:0] r_data_mem,

    //output logic [6:0] opcode_wb,
    output logic [4:0]  rd_wb,
    output logic [31:0] pc_wb,
    //output logic        mem_r_wb, 
    output logic        mem_w_wb, 
    output logic        reg_write_wb, 
    output logic [2:0]  wb_sel_wb,
    output logic [31:0] r_data_wb,
    output logic [31:0] alu_result_wb
);

    always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin// rst_n is active low
        pc_wb <= '0;
        rd_wb <= '0;
        //mem_r_wb <= '0;
        mem_w_wb <= '0;
        reg_write_wb <= '0;
        wb_sel_wb <= '0;
        r_data_wb <= '0;
        alu_result_wb <= '0;
    end 
    // else if (stall) begin
    //     pc_wb <= pc_wb;
    //     rd_wb <= rd_wb;
    //     //mem_r_wb <= mem_r_wb;
    //     mem_w_wb <= mem_w_wb;
    //     reg_write_wb <= reg_write_wb;
    //     wb_sel_wb <= wb_sel_wb;
    //     alu_result_wb <= alu_result_wb;
    // end
    else begin
        pc_wb <= pc_mem;
        rd_wb <= rd_mem;
        //mem_r_wb <= mem_r_mem;
        mem_w_wb <= mem_w_mem;
        reg_write_wb <= reg_write_mem;
        wb_sel_wb <= wb_sel_mem;
        r_data_wb <= r_data_mem;
        alu_result_wb <= alu_result_mem;
    end

    end

endmodule