module d_ff
(
	input clk, rst_b, set_b, d,
	output q
);

always @(posedge clk, negedge rst_b, negedge set_b) begin
	if(!set_b) q <= 1;
	else if (!rst_b) q <= 0;
	else q <= d;
end

endmodule

module lss5b
(
	input clk, rst_b,
	output [4:0] q
);

d_ff inst0(.clk(clk), .rst_b(1'b1), .set_b(rst_b), .d(q[4]), .q(q[0]));
d_ff inst1(.clk(clk), .rst_b(1'b1), .set_b(rst_b), .d(q[0]), .q(q[1]));
d_ff inst2(.clk(clk), .rst_b(1'b1), .set_b(rst_b), .d(q[1]), .q(q[2]));
d_ff inst3(.clk(clk), .rst_b(1'b1), .set_b(rst_b), .d(q[2] ^ q[4]), .q(q[3]));
d_ff inst4(.clk(clk), .rst_b(1'b1), .set_b(rst_b), .d(q[4] ^ q[3]), .q(q[4]));

endmodule

module lss5b_tb;
reg clk, rst_b;
wire [4:0] q;

lss5b lss5b_i (.clk(clk), .rst_b(rst_b), .q(q));

localparam CLK_PERIOD = 100, RUNNING_CYCLES = 15, RST_DURATION = 50;

initial begin
	clk = 0;
	repeat (2*RUNNING_CYCLES) #(CLK_PERIOD/2) clk = ~clk;
end

initial begin
	rst_b = 0;
	#RST_DURATION rst_b = 1;
end

endmodule