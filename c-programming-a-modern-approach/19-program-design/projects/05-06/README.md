# Project 05-06

## 05

Starting from the `queue.h` header of Exercise 1, create a file named `queueADT.h` that defines the following `Queue` type:

```c
typedef struct queue_type *Queue;
```

`queue_type` is an incomplete structure type. Create a file named `queueADT.c` that contains the full definition of `queue_type` as well as definitions for all the functions in `queue.h`. Use a **fixed-length** array to store the items in a queue (see Exercise 3a). Create a file named `queueclient.c` that creates two queues and performs operations on them. Be sure to provide `create` and `destroy` functions for your `ADT`.

## 06

Modify Project 5 so that the items in a queue are stored in a dynamically allocated array whose length is passed to the `create` function.
