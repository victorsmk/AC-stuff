module bcm
(
	input [2:0] i,
	output reg[1:0] o
);

always @(*)begin
	case(i)
		3'b000: o = 2'b11;
		3'b001: o = 2'b01;
		3'b010: o = 2'b11;
		3'b011: o = 2'b00;
		3'b100: o = 2'b11;
		3'b101: o = 2'b11;
		3'b110: o = 2'b00;
		3'b111: o = 2'b00;
	endcase
end

endmodule

module bcm_tb;
reg [2:0] i;
wire [1:0] o;

bcm inst (.i(i), .o(o));

integer k;
initial begin
	$display("input : i[2] i[1] i[0]| output : o[1] o[0]");
    $monitor("%d : %b      %b    %b | %d :   %b    %b", i, i[2], i[1], i[0], o, o[1], o[0]);
	for (k = 0; k < 8: k = k + 1)
		i = k;
		#20;
end
endmodule