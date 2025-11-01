#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue queue_t;
queue_t *queue_new(int size);
void queue_delete(queue_t **q);
bool print_queue(queue_t *q, int size);
bool queue_push(queue_t *q, void *elem);
bool queue_pop(queue_t *q, void **elem);



#endif
