__init:
    iloadc 0
    istoreg 0
    return

test:
    esr 1
    iloadg 0
    istore 2
    iloadg 0
    istore 2
    iloadc 1
    ireturn

.const int 3
.const int 2
.exportfun "__init" void __init
.global int
