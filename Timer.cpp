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

    int distance = date.tm_min*60 + date.tm_sec;
    /*std::cout << asctime(&date);
    std::tm fin = *std::localtime(&t);
    fin.tm_min += date.tm_min;
    fin.tm_sec += date.tm_sec;
    std::time_t f = std::mktime(&date);

    std::cout << difftime(t, f) << std::endl;*/

    while (true) 
    {
        
        std::time_t d = std::time(nullptr);
        //std::cout << (int)difftime(d, t) / 60 << std::endl;
        //std::cout << (int)difftime(d, t) % 60 << std::endl;
        if ((int)difftime(d, t) > distance) break;
        std::tm now = *std::localtime(&d);
        if ((date.tm_sec - (int)difftime(d, t) % 60) < 0)
        {
            now.tm_min = (date.tm_min - (int)difftime(d, t) / 60);
            now.tm_sec = 60 + (date.tm_sec - (int)difftime(d, t) % 60);
        }
        else
        {
            now.tm_min = date.tm_min - (int)difftime(d, t) / 60;
            now.tm_sec = date.tm_sec - (int)difftime(d, t) % 60;
        }
        
        std::cout << std::put_time(&now, "%M/%S") << std::endl;
        
    }
    std::cout << "Ding, ding, ding!" << std::endl;
}

