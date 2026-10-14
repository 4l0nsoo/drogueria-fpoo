/**
 * @file CBuscador.h
 * @brief CONTRATO del módulo de búsqueda (GRUPO 6).
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO. NO SE EDITA.
 * Si crees que falta algo o hay un error, abre un issue en el repositorio padre.
 *
 * Estándar CRC:
 *   Clase: CBuscador
 *   Responsabilidades:
 *     - Buscar medicamentos dentro de un inventario según distintos criterios.
 *     - NO modifica el inventario. NO imprime nada.
 *   Colaboradores:
 *     - CInventario: de aquí lee la lista de medicamentos.
 *     - CMedicamento: es lo que devuelve.
 *
 * REGLAS DEL CONTRATO:
 *   - porId(): devuelve un puntero al medicamento dentro del inventario, o nullptr si no existe.
 *   - porNombre(): coincidencia PARCIAL e insensible a mayúsculas/minúsculas.
 *       Ej: porNombre("ibu") encuentra "Ibuprofeno 30x20 Caja".
 *       Si texto es vacío devuelve una lista vacía.
 *   - porRangoPrecio(): precio de venta en [minimo, maximo] (ambos incluidos).
 *       Si minimo > maximo devuelve una lista vacía.
 *   - conPocoStock(): cantidad disponible <= umbral.
 *   - Las listas conservan el orden en que están en el inventario.
 */
#ifndef _CBUSCADOR_H_
#define _CBUSCADOR_H_
#include <string>
#include <vector>
#include "CInventario.h"
#include "CMedicamento.h"
using namespace std;

class CBuscador
{
  private:
    const CInventario& inventario;

  public:
    CBuscador(const CInventario& inventario);
    const CMedicamento* porId(int id) const;
    vector<CMedicamento> porNombre(string texto) const;
    vector<CMedicamento> porRangoPrecio(float minimo, float maximo) const;
    vector<CMedicamento> conPocoStock(int umbral) const;
};
#endif
