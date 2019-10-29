#include <stdio.h>

int char_count, word_count;

/* A line is allways present, because we write on lines */
int line_count = 1;

int
main
{
	char c;
	while ((c = getchar()) != EOF) {
		/*
		 * Any character read from input is accountable, even spaces
		 * and special characters from ASCII table.
		 * If we where to care for Unicode, we should change something,
		 * or else we have strange results.
		 */
		char_count++;

		if (c == '\n')
			line_count++;
	}

	if (char_count == 0)
		line_count = 0;

	printf("\n\n");
	printf("Nr. carateres: %d\t", char_count);
	printf("Nr. palavras: %d\t", word_count);
	printf("Nr. linhas: %d\t", line_count);
	printf("\n\n");

	return 0;
}