﻿// advent_of_code.cpp : Defines the entry point for the application.
//

#include "stdio.h"
#include "day_one.c"

#include "day_two.c"

int main(void)
{
	printf("day 1 solution:\t%i\n", day_one_solution());
	printf("day 1 part two:\t%i\n", day_one_part_two());

	printf("day 2 solution:\t%i\n", day_two_sollution());
	printf("day 2 part two:\t%i\n", day_two_part_two());
	
	return 0; 
}