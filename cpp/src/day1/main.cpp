#include "../util/input.h"
#include <iostream>
#include <cmath>

int fuel_required(int mass, bool include_fuel_mass = false, int total = 0) {
    if(mass <= 6) {
        return total;
    }
    if(include_fuel_mass) {
        int fuel = floor(mass / 3) - 2;
        return fuel_required(fuel, true, total + fuel);
    }
    return floor(mass / 3) - 2;
}

int main(int argc, char** argv) {
    aoc::input_reader reader;

    if(argc == 1) {
        reader.open(argv[0], "day1-1.txt");
    } else {
        reader.open(argv[1]);
    }
    
    if(reader.can_read() == false) {
        std::cerr << "The input file could not be read (" << reader.path() << ")" << std::endl;
        return 1;
    }

    int val = 0;
    int sum = 0;
    int sum_with_fuel_mass = 0;
    while(reader.read(val)) {
        sum += fuel_required(val);
        sum_with_fuel_mass += fuel_required(val, true);
    }

    std::cout << "Required Fuel for Modules: " << sum << std::endl;
    std::cout << "Required Fuel Total: " << sum_with_fuel_mass << std::endl;
    
    return 0;
}