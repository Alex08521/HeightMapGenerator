#include "pch.h"
#include "twoPoints.h"

twoPoints::twoPoints()
{
	pnt1=0;
	pnt2=0;
}

twoPoints::twoPoints(int a,int b)
{
	pnt1=a;
	pnt2=b;
}
int twoPoints::get_pnt1()
{
	return (pnt1);
}
int twoPoints::get_pnt2()
{
	return (pnt2);
}

void twoPoints::setPoints(int a, int b)
{
	pnt1 = a;
	pnt2 = b;
}
