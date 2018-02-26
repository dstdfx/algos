#ifndef TESTING_H
# define TESTING_H

#include "solution.h"

/* IF YOU IMPLEMENT STACK, PRINT AT THE BEGINNING OF YOUR .c FILE
 * #define STACK_IMPL
 *
 * IF YOU IMPLEMENT QUEUE:
 * #define QUEUE_IMPL
 *
 * IF YOU IMPLEMENT LIST:
 * #define LIST_IMPL
 *
 * IF YOU IMPLEMENT DEQ:
* #define DEQ_IMPL  */

typedef struct HW_STRUCT structure_t;
typedef struct HW_NODE node_t;

// generic interface
structure_t* init_st(int size);
int is_st_empty(structure_t* s);
// print struct nodes without change it
void print_struct(structure_t* s);
// end of generic interface

// stack interface
#ifdef STACK_IMPL
  node_t* pop(structure_t* s);
  void push(structure_t* s, node_t* e);
#endif // STACK_IMPL
// end stack interface

// queue interface
#ifdef QUEUE_IMPL
  void enqueue(structure_t* s, node_t* e);
  node_t* dequeue(structure_t* s);
#endif // QUEUE_IMPL
// end queue interface

// list interface
#ifdef LIST_IMPL
  void push(structure_t* s, node_t* e);
  node_t* pop(structure_t* s);
  node_t* find(structure_t* s, int key);
  node_t* delete(structure_t* s, int key);
#endif // LIST_IMPL
// end of list interface

// DEQ interface
#ifdef DEQ_IMPL
  node_t* popLeft(structure_t* s);
  node_t* popRight(structure_t* s);
  void pushLeft(structure_t* s, node_t* e);
  void pushRight(structure_t* s, node_t* e);
#endif // DEQ_IMPL
// end of deq interface

#endif // TESTING_H
