Bounded buffer API that defines a thread-safe queue using conditional variables and mutex locks. The struct queue is defined in queue.c
and is an opaque data structure, so it can only be interacted with through the API defined functions. 

queue_test.c and basic_thread_safety.c are test files. 

How to use:
Compile with clang/gcc as normal, and either make your own main file or use one of the two test files. 
