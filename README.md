# Luxoft_gdansk_test_task

Test task for Luxoft Gdansk
Condition of task located in top of cpp files.

Review:  
In general the first 4 tasks are solved - at least first 3 ones are ok and I don't have any comments.

Task 4 - "Phylosophers" - solved partly and shows the first iteration of eating but I'd rather prefer to see the "infinite" loop of philosophers eating and thinking with each operation excplicitly identified and random length of each operation (BTW quite often the output of two treads collides - it's a minor stuff but I would prefer also to see more elegant output - especially taking in account that it's threading-related task)

Task 5 - combinations. To be perfectly honest I don't really like how this task was solved. Please find my comments below:
a) From formal point of view it shows the correct results for positive numbers. But when it's zero or negative it still produces an output - i.e. when the max number of words is 0 it is expected to have empty file (no combinations) but it displays combinations of 1 word each instead
b) No basic validation of file data - i.e. if we have only 4 words but the max number is 11 it would be good to have an excplicit error or at least warning message.
The same is in case if we put letter instead of number in the first line - the application shows "Unable to open file..." error which is not really true.
c) Another goal of this task was to assess your architecture skills as well. But unfortunately the code is quite short-looking. For example, I don't see how it can be extended in the future if we are planning to read the input from the socket. The same is for the case if we decide to change the delimiter from spaces to commas. Also the whole code us ill-structured - everything is in one single file.
