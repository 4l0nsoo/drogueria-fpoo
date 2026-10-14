/**
 * @file CPersistencia.h
 * @brief CONTRATO del módulo de persistencia (GRUPO 5).
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO. NO SE EDITA.
 * Si crees que falta algo o hay un error, abre un issue en el repositorio padre.
 *
 * Estándar CRC:
 *   Clase: CPersistencia
 *   Responsabilidades:
 *     - Guardar un inventario completo en un archivo de texto.
 *     - Cargar un inventario desde un archivo de texto.
 *     - Informar (con un bool) si la operación funcionó. NO imprime nada.
 *   Colaboradores:
 *     - CInventario: se lee para guardar / se llena al cargar.
 *     - CMedicamento: cada línea del archivo representa uno.
 *
 * FORMATO DEL ARCHIVO (CSV con punto y coma):
 *   Línea 1:   nombreDeLaDrogueria;fechaDeActualizacion
 *   Líneas 2+: id;nombre;formaDePresentacion;cantidadDisponible;costoDeCompra;precioDeVenta
 *
 * Ejemplo:
 *   Drogas La Especial;07-10-2026
 *   1;Acetaminofen 60Mg;1;100;1000;2000
 *   2;Ibuprofeno 30x20 Caja;2;10000;500;2500
 *
 * REGLAS DEL CONTRATO:
 *   - guardar(): devuelve true si escribió el archivo; false si no pudo abrirlo.
 *   - cargar(): REEMPLAZA el contenido del inventario recibido (nombre, fecha y
 *     medicamentos). Devuelve false si el archivo no existe o está corrupto, y en
 *     ese caso el inventario recibido NO debe quedar modificado.
 *   - Este módulo no usa cin ni cout (es modelo, no vista).
 */
#ifndef _CPERSISTENCIA_H_
#define _CPERSISTENCIA_H_
#include <string>
#include "CInventario.h"
using namespace std;

class CPersistencia
{
  private:
    string ruta;

  public:
    CPersistencia(string ruta);
    bool guardar(const CInventario& inventario) const;
    bool cargar(CInventario& inventario) const;
};
#endif
