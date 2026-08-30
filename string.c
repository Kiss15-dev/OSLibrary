#include <stddef.h>
#include <stdint.h>
#include <vector.h>

void *my_memcpy(void *dest, const void *scr, size_t n) {
	uint8_t *d = (uint8_t*)dest;
	const uint8_t *s = (const uint8_t*)scr;

	while(n--) {
		*d++ = *s++;
	}

	return dest;
}

void* my_memset(void *scr, int c, size_t n) {
	uint8_t *s = (uint8_t*)scr;

	while(n--) {
		*s++ = (uint8_t)c;
	}

	return scr;
}

uint8_t my_memcmp(const void *scr1, const void *scr2, size_t n) {
	const uint8_t *s1 = (const uint8_t*)scr1;
	const uint8_t *s2 = (const uint8_t*)scr2;

	for (size_t i = 0; i < n; i++) {
		if (s1[i] < s2[i]) return -1;
		if (s1[i] > s2[i]) return 1;
	}

	return 0;
}

void* my_memchr(const void* scr, int c, size_t n) {
	const uint8_t* s = (const uint8_t*)scr;

	while(n--) {
		if (*s == (uint8_t)c) return (void *)s;
		s++;
	}
}

size_t my_strlen(char* str) {
	char* s = str;
	size_t i;

	while(*s++ != '\0') {
		i++;
	}

	return i;
}

void* str_append(struct Vector *vector, char* str) {
	if (get_size_vector(vector) == 1) {
		char *s = str;
		size_t length = my_strlen(str);

		if (length + 1 == '\0') {
			while (*s != '\0') {
				push_back_vector(vector, *s);
				s++;
			}

			push_back_vector(vector, '\0');

			return;
		}
	}

	return NULL;
}

void str_lower(char* str) {
	char* s = str;

	while(*s != '\0') {
		if (*s < 100) {
			*s += 32;
		}

		s++;
	}
}

void str_upper(char* str) {
	char* s = str;

	while (*s != '\0') {
		if (*s > 100) {
			*s -= 32;
		}

		s++;
	}
}

void* str_terminate(struct Vector *vector) {
	if (get_size_vector(vector) == 1) {
		if (get_last_elem_vector(vector) != '\0') {
			push_back_vector(vector, '\0');
		}
	}

	return NULL;
}

int strcmp(char *str1, char *str2) {
	char* s1 = str1;
	char* s2 = str2;

	while (*s1 && *s1 == *s2) {
		s1++;
		s2++;	
	}

	if (*s1 < *s2) return -1;
	if (*s1 > *s2) return 1;
	return 0;
}

int strncmp(char *str1, char *str2, size_t n) {
	char* s1 = str1;
	char* s2 = str2;

	while (*s1 && *s1 == *s2 && n-- > 0) {
		s1++;
		s2++;	
	}

	if (*s1 < *s2) return -1;
	if (*s1 > *s2) return 1;
	return 0;
}

void main() {

}