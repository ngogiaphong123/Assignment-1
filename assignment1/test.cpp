#include<iostream>
#include<string>
using namespace std;
class Student{
    private:
        string name;
        char gender;
    public:
        Student()
        {
            name="Unknown";
            gender='u';
        }
        Student(string name)
        {
            this->name = name;
        }
        Student(char gender)
        {
            this->gender = gender;
        }
        Student(string name, char gender)
        {
            this->name = name;
            this->gender=gender;
        }
        void display()
        {
            if(this->gender=='m') 
            {
                cout << "Name: "<<this->name;
                cout <<"Gender: Male";
            }
            if(this->gender=='f')
            {
                cout << "Name: "<<this->name;
                cout <<"Gender: Female";
            }
            if(this->gender=='u')
            {
                cout << "Name: "<<this->name;
                cout <<"Gender: Unknown";
            }
        }
};