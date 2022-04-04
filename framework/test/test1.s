test:
    isrg
    jsr 0 test2
    return

__test_test3:
    esr 1
    iloadc 0
    istore 0
    iload_0
    ireturn

test2:
    esr 1
    iloadc 1
    istore 0
    return

.const int 4
.const int 3
