#pragma once

#include <iostream>
using namespace std;

class Student
{
public:
    Student();  // ����������� ��� ����������
    Student(char*, int, bool);  // ����������� � �����������
    Student(const Student&);     // ����������� �����������
    ~Student(); //����������

    void set_name(char*);   // �����: ���������� ��� ��������
    char* get_name();   // �����: �������� ��� ��������
    void print_name();  // �����: ������� ��� ��������

    void set_course(int);   // �����: ���������� ���� ��������
    int get_course();       // �����: �������� ���� ��������
    void print_course();    // �����: ������� ���� ��������

    void set_gender(bool);  // �����: ���������� ��� ��������
    bool get_gender();      // �����: �������� ��� ��������
    void print_gender();    // �����: ������� ��� ��������

    void set_all(char*, int, bool);  // �����: ���������� ���, ����, ��� ��������
    void print_all();    // �����: ������� ���, ����, ��� ��������

private:
    char* name;     // ���
    int course;     // ����
    bool gender;    // ���
};
