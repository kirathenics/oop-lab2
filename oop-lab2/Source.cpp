#include "Student.h"

void show_student(Student object);  // �������� ������� � ��������� ������� ������ �� ��������
Student create_temp_object(Student& object);   // �������� ������� ��� �������� ���������� �������

int main()
{
    system("chcp 1251");

    char name1[] = "�������� ����", name2[] = "�������� ����������", name3[] = "������ ���������";

    cout << "�������� ������� ��� ����������" << endl;
    Student object_without_params;     // �������� ������� ��� ����������
    object_without_params.set_name(name1);     // ������������� ������� ������������ � ������ �����
    object_without_params.set_course(2);
    object_without_params.set_gender(1);
    object_without_params.print_name();
    object_without_params.print_course();
    object_without_params.print_gender();

    cout << endl << "�������� ������� � �����������" << endl;
    Student object_with_params(name2, 3, 0);   // �������� ������� � �����������
    object_with_params.print_all();

    cout << endl << "������������� ������� ��� ������������� ������� �������" << endl;
    Student obj_copied = object_with_params;   // ������������� ������� ��� ������������� ������� �������
    obj_copied.print_all();

    cout << endl << "������ ���������� � ������� �� ��������" << endl;
    show_student(object_with_params);  // ������ ���������� � ������� �� ��������

    cout << endl << "������������� ���������� ���������� ������� ��� ������������� �������" << endl;
    Student temp_copied = create_temp_object(object_without_params);   // ������������� ���������� ���������� ������� ��� ������������� �������
    temp_copied.print_all();

    cout << endl << "���������� ������� � ����������� ������" << endl;
    Student static_arr[3] = {    // ���������� ������� � ����������� ������
        Student(name1, 2, 1),
        Student(name2, 3, 0),
        Student(name3, 1, 1)
    };
    for (int i = 0; i < 3; i++)
    {
        static_arr[i].print_all();
    }

    cout << endl << "���������� ������� � ������������ ������" << endl;
    Student* dynamic_arr = new Student[3] {  // ���������� ������� � ������������ ������
        Student(name1, 2, 1),
        Student(name2, 3, 0),
        Student(name3, 1, 1)
    };   

    for (int i = 0; i < 3; i++)
    {
        dynamic_arr[i].print_all();
    }
    delete[] dynamic_arr;

    cout << endl << "����������� � ������������� ��������� �� ������ ������" << endl;
    Student* object_ptr = &static_arr[2];  // ����������� ��������� �� ������ ������
    object_ptr->print_all();   // ������������� ��������� �� ������ ������

    cout << endl << "����������� � ������������� ��������� �� ����������-������� ������" << endl;
    void (Student:: * function_ptr)();  // ����������� ��������� �� ������ ������
    function_ptr = &Student::print_all;
    (static_arr[0].*function_ptr)();    // ������������� ��������� �� ������ ������

    return 0;
}

void show_student(Student object)
{
    cout << "������� ������ ������� �� ��������" << endl;
    object.print_all();
}

Student create_temp_object(Student& object)
{
    Student temp_object(object);
    char undef_name[] = "�� ����������";
    temp_object.set_name(undef_name);
    return temp_object;
}