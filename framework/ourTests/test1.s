__init:
    iloadc 0
    istoreg 0
    return

test1:
    esr 3
    iload_1
    iload_2
    ieq
    bstore 3
    iloadc 1
    ireturn

test2:
    esr 1
    iloadc 0
    istore 1
    iload_1
    ireturn

.const int 3
.const int 2
.exportfun "__init" void __init
.global int
