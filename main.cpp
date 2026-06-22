#include <stdlib.h>
#include <ctime>
#include <iostream>

int main(){

    std::cout << "Start of the Black-Schole Option Pricer" << std::endl;
    std::time_t result = std::time(nullptr);
    std::cout << "The date is " << std::ctime(&result);
    
    return 0;
}