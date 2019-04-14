#ifndef aula_h
#define aula_h
#include <vector>
#include <fstream>
#include "alumno.h"

class Aula{
public:
    std::vector<Alumno> lista;
    
    Aula()=default;
    
    void load(std::string filename){
        std::fstream arc(filename,std::ios::in);
        std::string palabra;
        Alumno master;
        int cont=0;
        while(arc>>palabra){
            switch(cont){
                case 0 :
                master.set_nombre(palabra);
                cont++;
                break;
                
                case 1 :
                master.set_apPaterno(palabra);
                cont++;
                break;

                case 2 :
                master.set_apMaterno(palabra);
                cont++;
                break;

                case 3 :
                master.set_carrera(palabra);
                lista.push_back(master);
                cont=0;
                break;
            }
        }

        for(auto &i : lista){
            i.print();
        }    
    }

    void add(Alumno a){
        lista.push_back(a);
        std::fstream arc("datos.txt",std::ios::out | std::ios::app);
        arc<<'\n'<<a.nombre<<"     "<<a.apPaterno<<"    "<<a.apMaterno<<"     "<<a.carrera;
    }

    

};
#endif