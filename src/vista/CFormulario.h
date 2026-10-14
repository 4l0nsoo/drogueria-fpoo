/**
 * @file CFormulario.h
 * @brief CONTRATO del módulo de formularios de captura (GRUPO 2).
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO. NO SE EDITA.
 * Si crees que falta algo o hay un error, abre un issue en el repositorio padre.
 *
 * Estándar CRC:
 *   Clase: CFormulario
 *   Responsabilidades:
 *     - Pedirle al usuario los datos necesarios para una operación y devolverlos.
 *     - NO decide qué hacer con los datos (eso lo decide CMenu) y NO valida por su
 *       cuenta: usa a CValidador.
 *   Colaboradores:
 *     - CValidador: para leer cada dato validado.
 *     - CMedicamento: pedirMedicamento() construye y devuelve uno.
 *
 * REGLAS DEL CONTRATO:
 *   - pedirMedicamento(): pregunta en este ORDEN: id, nombre, forma de presentación,
 *       cantidad disponible, costo de compra, precio de venta.
 *       Forma de presentación: 1=Tableta, 2=Caja, 3=Jarabe, 4=Ampolla, 5=Crema
 *       (el formulario debe mostrar estas opciones y pedir un número entre 1 y 5).
 *   - pedirId(): pide un id (entero >= 1).
 *   - pedirCantidad(): pide una cantidad (entero >= 1).
 *   - pedirFecha(): pide una fecha dd-mm-aaaa válida.
 */
#ifndef _CFORMULARIO_H_
#define _CFORMULARIO_H_
#include <iostream>
#include <string>
#include "CMedicamento.h"
#include "CValidador.h"
using namespace std;

class CFormulario
{
  private:
    CValidador& validador;
    ostream& salida;

  public:
    CFormulario(CValidador& validador, ostream& salida = cout);
    CMedicamento pedirMedicamento();
    int pedirId();
    int pedirCantidad();
    string pedirFecha();
};
#endif
