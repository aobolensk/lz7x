#include <iostream>
#include "lz77.h"
#include "lz78.h"

int main() {
    std::cout << LZ77::decode(LZ77::encode("abacabacabadaca", 5)) << std::endl;
    return 0;
}
