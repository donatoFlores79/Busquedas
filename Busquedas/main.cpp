#include <iostream>
#include "cola.h"

using namespace std;

template<class T>
T Cola<T>::Front()const{
    T x=datos[primero()];
    return x;
}

template<class T>
bool Cola<T>::Dequeue(){
    if(vacia()){
        return false;
    }
    else{
        elimina(primero());
    }
    return true;
}

template<class T>
bool Cola<T>::Queue(T& elem){
    if(llena()){
        return false;
    }
    if(vacia()){
        inserta(elem,0);
    }
    else{
        inserta(elem, ultimo()+1);
    }
    return true;
}

template<class T>
void Cola<T>::imprime()const{
    if(!vacia()){
        for(int i=0; i<=ult; i++){
            Constancia x=datos[i];
            cout<<x<<endl;
        }
    }
}

template<class T>
bool Cola<T>::vacia()const{
    return ult==-1;
}

template<class T>
bool Cola<T>::llena()const{
    return ult==TAM-1;
}

template<class T>
bool Cola<T>::inserta(T elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        cout<<"\n No se pudo insertar";
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

template<class T>
bool Cola<T>::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

template<class T>
T Cola<T>::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

template<class T>
int Cola<T>::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}

template<class T>
int Cola<T>::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}

template<class T>
int Cola<T>::busqueda(Constancia s) const{
    if(vacia())
        return -1;
    for(int i=0; i<=ult; i++){
        if(s == datos[i])
            return i;
        else
            return -1;
    }
}

int main()
{
    int opc;
    Cola<Constancia> MiCola;
    Constancia x;
    do{
        cout<< "Que deseas realizar?\n";
        cout<< "1.Dar de alta solicitud de constancia de estudios\n";
        cout<< "2.Elaborar solicitud\n";
        cout<< "3.Buscar un Constancia\n";
        cout<< "4.Salir\n";

        cin>> opc;

        if (opc==1){
            cout<<"\n\n\n AColacion"<<endl;

            cin>>x;
            MiCola.Queue(x);

            cout<< "\n---Cola---\n";
            MiCola.imprime();
            cout<<"\n\n\n";
        }
        else if(opc==2){
            if(MiCola.vacia())
                cout<< "La cola esta vacia\n\n";
            else{
                x=MiCola.Front();
                cout<<"\n\n\n____UNIVERSIDAD DE GUADALAJARA____\n";
                cout<<"  Constancia de estudios del Constancia\n";
                cout<<"Nombre:" << x.getNombre();
                cout<<"\nCarrera:" << x.getCarrera();
                cout<<"\nMaterias aprobadas:" << x.getMateriasAprobadas();
                cout<<"\nPromedio:" << x.getPromedio();

                cout<<"\n\n DesaColado"<<endl;
                cout<<x<<endl;
                MiCola.Dequeue();

                cout<<"\n---Cola---\n";
                MiCola.imprime();
                cout<<"\n\n\n";
            }
        }
        else if(opc==3){
            Constancia s;
            int pos;
            cout<< "\n\n\nIngresa los datos de la constancia a buscar:\n";
            cin>> s;

            pos = MiCola.busqueda(s);

            if(pos == -1)
                cout<< "\nEl alumno no ha solicitado una constancia o la cola esta vacia\n\n\n\n";
            else
                cout<< "\nSe tiene(n) que elaborar " << pos << " constancia(s) para que se entregue su constancia\n\n\n\n";
        }
        else if(opc!=4)
            cout<< "Por favor ingresa un numero del 1 al 3\n";
    }while(opc!=4);
    return 0;
}
