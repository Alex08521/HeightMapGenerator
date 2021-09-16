#ifndef MYRAND_H
#define MYRAND_H

class MyRand
{
private:
	unsigned int bGlobRand;
	unsigned int cGlobRand;
	unsigned int dGlobRand;
	unsigned int eGlobRand;
	unsigned int iterGlobRand;
	unsigned int previousGlobRand;
	unsigned int previous2GlobRand;
	unsigned int previous3GlobRand;
	unsigned short checkerGlobRand;
public:
	MyRand();
	unsigned int randomize(unsigned int lRand);
};
#endif
