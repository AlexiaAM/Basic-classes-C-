#include <iostream>
#include <vector>

using namespace std;

struct Municipio {
    string nombre;
    int poblacion;

    /// Defatult
    Municipio (){}

    /// Por nombre
    Municipio(string nombre){
        this->nombre = nombre;
        poblacion = 0;
    }

    /// Por nombre y poblacion
    Municipio(string nombre, int poblacion){
        this->nombre = nombre;
        this->poblacion = poblacion;
    }

    /// Funcion para imprimir los datos del municipio.
    void imprimirDatos(){
        if(poblacion == 0){
            cout << nombre << "\n";
        }
        else{
            cout << nombre << "\n";
            cout << poblacion << "\n";
        }
    }
};

struct Estado {

    string nombre;
    vector<Municipio> municipios;

    // Default
    Estado(){}

    // Por nombre
    Estado(string nombre){
        this->nombre = nombre;
    }


    // Debe recibir Un municipio y agregarlo a la lista de municipios
    void agregar(Municipio muni){
        municipios.push_back(muni);
    }

    // Funcion para imprimir todos los Municipios del Estado.
    void imprimirMunicipiosEstado(){
        for(Municipio m : municipios){
            if(m.poblacion == 0){
                cout << m.nombre << "\n";
            }
            else{
                cout << m.nombre << " " << m.poblacion << "\n";
            }

        }
    }

    // Funcion para eliminar un Municipio por nombre.
    void eliminarMunicipioNombre(string nombre){
        int pos = 0;
        int deleteElement = 0;
        vector<Municipio>::iterator it;
        for(Municipio m : municipios){
            if(m.nombre == nombre){
                it = municipios.begin()+pos;
                municipios.erase(it);
                break;
            }
            pos++;
        }
    }

};

int main (){

    // Crear 3 Estados
    Estado e1("Guanajuato");
    Estado e2("Michoacan");
    Estado e3("Durango");

    // Agregar 2-3 Municipios a cada estado
    Municipio m1("Uriangato");
    Municipio m2("Moroleon");
    Municipio m3("Yuriria");
    e1.agregar(m1);
    e1.agregar(m2);
    e1.agregar(m3);

    Municipio m4("Morelia");
    Municipio m5("Paztcuaro");
    Municipio m6("Pinicuaro");
    e2.agregar(m4);
    e2.agregar(m5);
    e2.agregar(m6);

    Municipio m7("Mexiquillo");
    Municipio m8("rosa");
    Municipio m9("Vainilla");
    e3.agregar(m7);
    e3.agregar(m8);
    e3.agregar(m9);

    // Imprimir los datos del primer Estado
    e1.imprimirMunicipiosEstado();

    // Eliminar un municipio del primer estado.
    e1.eliminarMunicipioNombre("Moroleon");
    cout << "\n";

    // Imprimir los datos del primer Estado.
    e1.imprimirMunicipiosEstado();
    cout << "\n";

    // Imprimir los datos del 3er estado.
    e3.imprimirMunicipiosEstado();

    return 0;
}
