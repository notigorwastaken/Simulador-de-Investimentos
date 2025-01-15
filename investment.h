#ifndef INVESTMENT_H
#define INVESTMENT_H

class Investment
{
public:
  Investment(double initialAmount, double rate, int years, double monthlyContribution = 0.0);
  double simulateFixedIncome();
  double simulateVariableIncome(double volatility);

private:
  double initialAmount;
  double rate;
  int years;
  double monthlyContribution;
};

#endif