/**
 * @file CReportes.h
 * @brief CONTRATO del módulo de reportes (GRUPO 8).
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO. NO SE EDITA.
 * Si crees que falta algo o hay un error, abre un issue en el repositorio padre.
 *
 * Estándar CRC:
 *   Clase: CReportes
 *   Responsabilidades:
 *     - Calcular totales y estadísticas del inventario.
 *     - Devolver listas de medicamentos ordenadas.
 *     - NO modifica el inventario. NO imprime nada.
 *   Colaboradores:
 *     - CInventario: de aquí lee la lista de medicamentos.
 *     - CMedicamento: es lo que devuelve en las listas.
 *
 * REGLAS DEL CONTRATO:
 *   - valorTotalCosto():  suma de costoDeCompra * cantidadDisponible.
 *   - valorTotalVenta():  suma de precioDeVenta * cantidadDisponible.
 *   - gananciaPotencial(): valorTotalVenta() - valorTotalCosto().
 *   - margenPorUnidad(id): precioDeVenta - costoDeCompra del medicamento; 0 si no existe.
 *   - masRentables(n): los n medicamentos con mayor margen por unidad, de mayor a menor.
 *       Si n > cantidad de medicamentos devuelve todos; si n <= 0, lista vacía.
 *   - ordenadosPorPrecio(): por precio de venta, de menor a mayor.
 *   - ordenadosPorNombre(): alfabéticamente (A-Z).
 *   - ordenadosPorCantidad(): por cantidad disponible, de menor a mayor.
 *   - Todas las listas son COPIAS: el orden del inventario original no cambia.
 */
#ifndef _CREPORTES_H_
#define _CREPORTES_H_
#include <vector>
#include "CInventario.h"
#include "CMedicamento.h"
using namespace std;

class CReportes
{
  private:
    const CInventario& inventario;

  public:
    CReportes(const CInventario& inventario);
    float valorTotalCosto() const;
    float valorTotalVenta() const;
    float gananciaPotencial() const;
    float margenPorUnidad(int id) const;
    vector<CMedicamento> masRentables(int n) const;
    vector<CMedicamento> ordenadosPorPrecio() const;
    vector<CMedicamento> ordenadosPorNombre() const;
    vector<CMedicamento> ordenadosPorCantidad() const;
};
#endif
