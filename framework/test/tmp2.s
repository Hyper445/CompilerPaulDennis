
printInt:

__init:
	return
	iloadc 0
	istoreg 1

main:
	isr 
	iloadg 1
	jsr 1 printInt
	ipop
	iloadc_0
	ireturn
.const int 10
.exportfun "printInt" void printInt
.global int

printInt:

__init:
	return
	iloadc 0
	istoreg 1

main:
	isr 
	iloadg 1
	jsr 1 printInt
	ipop
	iloadc_0
	ireturn
.const int 10
.exportfun "printInt" void printInt
.exportfun "main" int main
.global int
