#include <random>
#include "Utility/RandomNumberGenerator.h"

namespace Utility
{

    RandomNumberGenerator::RandomNumberGenerator(int min, int max)
    : gen(std::random_device{} ()), dist(min, max)
    {

    }

    int RandomNumberGenerator::generate()
    {
        return dist(gen);
    }

} // namespace Utility
