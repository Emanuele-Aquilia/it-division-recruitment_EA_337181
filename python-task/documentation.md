## Reader 

The reader extends the given class to initialize, and when it receives a message it write it to the PIPE. 
In hte main it opens the pipe, then initialize the notifier and enters in a loop, the notifiers will notify asyncronously the listener --> that write the message received in the pipe 

## Printer 

The printer first wait for the pipe to be opened, then check if any message has been written to it, if yes simply prints it.

## Comment 

I have to use a lot of documentation for this problem, mainly because I never worked with object python, and I didn't clearly understand the request, maybe because of that.