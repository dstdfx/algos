// List implementation

#ifdef LIST_IMPL
typedef struct my_list list_t;
typedef struct list_elem list_elem_t;

list_t* new_list(int size);
void push(list_t* list, list_elem_t* elem);
list_elem_t* pop(list_t* list);
list_elem_t* find(list_t* list, int key);
list_elem_t* delete(list_t* list, int key);
int is_empty(list_t* list);
void print_struct(list_t* list);

#endif