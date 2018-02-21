/*
 *
 * Author: Rutskiy Daniil
 *
 * Implemented: doubly linked list
 * Big-O of solution:
 *   pop  - O(n)
 *   push - O(n)
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
    ll->head = NULL;
    return ll;
}

int is_st_empty(structure_t *list){
    return list->size == 0 ? 1 : 0;
}

void print_struct(structure_t *list){
    if (!is_st_empty(list)){
        node_t *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }

        while (current != NULL) {
            printf("%d ", current->key);
            current = current->prev;
        }
        printf("\n");
    }
}

void push(structure_t *list, node_t *elem){
    printf("Push %d\n", elem->key);
    // In case if list is empty
    if (list->head == NULL){
        list->head = elem;
        list->head->prev = NULL;
        list->head->next = NULL;
        list->size++;
    } else {
        node_t *current = list->head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = elem;
        current->next->prev = current;
        current->next->next = NULL;
        list->size++;
    }
}

node_t *pop(structure_t *list){

    if (is_st_empty(list)){
        return NULL;
    }

    if (list->size == 1){
        node_t *tmp = list->head;
        printf("Pop %d\n", tmp->key);
        list->head = NULL;
        list->size--;
        return tmp;
    }

    node_t *current = list->head;
    while (current->next != NULL){
        current = current->next;
    }
    printf("Pop %d\n", current->key);
    current->prev->next = current->next;
    current->prev = NULL;
    current->next = NULL;
    list->size--;
    return current;
}

node_t *find(structure_t *list, int key){

    int found = 0;
    node_t *current = list->head;
    while (current != NULL && found == 0) {
        if (current->key == key) {
            found = 1;
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

    if (elem->prev == NULL){
        if (list->size != 1){
            list->head = elem->next;
            list->head->prev = NULL;
        } else {
            list->head = NULL;
        }
    } else {
        elem->prev->next = elem->next;
        if (elem->next != NULL){
            elem->next->prev = elem->prev;
        }
    }
    elem->next = NULL;
    elem->prev = NULL;
    list->size--;
    return elem;
}
