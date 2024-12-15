module fsmm
(
	input clk, rst_b, a, b,
	output m, n
);

reg [2:0] st, st_nxt;

localparam S0 = 3'b000, S1 = 3'b001, S2 = 3'b010, S3 = 3'b011, S4 = 3'b100;

always @(*) begin
	case (st)
		S0: if (~a) begin st_nxt = S0; m = 0; n = 0; end
			else if (a & b) begin st_nxt = S4; m = 1; end
			else if (a & ~b) begin st_nxt = S1; n = 1; end
		S1: begin st_nxt = S2; m = 1; n = 1; end
		S2: if (a) begin  st_nxt = S3; m = 1; end 
			else if (~a) begin st_nxt = S4; n = 1; end
		S3: if (~a & b) begin st_nxt = S3; m = 1; n = 1; end
			else if (a & ~b) begin st_nxt = S0; m = 1; n = 1; end
			else if (a & b) begin st_nxt = S4; end
		S4: if (~b) begin st_nxt = S4; n = 1; end
			else if (b) begin st_nxt = S1; m = 1; n = 1; end
	endcase
end

always @(posedge clk, negedge rst_b) begin
	if(!rst_b) st <= S0;
	else st <= st_nxt;
end

endmodule


module fsmm_tb;
reg clk, rst_b, a, b;
wire m, n;
wire [2:0] st;

fsmm fsmm_i (.clk(clk), .rst_b(rst_b), .a(a), .b(b), .m(m), .n(n));

localparam CLK_PERIOD = 100, RUNNING_CYCLES = 8, RST_DURATION = 50;

initial begin
	clk = 0;
	repeat (2 * RUNNING_CYCLES) #(CLK_PERIOD/2) clk = ~clk;
end

initial begin
	rst_b = 0;
	#(RST_DURATION) rst_b = 1;
end

initial begin
	a = 0;
	#(2*CLK_PERIOD) a = 1;
	#(5*CLK_PERIOD) a = 0;
end

initial begin
	b = 0;
	#(CLK_PERIOD/2) b = 1;
	#(3*CLK_PERIOD/2) b = 0;
	#(3*CLK_PERIOD/2) b = 1;
	#(CLK_PERIOD) b = 0;
	#(CLK_PERIOD) b = 1;
	#(2*CLK_PERIOD) b = 0;
end

endmodule