// Copyright 2022 Dacyto

#include <algorithm>
#include <string>

#include "textgen.h"

Prefix MarkovGenerator::ReadState(std::istream &in, const int npref) {
    std::string in_string;

    Prefix prefix;

    Prefix starting_prefix;

    for (int i = 0; i < npref; i++) {
        in >> in_string;

        prefix.push_back(std::move(in_string));
    }

    starting_prefix = prefix;

    while (in >> in_string) {
        addPrefix(prefix);
        addSuffixToPrefix(prefix, in_string);
        shiftPrefix(prefix, in_string);
    }

    return starting_prefix;
}

void MarkovGenerator::addPrefix(const Prefix& prefix) {
    statetab[prefix];
}

void MarkovGenerator::addSuffixToPrefix(const Prefix& prefix,
                                        const std::string& suffix) {
    addPrefix(prefix);

    std::vector<std::string> &vec = statetab[prefix];

    if (std::find(vec.begin(), vec.end(), suffix) == vec.end()) {
        vec.push_back(suffix);
    }
}

