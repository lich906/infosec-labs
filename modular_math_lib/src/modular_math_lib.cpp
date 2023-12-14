#include "../include/modular_math_lib_pch.h"
#include "../include/modular_math_lib.h"


int modular_inv(int x, int mod);
int bin_pow(int base, int p, int mod);


int modular_add(int x, int y, int mod)
{
	return (x % mod + y % mod) % mod;
}

int modular_sub(int x, int y, int mod)
{
	return (x % mod + (mod - y % mod)) % mod;
}

int modular_mul(int x, int y, int mod)
{
	return (x % mod * y % mod) % mod;
}

int modular_div(int x, int y, int mod)
{
	return x * modular_inv(y, mod) % mod;
}

int modular_inv(int x, int mod)
{
	return bin_pow(x, mod - 2, mod);
}

int bin_pow(int base, int p, int mod)
{
	if (p == 1)
	{
		return base;
	}

	if (p % 2 == 0)
	{
		long long t = bin_pow(base, p / 2, mod);
		return t * t % mod;
	}
	else
	{
		return bin_pow(base, p - 1, mod) * base % mod;
	}
}
