#ifndef STRUCT_GENERIC_H
# define STRUCT_GENERIC_H

// Fill struct and uncomment define if you want to implement deq
// #define DEQ_IMPL
struct my_deq {
  int size;
};

// Fill it if you want to implement queue
// #define QUEUE_IMPL
struct my_queue {
  int size;
};

struct my_queue_elem {
  int key;
};

// Fill it if you want to implement stack
// #define STACK_IMPL
struct my_stack {
  int size;
};

// Fill it if you want to implement list
// #define LIST_IMPL
struct my_list {
    int size;
    list_elem_t *head;
};

struct list_elem {
    int key;
    list_elem_t *next;
    list_elem_t *prev;
};

#endif // STRUCT_GENERIC_H