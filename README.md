# parallelprogramming--Pthread--use-of-mutex-semaphore-busywaiting-in-C


It has three class for busy waiting, mutex, and semaphore and the file names are busywait43.c, mutex43.c, and sema43.c

These classes implement trapezoidal rule to calculate area under the curve using pthread.

To compile busywait43.c in windows system.

gcc -g -Wall -o busy busywait43.c -lpthread

To run busywait43.c in windows system.

busy 4

To compile mutex43.c in windows system.

gcc -g -Wall -o mutex mutex43.c -lpthread

To run mutex43.c in windows system.

mutex 4

To compile sema43.c in windows system.

gcc -g -Wall -o sema sema43.c -lpthread

To run sema43.c in windows system.

sema 4

The number 4 can be replace with any number of thread count.
