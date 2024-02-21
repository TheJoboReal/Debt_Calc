compile:
	g++ main.cpp personer.cpp person.cpp -o shares.out

win:
	x86_64-w64-mingw32-g++ main.cpp person.cpp personer.cpp -o shares.exe

run: compile
	./shares.out

install: compile
	sudo rm /usr/bin/shares
	cp shares.out shares
	sudo chmod +x shares
	sudo mv shares /usr/bin