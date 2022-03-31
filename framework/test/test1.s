__init:
    iloadc 0
    istoreg 0
    iloadc 1
    istoreg 1
    iloadc 2
    istoreg 2
    return

test:
    esr 1
    iloadg 0
    istore 2
    iloadg 0
    istore 2
    return

test4:
    iloadc 1
    ireturn

.const int 3
.const int 2
.const int 5
.exportfun "__init" void __init
.global int
.global int
.global int
