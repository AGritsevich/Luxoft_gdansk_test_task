// Task 2
// Write a function that will calculate the area of a circle
// 
#define _USE_MATH_DEFINES

#include <math.h>
#include <iostream>
#include <assert.h>


double circle_area(double radius) {
	if (radius < 0) radius *= -1; // number area belong to N

	return M_PI * pow(radius, 2);
}

void main() {
	
	assert(circle_area(0) == 0);
	assert(circle_area(1) == M_PI);
	assert(circle_area(-1) == M_PI);
	assert(circle_area(0.1) == 0.01 * M_PI);
}