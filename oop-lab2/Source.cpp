#include "Student.h"

void show_student(Student object);  // прототип функции с передачей объекта класса по значению
Student create_temp_object(Student& object);   // прототип функции для создания временного объекта

int main()
{
    system("chcp 1251");

    char name1[] = "Морозова Анна", name2[] = "Толкачев Константин", name3[] = "Орлова Елизавета";

    cout << "Создание объекта без параметров" << endl;
    Student object_without_params;     // создание объекта без параметров
    object_without_params.set_name(name1);     // использование методов установления и вывода полей
    object_without_params.set_course(2);
    object_without_params.set_gender(1);
    object_without_params.print_name();
    object_without_params.print_course();
    object_without_params.print_gender();

    cout << endl << "Создание объекта с параметрами" << endl;
    Student object_with_params(name2, 3, 0);   // создание объекта с параметрами
    object_with_params.print_all();

    cout << endl << "Использование объекта для инициализации другого объекта" << endl;
    Student obj_copied = object_with_params;   // использование объекта для инициализации другого объекта
    obj_copied.print_all();

    cout << endl << "Объект передается в функцию по значению" << endl;
    show_student(object_with_params);  // объект передается в функцию по значению

    cout << endl << "Использование построения временного объекта как возвращаемого объекта" << endl;
    Student temp_copied = create_temp_object(object_without_params);   // использование построения временного объекта как возвращаемого объекта
    temp_copied.print_all();

    cout << endl << "Размещение объекта в статической памяти" << endl;
    Student static_arr[3] = {    // размещение объекта в статической памяти
        Student(name1, 2, 1),
        Student(name2, 3, 0),
        Student(name3, 1, 1)
    };
    for (int i = 0; i < 3; i++)
    {
        static_arr[i].print_all();
    }

    cout << endl << "Размещение объекта в динамической памяти" << endl;
    Student* dynamic_arr = new Student[3] {  // размещение объекта в динамической памяти
        Student(name1, 2, 1),
        Student(name2, 3, 0),
        Student(name3, 1, 1)
    };   

    for (int i = 0; i < 3; i++)
    {
        dynamic_arr[i].print_all();
    }
    delete[] dynamic_arr;

    cout << endl << "Определение и использование указателя на объект класса" << endl;
    Student* object_ptr = &static_arr[2];  // определение указателя на объект класса
    object_ptr->print_all();   // использование указателя на объект класса

    cout << endl << "Определение и использование указателя на компоненту-функцию класса" << endl;
    void (Student:: * function_ptr)();  // определение указателя на объект класса
    function_ptr = &Student::print_all;
    (static_arr[0].*function_ptr)();    // использование указателя на объект класса

    return 0;
}

void show_student(Student object)
{
    cout << "Передан объект функции по значению" << endl;
    object.print_all();
}

Student create_temp_object(Student& object)
{
    Student temp_object(object);
    char undef_name[] = "Не определено";
    temp_object.set_name(undef_name);
    return temp_object;
}