#ifndef alumno2_h
#define alumno2_h
#include <iostream>
#include <cstring>

class Alumno{

public:
char nombre[12];
char apPaterno[12];
char apMaterno[12];
char carrera[15];
int ciclo;
float mensualidad;

Alumno()=default;
 void set_nombre(std::string nombre){
    strcpy(this->nombre,nombre.c_str()); 
 }
void set_apPaterno(std::string apPaterno){
    strcpy(this->apPaterno,apPaterno.c_str()); 
 }
 void set_apMaterno(std::string apMaterno){
    strcpy(this->apMaterno,apMaterno.c_str()); 
 }
 void set_carrera(std::string carrera){
    strcpy(this->carrera,carrera.c_str());
 }
 void set_ciclo(std::string ciclo){
     this->ciclo= stoi(ciclo);
 }
 void set_mensualidad(std::string mensualidad){
     this->mensualidad=stof(mensualidad);
 }
Alumno(std::string nombre,std::string apPaterno,std::string apMaterno,std::string carrera,std::string ciclo,std::string mensualidad){
   set_nombre(nombre);
   set_apPaterno(apPaterno);
   set_apMaterno(apMaterno);
   set_carrera(carrera);
   set_ciclo(ciclo);
   set_mensualidad(mensualidad);
}
 void print(){
     std::cout<<"nombre: "<< this->nombre <<'\n';
     std::cout<<"apellido P: "<< this->apPaterno <<'\n';
     std::cout<<"apellido M: "<< this->apMaterno <<'\n';
     std::cout<<"carrera: "<< this->carrera <<'\n';
     std::cout<<"ciclo: "<< this->ciclo <<'\n';
     std::cout<<"mensualidad: "<< this->mensualidad <<'\n';
     std::cout<<"........................\n";
 }

};
#endif