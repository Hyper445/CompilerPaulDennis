
__init:
	return
	iloadc 0
	istoreg 1

main:
	isr 
	iloadg 1
	jsre 0
	iloadc_0
	ireturn
.const int 10
.exportfun "__init" void __init
.exportfun "main" int main
.global int
.importfun "printInt" void int 
