
#include "point.hpp"
#include "line.hpp"

#include <cassert>
#include <sstream>

void test_point()
{
    // Test operator==
    {
        const point p1{1, 2};
        const point p2 = p1;
        const point p3{3, 4};

        assert(p1 == p2);
        assert(!(p1 == p3));
    }

    // Test operator!=
    {
        const point p1{1, 2};
        const point p2 = {3, 4};
        const point p3 = p1;

        assert(p1 != p2);
        assert(!(p1 != p3));
    }

    // Test operator+
    {
        const point p1{1, 2};
        const point p2{3, 4};
        const point p3{4, 6};

        assert(p1 + p2 == p3);
    }

    // Test operator-
    {
        const point p1{3, 4};
        const point p2{1, 2};
        const point p3{2, 2};

        assert(p1 - p2 == p3);
    }

    // Test operator+=
    {
        point p1{1, 2};
        const point p2{3, 4};
        const point result{4, 6};

        p1 += p2;

        assert(p1 == result);
    }

    // Test operator-=
    {
        point p1{3, 4};
        const point p2{1, 2};
        const point result{2, 2};

        p1 -= p2;

        assert(p1 == result);
    }

    // Test output streaming
    {
        std::ostringstream ss;
        ss << point{3, 4} << '\n';
        assert(ss.str() == "(3, 4)\n");
    }
}

void test_line()
{
    // Test two-argument constructor
    {
        const point p1{1, 2}, p2{3, 4};
        const line l(p1, p2);
        assert(l.start == p1);
        assert(l.end == p2);
    }

    // Test default constructor
    {
        const line l{};

        assert((l.start == point{0, 0}));
        assert((l.end == point{}));
    }

    // Test length() member
    {
        const line l1{point{}, point{9, 12}};
        assert(l1.length() == 15.0);

        const line l2{point{1, 2}, point{-4, -10}};
        assert(l2.length() == 13.0);

    }
}

int main()
{
    test_point();
    test_line();
}