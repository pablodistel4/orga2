
global suma 

section .text

suma:
    XOR RAX, RAX
    ADD RAX, RDI
    ADD RAX, RSI
    ret