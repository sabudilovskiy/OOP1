//
// Created by asus on 10.09.2021.
//

#ifndef OOP1_INPUT_H
#define OOP1_INPUT_H
template<class Tmain, class Tsup>
void input(Tmain* t, void (Tmain::*method)(Tsup), Tsup(*cast_func)(std::string), std::string input, std::string _error)
{
    std::string temp;
    std::cout << input;
    std::cin >> temp;
    bool error = true;
    try {
        (t->*method)(cast_func(temp));
        error = false;
    }
    catch (std::invalid_argument) {
        while (error) {
            std::cout << _error;
            std::cin >> temp;
            try {
                (t->*method)(cast_func(temp));
                error = false;
            }
            catch (std::invalid_argument) {
            }
        }
    }
}

bool stob(std::string input) {
    if (input == "y" || input == "yes" || input == "true" || input == "1" || input == "да") return true;
    else if (input == "n" || input == "no" || input == "false" || input == "0" || input == "нет") return false;
    else throw std::invalid_argument("");
}

int my_stoi(std::string input) { return std::stoi(input); }

#endif //OOP1_INPUT_H
