#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include "lz77.h"

std::vector <LZ77::Node> LZ77::encode(const std::string &s, size_t buf_size) {
    std::vector <LZ77::Node> result;
    size_t buf_pos = 0;
    static auto find_matching = [&s, buf_size](int buf_pos) -> std::pair <int, int> {
        std::pair <int, int> result = {0, 0};
        std::string buffer;
        buffer.resize(buf_size);
        for (int i = 0; i < buf_size; ++i)
            buffer[i] = 0;
        int j = buf_size - 1;
        for (int i = buf_pos - 1; i >= 0; --i) {
            buffer[j--] = s[i];
            if (j < 0)
                break;
        }
        int cnt = buf_size - 1;
        while (buffer[0] == 0) {
            for (int i = 0; i < buf_size - 1; ++i) {
                buffer[i] = buffer[i + 1];
            }
            buffer[cnt--] = 0;
            if (cnt == 0)
                break;
        }
        for (int i = 0; i < buf_size; ++i)
            std::cout << (buffer[i] ? buffer[i] : '_');
        std::cout << std::endl;
        int buf_len = strlen(&buffer[0]);
        for (int len = 1; len + buf_pos <= (int)s.size(); ++len) {
            bool flag = false;
            for (int j = 0; j < buf_len; ++j) {
                int i = 0;
                if (buffer[j] == s[buf_pos + i]) {
                    int start = j;
                    bool good = true;
                    while (true) {
                        if (i == len)
                            break;
                        if (buffer[j] != s[buf_pos + i]) {
                            good = false;
                            break;
                        }
                        ++i;
                        j = (j + 1) % buf_len;
                    }
                    j = start;
                    if (good) {
                        result = {buf_len - start, len};
                        flag = true;
                    }
                }
            }
            if (!flag)
                break;
        }
        return result;
    };
    while (buf_pos < s.size()) {
        std::pair <int, int> p = find_matching(buf_pos);
        buf_pos += p.second + 1;
        result.push_back({p.first, p.second, s[buf_pos - 1]});
    }
    return result;
}

std::string LZ77::decode(const std::vector <LZ77::Node> &nodes) {
    std::string result;
    for (const LZ77::Node &node : nodes) {
        if (node.length > 0) {
            int start = (int)result.size() - node.offset;
            for (int i = 0; i < node.length; ++i) {
                result += result[start + i];
            }
        }
        result += node.next;
    }
    return result;
}
