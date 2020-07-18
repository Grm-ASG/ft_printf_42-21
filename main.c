#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

#define ARG	"|%-*.*s|\n", 5, 2, NULL

int main(void)
{
	printf(ARG);
	ft_printf(ARG);
	return (0);
}
