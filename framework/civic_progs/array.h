#ifndef __ARRAY_H
#define __ARRAY_H

extern void printIntVec(int[n] vec);
extern void printFloatVec(float[n] vec);

extern void printIntMat(int[m,n] mat);
extern void printFloatMat(float[m,n] mat);

extern void scanIntVec(int[n] vec);
extern void scanFloatVec(float[n] vec);

extern void scanIntMat(int[n,m] mat);
extern void scanFloatMat(float[n,m] mat);

extern int matMul(float[m, n] a, float[o, p] b, float[q, l] c);

#endif



