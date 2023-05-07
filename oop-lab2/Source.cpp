#include "Student.h"

void ViewPerson(Student object);  // прототип функции с передачей объекта класса по значению
Student CreateTempObject(Student& object);   // прототип функции для создания временного объекта

int main()
{
    system("chcp 1251");
    //setlocale(0, "");

    char name1[] = "Родион Раскольников", name2[] = "Дин И", name3[] = "Мартин Иден";

    cout << "Создание объекта без параметров" << endl;
    Student withoutParams;   // создание объекта без параметров
    withoutParams.set_name(name1);     // использование методов установления и вывода полей
    withoutParams.set_course(23);
    withoutParams.set_gender(1);
    withoutParams.print_name();
    withoutParams.print_course();
    withoutParams.print_gender();

    cout << "\nСоздание объекта с параметрами" << endl;
    Student withParams(name2, 34, 0);  // создание объекта с параметрами
    withParams.print_all();

    cout << "\nИспользование объекта для инициализации другого объекта" << endl;
    Student copyWithParams = withParams; // использование объекта для инициализации другого объекта
    copyWithParams.print_all();

    cout << "\nОбъект передается в функцию по значению" << endl;
    ViewPerson(withParams);     // объект передается в функцию по значению

    cout << "\nИспользование построения временного объекта как возвращаемого объекта" << endl;
    Student copyTemp = CreateTempObject(withoutParams);    // использование построения временного объекта как возвращаемого объекта
    copyTemp.print_all();

    cout << "\nРазмещение объекта в статической памяти" << endl;
    Student staticPersons[3] =  // размещение объекта в статической памяти
    {
        Person(name1, 23, 1),
        Person(name2, 34, 0),
        Person(name3, 21, 1)
    };
    for (int i = 0; i < 3; i++)
    {
        staticPersons[i].print_all();
    }

    cout << "\nРазмещение объекта в динамической памяти" << endl;
    Student* dynamicPersons = new Student[3]{ Person(name1, 23, 1), Person(name2, 34, 0), Person(name3, 21, 1) };   // размещение объекта в динамической памяти

    for (int i = 0; i < 3; i++)
    {
        dynamicPersons[i].print_all();
    }
    delete[] dynamicPersons;

    cout << "\nОпределение и использование указателя на объект класса" << endl;
    Student* ptrStaticPersons = &staticPersons[2];   // определение указателя на объект класса
    ptrStaticPersons->print_all();   // использование указателя на объект класса

    cout << "\nОпределение и использование указателя на компоненту-функцию класса" << endl;
    void (Student:: * ptr)();    // определение указателя на объект класса
    ptr = &Student::print_all;
    (staticPersons[0].*ptr)();  // использование указателя на объект класса

    return 0;
}

void ViewPerson(Student object)
{
    cout << "Переданный объект функции по значению" << endl;
    object.print_all();
}

Student CreateTempObject(Student& object)
{
    Student tempObject(object);
    char nonDefined[] = "Не определено";
    tempObject.set_name(nonDefined);
    return tempObject;
}