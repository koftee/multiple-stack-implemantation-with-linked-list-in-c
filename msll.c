#include <stdio.h>
#include <stdlib.h>
#define MAX_QUE 10

typedef struct que *quepointer;
typedef struct que {
    int x;
    struct que *next;
} que;

quepointer front[MAX_QUE];
quepointer rear[MAX_QUE];

void add_que(quepointer *front, quepointer *rear, int x) {
    quepointer temp = (quepointer)malloc(sizeof(que));
    temp->x = x;
    temp->next = NULL;

    if (*front == NULL && *rear == NULL) {
        printf("Queue is empty... enqueuing\n");
        *front = *rear = temp;
    } else {
        (*rear)->next = temp;
        *rear = temp;
    }
}

int remove_que(quepointer *front) {
    int x;
    quepointer p = *front;

    if (*front == NULL) {
        printf("Queue is empty\n");
        return -1; // Kuyruk boşsa -1 döndür
    }

    x = (*front)->x;
    *front = (*front)->next;
    free(p);
    return x;
}

int main() {
    // Kuyruğu başlat
    for (int i = 0; i < MAX_QUE; i++) {
        front[i] = NULL;
        rear[i] = NULL;
    }

    // Kuyruğa eleman ekleme
    for (int i = 0; i < 5; i++) {
        int value = i + 1;
        add_que(&front[i], &rear[i], value);
        printf("Enqueued: %d\n", value);
    }

    // Kuyruktan eleman çıkarma
    for (int i = 0; i < 5; i++) {
        if (front[i] != NULL) {
            int removedValue = remove_que(&front[i]);
            if (removedValue != -1) {
                printf("Dequeued: %d\n", removedValue);
            }
        }
    }

    return 0;
}
