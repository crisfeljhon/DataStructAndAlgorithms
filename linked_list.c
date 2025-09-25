//
// Created by PANDAN on 17/09/2025.
//

#include "linked_list.h"

#include <stdlib.h>

void linked_list_init(LinkedList *self) {
    self->head = NULL;
    self->size = 0;
}

void linked_list_append(LinkedList *self, void *data) {
    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    node->data = data;
    node->next = NULL;

    if (self->head == NULL) {
        self->head = node;
    } else {
        LinkedListNode *last = self->head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = node;
    }
    self->size += 1;
}

void linked_list_clear(LinkedList *self) {
    LinkedListNode *current = self->head;
    while (current != NULL) {
        LinkedListNode *next = current->next;
        free(current);
        current = next;
    }
    self->head = NULL;
    self->size = 0;
}

void linked_list_insert(LinkedList *self, size_t index, void *data) {
    if (index > self->size) return; // out of bounds

    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    node->data = data;

    if (index == 0) { // insert at head
        node->next = self->head;
        self->head = node;
    } else {
        LinkedListNode *prev = self->head;
        for (size_t i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        node->next = prev->next;
        prev->next = node;
    }
    self->size += 1;
}

void linked_list_remove(LinkedList *self, size_t index) {
    if (index >= self->size || self->head == NULL) return;

    LinkedListNode *to_delete;
    if (index == 0) {
        to_delete = self->head;
        self->head = self->head->next;
    } else {
        LinkedListNode *prev = self->head;
        for (size_t i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        to_delete = prev->next;
        prev->next = to_delete->next;
    }
    free(to_delete);
    self->size -= 1;
}

void *linked_list_get(LinkedList *self, size_t index) {
    if (index >= self->size) return NULL;

    LinkedListNode *current = self->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}
