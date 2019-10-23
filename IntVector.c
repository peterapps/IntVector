#include "IntVector.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>


void IntVector_init(IntVector *v){
	v->size = 0;
}

void IntVector_push(IntVector *v, int x){
	if (v->size == 0){ // Already empty
		v->data = malloc(sizeof(int));
	} else {
		// Copy data into new array
		int *new_data = malloc((v->size + 1)*sizeof(int));
		memcpy(new_data, v->data, (v->size)*sizeof(int));
		// Allocate memory for a bigger array
		free(v->data);
		v->data = new_data;
	}
	v->data[v->size] = x;
	v->size++;
}

int IntVector_pop(IntVector *v){
	assert(v->size > 0);
	int val = v->data[v->size-1];
	if (v->size == 1){ // Only 1 element left
		free(v->data);
	} else {
		// Copy data into new array
		int *new_data = malloc((v->size - 1)*sizeof(int));
		memcpy(new_data, v->data, (v->size - 1)*sizeof(int));
		// Allocate memory for a smaller array
		free(v->data);
		v->data = new_data;
	}
	v->size--;
	return val;
}

int IntVector_at(IntVector *v, int i){
	assert(i >= 0 && i < v->size);
	return v->data[i];
}

void IntVector_insert(IntVector *v, int x, int i){
	assert(i >= 0 && i <= v->size);
	if (i == v->size){
		IntVector_push(v, x);
	} else {
		int *new_data = malloc((v->size + 1)*sizeof(int));
		// Copy data before i
		memcpy(new_data, v->data, i*sizeof(int));
		// Set i
		new_data[i] = x;
		// Copy data after i
		memcpy(new_data + i + 1, v->data + i, (v->size - i)*sizeof(int));
		// Free memory
		free(v->data);
		v->data = new_data;
	}
	v->size++;
}
