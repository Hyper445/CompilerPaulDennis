__init:
    iloadc 0
    istoreg 0
    return

test1:
    iloadc 0
    ireturn

__test1_test2:
    iloadc_1
    ireturn

__test1_test2_test3:
    esr 1
    iloadc 0
    istore 1
    iloadc_1
    ireturn

test4:
    esr 1
    iloadc 0
    istore 1
    iload_1
    ireturn

.const int 3
.exportfun "__init" void __init
.global int
