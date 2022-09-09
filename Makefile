linux:
	gcc -o ./bin/multiverse ./src/main.c ./src/camera.c ./src/keys.c ./src/objects.c ./src/render.c -lglut -lGLU -lGL -lXext -lX11 -lm -llua5.1
ubuntu-dependencies:
	sudo apt-get install libglfw3
	sudo apt-get install libglfw3-dev
	sudo apt-get install liblua5.1-0-dev
	sudo apt-get install lua-devel
arch-dependencies:
	sudo pacman -S glfw-x11
	sudo pacman -S lua51
test:
	./bin/multiverse ./scripts/main.lua
