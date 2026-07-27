## TESTING ALU OPERATIONS (NON IMMEDIATE) ##

# print in decimal #
addi a0, x0, 1      # a0 = 1
addi a1, x0, 2      # a1 = 2
add a2, a1, a0      # a2 = 3
sub a3, a2, a0      # a3 = 2

# print in bin #
xor a4, a2, a0      # a4 = b10
and a5, a3, a2      # a5 = b10
or a6, a1, a0       # a6 = b11
sll a7, a1, a3      # a7 = b1000
srl s2, a3, a0      # s2 = b1
slt s3, a2, a3      # s3 = 0
slt s4, a3, a2      # s4 = 1
sub s5, x0, a2      # s5 = -3
sra s6, s5, a0      # left padding filled with sign bit
slt s7, s5, a3      # s7 = 1
sltu s8, s5, a3     # s8 = 0

# Overflow test
addi s9, x0, 4294967295
addi s10, s9, 1


