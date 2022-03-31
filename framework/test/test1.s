__init:
    iloadc 0
    istoreg 0
    iloadc 1
    istoreg 1
    iloadc 2
    istoreg 2
    return

test:
    esr 4
    bloadc_t
    bstore 2
    bloadc_f
    bstore 3
    iloadc 3
    istore 4
    bloadc_t
    bstore 5
    return

test4:
    iloadc 1
    ireturn

.const int 3
.const int 2
.const int 5
.const int 18
.exportfun "__init" void __init
.global int
.global int
.global int
