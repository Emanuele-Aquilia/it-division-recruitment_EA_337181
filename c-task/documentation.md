## Point 1 

For point 1 I used the given initialization function checking if the return value is GNSS_PARSER_OK, if not it prints an error message and then exits the program

## Point 2 

For point 2 I developed 2 implementation, one which is commented, both gets the uint8_t value from the rand() function % 256 (max value of a 8 bit unsigned), the the commented one instanciate a uint32_t variable to 0, then adds the two variables and returns the result, whilst the other one simply assign the uint32_t value to uint32_t, this should work because C use the zero-extension when extending a value from a lower number of bit to a higher one, if both are unsigned, if they are signed we get the sign-extension

## Point 3 

For point 3 we simply do some bitwise checks on value and we switch cases.