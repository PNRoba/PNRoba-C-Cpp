// md1_main.c - programmu C valodā, kas izsauc asamblera programmu un 
// padod tai parametru n un saņem rezultātu, ko izdrukā uz ekrāna.

#include <stdio.h>
#include <stdlib.h>
#include "md1.h"

int main(int argc, char **argv)
{
	unsigned int i = strtol(argv[1], NULL, 10);
	printf("%d\n", asum(i));
	return 0;
}
