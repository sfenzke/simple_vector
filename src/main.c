#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

/*
void vector_print_element_op(void* data, uint32_t element_size) {
	printf("%i\n", *(int*)data);
}
*/

int main() {
	int test_value = 5;
	int test_value2 = 45;
	vector* test_vec = vector_new(sizeof(int));

	vector_add(test_vec, (void*) &test_value);
	vector_add(test_vec, (void*) &test_value2);
	
//	vector_for_each(test_vec, &vector_print_element_op); 

	printf("[");
	for (uint32_t i = 0; i < test_vec->length; ++i)
		printf("%i%s", *(int*)vector_get(test_vec, i), i + 1 < test_vec->length ? ", " : "");
	printf("]\n");	
	
	vector_free(test_vec);
	return EXIT_SUCCESS;
}
