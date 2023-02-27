#include "vector_private.h"
#include "vector.h"
#include <string.h>

// public
vector* vector_new(size_t element_size) {
	vector* vec = (vector*)malloc(sizeof(vector));

	//preallocate size for 5 elements in the vector
	vec->allocated_memory = 5 * element_size;
	vec->data = malloc(vec->allocated_memory);
	vec->element_size = element_size;
	vec->length= 0;

	return (vector*) vec;
}

// public
void vector_free(vector* vec) {
	free(vec->data);
	free(vec);
}

// public
bool vector_add(vector* vec, void* data) {
	bool success = true;

	//check if reallocation is require and so if necessary 
	if (vec->length * vec->element_size >= vec->allocated_memory)
		success = vector_reallocate_memory(vec);
	
	if (success) {
		uint32_t offset = vec->length * vec->element_size;
		void* insert_pointer = (void*)(((uint8_t*)vec->data) + offset);
		memcpy(insert_pointer, data, vec->element_size);

		vec->length++;
	}

	return success;

}

void* vector_get(vector* vec, uint32_t element) {
	if (element > vec->length)
		return NULL;

	return 	(void*)(((uint8_t*)vec->data) + vec->element_size * element);
}

void vector_for_each(vector* vec, vector_operation op) {
	for (uint32_t i = 0; i < vec->length; ++i) {
		void* element = vector_get(vec, i);
		op(element, vec->element_size);	
	}
}

// private
bool vector_reallocate_memory(vector* vec) {
	uint32_t new_size = vec->element_size * (vec->length + 5);
	void* new_pointer = realloc(vec, new_size);

	if (new_pointer != NULL) {
		vec = new_pointer;
		vec->allocated_memory = new_size;
	}
	return new_pointer != NULL;
}
