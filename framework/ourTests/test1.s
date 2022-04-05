__init:
    iloadc 0
    istoreg 0
    return

test1:
    esr 4
    iloadc 0
    istore 2
    iloadc 1
    istore 3
    iloadc 0
    istore 4
    iload_3
    iload 4
    imul
    istore 5
    iloadc 1
    istore 2
    iloadc 2
    istore 2
    iloadc 0
    istore 0
    iloadc 3
    istore 1
    iloadc 3
    istore 3
    iloadc 0
    ireturn

.const int 3
.const int 5
.const int 6
.const int 2
.exportfun "__init" void __init
.global int
