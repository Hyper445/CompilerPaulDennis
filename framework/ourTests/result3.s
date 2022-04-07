test1:
    esr 1
    iloadc 0
    istore 0
    iinc_1 0               ; add -> inc
    iload_0
    ireturn

test2:
    esr 1
    iloadc 0
    istore 0
    iinc 0 0               ; add -> inc
    iload_0
    ireturn

test3:
    esr 1
    iloadc 1
    istore 0
    idec_1 0               ; sub -> dec
    iload_0
    ireturn

test4:
    esr 1
    iloadc 2
    istore 0
    idec 0 3               ; sub -> dec
    iload_0
    ireturn

.const int 3
.const int 5
.const int 6
.const int 12
