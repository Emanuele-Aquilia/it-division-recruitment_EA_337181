#include "queue.h"

Queue* create_queue(int size, GNSSParser_Data_t type) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->msg = (void**)malloc(capacity * sizeof(type));
    q->indx = 0;
    q->size = size;
    q->cur_num = 0;
    return q;
}

void destroy_queue(Queue *q) {
    q->msg = NULL;
    q = NULL;
    free(q->data);
    free(q);
}

void enqueue(Queue *q, void *data) {
    if (q->size % q->cur_num == 0) {
        q->indx = 0;
        q->cur_num = 0;
    }
    q->msg[q->indx] = data;
    q->indx = q->indx + 1;
    q->cur_num++;
}