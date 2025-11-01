#include "queue.h"
#include <pthread.h>
typedef struct queue {
	pthread_mutex_t *mutex;
	pthread_cond_t *queue_full;
	pthread_cond_t *queue_empty;
	int length;
	int oldest;
	void **queue;
	int top;
} queue_t; 

bool print_queue(queue_t *q, int size){
	for (int i = 0; i < size; i++){
                	if (q -> queue[i] == NULL){
                        	printf("NULL\n");
                	}
        	}
	printf("%d\n", q -> length);
	printf("%d\n", q -> top);
	return true;
}
queue_t* queue_new(int size){
	queue_t *q;
	q = (queue_t*)malloc(sizeof(queue_t));
	q -> queue = (void**)malloc(sizeof(void*) * size);
	for (int i = 0; i < size; i++){
		q -> queue[i] = NULL;
	}
	q -> length = size;
	q -> top = -1;
	q -> oldest = 0;
	q -> mutex = malloc(sizeof(*(q -> mutex)));
	q -> queue_full = malloc(sizeof(*(q -> queue_full)));
	q -> queue_empty = malloc(sizeof(*(q -> queue_empty)));
	int result = pthread_mutex_init(q -> mutex, NULL);

	pthread_cond_init(q -> queue_full, NULL);
	pthread_cond_init(q -> queue_empty, NULL);
	return q;
}

void queue_delete(queue_t **q){
	free((*q) -> queue);
	pthread_mutex_destroy((*q) -> mutex);
	pthread_cond_destroy((*q) -> queue_empty);
	pthread_cond_destroy((*q) -> queue_full);
	free((*q));

}

bool queue_push(queue_t *q, void *elem){
	pthread_mutex_lock(q -> mutex);
	if (q == NULL){
		return false;
	}
	while(q -> top == (q -> length)){
		pthread_cond_wait(q -> queue_full, q -> mutex);
		
	}
	q -> top++;
	int rear = (q -> top + q -> oldest)%(q -> length);	
	q -> queue[rear] = elem;
	pthread_mutex_unlock(q -> mutex);
	return true;
}

bool queue_pop(queue_t *q, void **elem){
	pthread_mutex_lock(q -> mutex);
	if (q == NULL){
		return false;
	}
	while(q -> top == -1){
		pthread_cond_wait(q -> queue_empty, q -> mutex);
	}
	*elem = q -> queue[q -> oldest];	
	q -> oldest = (q -> oldest + 1)%(q -> length);
	q -> top--;
	
	pthread_mutex_unlock(q -> mutex); 

	return true;
}
