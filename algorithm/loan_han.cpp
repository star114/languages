#include <iostream>
#include <vector>
#include <iomanip> 

bool checkRepayment(double principle, int month, double interest, double repayment)
{
    double remaining = principle;
    double realInterest = (1.0 + (interest / 100.0) / 12.0);
    for ( int i = 0; i < month; ++i)
    {
        remaining *= realInterest;
        remaining -= repayment;
        if ( remaining <= 0.0)
            return true;
    }
    return false;
}

double calculate(double principle, int month, double interest)
{
    double lowRepay = 0;
    double highRepay = principle;
    while(true)
    {
        double middleRepay  = (lowRepay + highRepay) / 2.0;
        if (checkRepayment(principle, month, interest, middleRepay))
            highRepay = middleRepay;
        else
            lowRepay = middleRepay;
        if ( (highRepay - lowRepay) < 0.00000005)
            return highRepay;
    }
}

int main(int argc, char** argv)
{
    int numTests = 0;
    std::vector<int> numPoly;

    std::cin >> numTests;
    for (int test = 0; test < numTests; ++test)
    {
        double principle = 0.0;
        std::cin >> principle;
        int month = 0;
        std::cin >> month;
        double interest = 0.0;
        std::cin >> interest;

        double repayment = calculate(principle, month, interest);
        std::cout << std::setprecision(10);
        std::cout << std::setiosflags(std::ios::fixed);
        std::cout << repayment << std::endl;
    }
    return 0;
}
