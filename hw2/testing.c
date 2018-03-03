#include <stdlib.h>
#include <assert.h>
#include "stdio.h"

#include "priorityqueue.h"


void test_pq(){
    pq_struct__t *pq = initPQ(10);

    for(int i = 7; i >= 1; i--){
        pq_node__t* n = (pq_node__t*)malloc(sizeof(pq_node__t));
        *n = i * 3;
        insert(pq, n);
    }

    printPQ(pq);

    assert(pq->elements == 7);

    pq_node__t* n1 = (pq_node__t*)malloc(sizeof(pq_node__t));
    *n1 =  33;
    insert(pq, n1);

    assert(getMax(pq) == 33);
    assert(pq->elements == 8);

    pq_node__t* n2 = (pq_node__t*)malloc(sizeof(pq_node__t));
    *n2 =  44;
    insert(pq, n2);

    assert(getMax(pq) == 44);
    assert(pq->elements == 9);

    pq_node__t* n3 = (pq_node__t*)malloc(sizeof(pq_node__t));
    *n3 =  10;
    insert(pq, n3);

    assert(pq->elements == 10);

    printPQ(pq);

    pq_node__t *h = extractMax(pq);
    printf("Extracted: %d %p\n", *h, h);

    assert(getMax(pq) == 33);
    assert(pq->elements == 9);
    assert(*h == 44);

    changePriority(pq, 0, 4);

    printPQ(pq);

    assert(getMax(pq) == 21);
    assert(*(pq->payload[7]) == 4);
    assert(pq->elements == 9);

    removeElement(pq, 3);
    assert(pq->elements == 8);

    printPQ(pq);

    free(pq->payload);
    free(pq);
}

int main(){
    test_pq();
    return 0;
}