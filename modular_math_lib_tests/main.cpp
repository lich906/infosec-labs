#include <ios>
#include "../modular_math_lib/include/modular_math_lib.h"

void test(bool success);

int main()
{
	test(modular_add(6, 24, 4) == 2);
	test(modular_add(24, 6, 4) == 2);

	test(modular_sub(13, 4, 6) == 3);
	test(modular_sub(13, 3, 6) == 4);

	test(modular_mul(5, 8, 17) == 6);

	test(modular_div(17, 5, 7) == 2);
	test(modular_div(17, 2, 7) == 5);
}

void test(bool success)
{
	if (success)
	{
		printf("OK!\n");
	}
	else
	{
		printf("ERROR!\n");
	}
}
