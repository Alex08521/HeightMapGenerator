#ifndef TWOPOINTS_H
#define TWOPOINTS_H

class twoPoints
{
	public:
		twoPoints();
		twoPoints(int a,int b);
		int get_pnt1();
		int get_pnt2();
		void setPoints(int a, int b);
	private:
		int pnt1;
		int pnt2;
};

#endif
