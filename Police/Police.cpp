// Police.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <list>
#include <string>
#include <Windows.h>
#include "Crime.h"

using std::cin;
using std::cout;
using std::endl;



#define tab "\t"

void print(const std::map<std::string, std::list<Crime>>& base);

int main()
{
    /*setlocale(LC_ALL, "");*/
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::map<std::string, std::list<Crime>> base =
    {
        {"a777km", {Crime(1,"улица Ћенина"), Crime(2,"”лица ‘рунзе")}},
        {"a557аb", {Crime(5,"”лица космонавтов")}},
        {"a001a", {Crime(4,"ѕерекресток Ћенина и ќкт€брьской"), Crime(3,"ул ќкт€брьска€")}}
    };
    print(base);

   // std::string licence_plate;
   // int id;
   // std::string place;
   // cin >> licence_plate;
   // cin >> id;
   // cin.clear();
   // cin.ignore();
   // std::getline(cin, place);
   ///* base[licence_plate].push_back(Crime(id, place));*/
   // std::map<std::string, std::list<Crime>>::iterator it = base.find(licence_plate);
   // if (it != base.end())
   // {
   //     it->second.push_back(Crime(id, place));
   // }
   // else
   // {
   //     base.insert(std::pair< std::string, std::list<Crime>>(licence_plate, { Crime(id, place) }));
   // }
   /* print(base);*/

    std::ofstream fout("myfile.txt");
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
    system("start notepad myfile.txt");
   
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
