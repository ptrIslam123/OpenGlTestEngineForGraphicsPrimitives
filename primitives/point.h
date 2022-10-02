#pragma once

namespace util {

template<typename T>
struct BasePoint {
    T x;
    T y;

    BasePoint(): x(T()), y(T()) {}
    BasePoint(const T &x, const T &y): x(x), y(y) {}

    BasePoint &operator+=(const BasePoint &other) {
        x += other.x;
        y += other.y;
        return *this;
    }
};

template<typename T>
BasePoint<T> operator+(BasePoint<T> rhs, const BasePoint<T> &lhs) {
    return rhs += lhs;
}

typedef BasePoint<float> PointF32;

} // namespace util