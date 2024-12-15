module regfl 
(
	input clk, rst_b, we,
	input [63:0] d,
	input [2:0] s,
	output [511:0] q
);

wire [7:0] dout;

dec #(.w(3)) dec_i (.e(we), .s(s), .o(dout));

generate
	genvar k;
	for (k = 0; k < 8; k = k + 1)
		rgst #(.w(64)) rgst_ik (.clk(clk), .rst_b(rst_b), .ld(dout[k]), .clr(1'b0), .d(d), .q(q[511 - k*64:448 - k*64]));
endgenerate

endmodule