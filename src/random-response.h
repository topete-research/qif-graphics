#ifndef RANDOM_RESPONSE // include guard
#define RANDOM_RESPONSE

#include <iostream>
#include <typeinfo>
#include <vector>
#include <cfloat>
#include <cmath>

namespace RR
{
    class random_response
    {
        public:
            random_response(int size = 3, long double epsilon = log(2), long double delta = 0);
            std::vector<std::vector<long double>> get_channel(int size, long double epsilon, long double delta);
        
        private:
            // Secret domain size.
            int size;

            // Differential privacy parameters.
            long double epsilon;
            long double delta;

            // Channel probability values.
            long double truthful;
            long double other;

            // Check channel and differential privacy parameters.
            void check_parameters(int size, long double epsilon, long double delta);

            // Check resulting channel.
            void check_channel(std::vector<std::vector<long double>> channel, int size, long double epsilon, long double delta);
    };
}

#endif /* RANDOM_RESPONSE */