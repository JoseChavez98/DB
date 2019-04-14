#ifndef alumno_h
#define alumno_h
#include <iostream>
#include <cstring>

class Alumno{

private:
std::string nombre;
std::string apellido;
std::string carrera;
float mensualidad;
std::string id;
std::string id_before="";
std::string id_next="";

public:

 void set_id(std::string id){
    this->id=id;
}
 void set_nombre(std::string nombre){
    this->nombre=nombre; 
 }
void set_apellido(std::string apellido){
    this->apellido=apellido;
 }
 void set_carrera(std::string carrera){
    
    this->carrera=carrera;
 }
 void set_mensualidad(std::string mensualidad){
    this->mensualidad=std::stof(mensualidad);
 }
 void set_next(std::string id_next){
     this-> id_next = id_next;
 }
 void set_before(std::string id_before){
     this->id_before=id_before;
 }

    const std::string &getNombre() const {
        return nombre;
    }

    const std::string &getApellido() const {
        return apellido;
    }

    const std::string &getCarrera() const {
        return carrera;
    }

    float getMensualidad() const {
        return mensualidad;
    }

    const std::string &getId() const {
        return id;
    }

    const std::string &getId_before() const {
        return id_before;
    }

    const std::string &getId_next() const {
        return id_next;
    }

    void print(){
     std::cout<<"nombre: "<< this->nombre <<'\n';
     std::cout<<"apellido: "<< this->apellido <<'\n';
     std::cout<<"Carrera: "<< this->carrera <<'\n';
     std::cout<<"mensualidad: "<< this->mensualidad <<'\n';
     std::cout<<"........................\n";
 }

};
#endif