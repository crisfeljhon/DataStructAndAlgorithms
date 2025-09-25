//
// Created by PANDAN on 17/09/2025.
//

#ifndef DATASTRUCTANDALGORITHMS_LINKED_LIST_H
#define DATASTRUCTANDALGORITHMS_LINKED_LIST_H

#include <stddef.h>

typedef struct LinkedListNode {
    struct LinkedListNode *next;
    void *data;
} LinkedListNode;

typedef struct {
    LinkedListNode *head;
    size_t size;
} LinkedList;

void linked_list_init(LinkedList *self);
void linked_list_append(LinkedList *self, void *data);
void linked_list_insert(LinkedList *self, size_t index, void *data);
void linked_list_remove(LinkedList *self, size_t index);
void linked_list_clear(LinkedList *self);
void *linked_list_get(LinkedList *self, size_t index);

#endif // DATASTRUCTANDALGORITHMS_LINKED_LIST_H
