__init:
    floadc 0
    fstoreg 0
    floadc 0
    fstoreg 1
    return

test:
    esr 2
    iloadc 1
    istore 2
    iloadc 2
    istore 3
    return

.const float 3.0
.const int 3
.const int 4
.exportfun "__init" void __init
.global float
.global float
