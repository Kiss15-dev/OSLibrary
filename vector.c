#include <stdlib.h>
#include <string.h>
#include <vector.h>

void init_vector(Vector *vector, size_t elem_size) {
	vector->capacity = 32;
	vector->ptr = malloc(vector->elem_size * vector->capacity);
	vector->elem_size = elem_size;
}

void free_vector(Vector *vector) {
	free(vector->ptr);
	vector->ptr = NULL;
	vector->size = 0;
	vector->capacity = 0;
	vector->elem_size = 0;
}

static void reserve_vector(Vector *vector, int new_capacity) {
	void *buff_ptr = realloc(vector->ptr, new_capacity);

	if (buff_ptr != NULL) {
		vector->capacity = new_capacity;
		vector->ptr = buff_ptr;
	}
}

void shrink_to_fit_vector(Vector *vector) {
	if (vector->capacity != vector->size) {
		void *buff_ptr = realloc(vector->ptr, vector->size);

		if (buff_ptr != NULL) {
			vector->ptr = buff_ptr;
			vector->capacity = vector->size;
		}
	}
}

void* push_back_vector(Vector *vector, const void *elem) {
	if (elem != NULL) {
		if (vector->size == vector->capacity) {
			reserve_vector(vector, vector->capacity * 2);
		}

		vector->size++;
		memcpy((uint8_t*)vector->ptr + (vector->size * vector->elem_size), elem, vector->elem_size);
	}

	return NULL;
}

void* insert_vector(Vector *vector, int index, const void* elem) {
	if (vector->size == vector->capacity) {
		reserve_vector(vector, vector->capacity * 2);
	}

	if (index < vector->size && index >= 0) {
		vector->size++;

		for (int i = 0; i < vector->size - index - 1; i++) {
			memcpy((uint8_t*)vector->ptr + vector->elem_size * (vector->size - 1 - i), (uint8_t*)vector->ptr + vector->elem_size * (vector->size - 2 - i), vector->elem_size);
		}

		memcpy((uint8_t*)vector->ptr + index * vector->elem_size, elem, vector->elem_size);
		return;
	}

	return NULL;
}

void* erase_vector(Vector *vector, int index) {
	if (index < vector->size && index > -1) {
		for (int i = 0; i < vector->size - index - 1; i++) {
			memcpy((uint8_t*)vector->ptr + vector->elem_size * (index + i), (uint8_t*)vector->ptr + vector->elem_size * (index + 1 + i), vector->elem_size);
		}

		vector->size--;
		return;
	}

	return NULL;
}

void* pop_back_vector(Vector *vector) {
	if (vector->size > 0) {
		vector->size--;
	}

	return NULL;
}

void* get_elem_vector(Vector *vector, int index) {
	if (index < vector->size && index > -1) {
		return (uint8_t*)vector->ptr + index * vector->elem_size;
	}

	return NULL;
}

void* set_elem_vector(Vector *vector, int index, int new_elem) {
	if (index < vector->size && index > -1) {
		memcpy((uint8_t*)vector->ptr + index * vector->elem_size, new_elem, vector->elem_size);
	}

	return NULL;
}

void* get_capacity_vector(Vector *vector) {
	return vector->capacity;
}

void* get_size_vector(Vector *vector) {
	return vector->size;
}

void* get_elem_size_vector(Vector *vector) {
	return vector->elem_size;
} 

int empty_vector(Vector *vector) {
	if (vector->size == 0) return 1;
	return 0;
}

uint8_t* get_last_elem_vector(Vector *vector) {
	return (uint8_t*)vector->ptr + vector->size * vector->elem_size;
}