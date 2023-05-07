#pragma once

#include <iostream>
using namespace std;

class Student
{
public:
    Student();  // конструктор без параметров
    Student(char*, int, bool);  // конструктор с параметрами
    Student(const Student&);     // конструктор копирования
    ~Student(); //деструктор

    void set_name(char*);   // метод: установить имя студента
    char* get_name();   // метод: получить имя студента
    void print_name();  // метод: вывести имя студента

    void set_course(int);   // метод: установить курс студента
    int get_course();       // метод: получить курс студента
    void print_course();    // метод: вывести курс студента

    void set_gender(bool);  // метод: установить пол студента
    bool get_gender();      // метод: получить пол студента
    void print_gender();    // метод: вывести пол студента

    void set_all(char*, int, bool);  // метод: установить имя, курс, пол студента
    void print_all();    // метод: вывести имя, курс, пол студента

private:
    char* name;     // имя
    int course;     // курс
    bool gender;    // пол
};
