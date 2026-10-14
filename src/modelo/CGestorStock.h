/**
 * @file CGestorStock.h
 * @brief CONTRATO del módulo de stock y ventas (GRUPO 7).
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO. NO SE EDITA.
 * Si crees que falta algo o hay un error, abre un issue en el repositorio padre.
 *
 * Estándar CRC:
 *   Clase: CGestorStock
 *   Responsabilidades:
 *     - Aplicar las reglas de negocio de ventas y reabastecimiento.
 *     - Modificar la cantidad disponible de un medicamento del inventario.
 *     - Informar el resultado con un código (enum). NO imprime nada.
 *   Colaboradores:
 *     - CInventario: se modifica a través de getMedicamentos().
 *     - CMedicamento: se usa setCantidadDisponible().
 *
 * REGLAS DEL CONTRATO:
 *   - vender(id, cantidad):
 *       NO_EXISTE          si no hay un medicamento con ese id
 *       CANTIDAD_INVALIDA  si cantidad <= 0
 *       STOCK_INSUFICIENTE si cantidad > cantidad disponible
 *       OK                 en otro caso (y descuenta del stock)
 *     Si el resultado no es OK, el stock NO cambia.
 *   - reabastecer(id, cantidad): NO_EXISTE, CANTIDAD_INVALIDA u OK (y suma al stock).
 *   - esStockBajo(id, umbral): true si el medicamento existe y su cantidad es <= umbral.
 */
#ifndef _CGESTORSTOCK_H_
#define _CGESTORSTOCK_H_
#include "CInventario.h"
using namespace std;

enum class ResultadoStock { OK, NO_EXISTE, CANTIDAD_INVALIDA, STOCK_INSUFICIENTE };

class CGestorStock
{
  private:
    CInventario& inventario;

  public:
    CGestorStock(CInventario& inventario);
    ResultadoStock vender(int id, int cantidad);
    ResultadoStock reabastecer(int id, int cantidad);
    bool esStockBajo(int id, int umbral) const;
};
#endif
