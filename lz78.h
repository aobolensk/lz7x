#include <vector>
#include <string>

namespace LZ78 {
    struct Node {
        int pos;
        char next;
    };

    std::vector <Node> encode(const std::string &s);
    std::string decode(const std::vector <Node> &nodes);
}
