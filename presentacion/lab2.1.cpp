#include <iostream>
#include <fstream>
#include <vector>
#include "alumno2.1.h"

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



void bulkInsert2(std::string read , std::string write) {

    std::fstream obj_read(read, std::ios::in);
    std::fstream obj_write(write, std::ios::in| std::ios::out | std::ios::app);



//    if (auxiliar.is_open())
//    {
//        auxiliar << "This is a line.\n";
//        auxiliar << "This is another line.\n";
//        auxiliar.close();
//    }
//    else std::cout << "Unable to open file";


    Alumno a;
    int cont = 0;
    std::string linea;
    Alumno b;
    int cont2 = 0;
    std::string linea2;
    std::string name;


    getline(obj_read, linea);
    while (getline(obj_read, linea, '|')) {
        switch (cont) {
            case 0 :
                a.set_nombre(linea);
                cont++;
                break;
            case 1 :
                a.set_apellido(linea);
                cont++;
                break;
            case 2 :
                a.set_carrera(linea);
                cont++;
                break;
            case 3 :
                a.set_mensualidad(linea);
                getline(obj_read, linea);
                a.set_id(linea);
                cont=0;


                obj_write.seekg(0);

                getline(obj_write, linea2);
                while (getline(obj_write, linea2, '|')) {
                    switch (cont2) {
                        case 0 :
                            b.set_nombre(linea2);
                            cont2++;
                            break;
                        case 1 :
                            b.set_apellido(linea2);
                            cont2++;
                            break;
                        case 2 :
                            b.set_carrera(linea2);
                            cont2++;
                            break;
                        case 3 :
                            b.set_mensualidad(linea2);
                            cont2++;
                            break;
                        case 4 :
                            b.set_id(linea2);
                            cont2++;
                            break;
                        case 5 :
                            b.set_before(linea2);
                            getline(obj_write, linea2);
                            b.set_next(linea2);
                            if(compareStrings(a.getNombre(),b.getNombre())){
                                a.set_before(b.getId_before());
                                a.set_next(b.getId_before());

                                std::ofstream auxiliar ("/home/jose/BD/archivoslongfija/auxiliar.txt",std::ios::app | std::ios::trunc);

                                auxiliar<<a.compound();
                                auxiliar.close();

                            }else{
                                obj_write<<a.compound();
                            }
                            cont2=0;
                            break;

                    }
                }
                break;

        }

    }

}

int main(){


    //bulkInsert("datos.txt","sort-data.txt");

    bulkInsert2("/home/jose/BD/archivoslongfija/datos.txt","/home/jose/BD/archivoslongfija/sort-data.txt");


    return 0;
}