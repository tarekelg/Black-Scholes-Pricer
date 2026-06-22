#include <ctime>
#include <string>
#include <iostream>

class BSMOptionPricer{

    public:
    BSMOptionPricer();

    int setTimeToMaturity(std::string);

    private:
    //Variables in the Black-Scholes Modell   
    //Achtung: I have to change to another datatype as doubles can create rounding errors 
        double C; //Call option price
        double S; //Current stock (or other underlying) price
        double K; //Strike price
        double r; //Risk-free interest rate
        double t; //Time to maturity

    
    ~BSMOptionPricer();


};