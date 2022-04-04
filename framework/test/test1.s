__init:
    iloadc 0
    istoreg 0
    return

test:
    iloadc 0
    istore 0
    return

test2:
    esr 1
    iloadc 0
    istore 0
    return

.const int 3
.exportfun "__init" void __init
.global int
