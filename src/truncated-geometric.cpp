#include "truncated-geometric.h"

using namespace TG;

// Class truncated_geometric constructor.
truncated_geometric::truncated_geometric(int size, long double alpha)
{
    std::vector<std::vector<long double>> channel(size + 1, std::vector<long double>(size + 1, 0));

    create_channel(channel, size + 1, alpha);

    try
    {
        truncated_geometric::check_channel(channel, size + 1, alpha);
    }
    catch (const char* err)
    {
        std::cerr << err << std::endl;
    }
}

// Channel updater.
std::vector<std::vector<long double>> truncated_geometric::get_channel(int size, long double alpha)
{
    try
    {
        truncated_geometric::check_parameters(size, alpha);
    }
    catch (const char* err)
    {
        std::cerr << err << std::endl;
    }

    std::vector<std::vector<long double>> channel(size + 1, std::vector<long double>(size + 1, 0));
    
    create_channel(channel, size + 1, alpha);

    try
    {
        truncated_geometric::check_channel(channel, size + 1, alpha);
    }
    catch (const char* err)
    {
        std::cerr << err << std::endl;
    }

    return channel;
}

// Secret domain size.
int size;

// Differential privacy parameters.
long double alpha;

// Create channel.
void truncated_geometric::create_channel(std::vector<std::vector<long double>> &channel, int size, long double alpha)
{
    // Create channel for given parameters.
    int i = 0, j = 0;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (j == 0 || j == size - 1)
            {
                channel[i][j] = (1 / (1 + alpha)) * pow(alpha, abs(i - j));
            }
            else
            {
                channel[i][j] = ((1 - alpha) / (1 + alpha)) * pow(alpha, abs(i - j));
            }
        }
    }
}

// Check channel and differential privacy parameters.
void truncated_geometric::check_parameters(int size, long double alpha)
{
    // Secret domain size must be an integer.
    if (typeid(size) != typeid(int))
    {
        throw "Secret domain size must be an integer.";
    }

    // Secret domain size must be greater than one.
    else if (size < 2)
    {
        throw "Secret must have at least two values.";
    }

    // Alpha must be real.
    else if (typeid(alpha) != typeid(long double))
    {
        throw "Alpha must be numeric.";
    }

    // Alpha must be in range [0,1].
    else if (alpha < 0 || alpha > 1)
    {
        throw "Alpha must be in range [0,1].";
    }
}

// Check resulting channel.
void truncated_geometric::check_channel(std::vector<std::vector<long double>> channel, int size, long double alpha)
{
    // Check channel properties (e.g. each row sums to 1).
    int i = 0, j = 0;
    for (i = 0; i < size; i++)
    {
        long double row = 0;

        for (j = 0; j < size; j++)
        {
            row = row + channel[i][j];
        }

        if (!(fabs(1 - row) < (size - 1) * LDBL_EPSILON * fabs(1 + row)) || !(fabs(1 - row) < LDBL_MIN))
        {
            throw "Channel rows must sum to one.";
        }
    }
}