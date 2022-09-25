# Leak report

In `checkwhitespace.c`, we found one leak issue. There are two methods under that part, and in the final part, the passed pointer was not being cleaned up, which led to the leak issue. The solution will be adding the code to free the memory at the final.

Under the test profile `check_whitespace_test.cpp` , there are multiple locations with leak issues, all of which are `strip` tests. To fix that issue, the way to do this is to create a variable in each test function and run the test with that variable, after properly freeing it.
