gcd:
    iload_0
    iloadc_0
    ieq
    branch_f 54_end
    iload_1
    ireturn
54_end:
    iload_1
    iloadc_0
    ieq
    branch_f 53_end
    iload_0
    ireturn
53_end:
    iload_0
    iload_1
    igt
    branch_f 52_end
    isrg
    iload_0
    iload_1
    isub
    iload_1
    jsr 2 gcd
    ireturn
52_end:
    isrg
    iload_0
    iload_1
    iload_0
    isub
    jsr 2 gcd
    ireturn

fac:
    iload_0
    iloadc_1
    ige
    branch_f 50_else
    iload_0
    isrg
    iload_0
    iloadc_1
    isub
    jsr 1 fac
    imul
    ireturn
    jump 51_end
50_else:
    iloadc_1
    ireturn
51_end:
    iloadc_0
    ireturn

fib:
    iload_0
    iloadc_1
    ile
    branch_f 49_end
    iload_0
    ireturn
49_end:
    isrg
    iload_0
    iloadc_1
    isub
    jsr 1 fib
    isrg
    iload_0
    iloadc 0
    isub
    jsr 1 fib
    iadd
    ireturn

isPrime:
    esr 3
    iloadc 0
    istore 2
    iload_0
    iloadc_1
    iadd
    istore 3
40_while:
    iload_2
    iload_3
    ilt
    branch_f 41_end
    iload_0
    iload_2
    irem
    iloadc_0
    ieq
    branch_f 47_false_expr
    iload_2
    iload_0
    ieq
    jump 48_end
47_false_expr:
    bloadc_f
48_end:
    branch_f 42_else
    bloadc_t
    breturn
    jump 43_end
42_else:
    iload_0
    iload_2
    irem
    iloadc_0
    ieq
    branch_f 45_false_expr
    iload_2
    iload_0
    ine
    jump 46_end
45_false_expr:
    bloadc_f
46_end:
    branch_f 44_end
    bloadc_f
    breturn
44_end:
43_end:
    iinc_1 2               ; add -> inc
    jump 40_while
41_end:
    bloadc_f
    breturn

fibs:
    esr 2
    iloadc_0
    istore 1
    iload_0
    istore 2
38_while:
    iload_1
    iload_2
    ilt
    branch_f 39_end
    isrg
    isrg
    iload_1
    jsr 1 fib
    jsre 0
    isrg
    iloadc_1
    jsre 5
    iinc_1 1               ; add -> inc
    jump 38_while
39_end:
    return

primes:
    esr 2
    iloadc_0
    istore 1
    iloadc_0
    istore 2
35_while:
    iload_1
    iload_0
    ilt
    branch_f 36_end
    isrg
    iload_2
    jsr 1 isPrime
    branch_f 37_end
    isrg
    iload_2
    jsre 0
    isrg
    iloadc_1
    jsre 5
    iinc_1 1               ; add -> inc
37_end:
    iinc_1 2               ; add -> inc
    jump 35_while
36_end:
    return

printIntVec:
    esr 2
    iloadc_0
    istore 2
    iload_0
    istore 3
33_while:
    iload_2
    iload_3
    ilt
    branch_f 34_end
    isrg
    iload_2
    aload_1
    iloada
    jsre 0
    iinc_1 2               ; add -> inc
    jump 33_while
34_end:
    return

printFloatVec:
    esr 2
    iloadc_0
    istore 2
    iload_0
    istore 3
31_while:
    iload_2
    iload_3
    ilt
    branch_f 32_end
    isrg
    iload_2
    aload_1
    floada
    jsre 1
    iinc_1 2               ; add -> inc
    jump 31_while
32_end:
    return

printIntMat:
    esr 4
    iloadc_0
    istore 3
    iload_0
    istore 4
27_while:
    iload_3
    iload 4
    ilt
    branch_f 28_end
    iloadc_0
    istore 5
    iload_1
    istore 6
29_while:
    iload 5
    iload 6
    ilt
    branch_f 30_end
    isrg
    iload_3
    iload_1
    imul
    iload 5
    iadd
    aload_2
    iloada
    jsre 0
    iinc_1 5               ; add -> inc
    jump 29_while
30_end:
    iinc_1 3               ; add -> inc
    jump 27_while
28_end:
    return

printFloatMat:
    esr 4
    iloadc_0
    istore 3
    iload_0
    istore 4
23_while:
    iload_3
    iload 4
    ilt
    branch_f 24_end
    iloadc_0
    istore 5
    iload_1
    istore 6
25_while:
    iload 5
    iload 6
    ilt
    branch_f 26_end
    isrg
    iload_3
    iload_1
    imul
    iload 5
    iadd
    aload_2
    floada
    jsre 1
    iinc_1 5               ; add -> inc
    jump 25_while
26_end:
    iinc_1 3               ; add -> inc
    jump 23_while
24_end:
    return

scanIntVec:
    esr 2
    iloadc_0
    istore 2
    iload_0
    istore 3
21_while:
    iload_2
    iload_3
    ilt
    branch_f 22_end
    iload_2
    isrg
    jsre 2
    iload_2
    aload_1
    istorea
    iinc_1 2               ; add -> inc
    jump 21_while
22_end:
    return

scanFloatVec:
    esr 2
    iloadc_0
    istore 2
    iload_0
    istore 3
19_while:
    iload_2
    iload_3
    ilt
    branch_f 20_end
    iload_2
    isrg
    jsre 3
    iload_2
    aload_1
    fstorea
    iinc_1 2               ; add -> inc
    jump 19_while
20_end:
    return

scanIntMat:
    esr 4
    iloadc_0
    istore 3
    iload_0
    istore 4
15_while:
    iload_3
    iload 4
    ilt
    branch_f 16_end
    iloadc_0
    istore 5
    iload_1
    istore 6
17_while:
    iload 5
    iload 6
    ilt
    branch_f 18_end
    iload_3
    iload_1
    imul
    iload 5
    iadd
    isrg
    jsre 2
    iload_3
    iload_1
    imul
    iload 5
    iadd
    aload_2
    istorea
    iinc_1 5               ; add -> inc
    jump 17_while
18_end:
    iinc_1 3               ; add -> inc
    jump 15_while
16_end:
    return

scanFloatMat:
    esr 4
    iloadc_0
    istore 3
    iload_0
    istore 4
11_while:
    iload_3
    iload 4
    ilt
    branch_f 12_end
    iloadc_0
    istore 5
    iload_1
    istore 6
13_while:
    iload 5
    iload 6
    ilt
    branch_f 14_end
    iload_3
    iload_1
    imul
    iload 5
    iadd
    isrg
    jsre 3
    iload_3
    iload_1
    imul
    iload 5
    iadd
    aload_2
    fstorea
    iinc_1 5               ; add -> inc
    jump 13_while
14_end:
    iinc_1 3               ; add -> inc
    jump 11_while
12_end:
    return

matMul:
    esr 7
    iloadc_0
    istore 10
    iload_0
    istore 11
5_while:
    iload 10
    iload 11
    ilt
    branch_f 6_end
    iloadc_0
    istore 12
    iload_0
    istore 13
7_while:
    iload 12
    iload 13
    ilt
    branch_f 8_end
    iloadc_0
    istore 14
    iload_1
    istore 15
9_while:
    iload 14
    iload 15
    ilt
    branch_f 10_end
    iload 10
    iload 7
    imul
    iload 12
    iadd
    iload 10
    iload 7
    imul
    iload 12
    iadd
    aload 8
    floada
    iload 10
    iload_1
    imul
    iload 14
    iadd
    aload_2
    floada
    iload 14
    iload 4
    imul
    iload 12
    iadd
    aload 5
    floada
    fmul
    fadd
    iload 10
    iload 7
    imul
    iload 12
    iadd
    aload 8
    fstorea
    iinc_1 14              ; add -> inc
    jump 9_while
10_end:
    iinc_1 12              ; add -> inc
    jump 7_while
8_end:
    iinc_1 10              ; add -> inc
    jump 5_while
6_end:
    isrg
    iload 6
    iload 7
    aload 8
    jsr 3 printFloatMat
    iloadc_1
    ireturn

main:
    isrg
    jsr 0 testCore
    isrg
    jsr 0 testCoreio
    isrg
    jsr 0 testArray
    iloadc_0
    ireturn

testCore:
    esr 4
    iloadc 1
    istore 0
    iloadc 2
    istore 1
    iloadc 3
    istore 2
    iloadc 4
    istore 3
    isrg
    iloadc_1
    jsre 5
    isrg
    isrg
    iload_0
    iload_2
    jsr 2 gcd
    jsre 0
    isrg
    iloadc_1
    jsre 5
    isrg
    isrg
    iload_3
    jsr 1 fac
    jsre 0
    isrg
    iloadc_1
    jsre 5
    isrg
    isrg
    iload_3
    jsr 1 fib
    jsre 0
    isrg
    iloadc_1
    jsre 5
    isrg
    iloadc 1
    jsr 1 isPrime
    branch_f 3_else
    isrg
    iloadc_1
    jsre 0
    jump 4_end
3_else:
    isrg
    iloadc_0
    jsre 0
4_end:
    isrg
    iloadc 2
    jsr 1 isPrime
    branch_f 1_else
    isrg
    iloadc_1
    jsre 0
    jump 2_end
1_else:
    isrg
    iloadc_0
    jsre 0
2_end:
    isrg
    iloadc 0
    jsre 5
    return

testCoreio:
    esr 1
    iloadc 5
    istore 0
    isrg
    iload_0
    jsr 1 fibs
    isrg
    iloadc_1
    jsre 5
    isrg
    iload_0
    jsr 1 primes
    return

testArray:
    esr 9
    iloadc 6
    fnewa
    astore 0
    iloadc_0
    floadc 7
    iloadc_0
    aload_0
    fstorea
    iloadc_1
    floadc 8
    iloadc_1
    aload_0
    fstorea
    iloadc 0
    floadc 9
    iloadc 0
    aload_0
    fstorea
    iloadc 4
    floadc 10
    iloadc 4
    aload_0
    fstorea
    iloadc 11
    floadc 12
    iloadc 11
    aload_0
    fstorea
    iloadc 13
    floadc 14
    iloadc 13
    aload_0
    fstorea
    iloadc 6
    fnewa
    astore 1
    iloadc_0
    floadc 7
    iloadc_0
    aload_1
    fstorea
    iloadc_1
    floadc_1
    iloadc_1
    aload_1
    fstorea
    iloadc 0
    floadc 12
    iloadc 0
    aload_1
    fstorea
    iloadc 4
    floadc 15
    iloadc 4
    aload_1
    fstorea
    iloadc 11
    floadc 14
    iloadc 11
    aload_1
    fstorea
    iloadc 13
    floadc 9
    iloadc 13
    aload_1
    fstorea
    iloadc 16
    fnewa
    astore 2
    iloadc 11
    inewa
    astore 3
    iloadc_0
    iloadc_1
    iloadc_0
    aload_3
    istorea
    iloadc_1
    iloadc 0
    iloadc_1
    aload_3
    istorea
    iloadc 0
    iloadc 4
    iloadc 0
    aload_3
    istorea
    iloadc 4
    iloadc 11
    iloadc 4
    aload_3
    istorea
    iloadc 11
    fnewa
    astore 4
    iloadc_0
    floadc 10
    iloadc_0
    aload 4
    fstorea
    iloadc_1
    floadc 7
    iloadc_1
    aload 4
    fstorea
    iloadc 0
    floadc 8
    iloadc 0
    aload 4
    fstorea
    iloadc 4
    floadc 12
    iloadc 4
    aload 4
    fstorea
    iloadc 6
    inewa
    astore 5
    iloadc_0
    iloadc_1
    iloadc_0
    aload 5
    istorea
    iloadc_1
    iloadc 0
    iloadc_1
    aload 5
    istorea
    iloadc 0
    iloadc 4
    iloadc 0
    aload 5
    istorea
    iloadc 4
    iloadc 11
    iloadc 4
    aload 5
    istorea
    iloadc 11
    iloadc 13
    iloadc 11
    aload 5
    istorea
    iloadc 13
    iloadc 6
    iloadc 13
    aload 5
    istorea
    iloadc 4
    inewa
    astore 6
    iloadc 4
    fnewa
    astore 7
    iloadc 0
    inewa
    astore 8
    isrg
    iloadc 11
    aload_3
    jsr 2 printIntVec
    isrg
    iloadc 11
    aload 4
    jsr 2 printFloatVec
    isrg
    iloadc 4
    iloadc 0
    aload 5
    jsr 3 printIntMat
    isrg
    iloadc 4
    iloadc 0
    aload_0
    jsr 3 printFloatMat
    isrg
    iloadc 4
    aload 6
    jsr 2 scanIntVec
    isrg
    iloadc 4
    aload 7
    jsr 2 scanFloatVec
    isrg
    iloadc_1
    iloadc 0
    aload 8
    jsr 3 scanIntMat
    isrg
    iloadc 4
    iloadc 4
    aload_2
    jsr 3 scanFloatMat
    isrg
    iloadc 4
    iloadc 0
    aload_0
    iloadc 0
    iloadc 4
    aload_1
    iloadc 4
    iloadc 4
    aload_2
    jsr 9 matMul
    ipop
    return

.const int 2
.const int 12
.const int 13
.const int 144
.const int 3
.const int 8
.const int 6
.const float 3.0
.const float 4.0
.const float 7.0
.const float 2.0
.const int 4
.const float 5.0
.const int 5
.const float 9.0
.const float 6.0
.const int 9
.exportfun "gcd" int int int gcd
.exportfun "fac" int int fac
.exportfun "fib" int int fib
.exportfun "isPrime" bool int isPrime
.exportfun "fibs" void int fibs
.exportfun "primes" void int primes
.exportfun "main" int main
.importfun "printInt" void int
.importfun "printFloat" void float
.importfun "scanInt" int
.importfun "scanFloat" float
.importfun "printSpaces" void int
.importfun "printNewlines" void int
