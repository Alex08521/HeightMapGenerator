#ifndef NEWTERRANE_H
#define NEWTERRANE_H
#include "Field2D.h"
#include "twoPoints.h"
#include "MyRand.h"
#include "enumerations.h"
#include <iostream>
#ifdef _WIN64
#include "SFML/Graphics.hpp"
#elif _WIN32
#include "SFML/Graphics.hpp"
#endif

using namespace std;
using namespace sf;

class newTerrane
{
	public:
		newTerrane(short terr,wstring name);
		newTerrane();
		~newTerrane();
		void printScope(bool climates, bool biomes);
		wstring getName();
		void construct();
		void clear();
		void saveTerrane();
		bool loadTerrane();
		void reSetTerrane(short rterr, wstring rname);
		int getScopeLineSize();
		auto getScopeElem(short x, short y);
		auto getForestElem(short x, short y);
		auto getCivilizationElem(short x, short y);
		auto getClimat_zoneElem(short x, short y);
		auto getBiomeElem(short x, short y);
		auto getZone_nameElem(short x, short y);
		auto getResoursesElem(short x, short y);
		void history_years_set(short a);
		short set_percentOfWater(short a);
		void frameConstructor(short a);
		void set_numberOfContinents(int continents);
	protected:
		short numOfContinents;
		ContextSettings settings;
		RenderWindow window;
		MyRand d8;
		wstring name;
		short history_yeras;
		short terrSize;
		short mountains;
		short percentOfWater;
		Field2D <uint8_t> scope;
		Field2D <bool> forest;
		Field2D <uint8_t> resourses;
		Field2D <uint8_t> civilization;
		Field2D <uint8_t> climat_zone;
		Field2D <uint8_t> biome;
		Field2D <wstring> zone_name;
		bool constrLand(int X, int Y, int sizeOfContSideX, int sizeOfContSideY, scopeType scopeWidth);
		bool corrLand();
		bool artifactDeleter(int solid);
		bool logicCorr(short a);
		void spiralGen(short sizeofSide, int localX, int localY, scopeType scopeWidht);
		void spiralCorrection();
		void spiralLogicCorrection();
		void forest_generate();
		void showParam();
		bool ScopeScaner(short target, short numOfCykles, short ignore, short worktype);
		bool ClimateScaner(short target, short numOfCykles, short ignore, short worktype);
		bool BiomeScaner(short target, short numOfCykles, short ignore, short worktype);
		void mountainesGenerator();
		void zeroDelete(short a);
		short typeOfLandVariator(short target, short solid);
		short typeOfLandRelocator(short target, short solid);
		bool climateZoneConstructor();
		void biomeConstructor();
		bool riverConstructor(int numOfRivers);
		void contconstr();
		//void resourse_spawner();
};

#endif
