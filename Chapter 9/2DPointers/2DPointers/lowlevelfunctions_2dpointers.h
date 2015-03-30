#ifndef LOWLEVELFUNCTIONS_2DPOINTERS_H
#define LOWLEVELFUNCTIONS_2DPOINTERS_H

typedef int ITEM_TYPE;

ITEM_TYPE** allocate(int size []);
ITEM_TYPE* allocate(int size);
ITEM_TYPE** allocateWithPointers(int* size);
void deallocate(int** rows, int *size);
void print(ITEM_TYPE *array, int size);
void printAll(ITEM_TYPE **array, int *size);
int findLength(int* array);
void initialize(ITEM_TYPE *array, int size);
void initializeAll(ITEM_TYPE** array, int *size);
bool exist(ITEM_TYPE** array, int* size , int row, int collumn);
ITEM_TYPE* at(ITEM_TYPE** array,int* size, int row, int collumn);
ITEM_TYPE read(ITEM_TYPE** array,int* size, int row, int collumn);
void write(ITEM_TYPE** array,int* size, int row, int collumn, ITEM_TYPE input);
ITEM_TYPE* search(ITEM_TYPE* array, int size, ITEM_TYPE input);
ITEM_TYPE* searchAll(ITEM_TYPE **array, int *size, ITEM_TYPE input);

//To make size array dynamic
//ITEM_TYPE* copy( ITEM_TYPE *source, int size);//low level

void copy(ITEM_TYPE *source, int sourceSize, ITEM_TYPE *&destination, int &destinationSize);
void copyAll(ITEM_TYPE **source, int *sourceSize, ITEM_TYPE**&destination, int *&destinationSize);
void addEntry(ITEM_TYPE* &array, int &size, ITEM_TYPE entry);



#endif // LOWLEVELFUNCTIONS_2DPOINTERS_H
