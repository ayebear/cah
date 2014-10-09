// Copyright (C) 2014 Eric Hebert (ayebear)
// This code is licensed under GPLv3, see LICENSE.txt for details.

#include "cah.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

// These are just defaults, and can be adjusted later
const unsigned CAH::defaultHashSize = 256;
const unsigned CAH::defaultIterations = 100;
const char* CAH::defaultRules = "B13579/S2468";

CAH::CAH(unsigned hashSize, unsigned iterations, const std::string& rules):
    hashSize(hashSize),
    iterations(iterations),
    rules(rules)
{
}

std::string CAH::genHashFromFile(const std::string& filename) const
{
    std::ifstream file(filename.c_str(), std::ios::binary | std::ios::in | std::ios::ate);
    if (file)
    {
        // Create a buffer as large as the file
        std::vector<char> buffer(file.tellg());

        // Read the entire file into the buffer
        file.seekg(0, std::ios::beg);
        file.read(buffer.data(), buffer.size());

        // Generate the hash from the buffer
        return genHash(buffer);
    }
    return "";
}

std::string CAH::genHash(const std::vector<char>& buffer) const
{
    // Each char is holding 1 bit, since we don't want to use the vector bool specialization
    std::vector<char> output(hashSize, 0);
    //std::string output;
    //output.resize(hashSize, '\0');

    // Iterate through the characters from the input data, and generate the hash
    unsigned outBit = 0;
    for (char c: buffer)
    {
        // Extract the bits from the input byte
        for (unsigned bit = 0; bit < 8; ++bit)
        {
            // Just XOR the hash for now
            output[outBit + bit] ^= ((c >> (7 - bit)) & 1);
        }
        (outBit += 8) %= hashSize;
    }

    // Re-join the bits into bytes, and convert to hex
    std::stringstream ss;
    char outByte = 0;
    unsigned count = 0;
    for (char bit: output)
    {
        // Join each bit
        outByte = ((outByte << 1) | (bit & 1));

        // See if we have a full byte
        if (++count % 8 == 0)
        {
            // Convert to hex
            ss << std::hex << std::setfill('0') << std::setw(2) << (int)outByte;
            outByte = 0;
        }
    }

    //return std::string(output.begin(), output.end());
    return ss.str();
}
