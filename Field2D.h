#ifndef FIELD2D_H
#define FIELD2D_H

template <typename variabletype>
class Field2D
{
	public:
	Field2D(short f);
	Field2D();
	~Field2D();
	void get_zeropnt();
	void set_zeropnt(short i, short n);
	bool set_elem(variabletype i);
	variabletype get_elem();
	bool move_up();
	bool move_down();
	bool move_left();
	bool move_right();
	bool move_upl();
	bool move_upr();
	bool move_downl();
	bool move_downr();
	bool moveToPnt(short X, short Y);
	void get_coordinate();
	bool moveToCoordinate(short coordX, short coordY);
	void get_nowPos();
	unsigned short get_nowx();
	unsigned short get_nowy();
	void remakeField(short terr);
	
	private:
	short x;
	short y;
	short zeroy;
	short zerox;
	short nowy;
	short nowx;
	short absciss;
	short ordinate;
	variabletype FIELD [1024][1024];
};

#endif
