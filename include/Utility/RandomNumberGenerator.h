#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

#include <random>

namespace Utility
{

    class RandomNumberGenerator 
    {
        private:
            std::mt19937 gen;
            std::uniform_int_distribution<int> dist; 

        public:
            RandomNumberGenerator(int min, int max);

            int generate();
    };

} // namespace Utility

#endif // RANDOMNUMBERGENERATOR_H
