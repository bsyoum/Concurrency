#include "queue.h"
#include <unistd.h>
#include <stdint.h>
int main(){
	queue_t *q = NULL;
	printf("1\n");
	q = queue_new(5);
	printf("2\n");
	print_queue(q, 5);
	printf("3\n");
	int x = 5;
	void *y;
	y = &x; 
	uintptr_t z;
	queue_push(q, &x);
	queue_push(q, (void*)1);
	print_queue(q, 5);
	printf("this is z: %lu\n", z);
	queue_pop(q, (void**)&z);
	printf("this is z: %lu\n", z);
	print_queue(q, 5);
	queue_delete(&q);
	return 0;
}
