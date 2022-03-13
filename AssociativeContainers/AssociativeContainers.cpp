// AssociativeContainers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include<map>
#include<list>


using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
//#define STL_SET
//#define STL_MAP


class GAI
{
	std::map<std::string, std::list<std::string>> Base;
public:
	GAI() :Base(Base){}
	GAI(const std::initializer_list<std::map<std::string, std::list<std::string>>>& il):GAI()
	{
		for (std::map<std::string, std::list<std::string>>::iterator it = Base.begin(); it != Base.end(); ++it)
		{
			for (std::list<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
			{
				
			}
		}
	}
	
	~GAI()
	{

	};

	

	void print_full_base()
	{
		for (std::map<std::string, std::list<std::string>>::iterator it = Base.begin(); it != Base.end(); ++it)
		{
			cout << it->first + " : ";
			for (std::list<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
			{
				cout << *jt << ", ";
			}
		}
	}

	void print_for_number(std::string number)
	{
		for (std::map<std::string, std::list<std::string>>::iterator it = Base.begin(); it != Base.end(); ++it)
		{
			
			for (std::list<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
			{
				if (it->first == number)
				{
					cout << *jt;
				}
			}
		}
	}

	void get_add(std::string key, std::list<std::string> value)
	{
		Base.insert(make_pair(key, value));
	}

};




int main()
{
	setlocale(LC_ALL, "");

#ifdef STL_SET
	std::set<int> my_set = { 50, 25, 75,16,32,64,80 };
	/*for (size_t i = 0; i < my_set.size(); i++)
	{
		cout << my_set[i]<<tab;
	}
	cout << endl;*/
	for (std::set<int>::iterator it = my_set.begin(); it != my_set.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	int value; cin >> value;
	cout << endl;
	my_set.insert(value);
	for (int i : my_set)
	{
		cout << i << tab;
	}
	cout << endl;
	my_set.erase(value);
	for (int i : my_set)
	{
		cout << i << tab;
	}
	cout << endl;
	for (std::set<int>::iterator it = my_set.lower_bound(25); it != my_set.upper_bound(75); ++it)
	{
		cout << *it << tab;
	}
#endif // STL_SET


#ifdef STL_MAP
	std::map<int, std::string> week =
	{
		std::pair<int, std::string>(0, "Sunday"),
		std::pair<int, std::string>(1, "Monday"),
		std::pair<int, std::string>(2, "Thuesday"),
		std::pair<int, std::string>(3, "Wendsday"),
		{4, "Thurrsday" },
		{5, "Friday" },
		{6, "Saturday" },
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}


#endif // STL_MAP

	//std::map<std::string, std::list<std::string>> dictionary
	//{
	//	std::pair<std::string, std::list<std::string>>
	//	("splice",{"сваривание","сращивание"}),
	//	{"recconaiisance",{"разведка","зондирование"}},
	//	{"space",{"космос","пространство","пробел"}},
	//	{"pencil",{"карандаш"}},
	//	{"desk",{"рабочий стол","доска"}},
	//	{"prohibit",{"запрещать",}},
	//	{"appreciate",{"быть признательным","ценить"}},
	//};

	//for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	//{
	//	cout.width(20);
	//	cout << std::left;
	//	cout << it->first + ":";
	//	for (std::list<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
	//	{
	//		cout << *jt << ", ";
	//	}
	//	cout << endl;
	//}

	//cout << "\n---------------------------------------------------------\n";
	//for (std::pair<std::string, std::list<std::string>>i:dictionary)
	//{
	//	cout.width(20);
	//	cout << std::left;
	//	cout << i.first + ":";
	//	for (std::string j : i.second)cout << j << ", ";
	//	cout << endl;
	//}

	GAI Base;

	Base.get_add("в303ур", { "выезд на встречку" });
	Base.get_add("в555ур", { "превышение" });
	Base.print_full_base();
	cout << "\n---------------------------------------------------------\n";
	Base.print_for_number("в303ур");





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
