CAH
===

CAH is a Cellular Automata Hash algorithm. The idea is that some input data could be used to generate a hash by placing the bits in a 2D grid, and simulating some set of rules on the grid. It can generate arbitrarily long hash sizes, with any number of iterations, and any rule set for 2D orthogonal cellular automata. This may not be cryptographically secure, but it seems interesting and I want to see how useful it could be.

Good defaults for these options will be chosen, as well as the default hash size being 512 bits.

This will be implemented as a library for use in other projects, and a command line program will be provided.

Code
----

The code (will be) written in C++, and will most likely not have any dependencies.

Author
------

Eric Hebert
