#ifndef aula2_h
#define aula2_h
#include <vector>
#include <fstream>
#include "alumno2.h"

class Aula{
public:
    std::vector<Alumno> lista;
    
    Aula()=default;
    
    bool find_deleted(int registro){
        std::fstream arc("header.txt",std::ios::in);
        std::string reg;
        while(arc>>reg){
            if(stoi(reg)==registro){
                return true;
            }
        }return false;
    }

    void load(std::string filename){
        std::fstream arc(filename,std::ios::in);
        std::string palabra;
        Alumno master;
        int cont=0;
        int registro=0;
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
                cont++;
                break;

                case 4 :
                master.set_ciclo(palabra);
                cont++;
                break;

                case 5 :
                master.set_mensualidad(palabra);
                lista.push_back(master);
                cont=0;
                break;
            }
        }

        for(auto &i : lista){

            if(find_deleted(registro)){
                registro+=sizeof(Alumno);
            }else{
                i.print();
                registro+=sizeof(Alumno);
            }
        }    
    }

    void add(Alumno a){
        lista.push_back(a);
        std::fstream arc("datos.txt",std::ios::out | std::ios::app );
        arc<<'\n'<<a.nombre<<"     "<<a.apPaterno<<"    "<<a.apMaterno<<"     "<<a.carrera<<"     "<<a.ciclo<<"     "<<a.mensualidad;
    }

    bool delete_alumno(int pos){
        int size=sizeof(Alumno);
        auto start = size*(pos-1);
        std::fstream arc("header.txt",std::ios::trunc |  std::ios::out | std::ios::app);
        arc<<start<<'\n';
    }

    

};
#endif