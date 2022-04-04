__init:
    iloadc 0
    istoreg 0
    return

test1:
    esr 1
    iloadc 0
    istore 2
    iloadc 1
    istore 2
    iloadc 2
    istore 2
    iloadc 0
    ireturn

.const int 3
.const int 5
.const int 6
.exportfun "__init" void __init
.global int
