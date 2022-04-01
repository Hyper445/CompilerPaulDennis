__init:
    iloadc_1
    istoreg 0
    return

test:
    esr 4
    bloadc_t
    bstore 2
    bloadc_f
    bstore 3
    iloadc 0
    istore 4
    bloadc_t
    bstore 5
    return

.const int 100
.exportfun "__init" void __init
.global int
