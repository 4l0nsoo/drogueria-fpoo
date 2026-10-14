# Reglas del taller

1. **Cada grupo edita solo sus archivos** (ver la tabla del `README.md`).
2. **Los headers `.h` de los módulos son contratos: no se editan.** Si creen que falta un método o hay un error, abran un *issue* en el repositorio padre y el monitor responde.
3. **No se editan** `main.cpp`, `Makefile`, `minitest.h` ni archivos de otros grupos.
4. **Modelo y vista no se mezclan:** el modelo nunca usa `cin`/`cout`; la vista nunca calcula lógica de negocio.
5. **Cada grupo entrega tres cosas:** su código, sus pruebas (las iniciales + las suyas) y su fragmento UML en `docs/`.
6. **Antes de enviar el Pull Request:** `git pull upstream main`, `make` sin errores y sus pruebas en verde.
7. **Commits pequeños y con mensajes claros** (ej: `Grupo 6: implementa porNombre`). Todos los integrantes deben tener commits.
8. **Los módulos son independientes:** no esperen a que otro grupo termine. Programen contra el header (contrato) del módulo que necesiten; su versión vacía ya compila.
