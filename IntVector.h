#ifndef IntVector_h
#define IntVector_h

typedef struct IntVectors {
	int *data;
	int size;
} IntVector;

void IntVector_init(IntVector *v);
void IntVector_push(IntVector *v, int x);
int IntVector_pop(IntVector *v);
int IntVector_at(IntVector *v, int i);
void IntVector_insert(IntVector *v, int x, int i);

#endif /* IntVector_h */
