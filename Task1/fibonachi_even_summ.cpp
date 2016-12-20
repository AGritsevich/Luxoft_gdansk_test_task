// Task 1
// Add up all the even elements of the fibonacci sequence below 1000. Ie. f(i) < 1000
#include <assert.h>

typedef unsigned long long LONG;

LONG calculate_even_ibonachi_sum(const unsigned int kMaxFibSeqNumber) {
	LONG fibonachi_even_sum = 0;
	LONG prev_num = 1;
	LONG cur_num = 1;
	LONG buffer = 0;

	while (buffer < kMaxFibSeqNumber ) {
		if (buffer % 2 == 0) {
			fibonachi_even_sum += buffer;
		}

		buffer = prev_num + cur_num;
		prev_num = cur_num;
		cur_num = buffer;
	}

	return fibonachi_even_sum;
}

void main() {
	assert(calculate_even_ibonachi_sum(3) == 2); // !1 + !1 + 2 = 2
	assert(calculate_even_ibonachi_sum(10) == 10);// !1 + !1 + 2 + !3 + !5 + 8 = 10
	assert(calculate_even_ibonachi_sum(200) == 188);// !1 + !1 + 2 + !3 + !5 + 8 + !13 + !21 + 34 + !55 + !89 + 144 = 188
	assert(calculate_even_ibonachi_sum(1) == 0); 
	assert(calculate_even_ibonachi_sum(0) == 0);
	assert(calculate_even_ibonachi_sum(1000) == 798); // !1 + !1 + 2 + !3 + !5 + 8 + !13 + !21 + 34 + !55 + !89 + 144 + !233 + !377 + 610 + !987
}