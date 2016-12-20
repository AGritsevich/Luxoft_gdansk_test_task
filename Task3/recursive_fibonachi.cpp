// Task 3
// Write a recursive function that calculates the fibonacci sequence up to 1000 Ie. f(i) < 1000. Return the sequence in some kind of container.

#include <list>
#include <assert.h>
#include <iostream>

// In VS for C++ program default stack size 1 MB
// One recursive call take from stack N bytes, where N depends on build configuration size of function and other params for function call
// So, max safe recurse deep is 2^20/ = 1 048 576 / 230 = ~4539 (~231 one call in debug for my machine)
// https://msdn.microsoft.com/en-us/library/8cxs58a6.aspx
const short kMaxFibonacciNumber = 4539; // safely stack deep 
const short kMinFibNumber = 2;
typedef unsigned long LONG;
typedef std::list<LONG> FibList;
std::list<LONG> container;
FibList sequence; // I can take in from fanc param, but it test task, so I don't think that it's real need here.
unsigned int Recursive_deep = 0; // I think will be enough and global

void recursive_fibonachi(LONG prev, LONG next, const LONG &max_number) {
	if (++Recursive_deep > kMaxFibonacciNumber) { // Max deep
		return; // can corrupt stack
	}
	if (next >= max_number) { // max_number not global to safely set it for every call
		return;
	}

	sequence.push_back(next);

	return recursive_fibonachi(next, prev + next, max_number);
} 

FibList fibonacci_seq(LONG max_fib_number) {
	sequence.clear();
	Recursive_deep = 0;
	
	if (max_fib_number >= kMinFibNumber) { // minimal calculate number of Fibonacci
		sequence.push_back(1); // Pre-condition of Fibonacci sequence
		recursive_fibonachi(1, 1, max_fib_number);
	}

	return sequence;
}

void main() {
	assert(fibonacci_seq(1000).size() == 16);
	assert(fibonacci_seq(100).size() == 11);
	assert(fibonacci_seq(10).size() == 6);
	assert(fibonacci_seq(1).size() == 0);
	assert(fibonacci_seq(0).size() == 0);
	assert(fibonacci_seq(-1).size() == kMaxFibonacciNumber + 1); // one precondition number
}