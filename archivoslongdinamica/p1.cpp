#include <iostream>
#include <fstream>
#include <vector>
#include "alumno.h"

bool compareStrings(std::string a, std::string b){
    int size;
    int a_size = a.size();
    int b_size = b.size();

    if(a_size > b_size)
    {
        size = b_size;
    }
    else
    {
        size = a_size;
    }

    for( int i = 0;i<size;i++)
    {
            if(a[i]<b[i]){
                return true;
            }
            else if(b[i]<a[i]){
                return false;
            }
            else if(a[i]==b[i]){
                continue;
            }
    }
    return false;
}

void bulkInsert(Alumno br,std::fstream obj_read,std::fstream obj_write) {
    std::string linea;
    std::string id_before="";

    std::fstream auxiliar("auxiliar.txt",std::ios::out | std::ios::app);


    int cont = 0;

    Alumno a;
    getline(obj_read, linea);
    while (getline(obj_read, linea, '|')) {
        switch (cont) {
            case 0 :
                a.set_id(linea);
                break;
            case 1 :
                a.set_nombre(linea);
                break;
            case 2 :
                a.set_apellido(linea);
                break;
            case 3 :
                a.set_carrera(linea);
                break;
            case 4 :
                a.set_mensualidad(linea);
                getline(obj_read, linea);
                a.set_id(linea);
                break;

        }
        cont = (cont + 1) % 3;


        Alumno b;
        int cont2 = 0;
        std::string linea2;
        getline(obj_write, linea2);
        std::string name;
        while (getline(obj_write, linea2, '|')) {
            switch (cont) {
                case 0 :
                    b.set_nombre(linea2);
                    break;
                case 1 :
                    b.set_apellido(linea2);
                    break;
                case 2 :
                    b.set_carrera(linea2);
                    break;
                case 3 :
                    b.set_mensualidad(linea2);
                    break;
                case 4 :
                    b.set_id(linea2);
                    break;
                case 5 :
                    b.set_before(linea2);
                    getline(obj_write, linea2);
                    b.set_next(linea2);

                    if (compareStrings(a.getNombre(), b.getNombre())) {
                        a.set_before(b.getId_before());
                        b.set_before(a.getId_before());
                        a.set_next(b.getId_before());
                        auxiliar<<
                    }
                    break;

            }
            cont = (cont + 1) % 3;
        }
    id_before=a.getId();
    }
}

int main(){
std::vector<Alumno> lista;

    std::fstream arc("datos.txt",std::ios::in);
    std::fstream arc1("sort-data.txt",std::ios::out );
    std::string linea;
    int cont=0;
    Alumno a;
    getline(arc,linea);
    while (getline(arc,linea,'|')){
        switch (cont){
            case 0 :
                a.set_nombre(linea);
                break;
            case 1 :
                a.set_apellido(linea);
                break;
            case 2 :
                a.set_carrera(linea);
                getline(arc,linea);
                a.set_mensualidad(linea);
                lista.push_back(a);
                break;

        }
        cont=(cont+1)%3;
    }



 for(auto &i:lista){
     i.print();
 }
    return 0;
}