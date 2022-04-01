__init:
    iloadc_1
    istoreg 0
    return

test:
    esr 6
    bloadc_t
    bstore 2
    bloadc_f
    bstore 3
    floadc 0
    fstore 4
    floadc_1
    fstore 5
    iloadc 1
    istore 6
    bloadc_t
    bstore 7
    return

.const float 3.0
.const int 100
.exportfun "__init" void __init
.global int
