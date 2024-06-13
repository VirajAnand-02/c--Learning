#include <iostream>

double calculateTotalAmount(double principalAmount, double time, double interestRate = 0.5) {
    double totalAmount = principalAmount + (principalAmount * interestRate * time) / 100;
    return totalAmount;
}

int main() {
    double principalAmount, time, interestRate;
    std::cout << "Enter principal amount: ";
    std::cin >> principalAmount;
    
    std::cout << "Enter time (years): ";
    std::cin >> time;
    
    std::cout << "Enter interest rate (percent, optional): ";
    if (std::cin >> interestRate) {
        std::cout << "Total amount: " << calculateTotalAmount(principalAmount, time, interestRate) << std::endl;
    } else {
        std::cout << "Total amount: " << calculateTotalAmount(principalAmount, time) << std::endl;
    }
    
    return 0;
}
