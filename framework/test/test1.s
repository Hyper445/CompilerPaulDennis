__init:
    iloadc 0
    istoreg 0
    floadc 1
    fstoreg 1
    iloadc 0
    istoreg 2
    return

test:
    iloadg 2
    iloadc_0
    ilt
    branch_f 1_else
    iloadg 0
    iloadc 2
    igt
    branch_f 3_end
    iloadg 2
    iloadc_1
    iadd
    istoreg 2
3_end:
    jump 2_end
1_else:
    iloadg 2
    iloadc 2
    imul
    istoreg 2
2_end:
    iloadg 2
    istoreg 0
    isrg
    iloadg 2
    jsr 1 test2
    ipop
    iloadc 3
    ireturn

test2:
    esr 1
    iloadc 0
    istore 1
    iload_1
    ireturn

.const int 3
.const float 2.0
.const int 5
.const int 2
.exportfun "__init" void __init
.global int
.global float
.global int
