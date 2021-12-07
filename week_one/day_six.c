#include "int_stack.c"
#include "stdint.h"
int initial_population[300] = { 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1, 4, 1, 5, 1, 3, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 5, 5, 2, 5, 1, 1, 2, 1, 1, 1, 1, 3, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 5, 4, 1, 1, 1, 1, 1, 5, 1, 2, 4, 1, 1, 1, 1, 1, 3, 3, 2, 1, 1, 4, 1, 1, 5, 5, 1, 1, 1, 1, 1, 2, 5, 1, 4, 1, 1, 1, 1, 1, 1, 2, 1, 1, 5, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 3, 1, 1, 3, 1, 3, 1, 4, 1, 5, 4, 1, 1, 2, 1, 1, 5, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 5, 4, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 2, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 2, 1, 2, 1, 1, 4, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2, 1, 4, 1, 5, 1, 1, 1, 4, 5, 1, 1, 1, 1, 1, 1, 5, 1, 1, 5, 1, 2, 1, 1, 2, 4, 1, 1, 2, 1, 5, 5, 3 };




void initial_pop(uint64_t population[9]) {
	for (uint64_t i = 0; i < 300; i++)
		population[initial_population[i]]++;
}
void simulate_day(uint64_t population[9]) {
	uint64_t temp = population[0];

	for (uint64_t i = 0; i < 8; i++)
		population[i] = population[i + 1];

	population[8] = temp;
	population[6] += temp;

}

void simulate_days(uint64_t population[9], uint64_t days) {
	while (days-- > 0)
		simulate_day(population);
}

uint64_t sum_population(uint64_t population[9]) {
	uint64_t sum = 0;
	for (uint64_t i = 0; i < 9; i++)
		sum += population[i];
	return sum;
}
uint64_t day_six_sollution() {
	uint64_t population[9] = { 0 };
	initial_pop(population);

	simulate_days(population, 80);

	return sum_population(population);
}
uint64_t day_six_part_two() {
	uint64_t population[9] = { 0 };
	initial_pop(population);

	simulate_days(population, 256);

	return sum_population(population);
}