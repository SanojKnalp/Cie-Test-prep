# Lessons Learned
## task 1
When creating dynamic memory, using <md> new Shape*[] </md>, we can actually create an array with the type Shape pointer, which is neat.
## task 2
One can create multidimensional arrays via dynamic memory. The freeing in such case needs to be in reverse order.
Also we needed a first pointer for the reference of the rows, but we did not need a second one cause then we were not assigning row pointers, but values.
## task 3
if we don't specifically allocate memory on the stack, temporary memory as used in functions will be deleted leading to memory leaks.
## task 4
Memory is copied into a function regardless if it's used or not, so if we only create shallow copies we will have memory leaks.
Also always follow the rule of three cause that memory may be then assigned internally using an assignment operator. 
## task 5
Nothing. That one was easy if you did the previous four.
## task 6
copy != new assignment
## task 7
If we just copy/pass by value then the new memory is just ignored. However if we pass by adress we can actually change the value. However if we pass again by value, we will face the issue that the derived memory is sliced off. 
## task 8
Passing by reference gives the correct derived class