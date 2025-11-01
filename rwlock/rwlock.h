#ifndef LOCK_H
#define LOCK_H

typedef struct rwlock rwlock_t;
typedef enum {READERS, WRITERS, N_WAY} PRIORITY;
rwlock_t* rwlock_new(PRIORITY p, int n);
void rwlock_delete(rwlock_t **l);
void read_lock(rwlock_t *rw);
void read_unlock(rwlock_t *rw);
void writer_lock(rwlock_t *rw);
void writer_unlock(rwlock_t *rw);

#endif
