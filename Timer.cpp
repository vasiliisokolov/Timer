#include <iostream>
#include <ctime>
#include <iomanip>

int main()
{
    std::cout << "Timer!" << std::endl;

    std::time_t t = std::time(nullptr);
    std::tm date = *std::localtime(&t);
    //std::cout << asctime(&date);
    std::cout << "Please, put time (mm/ss): ";
    std::cin >> std::get_time(&date, "%M/%S");

    //std::cout << asctime(&date);
    std::tm fin = *std::localtime(&t);
    fin.tm_min += date.tm_min;
    fin.tm_sec += date.tm_sec;
    std::time_t f = std::mktime(&date);

    std::cout << difftime(t, f) << std::endl;

    while (difftime(t, f) > 0)
    {
        std::time_t d = std::time(nullptr);
        std::tm now = *std::localtime(&t);
        std::cout << std::put_time(&now, "%M/%S") << std::endl;
        t += difftime(t, d);
    }

}

