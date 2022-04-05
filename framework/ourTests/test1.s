__init:
    iloadc 0
    istoreg 0
    return

test1:
    esr 2
    iloadc 0
    istore 2
    iloadc 1
    istore 3
    isrg
    iloadc 0
    jsr 1 test2
    ipop
    isrg
    iloadc 0
    iloadc 1
    jsr 2 test1
    ipop
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
