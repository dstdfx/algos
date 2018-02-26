/*
 *
 * Author: Rutskiy Daniil
 *
 * Implemented: deque
 * Big-O of solution:
 *   popLeft  - O(1)
 *   popRight - O(1)
 *   pushLeft - O(1)
 *   pushRight - O(1)
 *   print_struct - O(n)
 *   is_empty - O(1)*/

#define DEQ_IMPL

#include <stdlib.h>
#include <stdio.h>

#include "testing.h"

structure_t *init_st(int size){
    structure_t *ll = (structure_t*)malloc(sizeof(structure_t));
    if (ll == NULL){
        printf("Can't allocate memory, shit happens dude, take it easy..\n");
        return NULL;
    }
    ll->max_size = size;
    ll->elements = 0;
    ll->head = ll->tail = NULL;
    return ll;
}

int is_st_empty(structure_t *list){
    return list->elements == 0 ? 1 : 0;
}

void print_struct(structure_t *list){
    if (!is_st_empty(list)){
        node_t *current = list->tail;
        while (current != NULL) {
            printf("%d ", current->key);
            current = current->prev;
        }
        printf("\n");
    }
}


void pushRight(structure_t *list, node_t *elem){
    if (list->elements == list->max_size){
        printf("Deque is overflowed\n");
        return;
    }

    printf("Push right %d\n", elem->key);

    elem->next = elem->prev = NULL;

    if (list->head == NULL){
        list->head = list->tail = elem;
        list->elements++;
    } else {
        elem->prev = list->tail;
        list->tail = elem;
        list->tail->prev->next = elem;
        list->elements++;
    }
}

void pushLeft(structure_t *list, node_t *elem){
    if (list->elements == list->max_size){
        printf("Deque is overflowed\n");
        return;
    }

    printf("Push left %d\n", elem->key);

    elem->next = elem->prev = NULL;

    if (list->tail == NULL){
        list->tail = list->head = elem;
        list->elements++;
    } else {
        elem->next = list->head;
        list->head = elem;
        list->head->next->prev = elem;
        list->elements++;
    }
}

node_t *popLeft(structure_t *list){

    if (is_st_empty(list)){
        return NULL;
    }

    node_t *tmp = list->head;

    if (list->head->next == NULL){
        list->tail = NULL;
    } else {
        list->head->next->prev = NULL;
    }
    list->head = list->head->next;
    list->elements--;
    printf("Pop left %d\n", tmp->key);
    return tmp;
}

node_t *popRight(structure_t *list){

    if (is_st_empty(list)){
        return NULL;
    }

    node_t *tmp = list->tail;

    if (list->tail->prev == NULL){
        list->head = NULL;
    } else {
        list->tail->prev->next = NULL;
    }
    list->tail = list->tail->prev;
    list->elements--;
    printf("Pop right %d\n", tmp->key);
    return tmp;
}
