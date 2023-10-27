#include "Cola.h"

bool Cola::vacia()const{
    return (ult == -1);
}
bool Cola::llena()const{
    if(ult == TAM-1){
        return true;
    }
    else
        return false;
}

int Cola::ultimo()const{
    return ult;
}

std::ostream& operator<<(std::ostream & o, Cola& L)
{
    std::cout<<"\n";

    int i = 0, ult = L.ultimo();
    while(i <= ult){
        o<< L.constancias[i];
        i++;
    }

    return o;
}

void Cola::enqueue(Constancia& elem){
    if(llena())
        std::cout<< "La cola esta llena\n";
    else
        inserta(elem,0);
}

Constancia& Cola::dequeue(Constancia& c){
    if(vacia()){
        std::cout<< "La cola esta vacia\n";
        return c;
    }
    else{
        ult--;
        return constancias[ult+1];
    }
}

bool Cola::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        std::cout<<"\n error de eliminacion";
        return false;
    }

    int i = pos;
    while(i < ult)
    {
        constancias[i] = constancias[i+1];
        i++;
    }
    ult--;
    return true;
}
int Cola::inserta(Constancia& elem, int pos)
{
    if(llena()|| pos<0 || pos> ult+1){
        std::cout<<"\n Error de insercion";
        return 0;
    }

    int i = ult+1;
    while(i > pos)
    {
        constancias[i] = constancias[i-1];
        i--;
    }
    constancias[pos]=elem;
    ult++;
    return 1;
}

int Cola::busquedaLineal(Constancia& elem){
    if(vacia())
        return -1;

    for(int i = 0; i <= ult; i++){
        if(elem == constancias[i])
            return i;
    }

    return -1;
}

int Cola::busquedaBinaria(Constancia& elem){
    if(vacia())
        return -1;

    int izquierda = 0;
    int derecha = TAM - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (constancias[medio] == elem) {
            return medio;
        }

        if (constancias[medio] < elem) {
            izquierda = medio + 1;
        }

        else {
            derecha = medio - 1;
        }
    }

    return -1;
}
