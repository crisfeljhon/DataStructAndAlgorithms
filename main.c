#include "linked_list.h"
#include <stdio.h>

int main(void) {
    LinkedList mga_gwapo;
    linked_list_init(&mga_gwapo);

    linked_list_append(&mga_gwapo, (void *)69);
    linked_list_append(&mga_gwapo, (void *)9999);
    linked_list_insert(&mga_gwapo, 1, (void *)123);

    for (size_t i = 0; i < mga_gwapo.size; i++) {
        printf("Node %zu: %d\n", i, (int)(long)linked_list_get(&mga_gwapo, i));
    }

    linked_list_remove(&mga_gwapo, 1);

    printf("After remove:\n");
    for (size_t i = 0; i < mga_gwapo.size; i++) {
        printf("Node %zu: %d\n", i, (int)(long)linked_list_get(&mga_gwapo, i));
    }

    linked_list_clear(&mga_gwapo);
    return 0;
}
