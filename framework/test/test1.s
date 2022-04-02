__init:
    floadc 0
    fstoreg 0
    floadc 0
    fstoreg 1
    return

test:
    esr 3
    iloadc 1
    istore 2
    iloadc 2
    istore 3
    bloadc_t
    bstore 4
    return

test2:
    return

test3:
    esr 1
    iloadc 1
    istore 1
    iloadc_1
    ireturn

.const float 3.0
.const int 3
.const int 2
.exportfun "__init" void __init
.global float
.global float
