#include "point.h"
#include <cmath>

namespace aoc {
    int point::manhattan_distance(point other) {
        return abs(other.x - x) + abs(other.y - y);
    }
}