/*-
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 2019 Luis Bandarra <luis.bandarra@homestudio.pt>
 * All rights reserved.
 */

#include <stdio.h>

#define BITS 8
int change_pattern	(int, int, int, int);

/*
 * Search and check in value for the first occurence of a sequence of nbits,
 * set in pattern and return the result of the change of sequence
 */
int
change_pattern(int value, int nbits, int pattern, int new_pattern)
{
	/* create mask of nbits */
	int mask = ~(~0 << nbits);
	/* set pattern to nbit of size */
	pattern &= mask;
	/* set new pattern to nbit of size */
	new_pattern = ~new_pattern & mask;

	/* locate first pattern match */
	int idx = 0;
	for (; idx < (BITS * sizeof value); idx++)
		if (((value >> idx) & mask) == pattern)
			break;

	value |= mask << idx;
	new_pattern = ~(new_pattern << idx);
	return value & new_pattern;
}

int
main()
{
	printf("\nStart exercise 2...\n");
	printf("value: %x\tnew value:%x\n", 0x2AD555BC, change_pattern(0x2AD555BC, 5, 0x15, 0x2A));

	return 0;
}