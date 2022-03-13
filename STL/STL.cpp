// STL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
//#define STL_ARRAY
#define STL_VECTOR

int main()
{
    setlocale(LC_ALL, "");
#ifdef STL_ARRAY
    std::array<int,5> arr = {3,5,8,13,21};
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << tab;
    }
    cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
    std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i]<< tab;
    }
    cout << endl;
    cout << vec.size()<<endl;
    cout << vec.max_size()<<endl;
    cout << vec.capacity() << endl;
    vec.push_back(55);
    cout << vec.size() << endl;
    cout << vec.max_size() << endl;
    cout << vec.capacity() << endl;

#endif // STL_VECTOR

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
