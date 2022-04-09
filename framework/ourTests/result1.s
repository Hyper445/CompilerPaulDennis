__init:
    iloadc 0
    istoreg 0
    return

test1:
    isrg
    iloadc 1
    jsr 1 test4
    ireturn

__test1_test2:
    esr 1
    iloadc 0
    istore 1
    iloadc_1
    ireturn

__test1_test3:
    esr 2
    iloadc 2
    istore 1
    iloadc 3
    istore 2
    iloadc 4
    ireturn

test4:
    iload_0
    iloadc 0
    iadd
    ireturn

.const int 3
.const int 10
.const int 4
.const int 5
.const int 6
.exportfun "__init" void __init
.global int
