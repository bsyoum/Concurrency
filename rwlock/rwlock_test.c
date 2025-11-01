#include "rwlock.h"
#include <stdlib.h>
#include <stdio.h>


int main(){
	rwlock_t *lock;
	rwlock_new(READERS, 0);
	return 0;
}
