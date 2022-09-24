#include <stdio.h>
#include <math.h>
#define PRECISION 15
#define ARG -1234567890.12345

int main()
{
	printf("ARG -1234567890.12345\n");
	printf("ARG 12.34...\t\t%d\n", (int)(ARG));
	printf("truncate 12.34...\t\t%d\n", (int)(ARG * -1.0));
	printf("truncate -12.34...\t\t%d\n", (int)(ARG));
	printf("truncate -1234567890.12345\t\t%d\n", (int)(-1234567890.12345));
	const double	arg = ARG;
	const double	shift = pow(10, PRECISION);
	printf("shift \t\t%.20f\n", shift);
	const double	rounded = round(arg * shift) / shift;
	printf("arg * shift \t\t%.20f\n", arg * shift);
	printf("arg * shift truncated \t\t%lld\n", (long long)(arg * shift));
	printf("arg * shift / shift \t\t%.20f\n", ((long long)(arg * shift)) / shift);
	const double	unrounded = (trunc(arg * shift)) / shift;
	const double	diff = (arg - unrounded) - (rounded - arg);
	double			result;

	result = (arg * shift); // prepare
	printf("arg \t\t%f\n", arg);
	printf("rounded \t%f\n", rounded);
	printf("unrounded \t%f\n", unrounded);
	printf("result\t\t%f\n", result);
	printf("\n");

	printf("diff unrounded \t\t%f\n", arg - unrounded);
	printf("diff rounded \t\t%f\n", rounded - arg);
	printf("diff \t\t\t%f\n", (arg - unrounded) - (rounded - arg));
	if (arg > 0.0)
	{
		if (diff > 0.0 || (diff == 0.0 && (int)result % 2 != 0))
			/*printf("Not even (0): %d\n", (((int)result % 2 != 0)));*/
			result += 1;
	}
	else
	{
		if (diff < 0.0 || (diff == 0.0 && (int)result % 2 != 0))
			/*printf("Not even (0): %d\n", (((int)result % 2 != 0)));*/
			result -= 1;
	}
	result /= shift;
	printf("OWN RESULT \t\t%.15f\n", result);
	printf("REAL RESULT \t\t%.15f\n", ARG);

	return 0;
}
