## Point 1 

For point 1 I used the given initialization function checking if the return value is GNSS_PARSER_OK, if not it prints an error message and then exits the program

## Point 2 

For point 2 I developed 2 implementation, one which is commented, both gets the uint8_t value from the rand() function % 256 (max value of a 8 bit unsigned), the the commented one instanciate a uint32_t variable to 0, then adds the two variables and returns the result, whilst the other one simply assign the uint32_t value to uint32_t, this should work because C use the zero-extension when extending a value from a lower number of bit to a higher one, if both are unsigned, if they are signed we get the sign-extension

## Point 3 

For point 3 we simply do some bitwise checks on value and we switch cases, checking that the function called returned positive result, we do not stop the programm because it may have been a temporary malfunction, we can maybe implement a counter to check the count of errors and after a certain amount we stop the execution with a error message

## Bonus

After creating the queue.h, which contains the prototype of the three function needed and the struct, we implement them in the .c file --> the create takes the size of the queue and the data type allocating the memory needed, and initialize the index and the cur_num (current number of message in the queue), the destroy simply frees the memory after setting the pointers to NULL for security purpose (even tho seen the context it should not be necessary), the enqueue first check if the queue is "full" resetting the index and cur_num and after that enqueue the message.

In the main we instantiate the 3 queue, and after eache message if the printing return positive execution then we save the message.

## Comment 

On the bonus task I had to read some documentation, because I didn't perfectly remember ADT.