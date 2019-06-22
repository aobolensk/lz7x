#include <iostream>
#include "lz78.h"

int main() {
    std::cout << LZ78::decode(LZ78::encode("test_string")) << std::endl;
    return 0;
}
