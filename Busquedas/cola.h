#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "constancia.h"
#define TAM 50

template<class T>
class Cola{
private:
    T datos[TAM];
    int ult;
    bool inserta(T , int);
    bool elimina(int);
    T recupera(int)const;
    int primero()const;
    int ultimo()const;
public:
    Cola():ult(-1){}
    bool vacia()const;
    bool llena()const;
    bool  Queue(T&);
    bool Dequeue();
    T Front()const;
    void imprime()const;

    int busqueda(Constancia) const;
};

#endif // COLA_H_INCLUDED
