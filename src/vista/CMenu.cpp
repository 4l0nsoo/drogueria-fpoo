/*
    Proyecto: Drogueria - FPOO - Universidad del Valle
    Módulo: Menú principal (GRUPO 1)

    ESTE ARCHIVO ES TUYO: reemplaza los STUB por la implementación real.
*/
#include "CMenu.h"
#include "CFormulario.h"
#include "Cpresentador.h"
#include "Cbuscador.h"
#include "CGestorStock.h"
#include "CReportes.h"
#include "CPersistencia.h"
#include "CMedicamento.h"
#include "CInventario.h"
#include "CValidador.h"
#include <string>

using namespace std;

CMenu::CMenu(CInventario& inventario_, istream& entrada_, ostream& salida_)
    : inventario(inventario_), entrada(entrada_), salida(salida_) {
        int choice;
        salida <<"╔══════════════════════════════════════════╗\n"
               <<"          MENÚ OPCIONES - DROGUERÍA         \n"
               <<"╚══════════════════════════════════════════╝\n"<<endl;
        salida << "1. Agregar medicamento\n";
        salida << "2. Eliminar medicamento\n";
        salida << "3. Mostrar medicamentos\n";
        salida << "4. Buscar medicamento\n";
        salida << "5. Vender medicamento\n";
        salida << "6. Reabastecer\n";
        salida << "7. Mostrar reportes\n";
        salida << "8. Guardar\n";
        salida << "9. Cargar el inventario\n";
        salida << "0. Salir\n";
        salida << "Ingrese su elección: ";
        entrada >> choice;
    }
       
void CMenu::ejecutar(){
    int choice = -1;
    // STUB (Grupo 1): implementar
    
    switch (choice) {

        case 0:
            salida<<"Gracias por visitarnos"<<endl;
            return;

        case 1: {
            CValidador validador (entrada, salida);
            CFormulario formulario(validador, salida);
            CMedicamento med = formulario.pedirMedicamento();
            inventario.adicionarMedicamento(med);
            break;}
        case 2:{
            CValidador validador (entrada, salida);
            CFormulario formulario (validador, salida);
            CMedicamento med = formulario.pedirMedicamento(); 
            inventario.elimininarMedicamento(med);    
            break;}
        case 3:{
            CPresentador presentador (salida);
            presentador.mostrarMedicamentos(inventario.getMedicamentos());
            break;}
        case 4:{
            CValidador validador (entrada, salida);
            CBuscador buscador(inventario);
            CPresentador presentador (salida);
            string texto = validador.leerTextoNoVacio("Nombre del medicamento a buscar: ");
            presentador.mostrarMedicamentos(buscador.porNombre(texto));
            break;}
        case 5:{
            CValidador validador (entrada, salida);
            CFormulario formulario (validador, salida);
            CGestorStock gestor(inventario);
            int id = formulario.pedirId();
            int cantidad = formulario.pedirCantidad();
            gestor.vender(id, cantidad);
            break;}
        case 6:{
            CValidador validador (entrada, salida);
            CFormulario formulario (validador, salida);
            CGestorStock gestor(inventario);
            int id = formulario.pedirId();
            int cantidad = formulario.pedirCantidad();
            gestor.reabastecer(id, cantidad);
            break;}
        case 7:{
            CReportes reportes(inventario);
            CPresentador presentador(salida);
            salida << "Valor total de costo: " << reportes.valorTotalCosto() <<"\n";
            salida << "Valor total de venta: " << reportes.valorTotalVenta() <<"\n";
            salida << "Ganancia total: " << reportes.gananciaPotencial()<<"\n";
            presentador.mostrarMedicamentos(reportes.ordenadosPorNombre());
            break;}
        case 8:{
            CPersistencia persistencia("inventario.csv");
            persistencia.guardar(inventario);
            break;}
         case 9:{
            CPersistencia persistencia("inventario.csv");
            persistencia.cargar(inventario);
            break;}
            
        default:
            salida<<"Opcion incorrecta. Intentelo de nuevo"<<endl;
            break;
        }
    }   

   