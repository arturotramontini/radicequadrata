#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{

	//printf("argc:%d\n", argc);
	//for (int i = 0; i < argc; i++)
	//{
	//	printf("%02d:%s\n", i, argv[i]);
	//}

	double valore = 1;
	if (argc > 1)
	{
		sscanf(argv[1], "%lf", &valore);
	}
	//printf("valore: %e\n", valore);

	double area = valore;
	double altezza = valore;
	double base = 1;
	double basePrecedente = 0;
	int n = 0;
	while (1)
	{
		n++;
		altezza = area / base;
		basePrecedente = base;
		base = (base + altezza) / 2;
		if (base == basePrecedente)
		{
			break;
		}
	}
	double rv = sqrt(area);
	//printf("%d iterazioni\n", n);
	//printf("%f radice computer\n", rv);
	//printf("%f radice calcolata\n", base);
	//printf("%f differenza\n", rv - base);

	printf("%-20.16g", base);

	return 1;
}