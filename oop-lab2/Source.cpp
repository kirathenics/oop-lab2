#include "Student.h"

void ViewPerson(Student object);  // �������� ������� � ��������� ������� ������ �� ��������
Student CreateTempObject(Student& object);   // �������� ������� ��� �������� ���������� �������

int main()
{
    system("chcp 1251");
    //setlocale(0, "");

    char name1[] = "������ ������������", name2[] = "��� �", name3[] = "������ ����";

    cout << "�������� ������� ��� ����������" << endl;
    Student withoutParams;   // �������� ������� ��� ����������
    withoutParams.set_name(name1);     // ������������� ������� ������������ � ������ �����
    withoutParams.set_course(23);
    withoutParams.set_gender(1);
    withoutParams.print_name();
    withoutParams.print_course();
    withoutParams.print_gender();

    cout << "\n�������� ������� � �����������" << endl;
    Student withParams(name2, 34, 0);  // �������� ������� � �����������
    withParams.print_all();

    cout << "\n������������� ������� ��� ������������� ������� �������" << endl;
    Student copyWithParams = withParams; // ������������� ������� ��� ������������� ������� �������
    copyWithParams.print_all();

    cout << "\n������ ���������� � ������� �� ��������" << endl;
    ViewPerson(withParams);     // ������ ���������� � ������� �� ��������

    cout << "\n������������� ���������� ���������� ������� ��� ������������� �������" << endl;
    Student copyTemp = CreateTempObject(withoutParams);    // ������������� ���������� ���������� ������� ��� ������������� �������
    copyTemp.print_all();

    cout << "\n���������� ������� � ����������� ������" << endl;
    Student staticPersons[3] =  // ���������� ������� � ����������� ������
    {
        Person(name1, 23, 1),
        Person(name2, 34, 0),
        Person(name3, 21, 1)
    };
    for (int i = 0; i < 3; i++)
    {
        staticPersons[i].print_all();
    }

    cout << "\n���������� ������� � ������������ ������" << endl;
    Student* dynamicPersons = new Student[3]{ Person(name1, 23, 1), Person(name2, 34, 0), Person(name3, 21, 1) };   // ���������� ������� � ������������ ������

    for (int i = 0; i < 3; i++)
    {
        dynamicPersons[i].print_all();
    }
    delete[] dynamicPersons;

    cout << "\n����������� � ������������� ��������� �� ������ ������" << endl;
    Student* ptrStaticPersons = &staticPersons[2];   // ����������� ��������� �� ������ ������
    ptrStaticPersons->print_all();   // ������������� ��������� �� ������ ������

    cout << "\n����������� � ������������� ��������� �� ����������-������� ������" << endl;
    void (Student:: * ptr)();    // ����������� ��������� �� ������ ������
    ptr = &Student::print_all;
    (staticPersons[0].*ptr)();  // ������������� ��������� �� ������ ������

    return 0;
}

void ViewPerson(Student object)
{
    cout << "���������� ������ ������� �� ��������" << endl;
    object.print_all();
}

Student CreateTempObject(Student& object)
{
    Student tempObject(object);
    char nonDefined[] = "�� ����������";
    tempObject.set_name(nonDefined);
    return tempObject;
}