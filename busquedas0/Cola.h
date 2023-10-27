#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "constancia.h"

const int TAM = 20;

class Cola
{
private:
    Constancia constancias[TAM];
    int ult;
    bool elimina(int pos);
    int inserta(Constancia& elem, int pos);
public:
    Cola():ult(-1) {}
    bool vacia()const;
    bool llena()const;
    int ultimo()const;
    friend std::ostream& operator<<(std::ostream & o, Cola& c);
    void enqueue(Constancia& elem);
    Constancia& dequeue(Constancia&);

    int busquedaLineal(Constancia&);
    int busquedaBinaria(Constancia&);

};

#endif // COLA_H_INCLUDED
