#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

#define ARG "|%0*.*d|\n", 3, 2, 97

int main(void)
{
	printf("ORIG = ");
	printf(ARG);
	ft_printf("FAKE = ");
	ft_printf(ARG);
	return (0);
}
