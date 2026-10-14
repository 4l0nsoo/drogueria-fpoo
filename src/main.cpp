/*
    Proyecto: Drogueria 
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este proyecto gestiona una drogueria.

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2026

    NOTA: este archivo NO se edita durante el taller. Toda la interacción
    con el usuario vive en CMenu (Grupo 1).
*/
#include "CMedicamento.h"
#include "CInventario.h"
#include "CMenu.h"

int main(){
    CInventario inventarioDrogasLaEspecial("Drogas La Especial","07-10-2026");
    inventarioDrogasLaEspecial.adicionarMedicamento(CMedicamento(1, "Acetaminofen 60Mg",1,100,1000,2000));
    inventarioDrogasLaEspecial.adicionarMedicamento(CMedicamento(2, "Ibuprofeno 30x20 Caja",2,10000,500,2500));

    CMenu menu(inventarioDrogasLaEspecial);
    menu.ejecutar();
    return 0;
}
