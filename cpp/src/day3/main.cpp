#include "../util/input.h"
#include "wire.h"
#include <iostream>
#include <vector>
#include <string>
#include <climits>


int main(int argc, char** argv) {
    aoc::input_reader reader;

    if(argc == 1) {
        reader.open(argv[0], "day3-example.txt");
    } else {
        reader.open(argv[1]);
    }
    
    if(reader.can_read() == false) {
        std::cerr << "The input file could not be read (" << reader.path() << ")" << std::endl;
        return 1;
    }

    std::vector<aoc::wire> wires;
    std::string input;

    while(reader.read_line(input)) {
        aoc::wire wire(input);
        wires.push_back(wire);
    }

    std::cout << "Closest Intersection: " << wires[0].closest_intersection(wires[1], aoc::point{0, 0}) << std::endl;

    return 0;
}