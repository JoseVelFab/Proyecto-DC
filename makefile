SFML := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

bin/hello : src/hello.cpp
	g++ -o bin/hello src/hello.cpp $(SFML)

run : bin/hello
	bin/hello
