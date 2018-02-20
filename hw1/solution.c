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

#include "struct_generic.h"
#include "struct_list.h"

list_t *new_list(int size){
    list_t *ll = (list_t*)malloc(sizeof(list_t));
    ll->size = 0;
    ll->head = NULL;
    return ll;
}

int is_empty(list_t *list){
    return list->size == 0 ? 1 : 0;
}

void print_struct(list_t *list){
    list_elem_t *current = list->head;
    while (current->next != NULL){
        current = current->next;
    }

    while (current != NULL){
        printf("%d ", current->key);
        current = current->prev;
    }
}

void push(list_t *list, list_elem_t *elem){
    printf("Push %d\n", elem->key);
    // In case if list is empty
    if (list->head == NULL){
        list->head = elem;
        list->head->prev = NULL;
        list->head->next = NULL;
        list->size++;
    } else {
        list_elem_t *current = list->head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = elem;
        current->next->prev = current;
        current->next->next = NULL;
        list->size++;
    }
}

list_elem_t *pop(list_t *list){

    if (is_empty(list)){
        return NULL;
    }

    if (list->size == 1){
        list_elem_t *tmp = list->head;
        printf("Pop %d\n", tmp->key);
        list->head = NULL;
        list->size--;
        return tmp;
    }

    list_elem_t *current = list->head;
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

list_elem_t *find(list_t *list, int key){

    int found = 0;
    list_elem_t *current = list->head;
    while (current != NULL && found == 0) {
        if (current->key == key) {
            found = 1;
        } else {
            current = current->next;
        }
    }
    return current;
}

list_elem_t *delete(list_t *list, int key){
    list_elem_t *elem = find(list, key);
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
