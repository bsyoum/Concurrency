#include "rwlock.h"
#include <stdlib.h>
#include <mutex.h>

typedef struct rwlock{
	PRIORITY priority;
	int n_way;


} rwlock_t;

rwlock_t* rwlock_new(PRIORITY p, int n){
	rwlock_t *lock;
	lock = (rwlock_t*)malloc(sizeof(rwlock_t));
	lock -> priority = p;
	lock -> n_way = n;
	return lock;


}


