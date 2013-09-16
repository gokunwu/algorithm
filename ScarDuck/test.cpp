#if 0

#include <iostream>

union a {
int a_int1;
double a_double;
int a_int2;
};
typedef struct
{
a a1;
char y;
} b;
class c
{
double c_double;
b b1;
a a2;
};

int main(void)
{
	std::cout<<sizeof(c)<<std::endl;

	return 0;
}
#endif
