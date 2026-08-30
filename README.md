-----------------------------------------------------------------------------vector.c------------------------------------------------------------------------------------------------

	typedef struct {
		size_t capacity; - границы.
		size_t size; - реальный размер.
		size_t elem_size; - размер ОДНОГО элемента.
		void *ptr; - указатель на первый элемент.
	} Vector;

	void init_vector(Vector *vector, size_t elem_size) - начать работу с vector.
	void free_vector(Vector *vector) - очистить vector.
	void shrink_to_fit_vector(Vector *vector) - сузить capacity до size.
	void* push_back_vector(Vector *vector, const void *elem) - вставить элемент в конец vector.
	void* insert_vector(Vector *vector, int index, const void* elem) - вставить элемент в vector.
	void* erase_vector(Vector *vector, int index) - удалить элемент из vector.
	void* pop_back_vector(Vector *vector) - удалить последний элемент.
	void* get_elem_vector(Vector *vector, int index) - получить элемент по индексу.
	void* set_elem_vector(Vector *vector, int index, const void* new_elem) - изменить элемент по индексу.
	size_t get_capacity_vector(Vector *vector) - геттер capacity.
	size_t get_size_vector(Vector *vector) - геттер size.
	size_t get_elem_size_vector(Vector *vector) - геттер elem_size.
	int empty_vector(Vector *vector) - возвращает 1 если size = 0, 0 если size != 0.
	void* get_last_elem_vector(Vector *vector) - возвращает последний элемент vector.
