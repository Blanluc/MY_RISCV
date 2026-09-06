`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/06/2026 11:24:43 AM
// Design Name: 
// Module Name: clk_div
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module clk_div(
    input logic clk,
    output logic clk_div
    );
    integer counter;
    integer counter_next;
    
    initial begin
        counter_next = 0;
    end
    
    always_ff @(posedge clk) begin
        if (counter==2) begin
            clk_div <= !clk_div;
        end else begin
            clk_div <= clk_div;
        end
        
        counter <= counter_next;
        
    end
    
    always_comb begin
        if (counter==2) begin
            counter_next = 0;
        end
        else begin
            counter_next = counter + 1;
        end
    end
    
endmodule
