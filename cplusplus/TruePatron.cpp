/*
Todo este código que encuentras en esta serie de artículos está compilado usando C ++ 20 (aunque he usado
características de Modern C ++ hasta C ++ 17 en la mayoría de los casos)

sacado de https://dzone.com/articles/prototype-design-pattern-in-modern-c
*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<memory>
using namespace std;


/*
struct Office {

    string         m_street;

    string         m_city;

    int32_t         m_cubical;

    Office(string s, string c, int32_t n):m_street(s), m_city(c), m_cubical(n){}

};


struct Employee {

    string      m_name;

    Office        m_office;

    Employee(string n,  Office o):m_name(n), m_office(o){}


};

int main() {

    Employee john{ "John Doe", Office{"123 East Dr", "London", 123} };

    Employee jane{ "Jane Doe", Office{"123 East Dr", "London", 124} };

    Employee jack{ "jack Doe", Office{"123 ORR", "Bangaluru", 300} };

    return EXIT_SUCCESS;

}
*/
/*
struct  Empleado {


    string           m_name ;


    const  Office *    m_office ;


    Empleado ( cadena  n ,   Oficina  * o ): m_name ( n ), m_office ( o ) {}


};


 Oficina    estática LondonOffice { "123 East Dr" , "London" , 123 };


 Oficina    estática BangaluruOffice { "RMZ Ecoworld ORR" , "Londres" , 123 };



int  main () {


    Empleado  john { "John Doe" , & LondonOffice };


    Empleada  jane { "Jane Doe" , & LondonOffice };


    Empleado  jack { "jack Doe" , & BangaluruOffice };



    return  EXIT_SUCCESS ;


}
*/

struct Office {


    string      m_street;

    string      m_city;

    int32_t     m_cubical;

};


class Employee {

    string      m_name;
    Office*     m_office;


    // Private constructor, so direct instance can not be created except for `class EmployeeFactory`

          Employee(string n, Office *o) : m_name(n), m_office(o) {}

          friend class EmployeeFactory;

      public:

          Employee(const Employee &rhs) : m_name{rhs.m_name}, m_office{new Office{*rhs.m_office}}

          { }

          Employee& operator=(const Employee &rhs) {

              if (this == &rhs) return *this;

              m_name = rhs.m_name;

              m_office = new Office{*rhs.m_office};

              return *this;

          }


          friend ostream &operator<<(ostream &os, const Employee &o) {

              return os << o.m_name << " works at "

              << o.m_office->m_street << " " << o.m_office->m_city << " seats @" << o.m_office->m_cubical;

          }

};





class EmployeeFactory {

    static Employee     main;

    static Employee     aux;

    static unique_ptr<Employee> NewEmployee(string n, int32_t c, Employee &proto) {

        auto e = make_unique<Employee>(proto);

        e->m_name = n;

        e->m_office->m_cubical = c;

        return e;

    }


      public:

          static unique_ptr<Employee> NewMainOfficeEmployee(string name, int32_t cubical) {

              return NewEmployee(name, cubical, main);

          }

          static unique_ptr<Employee> NewAuxOfficeEmployee(string name, int32_t cubical) {

              return NewEmployee(name, cubical, aux);

          }

};



// Static Member Initialization

Employee EmployeeFactory::main{"", new Office{"123 East Dr", "London", 123}};

Employee EmployeeFactory::aux{"", new Office{"RMZ Ecoworld ORR", "London", 123}};


int main() {

    auto jane = EmployeeFactory::NewMainOfficeEmployee("Jane Doe", 125);

    auto jack = EmployeeFactory::NewAuxOfficeEmployee("jack Doe", 123);

    cout << *jane << endl << *jack << endl;

    return EXIT_SUCCESS;

}



/*

62

Jane Doe works at 123 East Dr London seats @125

63

jack Doe works at RMZ Ecoworld ORR London seats @123

64

*/
