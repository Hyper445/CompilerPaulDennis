foo:
    isrg
    iloadc 0
    jsre 0
    isrl
    jsr 0 __foo_bar
    isrg
    jsr 0 baz
    return

__foo_bar:
    isrg
    iloadc 1
    jsre 0
    isrl
    jsr 0 __foo_bar_bar
    isrg
    jsr 0 baz
    isr
    jsr 0 __foo_foobar
    return

__foo_bar_bar:
    isrg
    iloadc_1
    jsre 0
    isrn 1
    jsr 0 __foo_foobar
    return

__foo_foobar:
    return

bar:
    isrg
    iloadc 2
    jsre 0
    return

baz:
    isrg
    iloadc 3
    jsre 0
    isrg
    jsr 0 bar
    return

main:
    isrg
    jsr 0 foo
    isrg
    jsr 0 bar
    isrg
    jsr 0 baz
    iloadc_0
    ireturn

.const int 3
.const int 2
.const int 4
.const int 5
.exportfun "main" int main
.importfun "printInt" void int
