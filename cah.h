// Copyright (C) 2014 Eric Hebert (ayebear)
// This code is licensed under GPLv3, see LICENSE.txt for details.

#ifndef CAH_H
#define CAH_H

#include <vector>
#include <string>

/*
This class contains the Cellular Automata Hash algorithm.

Example usage:
    CAH cah(1024, 500); // Will generate 1024-bit hashes with 500 iterations
    cout << cah.genHash("Hello!") << endl;

Possible options:
    Hash size
        This depends on the grid size; will need to be a perfect square: 64, 256, 1024
        Note: This wouldn't have to be a perfect square if you could specify width/length of grid.
    Iterations
    Rule set
*/
class CAH
{
    public:
        static const unsigned defaultHashSize;
        static const unsigned defaultIterations;
        static const char* defaultRules;

        // Can set all of the options in the constructor
        CAH(unsigned hashSize = defaultHashSize, unsigned iterations = defaultIterations, const std::string& rules = defaultRules);

        // Generates a hash from a vector of chars
        std::string genHash(const std::vector<char>& buffer) const;

        // Generates a hash from a filename
        std::string genHashFromFile(const std::string& filename) const;

    private:
        unsigned hashSize;
        unsigned iterations;
        std::string rules;
};

#endif
