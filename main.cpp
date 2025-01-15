#include <iostream>
#include "investment.h"

int main()
{
    double initialAmount, rate, monthlyContribution;
    int years;
    char investmentType;

    std::cout << "Simulador de Investimentos\n";
    std::cout << "Digite o valor inicial: ";
    std::cin >> initialAmount;
    std::cout << "Digite a taxa de retorno anual (%): ";
    std::cin >> rate;
    std::cout << "Digite a contribuição mensal: ";
    std::cin >> monthlyContribution;
    std::cout << "Digite o período de investimento (anos): ";
    std::cin >> years;

    std::cout << "Selecione o tipo de investimento (F para Fixo, V para Variável): ";
    std::cin >> investmentType;

    Investment investment(initialAmount, rate, years, monthlyContribution);

    if (investmentType == 'F' || investmentType == 'f')
    {
        double finalAmount = investment.simulateFixedIncome();
        std::cout << "Valor final do investimento: R$ " << finalAmount << std::endl;
    }
    else if (investmentType == 'V' || investmentType == 'v')
    {
        double volatility;
        std::cout << "Digite a volatilidade (%): ";
        std::cin >> volatility;
        double finalAmount = investment.simulateVariableIncome(volatility);
        std::cout << "Valor final do investimento: R$ " << finalAmount << std::endl;
    }
    else
    {
        std::cout << "Opção inválida!" << std::endl;
    }

    return 0;
}