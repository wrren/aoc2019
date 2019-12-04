#include "wire.h"
#include <sstream>
#include <string>
#include <iostream>
#include <climits>

namespace aoc {
    wire::wire(const std::string& input) {
        std::string token;
        point p1{0, 0};
        point p2{0, 0};
        std::istringstream stream(input);
        while(std::getline(stream, token, ',')) {
            const char direction    = token[0];
            const int distance      = atoi(token.substr(1).c_str());
            switch(direction) {
                case 'R': p2.x = p1.x + distance; break;
                case 'U': p2.y = p1.y + distance; break;
                case 'L': p2.x = p1.x - distance; break;
                case 'D': p2.y = p1.y - distance; break;
            }
            m_lines.push_back(line(p1, p2));

            p1 = p2;
        }
    }

    void wire::add_line(const line& line) {
        m_lines.push_back(line);
    }

    std::vector<point> wire::intersections(const wire& other) const {
        std::vector<point> intersections;

        for(auto l1 : m_lines) {
            for(auto l2: other.m_lines) {
                auto result = l1.intersection(l2);
                if(result) {
                    intersections.push_back(*result);
                }
            }
        }

        return intersections;
    }

    int wire::closest_intersection(const wire& other, point origin) const {
        int distance = INT_MAX;

        for(auto l1 : m_lines) {
            for(auto l2: other.m_lines) {
                auto result = l1.intersection(l2);
                if(result) {
                    int new_distance = result->manhattan_distance(origin);
                    if(new_distance < distance) {
                        distance = new_distance;
                    }
                }
            }
        }

        return distance;
    }
}