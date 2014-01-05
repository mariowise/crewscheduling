#
# Crew Scheduling problem
# 	by mariowise

GALIB_INC = /usr/local/include/ga
GALIB_LIB = /usr/local/lib

INC_DIRS = -I $(GALIB_INC) -Isrc
LIB_DIRS = -L $(GALIB_LIB)

CFLAGS = -c -w
LIBS = -lga

main: build/main.o build/DateTime.o build/TimeInterval.o build/Station.o build/Trip.o build/Service.o build/Reader.o
	@ g++ build/*.o $(LIB_DIRS) $(LIBS) -o bin/crewshit.run
	@ echo "Compilación terminada de forma exitosa"

build/main.o: src/main.cpp
	@ echo "  src/main.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/main.cpp -o build/main.o

build/DateTime.o: src/eda/DateTime.cpp
	@ echo "  src/eda/DateTime.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/eda/DateTime.cpp -o build/DateTime.o

build/TimeInterval.o: src/eda/TimeInterval.cpp
	@ echo "  src/eda/TimeInterval.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/eda/TimeInterval.cpp -o build/TimeInterval.o

build/Station.o: src/eda/Station.cpp
	@ echo "  src/eda/Station.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/eda/Station.cpp -o build/Station.o

build/Trip.o: src/eda/Trip.cpp
	@ echo "  src/eda/Trip.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/eda/Trip.cpp -o build/Trip.o

build/Service.o: src/eda/Service.cpp
	@ echo "  src/eda/Service.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/eda/Service.cpp -o build/Service.o

build/Reader.o: src/problem/Reader.cpp
	@ echo "  src/problem/Reader.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/problem/Reader.cpp -o build/Reader.o

clean:
	@ clear
	@ echo "Limpiando.."
	@ rm -rf build/*
	@ rm -rf bin/*

run:
	@ clear
	@ ./bin/crewshit.run
	

me: clean main run	
