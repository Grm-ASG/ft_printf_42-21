#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

#define ARG "|%-*.*s|\n", -5, -1, "HELLO"

int main(void)
{
	printf("ORIG = ");
	printf(ARG);
	ft_printf("FAKE = ");
	ft_printf(ARG);
	return (0);
}
