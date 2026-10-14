# Proyecto Droguería — Taller colaborativo con GitHub
Fundamentos de Programación Orientada a Objetos (FPOO) — Universidad del Valle

Este repositorio contiene el software de la droguería **listo para que 8 grupos lo completen
en paralelo**. Lea primero `REGLAS.md`.

## Cómo compilar y probar

Necesita `g++` y `make`. Verifique con `g++ --version` y `make --version`.

- **Linux / macOS / WSL:** instale `g++` y `make` con el gestor de paquetes.
- **Windows:** instale MinGW-w64 (por ejemplo con MSYS2) y `make`, y agregue sus carpetas al PATH. El `Makefile` funciona directamente en PowerShell o CMD.
- **Alternativa:** abrir el repositorio en un Codespace de GitHub (ya trae todo instalado).

```
make                    # compila el programa -> drogueria (drogueria.exe en Windows)
make test               # corre TODAS las pruebas
make run-buscador       # corre solo las pruebas de un módulo (cambie 'buscador')
make clean              # borra lo compilado
```

Al inicio, **muchas pruebas fallan a propósito**: los módulos son *stubs* (versiones vacías que
compilan pero no hacen nada). Su trabajo es ponerlas en verde.

## Estructura

```
src/
  CMedicamento.*  CInventario.*     clases base (ya implementadas)
  main.cpp                          NO se edita
  modelo/                           lógica del negocio (no usa cin/cout)
    CPersistencia.*  CBuscador.*  CGestorStock.*  CReportes.*
  vista/                            interacción con el usuario
    CMenu.*  CFormulario.*  CValidador.*  CPresentador.*
pruebas/                            minitest.h y un test_<modulo>.cpp por módulo
docs/                               UML (un fragmento por grupo)
```

## ¿Qué archivos son de cada grupo?

| Grupo | Módulo | Capa | Archivos que SÍ puede editar |
|---|---|---|---|
| 1 | CMenu | Vista | `src/vista/CMenu.cpp`, `pruebas/test_menu.cpp`, `docs/uml_menu.puml` |
| 2 | CFormulario | Vista | `src/vista/CFormulario.cpp`, `pruebas/test_formulario.cpp`, `pruebas/test_medicamento.cpp`, `docs/uml_formulario.puml` |
| 3 | CValidador | Vista | `src/vista/CValidador.cpp`, `pruebas/test_validador.cpp`, `docs/uml_validador.puml` |
| 4 | CPresentador | Vista | `src/vista/CPresentador.cpp`, `src/CInventario.cpp`*, `pruebas/test_presentador.cpp`, `pruebas/test_inventario.cpp`, `docs/uml_presentador.puml` |
| 5 | CPersistencia | Modelo | `src/modelo/CPersistencia.cpp`, `pruebas/test_persistencia.cpp`, `docs/uml_persistencia.puml` |
| 6 | CBuscador | Modelo | `src/modelo/CBuscador.cpp`, `pruebas/test_buscador.cpp`, `docs/uml_buscador.puml` |
| 7 | CGestorStock | Modelo | `src/modelo/CGestorStock.cpp`, `pruebas/test_stock.cpp`, `docs/uml_stock.puml` |
| 8 | CReportes | Modelo | `src/modelo/CReportes.cpp`, `pruebas/test_reportes.cpp`, `docs/uml_reportes.puml` |

\* Solo el Grupo 4 puede tocar `CInventario.cpp`, y únicamente para corregir errores que descubran con sus pruebas.

Todo lo demás es de otros: **los headers (`.h`) son contratos y no se editan.**
Cada grupo puede crear archivos nuevos propios si los necesita (por ejemplo, funciones auxiliares), siempre con un nombre que no choque con los de otro grupo (prefijo del módulo).
