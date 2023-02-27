#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
	void* data;
	uint32_t element_size;
	uint32_t allocated_memory;  
	uint32_t length;
} vector;

typedef void (*vector_operation)(void* data, uint32_t data_size);

vector* vector_new(size_t element_size);
void vector_free(vector* vec);
bool vector_add(vector* vec, void* data);
void* vector_get(vector* vec, uint32_t element);
void vector_for_each(vector* vec, vector_operation);
