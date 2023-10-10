// UsingTemplatesApp.cpp 

#include <iostream>
#include <vector>
#include "Person.h"
using namespace std;

void experiment01();
void experiment02();

void showVector(vector<int> v, string caption);
void showVector(vector<string> v, string caption);
void showVector(vector<Person> v, string caption);

template <class T> void showVector2(vector<T> v, string caption);
template <class T> void sortVector(vector<T>& v);

int main()
{
    //experiment01();
    experiment02();



}
//-----------------------------------------------------------------
void experiment02() {

    vector<int> v1{ 11, 33, 44, 22 };
    showVector2(v1, "This is v1");
    sortVector(v1);
    showVector2(v1, "This is v1");

    vector<string> v2{ "aaa", "ccc", "bbb", "ddd" };
    showVector2(v2, "This is v2");
    sortVector(v2);
    showVector2(v2, "This is v2");

    vector<Person> v3{ Person("Homer Simpson", "hs@aol.com"),
                        Person("Maggie Simpson", "bs@gmail.com"),
                        Person("Lisa Simpson", "ls@gmail.com") };
    showVector2(v3, "This is v3 (a list of Person objects");
    sortVector(v3);
    showVector2(v3, "This is v3 (a list of Person objects");


    try
    {
        Person p("Bart Simpson", "bsgmail.com");
        cout << "\n\np " << p.toString();
    }
    catch (const std::exception& ex)
    {
        cout << "Error - rejected! " << ex.what() << endl;
    }


    cout << "ALIVE - Experiment02 is over!\n";

}

template <class T>
void sortVector(vector<T>& v)
{
    for (int i = v.size() - 1; i >0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[j + 1] < v[j]) {
                T temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}


//---------------------------------------------
void experiment01() {

    vector<int> v1{ 11, 33, 44, 22 };
    showVector(v1, "This is v1");

    vector<string> v2{ "aaa", "ccc", "bbb", "ddd" };
    showVector(v2, "This is v2");

    vector<Person> v3{ Person("Homer Simpson", "hs@aol.com"),
                        Person("Bart Simpson", "bs@gmail.com"),
                        Person("Lisa Simpson", "ls@gmail.com") };
    showVector(v3, "This is v3 (a list of Person objects");

}

void showVector(vector<int> v, string caption) {
    cout << caption << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

void showVector(vector<string> v, string caption) {
    cout << caption << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

void showVector(vector<Person> v, string caption) {
    cout << caption << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

//----------------------------------------------------------------
template <class T> 
void showVector2(vector<T> v, string caption) 
{
    cout << caption << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;
}