#ifndef SOLUTION_H
#define SOLUTION_H

struct HW_NODE {
  int key;
  struct HW_NODE *next;
  struct HW_NODE *prev;
};

struct HW_STRUCT {
  int max_size;
  int elements;
  struct HW_NODE *head;
  struct HW_NODE *tail;
};


#endif // SOLUTION_H
