/**
 * @file CMenu.h
 * @brief CONTRATO del menú principal (GRUPO 1).
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO. NO SE EDITA.
 * Si crees que falta algo o hay un error, abre un issue en el repositorio padre.
 *
 * Estándar CRC:
 *   Clase: CMenu
 *   Responsabilidades:
 *     - Mostrar el menú principal y los submenús.
 *     - Leer la opción elegida y llamar a la clase que corresponda.
 *     - Repetir hasta que el usuario elija salir.
 *   Colaboradores:
 *     - CInventario (el inventario sobre el que se trabaja)
 *     - CValidador, CFormulario, CPresentador (vista)
 *     - CBuscador, CGestorStock, CReportes, CPersistencia (modelo)
 *   CMenu crea internamente los colaboradores que necesite a partir del inventario
 *   recibido, usando SOLO los métodos de los contratos (headers) de cada módulo.
 *
 * REGLAS DEL CONTRATO:
 *   - ejecutar(): bucle principal. La opción 0 SIEMPRE es "Salir" y termina el método.
 *   - Si la entrada se termina (EOF) ejecutar() también debe terminar (no ciclo infinito).
 *   - El menú NO calcula lógica de negocio: delega en el modelo.
 *   - Funciones esperadas (la organización de los submenús la decide el grupo):
 *       agregar / eliminar / mostrar medicamentos, buscar, vender / reabastecer,
 *       reportes, guardar / cargar el inventario (archivo "inventario.csv").
 */
#ifndef _CMENU_H_
#define _CMENU_H_
#include <iostream>
#include "CInventario.h"
using namespace std;

class CMenu
{
  private:
    CInventario& inventario;
    istream& entrada;
    ostream& salida;

  public:
    CMenu(CInventario& inventario, istream& entrada = cin, ostream& salida = cout);
    void ejecutar();
};
#endif
