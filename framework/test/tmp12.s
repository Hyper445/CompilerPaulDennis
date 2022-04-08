__init:
	iloadc 0
	istoreg 0
	return
main:
	isrg 
	isrl 
	iloadg 1
	jsre 0
	iloadc_0
	ireturn

.const int 10
.exportfun "__init" void __init
.exportfun "main" int main
.global int
.importfun "printInt" void int 
__init:
	iloadc 0
	istoreg -1
	return
main:
	isrg 
	iloadg 1
	jsre 0
	iloadc_0
	ireturn

.const int 10
.exportfun "__init" void __init
.exportfun "main" int main
.global int
.importfun "printInt" void int 
__init:
	iloadc 0
	istoreg 0
	return
main:
	isrg 
	iloadg 1
	jsre 0
	iloadc_0
	ireturn

.const int 10
.exportfun "__init" void __init
.exportfun "main" int main
.global int
.importfun "printInt" void int 
__init:
	iloadc 0
	istoreg 0
	return
main:
	isrg 
	iloadg 0
	jsre 0
	iloadc_0
	ireturn

.const int 10
.exportfun "__init" void __init
.exportfun "main" int main
.global int
.importfun "printInt" void int 
