#include <stdio.h>
#include <string.h>

#include "./strtok_adequate.h"

int main(int argc, char *argv[])
{
	if(argc <= 1) {
		printf("no argument provided\n");
		return 1;
	}

	const char *str = argv[1];
	int len = strlen(str);

	/* set both to zero */
	unsigned long token_off = 0, token_len = 0;
	int total = 0;

	printf("tokens:");
	while(strtok_adequate(str, len, &token_off, &token_len, ",;")) {
		printf(" %.*s", (unsigned int) token_len, &str[token_off]);
		++total;
	}
	printf("\n%i total\n", total);

	return 0;
}

