#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "lz78.h"

std::vector <LZ78::Node> LZ78::encode(const std::string &s) {
    std::string buffer;
    std::map <std::string, int> dict;
    std::vector <LZ78::Node> result;
    for (size_t i = 0; i < s.size(); ++i) {
        if (dict.find(buffer + s[i]) != dict.end()) {
            buffer += s[i];
        } else {
            result.push_back({buffer != "" ? dict[buffer] : 0, s[i]});
            dict[buffer + s[i]] = dict.size() + 1;
            buffer = "";
        }
    }
    if (dict.find(buffer) != dict.end()) {
        result.push_back({buffer != "" ? dict[buffer] : 0, '\0'});
    }
    return result;
}

std::string LZ78::decode(const std::vector <LZ78::Node> &nodes) {
    std::vector <std::string> dict = {""};
    std::string result;
    for (const LZ78::Node &node : nodes) {
        std::string word = dict[node.pos];
        if (node.next)
            word.push_back(node.next);
        result += word;
        dict.push_back(word);
    }
    return result;
}
