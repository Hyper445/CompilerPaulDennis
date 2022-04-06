__init:
    iloadc 0
    istoreg 0
    return

test1:
    esr 4
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
    iloadc_1
    istore 3
    iload_2
    istore 4
1_while:
    iload_3
    iload 4
    ilt
    branch_f 2_end
    iloadc 0
    istore 1
    iinc_1 3               ; add -> inc
    jump 1_while
2_end:
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
