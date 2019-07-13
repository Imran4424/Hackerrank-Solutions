#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

class Student
{
    int age, standard;
    string firstName, lastName;

    public: void set_age(int age)
    {
        this -> age = age;
    }

    public: void set_standard(int standard)
    {
        this -> standard = standard;
    }

    public: void set_first_name(string firstName)
    {
        this -> firstName = firstName;
    }

    public: void set_last_name(string lastName)
    {
        this -> lastName = lastName;
    }

    public: int get_age()
    {
        return age;
    }

    public: int get_standard()
    {
        return standard;
    }

    public: string get_first_name()
    {
        return firstName;
    }

    public: string get_last_name()
    {
        return lastName;
    }

    public: string to_string()
    {
        stringstream ss;

        ss << age;

        string s = ss.str();

        stringstream dd;

    
        dd << standard;

        s = s + ',' + firstName + ',' + lastName + ',' + dd.str();

        return s;
    }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}

