#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include "Field2D.h"

using namespace std;

template Field2D<unsigned short>;
template Field2D<unsigned int>;
template Field2D<uint8_t>;
template Field2D<uint16_t>;
template Field2D<uint32_t>;
template Field2D<uint64_t>;
template Field2D<unsigned long>;
template Field2D<long>;
template Field2D<float>;
template Field2D<short>;
template Field2D<int>;
template Field2D<int8_t>;
template Field2D<int16_t>;
template Field2D<int32_t>;
template Field2D<int64_t>;
template Field2D<double>;
template Field2D<bool>;
template Field2D<char>;
template Field2D<wchar_t>;
template Field2D<string>;
template Field2D<wstring>;


template <typename variabletype>
Field2D<variabletype>::Field2D(short f)
	{	
		if(f>1024)
		{
			cout<<"Warning! Size of fieldside is longer 1024"<<endl;
			exit(0);
		}	
		if (f <= 0) { cout << "Warning, field is to short" << endl; exit(0); }
		x = f - 1;
		y = f - 1;
		zeroy=(y/2);
		zerox=(x/2);
		nowy=zeroy;
		nowx=zerox;
		absciss=0;
		ordinate=0;
		/*for (int i = 0; i < f; i++)
		{
			for (int j = 0; j < f; j++)
			{
					FIELD[i][j] = NULL;
			}
		}*/
	}
template <typename variabletype>
Field2D<variabletype>::Field2D():x(1023),y(1023)
	{		
		zeroy=511;
		zerox=511;
		nowy=zeroy;
		nowx=zerox;
		absciss=0;
		ordinate=0;
		/*for (int i = 0; i < 512; i++)
		{
			for (int j = 0; j < 512; j++)
			{
				FIELD[i][j] = NULL;
			}
		}*/
	}

template <typename variabletype>
Field2D<variabletype>::~Field2D()
	{

	}

template <typename variabletype>
void Field2D<variabletype>::remakeField(short terr)
	{
		if (terr > 1024)
		{
			cout << "Warning! Size of fieldside is longer 1024" << endl;
			exit(0);
		}
		if (terr <= 0) { cout << "Warning, field is to short" << endl; exit(0); }
		x = terr - 1;
		y = terr - 1;
		zeroy = (y / 2);
		zerox = (x / 2);
		nowy = zeroy;
		nowx = zerox;
		absciss = 0;
		ordinate = 0;
	}

	//////////////////////////////////////////////////////////////////
	//??????? ?????
	//??????? ???????? ??????? ?????
template <typename variabletype>
void Field2D<variabletype>::get_zeropnt()
	{
		cout<<"Zeropoint of field is y="<<zeroy<<", x="<<zerox<<endl;
	}
	//??????? ??? ??????? ??????? ????? ??? ????????? ????
template <typename variabletype>
void Field2D<variabletype>::set_zeropnt(short i, short n)
	{
		zeroy=i;
		zerox=n;
	}
	//??????? ??? ??????? ??????? ????? ?????????????
template <typename variabletype>
bool Field2D<variabletype>::set_elem(variabletype i)
	{
		FIELD[nowy][nowx] = i;
		if (FIELD[nowy][nowx] == i)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//???????????? ??????????? ???????? ??????
template <typename variabletype>
variabletype Field2D<variabletype>::get_elem()
	{
		variabletype pnt;
		pnt = FIELD[nowy][nowx];
		return pnt;
	}
	/////////////////////////////////////////////////////////////////////
	//?????????
	//??????????? ?????
template <typename variabletype>
bool Field2D<variabletype>::move_up()
	{
		if(nowy == 0)
		{
			return false;
		}
		else if (nowy < 0)
		{
			nowy = 0;
			return false;
		}
		else
		{
			nowy--;
			return true;
		}
	}
	//??????????? ????
template <typename variabletype>
bool Field2D<variabletype>::move_down()
	{
		if(nowy == y)
		{
			return false;
		}
		if (nowy > y)
		{
			nowy = y;
			return false;
		}
		else
		{ 
			nowy++;
			return true; 
		}
	}
	//??????????? ?????
template <typename variabletype>
bool Field2D<variabletype>::move_left()
	{
		if(nowx == 0)
		{
			return false;
		}
		else if (nowx < 0)
		{
			nowx = 0;
			return false;
		}
		else
		{ 
			nowx--;
			return true;
		}
	}
	//??????????? ??????
template <typename variabletype>
bool Field2D<variabletype>::move_right()
	{
		if(nowx == x)
		{
			return false;
		}
		else if (nowx > x)
		{
			nowx = x;
			return false;
		}
		else
		{ 
			nowx++;
			return true;
		}
	}
	//???????? ?????-?????
template <typename variabletype>
bool Field2D<variabletype>::move_upl()
	{
		if (nowy == 0 || nowx == 0 || nowy < 0 || nowx < 0)
		{
			if (nowy < 0)
			{
				nowy = 0;
			}
			if (nowx < 0)
			{
				nowx = 0;
			}
			return false;
		}
		else
		{ 
			nowy--;
			nowx--;
			return true;
		}
	}
	//???????? ?????-??????
template <typename variabletype>
bool Field2D<variabletype>::move_upr()
	{
		if(nowy == 0 || nowx == x || nowy < 0 || nowx > x)
		{
			if (nowy < 0)
			{
				nowy = 0;
			}
			if (nowx > x)
			{
				nowx = x;
			}
			return false;
		}
		else
		{ 
			nowy--;
			nowx++;
			return true;
		}
	}
	//???????? ????-?????
template <typename variabletype>
bool Field2D<variabletype>::move_downl()
	{
		if (nowy == y || nowx == 0 || nowy > y || nowx < 0)
		{
			if (nowy > y)
			{
				nowy = y;
			}
			if (nowx < 0)
			{
				nowx = 0;
			}
			return false;
		}
		else
		{ 
			nowy++;
			nowx--;
			return true;
		}
	}
	//???????? ????-??????
template <typename variabletype>
bool Field2D<variabletype>::move_downr()
	{
		if(nowy == y || nowx == x || nowy > y || nowx > x)
		{
			if (nowy > y)
			{
				nowy = y;
			}
			if (nowx > x)
			{
				nowx = x;
			}
			return false;
		}
		else
		{ 
			nowy++;
			nowx++;
			return true;
		}
	}

template <typename variabletype>
bool Field2D<variabletype>::moveToPnt(short X, short Y)
{
	if (Y > y || X > x || Y < 0 || X < 0)
		{
			if (nowy < 0)
			{
				nowy = 0;
			}
			if (nowx < 0)
			{
				nowx = 0;
			}
			if (nowy > y)
			{
				nowy = y;
			}
			if (nowx > x)
			{
				nowx = x;
			}
			return false;
		}
		else
		{ 
			nowy = Y;
			nowx = X;
			return true;
		}
	}	
	//////////////////////////////////////////////////////////////
	//????-????? ?????????
template <typename variabletype>
void Field2D<variabletype>::get_coordinate()
	{
		absciss=nowx-zerox;
		ordinate=zeroy-nowy;
		cout<<"Coordinate of point is ("<<absciss<<", "<<ordinate<<")"<<endl;
	}
template <typename variabletype>
bool Field2D<variabletype>::moveToCoordinate(short coordX, short coordY)
	{
		short a = coordX + zerox;
		short b = zeroy - coordY;
		if(a < 0 || a > x || b < 0 || b > y)
		{
			if (b < 0)
			{
				nowy = 0;
			}
			if (a < 0)
			{
				nowx = 0;
			}
			if (b > y)
			{
				nowy = y;
			}
			if (a > x)
			{
				nowx = x;
			}
			return false;
		}
		else
		{
			nowx = a;
			nowy = b;
			absciss = coordX;
			ordinate = coordY;
			return true;
		}
	}
template <typename variabletype>
void Field2D<variabletype>::get_nowPos()
	{
		cout<<"Now x ="<<nowx<<". Now y ="<<nowy<<"."<<endl;
	}
template <typename variabletype>
unsigned short Field2D<variabletype>::get_nowx()
	{
		return nowx;
	}
template <typename variabletype>
unsigned short Field2D<variabletype>::get_nowy()
	{
		return nowy;
	}
