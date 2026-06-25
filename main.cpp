#include <stdlib.h>
#include <chrono>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>


time_t parseDateTime(const std::string& datetimeString, const std::string& format){
    std::tm tmStruct {

    };

    std::istringstream ss(datetimeString);
    
    ss >> std::get_time(&tmStruct, format.c_str());

    return mktime(&tmStruct);

}

//Util function to determine if the year is a leap year
bool is_leap_year(int year){

    bool leap_year=false;

    if ((year%4 == 0 && year%100 !=0) || (year%400==0) ){
        leap_year=true;
    }

    return leap_year;

}


//Util function to calculate seconds in a year
double seconds_in_year(std::time_t t_diff, std::time_t t_now){

    //epoch time to calendar time
    const tm* tmPtr = std::gmtime(&t_now);
    int year = tmPtr->tm_year+1900;


    
    long long s_in_y; //seconds in a year 
    long long s_in_m_short,s_in_m_long, s_in_m_leap, s_in_m_feb_leap,s_in_m_feb; //seconds for different months

    s_in_m_short=60*60*24*30;
    s_in_m_long=60*60*24*31;
    s_in_m_feb_leap=60*60*24*29;
    s_in_m_feb=60*60*24*28;

    //check if its a leap year
    if(is_leap_year(year)){
        s_in_y=s_in_m_short*4+s_in_m_feb_leap+s_in_m_long*7;
    }else{
        s_in_y=s_in_m_short*4+s_in_m_feb+s_in_m_long*7;
    };

    return double(t_diff)/s_in_y;
}




int main(){

    std::cout << "Start of the Black-Schole Option Pricer" << std::endl;

    std::time_t result = std::time(nullptr);

    std::cout << "The date is " << std::ctime(&result);

    time_t parsedTime = parseDateTime("15/09/2026","%d/%m/%Y");

    std::cout << parsedTime << std::endl;

    std::cout << result << std::endl;

    std::cout << parsedTime -result << std::endl;

    double test=seconds_in_year((parsedTime -result), result);

    std::cout << test << std::endl;



    return 0;
}