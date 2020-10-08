// https://docs.google.com/document/preview?hgd=1&id=1DzNJq7gL1Dts30qFYfoIvKu2JoNfx5VJGGpatYrnvhk#

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void d2h(double v, char *s);
double x = 0, a = 0, r = 0;
double radice();
char *s;
char b[1000];
char s2[65];
double err = 1;
double errp1 = -1;
double errp2 = 0;
double prev = 0;

int main()

{
	s = &b[0];

	printf("start\n%030.24f\n", 1e-4);
	//x = 1.000000000041L;
	a = 24568.0;
	r = sqrt(a);
	x = 1;
	for (int i = 0; i < 30; i++)
	{

		//scritto cosi, sbaglia la sottrazione
		err = x - sqrt(x * x); // r;

		//scritto cosi , la sottrazione e' giusta
		r = sqrt(a);
		err = x - r; //sqrt(a); // r;

		//if (errp1 == err)
		//{
		//	printf("**break**\n\n");
		//	break;
		//}
		//errp2 = errp1;
		//errp1 = err;

		sprintf(s, "\nit:%d\n%030.24f\n%030.24f\n%3.2e\n", i, x, sqrt(a), err);
		printf("%s\n", s);

		prev = x;
		x = radice(x, a);

		if (prev == x)
		{
			printf("**break**\n\n");
			break;
		}
	}
	printf("stop\n\n");

	d2h(a, s2);
	printf("%s a\n", s2);

	d2h(sqrt(a), s2);
	printf("%s sqrt(a)\n", s2);

	d2h(x, s2);
	printf("%s x\n", s2);

	d2h(err, s2);
	printf("%s err\n", s2);

	return 0;
}

double radice(double x, double a)
{
	double v;
	v = 0.5 * (x + a / x);
	return v;
}

void d2h(double v, char *s)
{
	double value = v;
	unsigned char bv[8];
	char s1[65];
	memcpy(bv, (unsigned char *)&value, 8);
	for (int i = 0; i < 8; i++)
	{
		sprintf(s1, "%02X", bv[7 - i]);
		*s++ = s1[0];
		*s++ = s1[1];
	}
}
