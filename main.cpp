// Copyright (C) 2014 Eric Hebert (ayebear)
// This code is licensed under GPLv3, see LICENSE.txt for details.

#include <iostream>
#include <string>
#include "cah.h"

int main(int argc, char* argv[])
{
    // TODO: Parse options by using a map
    if (argc < 2)
    {
        // Print usage
        std::cout << "CAH - Cellular Automata Hash - v1.0.0\n";
        std::cout << "Usage: ./cahsum filename [options]\n";
        std::cout << "Options:\n-size Size in bits of output hash; default is " << CAH::defaultHashSize << "\n";
        std::cout << "-iterations Number of iterations; default is " << CAH::defaultIterations << "\n";
        std::cout << "-rules Rule string; default is \"" << CAH::defaultRules << "\"\n";
    }
    else
    {
        // Using defaults for now
        CAH caHash;

        // Generate and display the hash from the specified file
        std::cout << caHash.genHashFromFile(argv[1]) << "\n";
    }
    return 0;
}
