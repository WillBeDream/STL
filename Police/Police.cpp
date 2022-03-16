// Police.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <list>
#include <string>
#include <Windows.h>
#include "Crime.h"
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;



#define tab "\t"

void add(std::map<std::string, std::list<Crime>>& base);
void print(const std::map<std::string, std::list<Crime>>& base);
void print(const std::map<std::string, std::list<Crime>>& base, const std::string& first_plate, const std::string& last_plate);
void print(const std::map<std::string, std::list<Crime>>& base, const std::string& licence_plate);
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename);
void load(std::map<std::string, std::list<Crime>>& base, const std::string& filename);


int main()
{
	/*setlocale(LC_ALL, "");*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::map<std::string, std::list<Crime>> base/* =
	{
		{"a777km", {Crime(1,"улица Ленина"), Crime(2,"Улица Фрунзе")}},
		{"a557аb", {Crime(5,"Улица космонавтов")}},
		{"a001a", {Crime(4,"Перекресток Ленина и Октябрьской"), Crime(3,"ул Октябрьская")}}
	}*/;

	load(base, "base.txt");
	load(base, "base.txt");
	load(base, "base.txt");
	print(base);

	std::string licence_plate1;
	cin >> licence_plate1;
	std::string licence_plate2;
	cin >> licence_plate2;
	print(base, licence_plate1, licence_plate2);
	//save(base, "base.txt");
	/*add(base);*/
	/*print(base);*/



	/*std::ofstream fout("myfile.txt");
	for (std::map < std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		fout << it->first + ":\n";
		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			fout << "\t" << *jt << ";\n";
		}
		fout << "\n------------------------------------------------------------------------\n";
	}
	fout.close();
	system("start notepad myfile.txt");*/

}

void add(std::map<std::string, std::list<Crime>>& base)
{
	std::string licence_plate;
	int id;
	std::string place;
	cin >> licence_plate;
	cin >> id;
	cin.clear();
	cin.ignore();
	std::getline(cin, place);
	/* base[licence_plate].push_back(Crime(id, place));*/
	std::map<std::string, std::list<Crime>>::iterator it = base.find(licence_plate);
	if (it != base.end())
	{
		it->second.push_back(Crime(id, place));
	}
	else
	{
		base.insert(std::pair< std::string, std::list<Crime>>(licence_plate, { Crime(id, place) }));
	}
}

void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map < std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first + ":\n";
		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << "\t" << *jt << ";\n";
		}
		cout << "\n------------------------------------------------------------------------\n";
	}
}

void print(const std::map<std::string, std::list<Crime>>& base, const std::string& first_plate, const std::string& last_plate)
{
	try
	{
		
		for (std::map<std::string, std::list<Crime>>::const_iterator it = base.lower_bound(first_plate);
			it != base.upper_bound(last_plate); ++it)
		{
			cout << it->first + ":\n";
			for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
			{
				cout << *jt << endl;
			}
			cout << "\n------------------------------------------------------------------------\n";
		}
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what()<<endl;
	}
}

void print(const std::map<std::string, std::list<Crime>>& base, const std::string& licence_plate)
{
	try
	{
		cout << licence_plate << ":\n";
		for (std::list<Crime>::const_iterator it = base.at(licence_plate).begin();
			it != base.at(licence_plate).end();
			++it)
			cout << *it << endl;
	}
	catch (...)
	{
		std::cerr << "В базе нет такого номера" << endl;
	}
}

void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ofstream fout(filename);
	for (std::pair<std::string, std::list<Crime>> i : base)
	{
		fout << i.first << ":\t";
		for (Crime j : i.second)
		{
			fout << j << ", ";
		}
		fout.seekp(-2, std::ios::cur);
		fout << ";\n";
	}
	fout.close();
	std::string command = std::string("start notepad ") + filename;
	system(command.c_str());

}

void load(std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string licence_plate;
			int id;
			std::string place;
			std::string crimes;
			std::getline(fin, licence_plate, ':');
			std::getline(fin, crimes);
			if (crimes.empty())continue;

			char* sz_crimes = new char[crimes.size() + 1]{};
			std::strcpy(sz_crimes, crimes.c_str());
			char sz_delimeters[] = ",;";

			for (char* pch = strtok(sz_crimes, sz_delimeters); pch; pch = strtok(NULL, sz_delimeters))
			{
				while (*pch == ' ')pch++;
				id = std::atoi(pch);
				pch = std::strchr(pch, ' ')+1;
				if(
					std::find(base[licence_plate].begin(), base[licence_plate].end(), Crime(id, pch))
					==base[licence_plate].end()
					)
					base[licence_plate].push_back(Crime(id, pch));
			}

			delete[]sz_crimes;
				/*if (crimes.find(',') != std::string::npos)
				{
					for (int start = 0, end = crimes.find(','); end != std::string::npos; start = end)
					{
						end = crimes.find(',', start + 1);
						place = crimes.substr(start + 1, end);
						place.erase(0, place.find_first_not_of(' '));
						id = std::stoi(place.substr(0, place.find_first_of(' ')));
						place.erase(0, place.find_first_of(' ') + 1);
						base[licence_plate].push_back(Crime(id, place));
					}

				}
				else
				{
					id = std::stoi(crimes.substr(0, crimes.find_first_of(' ')));
					crimes.erase(0, crimes.find_first_of(' '));
					base[licence_plate].push_back(Crime(id, crimes));
				}*/
		}
	
		fin.close();
	}
	else
	{
		std::cerr << " Error file not found" << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
