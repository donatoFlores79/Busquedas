#include "Cola.h"

using namespace std;

int main()
{
    Cola colaConstancias;
    Constancia x;
    Constancia c("--", "--", 0, 0.0);

    int opc = 0;
    while(opc != 4){

        cout<< "1.Dar de alta solicitud de constancia\n";
        cout<< "2.Elaborar constancia\n";
        cout<< "3.Buscar constancia\n";
        cout<< "4.Salir\n";
        cout<< " --->";
        cin>> opc;

        int resultadoBusqueda;
        switch(opc){
            case 1:
                if(colaConstancias.llena())
                    cout<< "\nLa cola esta llena\n";
                else{
                    cout<< "\n- Datos de la solicitud -\n";
                    cin>> x;
                    colaConstancias.enqueue(x);
                }
                break;
            case 2:
                if(colaConstancias.vacia())
                    cout<< "La cola esta vacia\n";
                else{
                    cout<< "\n";
                    cout<< colaConstancias.dequeue(c);
                }
                break;
            case 3:
                if(colaConstancias.vacia())
                    cout<< "La cola esta vacia\n";
                else{
                    cout<< "- Constancia a buscar -\n";
                    cin>> x;
                    resultadoBusqueda = colaConstancias.busquedaLineal(x);
                    if(resultadoBusqueda == -1)
                        cout<< "No se encontro la constancia\n";
                    else
                        cout<< "Faltan " << colaConstancias.ultimo() - resultadoBusqueda << " constancias a elaborar para que sea turno de esta constancia";
                }
                break;
            case 4:
                break;
            default:
                cout<< "Ingresa una opcion valida\n";
        }

        cout<< "\n\n";
    }

    return 0;
}
