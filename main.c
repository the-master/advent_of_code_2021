// advent_of_code.cpp : Defines the entry point for the application.
//

#include "stdio.h"
#include "day_one.c"

#include "day_two.c"
#include "day_three.c"
#include "day_four.c"
#include "day_five.c"
#include "day_six.c"
#include "day_seven.c"
int main(void)
{
	printf("day 1 solution:\t%i\n", day_one_solution());
	printf("day 1 part two:\t%i\n", day_one_part_two());

	printf("day 2 solution:\t%i\n", day_two_sollution());
	printf("day 2 part two:\t%i\n", day_two_part_two());

	printf("day 3 solution:\t%i\n", day_three_sollution());
	printf("day 3 part two:\t%i\n", day_three_part_two());

	printf("day 4 solution:\t%i\n", day_four_sollution());
	printf("day 4 part two:\t%i\n", day_four_part_two());

	// this is kinda slow, my map is terrible
	//printf("day 5 solution:\t%i\n", day_five_sollution());
	//printf("day 5 part two:\t%i\n", day_five_part_two());

	printf("day 6 solution:\t%llu\n", day_six_sollution());
	printf("day 6 part two:\t%llu\n", day_six_part_two());
	
	
	printf("day 7 solution:\t%i\n", day_seven_sollution());
	printf("day 7 part two:\t%i\n", day_seven_part_two());
	return 0; 
}
