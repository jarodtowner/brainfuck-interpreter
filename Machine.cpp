#ifndef MACHINE
#define MACHINE

#include <iomanip>
#include <iostream>
#include <string>

class Machine {
 private:
	uint8_t tape[TAPE_LENGTH];
	int pointer;
	int highestMemoryAccessed;

 public:
	Machine();
	void movePointerRight();
	void movePointerLeft();
	uint8_t getCell();
	void setCell(char);
	void incrementCell();
	void decrementCell();
	void printMemoryDump();
	~Machine();
};

Machine::Machine() {
	pointer = 0;
	highestMemoryAccessed = 0;
	for (int i = 0; i < TAPE_LENGTH; i++) {
		tape[i] = 0;
	}
}

void Machine::movePointerRight() {
	pointer = (pointer + 1);
	if (pointer > highestMemoryAccessed) {
		highestMemoryAccessed = pointer;
	}
	if (pointer > TAPE_LENGTH) {
		throw "Out of Bounds";
	}
}

void Machine::movePointerLeft() {
	pointer = (pointer - 1);
	if (pointer < 0) {
		throw "Out of Bounds";
	}
}

uint8_t Machine::getCell() { return tape[pointer]; }

void Machine::setCell(char value) { tape[pointer] = (uint8_t)value; }

void Machine::incrementCell() { tape[pointer]++; }

void Machine::decrementCell() { tape[pointer]--; }

void Machine::printMemoryDump() {
	printf("\nPointer: %04x", pointer);
	for (int i = 0; i <= highestMemoryAccessed; i++) {
		printf("\n%04x: %02x", i, (int)tape[i]);
	}
	std::cout << std::endl;
}

Machine::~Machine() {}

#endif