TARGET = MiAdventure

CXX = g++
CXXFLAGS = -Wall -O2 -std=c++17 

SRC = main.cpp src/inventario.cpp src/juego.cpp src/jugador.cpp src/mapa.cpp

build:
	$(CXX) $(SRC) $(CXXFLAGS) -o $(TARGET)
run:
	./$(TARGET)
clean:
	rm -f $(TARGET)
