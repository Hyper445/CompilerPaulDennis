__init:
    iloadc 0
    istoreg 0
    return

test1:
    esr 2
    iloadc 0
    istore 1
    iloadc 1
    istore 2
    iload_1
    iload_1
    iadd
    istore 1
    iload_2
    iload_1
    iadd
    istore 1
    iloadc 2
    ireturn

test2:
    esr 1
    iloadc 0
    istore 1
    iload_1
    ireturn

.const int 3
.const int 5
.const int 2
.exportfun "__init" void __init
.global int
