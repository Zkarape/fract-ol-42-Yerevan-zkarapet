float	power(float x, int n)
{
	float	res;

	res = 1;
	while (n--)
		res = res * x;
	return (res);
}
//#include <stdio.h>
//int main()
//{
//	printf("%f\n", power(2.5, 3));
//}
