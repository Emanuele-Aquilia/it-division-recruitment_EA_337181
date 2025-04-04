#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void **data;         
    int indx, size, cur_num;      
} Queue;

Queue* create_queue(int size, GNSSParser_Data_t type);
void destroy_queue(Queue *q);
void enqueue(Queue *q, void *data);

#endif
