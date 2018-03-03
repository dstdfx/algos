/*
 *
 * Author: Rutskiy Daniil
 *
 * Implemented: priority queue via binary heap on array
 * Big-O of solution:
 */


#include <stdlib.h>
#include <stdio.h>

#include "priorityqueue.h"

pq_struct__t *initPQ(int size){
    pq_struct__t *pq = (pq_struct__t*)malloc(sizeof(pq_struct__t));
    if (pq == NULL){
        printf("Shit has happened!\n");
        exit(-1);
    }
    pq->size = size;
    pq->elements = 0;

    pq->payload = (pq_node__t**)malloc(sizeof(pq_node__t*) * size);
    if (pq->payload == NULL){
        printf("Shit has happened!\n");
        exit(-1);
    }
    return pq;
}

void siftDown(pq_struct__t* pq, int i) {

  while (2 * i + 1 <= pq->elements){
      // Til node has at least one child
      int left = 2 * i + 1;
      int right = left + 1;
      int j = left;

      if(j < pq->elements) {
        // Set to lager element out of two
        j = (*(pq->payload[right]) > *(pq->payload[left]))?right:left;
      } else return;

      // Order is right
      if(*(pq->payload[i]) >= *(pq->payload[j])) return;

      // Swap elements
      int temp = *(pq->payload[i]);
      *(pq->payload[i]) = *(pq->payload[j]);
      *(pq->payload[j]) = temp;

      i = left;
  }
}

void siftUp(pq_struct__t* pq, int i){
    while ((*pq->payload[i]) > *(pq->payload[(i - 1) / 2])){
        int tmp = *(pq->payload[i]);
        *(pq->payload[i]) = *(pq->payload[(i - 1) / 2]);
        *(pq->payload[(i - 1) / 2]) = tmp;
        i = (i - 1) / 2;
    }
}

void insert(pq_struct__t* pq, pq_node__t* n){
    if (pq->size == pq->elements){
        printf("PQ overflowed\n");
        return;
    }
    printf("Insert %d\n", *n);
    pq->elements++;
    pq->payload[pq->elements - 1] = n;
    siftUp(pq, pq->elements - 1);
}

int getMax(pq_struct__t* pq){
    return *(pq->payload[0]);
}

pq_node__t *extractMax(pq_struct__t *pq){
    int tmp = *(pq->payload[0]);
    *(pq->payload[0]) = *(pq->payload[pq->elements - 1]);
    *(pq->payload[pq->elements - 1]) = tmp;
    pq_node__t *max = pq->payload[pq->elements - 1];
    pq->elements--;

    siftDown(pq, 0);
    return max;
}

void removeElement(pq_struct__t *pq, int i){
    int myOwnInfinity = getMax(pq) + 1;
    printf("Remove element [%d] with priority %d\n", i, *(pq->payload[i]));
    *(pq->payload[i]) += myOwnInfinity;
    siftUp(pq, i);
    extractMax(pq);
}

void changePriority(pq_struct__t* pq, int i, int newPriority){
    int lastPriority = *(pq->payload[i]);
    printf("Change priority of [%d] from %d to %d\n", i, lastPriority, newPriority);
    *(pq->payload[i]) = newPriority;
    (lastPriority < newPriority) ? siftUp(pq, i) : siftDown(pq, i);
}

void printPQ(pq_struct__t *pq){
    for(int i = 0; i < pq->elements; i++){
        printf("[%d] %d %p\n", i, *(pq->payload[i]), pq->payload[i]);
    }
}
