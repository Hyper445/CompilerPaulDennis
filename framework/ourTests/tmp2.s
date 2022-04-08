
test1:
	esr 2
	iloadc_1
	i2b
	bstore 2
	iloadc 0
	ireturn

main:
	iloadc 0
	ireturn
.const int 2
.exportfun "main" int main
.importfun "print" int int 
