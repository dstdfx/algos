#ifndef SOLUTION_H
#define SOLUTION_H

struct HW_NODE {
  int key;
  struct HW_NODE *next;
  struct HW_NODE *prev;
};

struct HW_STRUCT {
  int size;
  struct HW_NODE *head;
};


#endif // SOLUTION_H
