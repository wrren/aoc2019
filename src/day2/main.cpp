#include "../util/input.h"
#include <iostream>
#include <vector>

#define OPCODE_ADD          1
#define OPCODE_MULTIPLY     2
#define OPCODE_END_PROGRAM  99

int main(int argc, char** argv) {
  aoc::input_reader reader;

  if(argc == 1) {
      reader.open(argv[0], "day2-1.txt");
  } else {
      reader.open(argv[1]);
  }
  
  if(reader.can_read() == false) {
      std::cerr << "The input file could not be read (" << reader.path() << ")" << std::endl;
      return 1;
  }

  std::vector<int> inputs;
  reader.read(inputs);
  int opcode, position = 0;

  inputs[1] = 12;
  inputs[2] = 2;

  while(position < inputs.size()) {
    opcode = inputs[position];
    if(opcode == OPCODE_END_PROGRAM) {
      break;
    }

    switch(opcode) {
      case OPCODE_ADD:
        inputs[inputs[position+1]] = inputs[position+2] + inputs[position+3];
      break;
      case OPCODE_MULTIPLY:
        inputs[inputs[position+1]] = inputs[position+2] * inputs[position+3];
      break;
    }

    position += 4;
  }

  std::cout << "Position 0: " << inputs[0] << std::endl;

  return 0;
}