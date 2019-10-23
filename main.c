//
//  main.c
//  CVector
//
//  Created by Peter Linder on 10/23/19.
//  Copyright © 2019 Peter Linder. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "IntVector.h"

int main(int argc, const char * argv[]) {
	// Initialize pointer to empty IntVector
	IntVector *vec = malloc(sizeof(IntVector));
	IntVector_init(vec);
	
	printf("Test Pushing\n");
	
	IntVector_push(vec, 3);
	IntVector_push(vec, 5);
	IntVector_push(vec, 9);
	IntVector_push(vec, 20);
	IntVector_insert(vec, 14, 2);
	
	for (int i = 0; i < vec->size; ++i){
		printf("%d: %d\n", i, IntVector_at(vec, i));
	}
	
	printf("Test Popping\n");
	
	while (vec->size > 0) printf("%d\n", IntVector_pop(vec));
	
	return 0;
}
