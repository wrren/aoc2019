#include "line.h"

bool between(int a, int b, int c) {
    if(b < c) {
        return a >= b && a <= c;
    } else {
        return a >= c && a <= b;
    }
}

namespace aoc {
    line::line(point p1, point p2) :
    m_p1(p1),
    m_p2(p2)
    {}

    line::result line::intersection(const line& other) const {
        if(m_p1.x == m_p2.x) {
            if(other.m_p1.x == other.m_p2.x) {
                return std::nullopt;
            }
            if(between(m_p1.x, other.m_p1.x, other.m_p2.x) && between(other.m_p1.y, m_p1.y, m_p2.y)) {
                if(other.m_p2.x >= m_p1.x) {
                    return result{point{other.m_p2.x - m_p1.x, other.m_p1.y}};
                } else {
                    return result{point{other.m_p1.x - m_p1.x, other.m_p1.y}};
                }
            }
        } else {
            if(other.m_p1.y == other.m_p2.y) {
                return std::nullopt;
            }
            return other.intersection(*this);
        }
        return std::nullopt;
    }
}