/*
    Proyecto: Drogueria 
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este proyecto gestiona una drogueria.

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2026
*/
// incluir la clase
#include "CMedicamento.h"
#include "CInventario.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor
 CInventario::CInventario(string nombre_, string fecha_){
    nombre=nombre_;
    fecha=fecha_;
    inventario.clear();
 } 

 void CInventario::adicionarMedicamento(CMedicamento medicamento){
    inventario.push_back(medicamento);
 }

void CInventario::mostrarInventario(){

    cout<<"El nombre de la drogueria es: "<<nombre<<endl;
    cout<<"La fecha de actualización es: "<<fecha<<endl;
    

    for (size_t i=0; i<inventario.size(); i++){
        inventario[i].mostrarMedicamento();
    }
}

void CInventario::elimininarMedicamento(CMedicamento medicamento){
   vector<CMedicamento>::iterator it, it1;
   int se=0;
   it1=inventario.begin();
   for (it = inventario.begin(); it != inventario.end(); it++) {
    if(it->getId()==medicamento.getId()){    
       it1=it;
       se=1;
    }
   }
   if(se==1){
    cout<<"El medicamento a borrar es:"<<endl;
    it->mostrarMedicamento(); 
    inventario.erase(it1); 
   }
   else{
    cout<<"No se econtró el medicamento para borrar"<<endl;
   }
}

// Getters
string CInventario::getNombre() const{
    return nombre;
}
string CInventario::getFecha() const{
    return fecha;
}
const vector<CMedicamento>& CInventario::getMedicamentos() const{
    return inventario;
}
vector<CMedicamento>& CInventario::getMedicamentos(){
    return inventario;
}

// Setters
void CInventario::setNombre(string nombre_){
    nombre=nombre_;
}
void CInventario::setFecha(string fecha_){
    fecha=fecha_;
}
