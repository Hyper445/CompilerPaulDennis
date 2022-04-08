main:
	esr 5
	iloadc 0
	istore 1
	iloadc 1
	istore 2
	iloadc_0
	istore 3
	iloadc 0
	istore 4
	iloadc 0
	istore 0
	iloadc 1
	istore 1
1_while:
	idec_1 0
	isrg 
	iload_0
	jsre 0
	isrg 
	iloadc 2
	jsre 0
	iinc_1 3
	iload_3
	iload_1
	igt
	jump 1_while
2_end:
	isrg 
	iloadc_1
	jsre 0
	iloadc 1
	istore 1
3_while:
	idec_1 0
	isrg 
	iload_0
	jsre 0
	isrg 
	iloadc 2
	jsre 0
	iload 4
	iloadc_1
	ineg
	iadd
	istore 4
	iload 4
	iload_1
	igt
	jump 3_while
4_end:
	isrg 
	iloadc_1
	jsre 0
	iloadc_0
	ireturn

.const int 10
.const int 5
.const int 3
.exportfun "main" int main
.importfun "printInt" void int 
.importfun "printFloat" void float 
.importfun "scanInt" int 
.importfun "scanFloat" float 
.importfun "printSpaces" void int 
.importfun "printNewlines" void int 
