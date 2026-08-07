// register file

module csr_file(
    input  logic        clk,
    input  logic        rst_n,
    input  logic [11:0]  csr_w_addr,
    input  logic [31:0] csr_w_data,
    input  logic        csr_w_en, // write enable
    input  logic        csr_r_en, // read enable
    input  logic [11:0]  csr_r_addr,
    output logic [31:0] csr_r_data
);
    //logic [31:0] regs [4095:0];

    // I think i'll do this later

    // IMPLEMENTED CSRs :
    logic [31:0] misa = 32'h40000100; // base 32 and I // Leaving it as read only
    logic [31:0] mvendorid = 0; // R
    logic [31:0] mimpid = 0; // Leaving it as read only
    logic [31:0] marchid = 0; // R
    logic [31:0] mhartid = 0; // R To be modified if more hw threads
    logic [31:0] mie;
    logic [31:0] mip;
    logic [31:0] mstatus; // R/W : Right now I only have M mode
    logic [31:0] mtvec;
    logic [31:0] mepc;
    logic [31:0] mcause;
    logic [31:0] mscratch;
    logic [31:0] mtval;

    
    localparam logic [11:0] ADDR_VENDORID  = 12'hF11;
    localparam logic [11:0] ADDR_MARCHID  = 12'hF12;
    localparam logic [11:0] ADDR_MIMPID  = 12'hF13;
    localparam logic [11:0] ADDR_MHARTID  = 12'hF13;

    localparam logic [11:0] ADDR_MSTATUS  = 12'h300;
    localparam logic [11:0] ADDR_MISA  = 12'h301;

    localparam logic [11:0] ADDR_MIE  = 12'h304;
    localparam logic [11:0] ADDR_MIP  = 12'h344;

    localparam logic [11:0] ADDR_MTVEC    = 12'h305;
    localparam logic [11:0] ADDR_MSCRATCH = 12'h340;
    localparam logic [11:0] ADDR_MEPC     = 12'h341;
    localparam logic [11:0] ADDR_MCAUSE   = 12'h342;
    localparam logic [11:0] ADDR_MTVAL    = 12'h343;
    



    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin 
            misa  <= 32'h40000100;
            mstatus  <= '0;
            mtvec    <= '0;
            mepc     <= '0;
            mcause   <= '0;
            mscratch <= '0;
            mtval    <= '0;
            mie     <= '0;
            mip   <= '0;
            mvendorid <= '0;
            mimpid <= '0;
            marchid <= '0;
            mhartid <= '0;
        end else if (csr_w_en) begin
            unique case (csr_w_addr)
                ADDR_MSTATUS:  mstatus  <= csr_w_data;
                ADDR_MTVEC:    mtvec    <= csr_w_data;
                ADDR_MSCRATCH: mscratch <= csr_w_data;
                ADDR_MEPC:     mepc     <= csr_w_data;
                ADDR_MCAUSE:   mcause   <= csr_w_data;
                ADDR_MTVAL:    mtval    <= csr_w_data;
                ADDR_MIE:   mie   <= csr_w_data;
                ADDR_MIP:    mip    <= csr_w_data;
                ADDR_MARCHID : marchid  <= csr_w_data;
                //ADDR_MIMPID : mimpid  <= csr_w_data; // Leavin it as 0
                default: ; // writes to unimplemented/read-only CSRs are no-ops
            endcase
        end
    end

    // Read
    always_comb begin
        // TODO : APPARENTLY DOING LIKE THIS IS CORRECT, VERIFY WHY?
        csr_r_data = 0;
        if (csr_r_en) begin
            unique case (csr_r_addr)
                ADDR_MSTATUS:  csr_r_data = mstatus;
                ADDR_MTVEC:    csr_r_data = mtvec;
                ADDR_MSCRATCH: csr_r_data = mscratch;
                ADDR_MEPC:     csr_r_data = mepc;
                ADDR_MCAUSE:   csr_r_data = mcause;
                ADDR_MTVAL:    csr_r_data = mtval;
                ADDR_MHARTID:  csr_r_data = mhartid;
                ADDR_MIE: csr_r_data = mie;
                ADDR_MIP: csr_r_data = mip;
                ADDR_MISA: csr_r_data = misa;
                ADDR_MARCHID : csr_r_data  = marchid;
                ADDR_VENDORID: csr_r_data = mvendorid;
                //ADDR_MIMPID: csr_r_data = mimpid;
                default:       csr_r_data = 32'd0; // unimplemented CSR reads as 0
            endcase
        end
    end

    

endmodule