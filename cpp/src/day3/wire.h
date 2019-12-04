#include "line.h"
#include <vector>
#include <string>

namespace aoc {
    class wire {
    public:

        wire(const std::string& input);

        void add_line(const line& line);

        std::vector<point> intersections(const wire& other) const;

        int closest_intersection(const wire& other, point origin) const;

    private:

        std::vector<line> m_lines;
    };
}