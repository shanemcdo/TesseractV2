all: main.o  coord.o project.o rotate.o reset.o
	g++ bin/*.o -o bin/test.exe -I include -lopenGL32 -lfreeGLUT 
	@echo

main.o: src/main.cpp
	g++ src/main.cpp -c -o bin/main.o -I include -lopenGL32 -lfreeGLUT 

coord.o: src/coord.cpp
	g++ src/coord.cpp -c -o bin/coord.o -I include -lopenGL32 -lfreeGLUT 
	
project.o: src/project.cpp
	g++ src/project.cpp -c -o bin/project.o -I include -lopenGL32 -lfreeGLUT 

rotate.o: src/rotate.cpp
	g++ src/rotate.cpp -c -o bin/rotate.o -I include -lopenGL32 -lfreeGLUT 

reset.o: src/reset.cpp
	g++ src/reset.cpp -c -o bin/reset.o -I include -lopenGL32 -lfreeGLUT 

clean:
	rm bin/*

new:
	mkdir bin

test: all
	bin/test.exe
