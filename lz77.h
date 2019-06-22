#include <vector>
#include <string>

namespace LZ77 {
    struct Node {
        int offset, length;
        char next;
    };

    std::vector <Node> encode(const std::string &s, size_t buf_size);
    std::string decode(const std::vector <Node> &nodes);
}
