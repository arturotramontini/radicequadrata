// https://docs.google.com/document/preview?hgd=1&id=1DzNJq7gL1Dts30qFYfoIvKu2JoNfx5VJGGpatYrnvhk#
// algoritmo di erone (geometrico) ricalca il babilonese
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

volatile double area = 24568.0;
volatile double base = 1;
volatile double altezza = 0;
volatile double erro = 1;
double errp1 = -1;
double errp2 = 0;
double prev = 0;

double sqrtArea;

//double calcolo();
void d2h(double v, char *s);

char *s;
char b[1000];
unsigned char bv[8];
char s2[65];

int main()
{

	sqrtArea = sqrt(area);

	s = &b[0];

	//s = (char *)malloc(1000);

	//printf("\n");
	//double value = 1;
	//memcpy(bv, (unsigned char *)&value, 8);
	//for (int i = 0; i < 8; i++)
	//{
	//	printf("%02X", bv[7 - i]);
	//}
	//printf("\n");

	printf("start\n");
	for (int i = 0; i < 30; i++)
	{
		sqrtArea = sqrt(area);

		//base = sqrt(area);

		//scritto cosi, sbaglia la sottrazione
		erro = (double)(base - (volatile double)(sqrt(area))); //xxx); // sqrt(area)); //sqrtArea);

		//if (errp1 == erro)
		//{
		//	printf("**break**\n\n");
		//	break;
		//}
		//errp2 = errp1;
		//errp1 = erro;

		//scritto cosi , la sottrazione e' giusta
		double xxx = sqrt(area);
		erro = (double)(base - xxx); //(volatile double)(sqrt(area))); //xxx); // sqrt(area)); //sqrtArea);

		d2h(sqrt(area), s2);
		printf("%s sqrt(area)\n", s2);
		d2h(base, s2);
		printf("%s base\n", s2);
		d2h(erro, s2);
		printf("%s erro\n", s2);

		sprintf(s, "\nit:%d \narea:%030.24f \nsqrt:%030.24f \nbase:%030.24f \nalt :%030.24f \nerr: %3.2e \n",
				i, area, sqrt(area), base, altezza, erro);

		printf("%s\n", s);

		altezza = area / base;

		prev = base;
		base = (base + altezza) / 2;

		//double er = (base - altezza);
		////er = -1.2345;

		//er = (er >= 0) ? er : -er;
		//d2h(er, s2);
		////strcpy(s2, "er: ");
		//printf("%s er  %3.2e\n\n", s2, er);

		//if (er < 1e-14)
		//{
		//	printf("---break---\n\n");
		//	break;
		//}

		if (prev == base)
		{
			printf("**break**\n\n");
			break;
		}
	}

	printf("stop\n\n");

	d2h(area, s2);
	printf("%s area \n", s2);

	d2h(sqrt(area), s2);
	printf("%s sqrt(area)\n", s2);

	d2h(base, s2);
	printf("%s base\n", s2);

	d2h(altezza, s2);
	printf("%s altezza\n", s2);

	d2h(erro, s2);
	printf("%s erro\n", s2);

	return 0;
}

//double calcolo(double x, double a)
//{
//	double v;
//	v = 0.5 * (x + a / x);
//	return v;
//}

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