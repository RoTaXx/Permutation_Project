#ifndef _H_PERMUTATION_H_
#define _H_PERMUTATION_H_

int resMem(int**, unsigned, unsigned);
int delMem(int**, unsigned);
int fillArr(int**, unsigned, unsigned);
int printArr(int**, unsigned, unsigned);
int swap(int**, int , int );
int bsort(int**, int);
bool check_unique_numbers(int**, unsigned);
bool Injective(int**, unsigned);
bool Surjective(int**, unsigned);
bool Bijection(int**, unsigned);
int permutationFinder(int);
bool fixedPoints(int**, unsigned);
int fixedPointsCounter(int**, unsigned);
bool indentical(int**, unsigned);
void cycleNotation(int**, unsigned);
int getIndexOf(int**, int, unsigned);
//int** permutationComposition(int**, int**, unsigned);
//int** permutationCompositionRemake(char*, unsigned)


#endif // !_H_PERMUTATION_H_

