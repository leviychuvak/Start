#include "Point.h"

std::ostream &operator<<(std::ostream &out, const Point &p) {
    out << "Point(" << p.x << ", " << p.y << ", " << p.z << ")";
    return out;
}
