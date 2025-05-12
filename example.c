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

	struct strtok_adequate_arg t = { str, len, ",;", 0, 0 };
	int total = 0;

	printf("tokens:");
	while(strtok_adequate_arg(&t)) {
		printf(" %.*s", (unsigned int) t.tlen, &str[t.toff]);
		++total;
	}
	printf("\n%i total\n", total);

	return 0;
}

