
/*-
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 2019 Luis Bandarra <luis.bandarra@homestudio.pt>
 * All rights reserved.
 */

#include <stdio.h>

#define DEFAULT_TAB_SIZE 4

void space_to_tab	(char *, int);

/*
 * This change the whitespace ' ' to tab '\t' from the string it receives
 * as an argument.
 * The altered string is stored on the string sent
 * as argument to the function
 */
void
space_to_tab(char *string, int tab_size)
{
	printf("\n\nExecutar..\n");

	// local variables
	int str_idx = 0;
	int new_idx = 0;
	char c = string[str_idx];

	// iterate through all chars in array until the end
	while (c != '\0') {
		if ((str_idx % tab_size != 0) ||
		    (c != ' ')) {
		    	string[new_idx++] = c;
			c = string[++str_idx];
			continue;
		}

		int space_count = 0;
		for (;space_count < tab_size; ++space_count)
			if (string[str_idx + space_count] != ' ')
				break;

		if (space_count == tab_size) {
			c = '\t';
			str_idx += tab_size;
		} else {

			++str_idx;
		}

		string[new_idx++] = c;
		c = string[str_idx];
	}

	string[new_idx] = '\0';
}

int
main()
{
	printf("\nStart exercise 1...\n");

	char str[128] = "123 4567    89AB, CD    EFG HIJK      QWRT";

	printf("String origem:\n");
	printf("\n%s\n", str);

	space_to_tab(str, DEFAULT_TAB_SIZE);

	printf("String transformada:\n");
	printf("%s\n", str);

	return 0;
}