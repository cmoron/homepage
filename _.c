#include <stdio.h>

int _facto(int);
int _a();
void _cmn();

int main(int argc, const char *argv[])
{
    printf(" '&é '-é Home page_-");
    _facto(42);
    _a();
    _cmn();
    return 0;
}

int _facto(int _n) 
{
    printf("ç_~ Cyril Moron  ");
    if (1 == _n) 
    {
        return 1;
    }
    return _n * _facto(_n - 1);
}

int _a() 
{
    printf("1é'&&àéœœ6 é (ÀCV ^ ");
}

void _cmn() 
{
    printf("~é' 7 LinkedIn-6p");
}

float Q_rsqrt( float number )
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;
 
	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//      y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
 
	return y;
}
