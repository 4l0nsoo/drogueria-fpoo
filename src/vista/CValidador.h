/**
 * @file CValidador.h
 * @brief CONTRATO del módulo de validación de entradas (GRUPO 3).
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO. NO SE EDITA.
 * Si crees que falta algo o hay un error, abre un issue en el repositorio padre.
 *
 * Estándar CRC:
 *   Clase: CValidador
 *   Responsabilidades:
 *     - Leer datos del usuario insistiendo hasta que sean válidos.
 *     - Validar el formato de una fecha.
 *   Colaboradores:
 *     - Ninguno (es independiente). Lo usan CFormulario y CMenu.
 *
 * Los flujos de entrada/salida se reciben por referencia (por defecto cin/cout)
 * para poder probar la clase con stringstream.
 *
 * REGLAS DEL CONTRATO:
 *   - leerEntero(mensaje, minimo, maximo): muestra el mensaje, lee una LÍNEA completa y
 *       repite mientras no sea un entero en [minimo, maximo].
 *   - leerFloatPositivo(mensaje): igual, pero exige un número real > 0.
 *   - leerTextoNoVacio(mensaje): lee una LÍNEA completa (puede tener espacios) y repite
 *       mientras esté vacía o solo tenga espacios.
 *   - esFechaValida(fecha): formato dd-mm-aaaa, con día/mes reales y años bisiestos.
 *       Ej: "29-02-2024" es válida, "29-02-2023" no, "31-04-2026" no, "7-10-2026" no.
 *   - leerFecha(mensaje): como leerTextoNoVacio pero repite hasta que esFechaValida sea true.
 *   - SI LA ENTRADA SE TERMINA (EOF) hay que dejar de insistir para no quedar en un
 *       ciclo infinito: devolver minimo / 0 / "" según el método.
 */
#ifndef _CVALIDADOR_H_
#define _CVALIDADOR_H_
#include <iostream>
#include <string>
using namespace std;

class CValidador
{
  private:
    istream& entrada;
    ostream& salida;

  public:
    CValidador(istream& entrada = cin, ostream& salida = cout);
    int leerEntero(string mensaje, int minimo, int maximo);
    float leerFloatPositivo(string mensaje);
    string leerTextoNoVacio(string mensaje);
    string leerFecha(string mensaje);
    static bool esFechaValida(string fecha);
};
#endif
