#include "vect2.hpp"
#include <iostream>
#include <ostream>

int main()
{
    // Default constructor
    vect2 v1;
    std::cout << "v1 (default constructed) = " << v1 << "\n\n";

    // Parameterized constructor
    vect2 v2(2, 3);
    vect2 v3(4, 5);

    std::cout << "v2 = " << v2 << "\n";
    std::cout << "v3 = " << v3 << "\n\n";

    // Copy constructor
    vect2 v4(v2);
    std::cout << "v4 (copy of v2) = " << v4 << "\n\n";

    // +
    std::cout << "v2 + v3 = " << (v2 + v3) << "\n";

    // +=
    vect2 temp = v2;
    temp += v3;
    std::cout << "temp = v2; temp += v3 -> " << temp << "\n";

    // prefix ++
    temp = v2;
    std::cout << "++temp = " << ++temp << "\n";

    // postfix ++
    temp = v2;
    std::cout << "temp++ = " << temp++ << " (after: " << temp << ")\n\n";

    // -
    std::cout << "v2 - v3 = " << (v2 - v3) << "\n";

    // -=
    temp = v2;
    temp -= v3;
    std::cout << "temp = v2; temp -= v3 -> " << temp << "\n";

    // prefix --
    temp = v2;
    std::cout << "--temp = " << --temp << "\n";

    // postfix --
    temp = v2;
    std::cout << "temp-- = " << temp-- << " (after: " << temp << ")\n\n";

    // *
    std::cout << "v2 * 3 = " << (v2 * 3) << "\n\n";

    // *=
    temp = v2;
    temp *= 3;
    std::cout << "temp = v2; temp *= 3 -> " << temp << "\n\n";

    // []
    std::cout << "v2[0] = " << v2[0] << "\n";
    std::cout << "v2[1] = " << v2[1] << "\n";




    return 0;
}
