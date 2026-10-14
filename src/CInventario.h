/**
 * @file CInventario.h
 * @brief Definición de la clase Inventario. 
 *
 * @details
 * Implementa la abstracción de el inventario en una drogueria. El inventario tiene nombre de la drogueria y la fecha de actualización
 *
 * -----------------------------------------------------------------------------
 * Estándar CRC (Clase - Responsabilidad - Colaboración)
 * -----------------------------------------------------------------------------
 *
 * Clase:
 *   CInventario
 *
 * Responsabilidades:
 *   - Representar los medicamentos que hay en el inventario de una drogueria.
 *   - Encapsula los datos nombre de drogueria y fecha de actualización.
 *   - Presenta los datos del inventario.
 *   - Eliminar un medicamento del inventario
 *   - Exponer su nombre, su fecha y su lista de medicamentos (getters/setters).
 *   
 * Colaboradores:
 *   - CIMedicamento:
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
#ifndef _CINVENTARIO_H_
#define _CINVENTARIO_H_
#include <string>
#include <vector>
#include "CMedicamento.h"

using namespace std;

// Nombre clase
class CInventario
{
  // atributos
  private: 
    string nombre, fecha;
    vector <CMedicamento> inventario;

  // métodos
  public:
 
    CInventario(string nombre, string fecha);   // Método constructor
    void adicionarMedicamento(CMedicamento medicamento);
    void elimininarMedicamento(CMedicamento medicamento);
    void mostrarInventario();

    // Getters
    string getNombre() const;
    string getFecha() const;
    const vector<CMedicamento>& getMedicamentos() const;   // solo lectura
    vector<CMedicamento>& getMedicamentos();               // lectura y modificación

    // Setters
    void setNombre(string nombre);
    void setFecha(string fecha);
    
};
// Cierro el candado
#endif
