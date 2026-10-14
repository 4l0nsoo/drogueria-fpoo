
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
#include <iostream>
#include <string>

using namespace std;

// Constructor
CMedicamento::CMedicamento(int id_, string nombre_, int formaDePresentacion_, int cantidadDisponible_, float costoDeCompra_, float precioDeVenta_) {
	id=id_;
	nombre=nombre_;
	formaDePresentacion=formaDePresentacion_;
	cantidadDisponible=cantidadDisponible_;
	costoDeCompra=costoDeCompra_;
	precioDeVenta=precioDeVenta_;
	}
void CMedicamento::mostrarMedicamento() const{
	cout<<"*******----------------------**********"<<endl;
	cout<<"id del medicamento: "<<id<<endl;
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Forma de presentacion: "<<formaDePresentacion<<endl;
	cout<<"Cantidad disponible: "<<cantidadDisponible<<endl;	
	cout<<"Costo de compra: "<<costoDeCompra<<endl;	
	cout<<"Precio de venta: "<<precioDeVenta<<endl;
	
}
int CMedicamento::getId() const{
	return id;
}
string CMedicamento::getNombre() const{
	return nombre;
}
int CMedicamento::getFormaDePresentacion() const{
	return formaDePresentacion;
}
int CMedicamento::getCantidadDisponible() const{
	return cantidadDisponible;
}
float CMedicamento::getCostoDeCompra() const{
	return costoDeCompra;
}
float CMedicamento::getPrecioDeVenta() const{
	return precioDeVenta;
}
void CMedicamento::setCantidadDisponible(int cantidadDisponible_){
	cantidadDisponible=cantidadDisponible_;
}
