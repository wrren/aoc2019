#include "../util/input.h"
#include "wire.h"
#include <iostream>
#include <vector>
#include <string>
#include <climits>

int main(int argc, char** argv) {
    aoc::input_reader reader;

    if(argc == 1) {
        reader.open(argv[0], "day3-1.txt");
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

    auto intersections  = wires[0].intersections(wires[1]);
    auto distance       = INT_MAX;
    auto origin         = aoc::point{0, 0};

    std::cout << "Found " << intersections.size() << " Intersection: " << std::endl;

    for(auto intersection: intersections) {
        auto new_distance = intersection.manhattan_distance(origin);

        if(new_distance < distance) {
            distance = new_distance;
        }
    }

    std::cout << "Closest Intersection: " << distance << std::endl;

    return 0;
}