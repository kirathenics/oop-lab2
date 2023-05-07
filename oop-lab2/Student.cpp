#include "Student.h"

Student::Student()
{
    cout << "Вызвался конструктор без параметров для объекта с адресом " << this << endl;
    name = nullptr;
    course = gender = NULL;
}

Student::Student(char* name, int age, bool gender)
{
    cout << "Вызвался конструктор с параметрами для объекта с адресом " << this << endl;
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
    this->course = age;
    this->gender = gender;
}

Student::Student(const Student& object)
{
    cout << "Вызвался конструктор копирования для объекта с адресом " << this << endl;
    if (object.name)
    {
        this->name = new char[strlen(object.name) + 1];
        strcpy_s(this->name, strlen(object.name) + 1, object.name);
    }
    else
    {
        this->name = nullptr;
    }
    this->course = object.course;
    this->gender = object.gender;
}

Student::~Student()
{
    cout << "Вызвался деструктор для объекта с адресом " << this << endl;
    delete[] name;
}

void Student::set_name(char* name)
{
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
}

char* Student::get_name()
{
    return name;
}

void Student::print_name()
{
    cout << "Имя: " << name << endl;
}

void Student::set_course(int age)
{
    this->course = age;
}

int Student::get_course()
{
    return course;
}

void Student::print_course()
{
    cout << "Курс: " << course << endl;
}

void Student::set_gender(bool gender)
{
    this->gender = gender;
}

bool Student::get_gender()
{
    return gender;
}

void Student::print_gender()
{
    cout << "Пол: " << gender << endl;
}

void Student::set_all(char* name, int age, bool gender)
{
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
    this->course = age;
    this->gender = gender;
}

void Student::print_all()
{
    cout << "Имя: " << name << " Возраст - " << course << " Пол - " << gender << endl;
}