#include "../util/input.h"
#include <iostream>
#include <vector>

#define OPCODE_ADD          1
#define OPCODE_MULTIPLY     2
#define OPCODE_END_PROGRAM  99

bool run_program(std::vector<int>& inputs) {
  int position = 0;

  while(position < inputs.size()) {
    switch(inputs[position]) {
      case OPCODE_END_PROGRAM:
        return true;
      case OPCODE_ADD:
        inputs[inputs[position+3]] = inputs[inputs[position+1]] + inputs[inputs[position+2]];
      break;
      case OPCODE_MULTIPLY:
        inputs[inputs[position+3]] = inputs[inputs[position+1]] * inputs[inputs[position+2]];
      break;
      default:
        std::cerr << "Unrecognized OpCode: " << inputs[position] << std::endl;
        return false;
    }
    position += 4;
  }

  return true;
}

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

  std::vector<int> original, inputs;
  reader.read(original, ',');

  inputs = original;
  inputs[1] = 12;
  inputs[2] = 2;

  if(run_program(inputs)) { 
    std::cout << "Position 0: " << inputs[0] << std::endl;
  }


  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      inputs = original;
      inputs[1] = i;
      inputs[2] = j;
      run_program(inputs);
      if(inputs[0] == 19690720) {
        std::cout << "Noun: " << i << ", Verb: " << j << std::endl;
        std::cout << "Result: " << (100 * i) + j << std::endl;
        return 0;
      }
    }
  }

  return 0;
}