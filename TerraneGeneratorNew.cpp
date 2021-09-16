#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "newTerrane.h"

using namespace std;

int main()
{
	cout << "Created by Alexandr Pluzhinskyi" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	setlocale(LC_ALL, "Russian");

	string answer = "nocommand";
	newTerrane* terr = new newTerrane();
	newTerrane& terr1 = *terr;
	cout << 64/10 << endl;
	bool biomes = false;

	cout << "Please, set language" << endl;
	cout << "1 - russian" << endl;
	cout << "2 - english" << endl;

	int language = 0;

	while (language != 1 && language != 2)
	{
		cin >> language;
		if (language != 1 && language != 2)
		{
			cout << "command not correct, try again" << endl;
		}
	}

	if (language == 1)
	{
		//cout << "load - ��� �������� ��������� ����" << endl;
		cout << "new - ��� �������� ����� �����" << endl;
		//cout << "save - ��� ���������� ������� �����" << endl;
		cout << "again - ��� ������������ ����� � �������� �����������" << endl;
		//cout << "test - ���� �� ���� ��� ������� 20 ���� ������" << endl;
		cout << "print - ��� ��������� ����� � ��������� �����������" << endl;
		cout << "exit - ��� ������ �� ���������" << endl;
	}
	else
	{
		//cout << "load - for loading saved map" << endl;
		cout << "new - for create new map" << endl;
		//cout << "save - for saving this map" << endl;
		cout << "again - for recreating map" << endl;
		//cout << "test - for bugtest on 20 maps" << endl;
		cout << "print - for printing map in window" << endl;
		cout << "exit - for exiting program" << endl;
	}


	int i = 0;
	while (answer != "exit")
	{
		cin >> answer;
		if (answer == "new")
		{
			if (language == 1)
			{
				cout << "������� ��� ����" << endl;
			}
			else
			{
				cout << "Set name of map" << endl;
			}
			wstring nameof;
			wcin >> nameof;
			cout << endl;
			if (language == 1)
			{
				cout << "������� ������ ������� ���� (�� ����� 1024)" << endl;
			}
			else
			{
				cout << "Set map side size" << endl;
			}
			int sidesize = 542;
			cin >> sidesize;
			while (sidesize > 1024 || sidesize < 1)
			{
				if (language == 1)
				{
					cout << "������ ������� �����������, ��������� ���� �����" << endl;
				}
				else
				{
					cout << "Size of side not correct, please try again" << endl;
				}
				cin >> sidesize;
				cout << endl;
			}
			/*if (language == 1)
			{
				cout << "������� ������� ��������� ���� �� �����" << endl;
			}
			else
			{
				cout << "Set percent of water" << endl;
			}
			short mn = 0;
			cin >> mn;
			
			terr1.set_percentOfWater(mn);
			/*/
			terr1.reSetTerrane(sidesize, nameof);
			terr1.clear();
			terr1.construct();
			terr1.printScope(false, biomes);
			i++;
		}
		/*else if (answer == "test")
		{
			if (language == 1)
			{
				cout << "������� ��� ����" << endl;
			}
			else
			{
				cout << "Set name of map" << endl;
			}
			wstring nameof;
			wcin >> nameof;
			cout << endl;
			if (language == 1)
			{
				cout << "������� ������ ������� ���� (�� ����� 1024)" << endl;
			}
			else
			{
				cout << "Set map side size" << endl;
			}
			int sidesize = 542;
			cin >> sidesize;
			while (sidesize > 1024 || sidesize < 1)
			{
				if (language == 1)
				{
					cout << "������ ������� �����������, ��������� ���� �����" << endl;
				}
				else
				{
					cout << "Size of side not correct, please try again" << endl;
				}
				cin >> sidesize;
				cout << endl;
			}
			if (language == 1)
			{
				cout << "������� ������� ��������� ���� �� �����" << endl;
			}
			else
			{
				cout << "Set percent of water" << endl;
			}
			short mn = 0;
			cin >> mn;
			terr1.set_percentOfWater(mn);
			for (int i = 0; i < 21; i++)
			{
				terr1.reSetTerrane(sidesize, nameof);
				terr1.clear();
				terr1.construct();
				terr1.printScope(false, biomes);
			}
			i++;
		}
		else if (answer == "load")
		{
			if (terr1.loadTerrane() == true)
			{
				wcout << terr1.getName() << endl;
				terr1.printScope(false, biomes);
				i++;
			}
		}
		else if (answer == "save")
		{
			if (i < 1) 
			{ 
				if (language == 1)
				{
					cout << "��� ���� ��� ����������" << endl;
				}
				else
				{
					cout << "Not find map for saving" << endl;
				}
			}
			else
			{
				terr1.saveTerrane();
			}
		}*/
		else if (answer == "again")
		{
			if (i < 1) 
			{ 
				if (language == 1)
				{
					cout << "��� ���� ��� ������������" << endl;
				}
				else
				{
					cout << "Not find map for recreating" << endl;
				}
			}
			else
			{
				/*if (language == 1)
				{
					cout << "������� ������� ��������� ���� �� �����" << endl;
				}
				else
				{
					cout << "Set percent of water" << endl;
				}
				short mn = 0;
				cin >> mn;
				if (language == 1)
				{
					cout << "������� ���������� �����������" << endl;
				}
				else
				{
					cout << "Set how many continents on map" << endl;
				}
				short mc = 0;
				cin >> mc;
				terr1.set_percentOfWater(mn);
				terr1.set_numberOfContinents(mc);*/
				terr1.clear();
				terr1.construct();
				terr1.printScope(false, biomes);
			}
		}
		else if (answer == "print")
		{
			if (i < 1) 
			{ 
				if (language == 1)
				{
					cout << "��� ���� ��� �����������" << endl;
				}
				else
				{
					cout << "Cand find map for printing" << endl;
				}
			}
			else
			{
				if (language == 1)
				{
					cout << "���������� ����� ������?(y/n)" << endl;
				}
				else
				{
					cout << "View biome map?(y/n)" << endl;
				}
				cin >> answer;
				if (answer == "y")
				{
					biomes = true;
					if (language == 1)
					{
						cout << "����� ����� ����������" << endl;
					}
					else
					{
						cout << "Biome map will be viewed" << endl;
					}
				}
				else
				{
					if (language == 1)
					{
						cout << "����� �� ����� ����������" << endl;
					}
					else
					{
						cout << "Biome map not wil be viewed" << endl;
					}
				}
				terr1.printScope(false, biomes);

				bool biomes = false;
			}
		}
		else if (answer == "exit")
		{
			if (language == 1)
			{
				cout << "������ �� ���������" << endl;
			}
			else
			{
				cout << "Exiting program" << endl;
			}
			terr1.~newTerrane();
		}
		else
		{
			if (language == 1)
			{
				cout << "������� ���������" << endl;
			}
			else
			{
				cout << "Command uncorrect" << endl;
			}
		}
		
	}
	return 0;
}