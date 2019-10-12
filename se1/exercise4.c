/*-
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 2019 Luis Bandarra <luis.bandarra@homestudio.pt>
 * All rights reserved.
 */

#include <stdio.h>

struct weather {
	float temperature;
	float wind;
	float humidity;
};

void
weather_average(struct weather *average,
                const struct weather *weathers[],
                size_t nweathers)
{
	// code
}

int
main(int argc, char *argv[])
{
	printf("\nStart exercise 4...\n");

	return 0;
}