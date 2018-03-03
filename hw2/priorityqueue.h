#ifndef SOLUTION_H
#define SOLUTION_H

typedef int pq_node__t;

typedef struct PriorityQueue {
    int size;
    int elements;
    pq_node__t **payload;
} pq_struct__t;

pq_struct__t *initPQ(int);
int getMax(pq_struct__t*);
pq_node__t *extractMax(pq_struct__t*);
void removeElement(pq_struct__t*, int);
void changePriority(pq_struct__t*, int, int);
void printPQ(pq_struct__t *pq);
void insert(pq_struct__t*, pq_node__t*);

#endif // SOLUTION_H
