compile:
	g++ main.cpp personer.cpp person.cpp -o main.out

run: compile
	./main.out

install: compile
	sudo rm /usr/bin/shares
	cp main.out shares
	sudo chmod +x shares
	sudo mv shares /usr/bin