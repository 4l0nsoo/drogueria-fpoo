// Pruebas de CValidador. Responsable: GRUPO 3
#include <sstream>
#include "minitest.h"
#include "CValidador.h"
using namespace std;

int main(){
    SECCION("CValidador: leerEntero insiste hasta recibir un valor valido");
    {
        stringstream in("abc\n7\n");
        stringstream out;
        CValidador v(in, out);
        CHECK_EQ(v.leerEntero("n: ", 1, 10), 7);
    }
    {
        stringstream in("50\n-3\n5\n");
        stringstream out;
        CValidador v(in, out);
        CHECK_EQ(v.leerEntero("n: ", 1, 10), 5);
    }

    SECCION("CValidador: leerTextoNoVacio");
    {
        stringstream in("\n   \nIbuprofeno 400 mg\n");
        stringstream out;
        CValidador v(in, out);
        CHECK_EQ(v.leerTextoNoVacio("nombre: "), "Ibuprofeno 400 mg");
    }

    SECCION("CValidador: esFechaValida");
    CHECK(CValidador::esFechaValida("07-10-2026"));
    CHECK(CValidador::esFechaValida("29-02-2024"));
    CHECK(!CValidador::esFechaValida("29-02-2023"));
    CHECK(!CValidador::esFechaValida("31-04-2026"));
    CHECK(!CValidador::esFechaValida("7-10-2026"));
    CHECK(!CValidador::esFechaValida("hola"));

    // TODO (Grupo 3): float positivo, fecha con letras, entrada que se termina (EOF),
    // límites del rango (minimo y maximo incluidos), años bisiestos (1900, 2000), etc.

    return RESUMEN();
}
