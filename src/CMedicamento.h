/**
 * @file CMedicamento.h
 * @brief Definición de la clase Medicamento. 
 *
 * @details
 * Implementa la abstracción de los medicamentos en una drogueria. Los medicamentos tienen las características
 * básicas de: nombre, forma de presentación, cantidad disponible, costo de compra y precio de
 * venta. Para poder mantener un control actualizado de los productos disponibles en la
 * droguería
 *
 * -----------------------------------------------------------------------------
 * Estándar CRC (Clase - Responsabilidad - Colaboración)
 * -----------------------------------------------------------------------------
 *
 * Clase:
 *   CMedicamento
 *
 * Responsabilidades:
 *   - Representar el Medicamento.
 *   - Encapsula los datos de un medicamento.
 *   - Presenta los datos de un medicamento.
 *   - Exponer sus datos mediante getters.
 *   - Permitir actualizar la cantidad disponible (setCantidadDisponible).
 *   
 * Colaboradores:
 *   - CInvetario:
 *       * Inventario utiliza la clase medicamento para hacer un vector.
 * 
 *
 * -----------------------------------------------------------------------------
 *
 * @author Victor Bucheli
 * @email victor.bucheli@correounivalle.edu.co
 * @license GNU General Public License v3.0 (GPL)
 *
 * Este programa es software libre: puede redistribuirlo y/o modificarlo
 * bajo los términos de la Licencia Pública General de GNU publicada por
 * la Free Software Foundation, ya sea la versión 3 de la Licencia, o
 * (a su elección) cualquier versión posterior.
 *
 * Este programa se distribuye con la esperanza de que sea útil,
 * pero SIN NINGUNA GARANTÍA; incluso sin la garantía implícita de
 * COMERCIABILIDAD o IDONEIDAD PARA UN PROPÓSITO PARTICULAR.
 * Véase la Licencia Pública General de GNU para más detalles.
 *
 * Debería haber recibido una copia de la Licencia Pública General de GNU
 * junto con este programa. Si no, consulte <https://www.gnu.org/licenses/>.
 */

// Candado: Evita la doble declaración
#ifndef _CMEDICAMENTO_H_
#define _CMEDICAMENTO_H_
#include <string>
using namespace std;

// Nombre clase
class CMedicamento
{
  // atributos
  private: 
    int id,formaDePresentacion,cantidadDisponible;
    string nombre;
    float costoDeCompra, precioDeVenta;


  // métodos
  public:
 
    CMedicamento(int id, string nombre, int formaDePresentacion, int cantidadDisponible, float costoDeCompra, float precioDeVenta);   // Método constructor

    // Getters
    int getId() const;
    string getNombre() const;
    int getFormaDePresentacion() const;
    int getCantidadDisponible() const;
    float getCostoDeCompra() const;
    float getPrecioDeVenta() const;

    // Setters
    void setCantidadDisponible(int cantidadDisponible);

    void mostrarMedicamento() const;
    
};
// Cierro el candado
#endif
