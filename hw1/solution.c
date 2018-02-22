/*
 *
 * Author: Rutskiy Daniil
 *
 * Implemented: doubly linked list
 * Big-O of solution:
 *   pop  - O(1)
 *   push - O(1)
 *   find - O(n)
 *   delete - O(n)
 *   print_stack - O(n)
 *   is_empty - O(1)*/

#define LIST_IMPL

#include <stdlib.h>
#include <stdio.h>

#include "testing.h"

structure_t *init_st(int size){
    structure_t *ll = (structure_t*)malloc(sizeof(structure_t));
    if (ll == NULL){
        printf("Can't allocate memory, shit happens dude, take it easy..\n");
        return NULL;
    }
    ll->size = 0;
    ll->head = ll->tail = NULL;
    return ll;
}

int is_st_empty(structure_t *list){
    return list->size == 0 ? 1 : 0;
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

// push to the list tail
void push(structure_t *list, node_t *elem){
    printf("Push %d\n", elem->key);

    elem->next = NULL;
    elem->prev = NULL;

    if (list->head == NULL){
        list->head = elem;
        list->tail = elem;
        list->size++;
    } else {
        elem->prev = list->tail;
        list->tail = elem;
        list->tail->prev->next = elem;
        list->size++;
    }
}

// pop from the list head
node_t *pop(structure_t *list){

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
    list->size--;
    return tmp;
}

node_t *find(structure_t *list, int key){

    node_t *current = list->head;
    while (current != NULL) {
        if (current->key == key) {
            return current;
        } else {
            current = current->next;
        }
    }
    return current;
}

node_t *delete(structure_t *list, int key){
    node_t *elem = find(list, key);

    if (elem == NULL){
        return NULL;
    }

    if (elem->prev == NULL && elem->next == NULL){
        // if it's the only element
        list->head = NULL;
        list->tail = NULL;
    } else if (elem->prev == NULL && list->head->next != NULL){
        // if it's head and not the only element
        list->head->next->prev = NULL;
        list->head = list->head->next;
    } else if (elem->next == NULL && list->tail->prev != NULL) {
        // if it's tail and not the only element
        list->tail->prev->next = NULL;
        list->tail = list->tail->prev;
    } else {
        elem->prev->next = elem->next;
        elem->next->prev = elem->prev;
    }

    elem->next = NULL;
    elem->prev = NULL;
    list->size--;
    return elem;
}
