/*-
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 2019 Luis Bandarra <luis.bandarra@homestudio.pt>
 * All rights reserved.
 */

#include <stdio.h>

#define ARRAY_SIZE(a) (sizeof a / sizeof a[0])

struct weather {
	float temperature;
	float wind;
	float humidity;
};

/* Return the average weather from an array containing several records
 * of weather information.
 */
void
weather_average(struct weather *average,
                const struct weather *weathers[],
                size_t nweathers)
{
	for (size_t i = 0; i < nweathers; i++) {
		average->temperature += (weathers[i]->temperature / nweathers);
		average->wind += (weathers[i]->wind / nweathers);
		average->humidity += (weathers[i]->humidity / nweathers);
		printf("Temp: %f\tWind: %f\tHum: %f\n",
			weathers[i]->temperature,
			weathers[i]->wind,
			weathers[i]->humidity);
	}
}

int
main(int argc, char *argv[])
{
	printf("\nStart exercise 4...\n");

	struct weather avg = {0.0,0.0,0.0};

	struct weather w1 = {20.0, 5.0, 80.5};
	struct weather w2 = {16.5, 1.2, 60.0};
	struct weather w3 = {17.0, 7.5, 72.4};
	struct weather w4 = {13.5, 13.6, 93.9};
	struct weather w5 = {18.0, 4.3, 75.3};

	const struct weather *weathers[] = {
		&w1, &w2, &w3, &w4, &w5
	};

	weather_average(&avg, weathers, ARRAY_SIZE(weathers));
	printf("Average temperature\nTem: %f\tWind: %f\tHumidity: %f",
	       avg.temperature, avg.wind, avg.humidity);

	return 0;
}