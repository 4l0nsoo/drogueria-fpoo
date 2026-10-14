# Makefile del proyecto Drogueria (FPOO). Este archivo NO se edita.
#
#   make                  compila el programa (ejecutable: drogueria)
#   make test             compila y corre TODAS las pruebas
#   make run-buscador     corre solo test_buscador.cpp (cambie 'buscador' por su modulo)
#   make clean            borra lo compilado
#
# Funciona en Linux, macOS y Windows (con MinGW-w64/MSYS2 y make).
# Solo usa g++ y funciones propias de make: no depende de mkdir, rm, find ni de bash.

CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Isrc -Isrc/modelo -Isrc/vista -Ipruebas -MMD -MP

ifeq ($(OS),Windows_NT)
EXE = .exe
else
EXE =
endif

# Los .cpp se buscan en estas carpetas; todo lo compilado va a build/ (carpeta plana)
vpath %.cpp src src/modelo src/vista pruebas

SRC_LIB    = $(filter-out src/main.cpp, $(wildcard src/*.cpp src/modelo/*.cpp src/vista/*.cpp))
OBJ_LIB    = $(addprefix build/, $(notdir $(SRC_LIB:.cpp=.o)))
TEST_SRC   = $(wildcard pruebas/test_*.cpp)
TEST_NAMES = $(patsubst test_%,%,$(basename $(notdir $(TEST_SRC))))

all: drogueria$(EXE)

drogueria$(EXE): $(OBJ_LIB) build/main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

build/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/test_%$(EXE): build/test_%.o $(OBJ_LIB)
	$(CXX) $(CXXFLAGS) $^ -o $@

run-%: build/test_%$(EXE)
	$(info === pruebas de $* ===)
	@build/test_$*$(EXE)

test: $(addprefix run-, $(TEST_NAMES))

clean:
ifeq ($(OS),Windows_NT)
	-@del /Q /F build\*.o build\*.d build\*.exe build\*.csv drogueria.exe
else
	@rm -f build/*.o build/*.d build/*.csv build/test_* drogueria
endif

-include $(wildcard build/*.d)

.PHONY: all test clean
.SECONDARY:
