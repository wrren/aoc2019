#include "point.h"
#include <optional>

namespace aoc {
    class line {
    public:

        typedef std::optional<point> result;

        line(point p1, point p2);

        result intersection(const line& other) const;

    private:

        point m_p1;
        point m_p2;
    };
}