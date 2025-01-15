#include "investment.h"
#include <cmath>
#include <random>

Investment::Investment(double initialAmount, double rate, int years, double monthlyContribution)
    : initialAmount(initialAmount), rate(rate), years(years), monthlyContribution(monthlyContribution) {}

double Investment::simulateFixedIncome()
{
    double total = initialAmount;
    for (int i = 0; i < years * 12; ++i)
    {
        total += monthlyContribution;
        total *= (1 + rate / 100 / 12);
    }
    return total;
}

double Investment::simulateVariableIncome(double volatility)
{
    double total = initialAmount;
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(rate, volatility);

    for (int i = 0; i < years * 12; ++i)
    {
        total += monthlyContribution;
        double monthlyRate = distribution(generator);
        total *= (1 + monthlyRate / 100 / 12);
    }
    return total;
}