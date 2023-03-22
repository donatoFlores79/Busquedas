#ifndef CONSTANCIA_H_INCLUDED
#define CONSTANCIA_H_INCLUDED

#include <iostream>

class Constancia{
private:
    std::string nombre, carrera;
    int materiasAprobadas;
    float promedio;
public:
    Constancia();

    std::string getNombre() const;
    std::string getCarrera() const;
    int getMateriasAprobadas() const;
    float getPromedio() const;

    friend std::ostream& operator << (std::ostream& O, Constancia& x);
    friend std::istream& operator >> (std::istream& O, Constancia& x);

    Constancia& operator = (const Constancia&);

    bool operator == (const Constancia&);
};

#endif // CONSTANCIA_H_INCLUDED
