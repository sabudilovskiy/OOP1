#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include "src/Flower.h"

 class ConsoleFile{
    int current_command;
 public:
     int getCurrentCommand() const {
         return current_command;
     }
     void setCurrentCommand(int currentCommand)  {
         if (currentCommand <= 2) current_command = currentCommand;
         else throw std::invalid_argument("");
     }
 } ;

 class ConsoleFlower{
    int current_command;
public:
    int getCurrentCommand() const {
        return current_command;
    }
    void setCurrentCommand(int currentCommand) {
        if (currentCommand <= 8) current_command = currentCommand;
        else throw std::invalid_argument("");
    }
} ;


int main() {
    SetConsoleCP(1251 );
    SetConsoleOutputCP( 1251  );
    std::string choice_file_message = "Выберите дальнейшее действие. 0 : выйти из программы, 1 : открыть старый файл, 2 : создать новый - ";
    std::string error_message = "Допущена ошибка при вводе, повторите ввод: ";
    std::string choice_flower_message = "Выберите команду.\n 0) закончить работу с объектом \n 1) изменить название \n 2: изменить имя\n 3) изменить максимальное количество дней без солнца\n 4) изменить максимальное количество дней без воды\n 5) изменить количество дней, когда цветок получал солнечные лучи\n 6) изменить количество дней, когда цветок поливали \n 7) изменить поворот цветка к солнцу \n 8) Вывести данные в консоль :";
    ConsoleFile consoleFile = ConsoleFile();
    input(&consoleFile,
          &ConsoleFile::setCurrentCommand,
          my_stoi,
          choice_file_message,
          error_message
    );
    while (consoleFile.getCurrentCommand() != 0){
        switch (consoleFile.getCurrentCommand()) {
            case 1: {
                std::string src = "";
                std::cout << "Введите название файла: ";
                std::cin >> src;
                std::ifstream old_file = std::ifstream(src);
                if (old_file.is_open()) {
                    std::vector<std::string> arr_str_from_file;
                    arr_str_from_file.resize(9);
                    int i = 0;
                    while (i < 9 && !old_file.eof()) {
                        getline(old_file, arr_str_from_file[i]);
                        i++;
                    }
                    if (i == 9 && old_file.eof()) {
                        bool check_struct = false;
                        try {
                            check_struct = (arr_str_from_file[0] == "{" &&
                                            arr_str_from_file[1].substr(0, 9) == "species: " &&
                                            arr_str_from_file[2].substr(0, 6) == "name: " &&
                                            arr_str_from_file[3].substr(0, 21) == "max_day_without_sun: " &&
                                            arr_str_from_file[4].substr(0, 23) == "max_day_without_water: " &&
                                            arr_str_from_file[5].substr(0, 16) == "last_sunny_day: " &&
                                            arr_str_from_file[6].substr(0, 15) == "last_watering: " &&
                                            arr_str_from_file[7].substr(0, 17) == "rotation_to_sun: " &&
                                            arr_str_from_file[8] == "}"
                            );
                        }
                        catch (std::invalid_argument) {}
                        catch (std::out_of_range) {}
                        if (check_struct) {
                            Flower *flower = nullptr;
                            try {
                                 flower = new Flower(Flower(
                                        arr_str_from_file[1].substr(9),
                                        arr_str_from_file[2].substr(6),
                                        my_stoi(arr_str_from_file[3].substr(21)),
                                        my_stoi(arr_str_from_file[4].substr(23)),
                                        my_stoi(arr_str_from_file[5].substr(16)),
                                        my_stoi(arr_str_from_file[6].substr(15)),
                                        stob(arr_str_from_file[7].substr(17))
                                ));
                            }
                            catch (std::invalid_argument) {}
                            catch (std::out_of_range) {}
                            if (flower != nullptr) {
                                ConsoleFlower consoleFlower;
                                input(&consoleFlower,
                                      &ConsoleFlower::setCurrentCommand,
                                      my_stoi,
                                      choice_flower_message,
                                      error_message
                                );
                                while (consoleFlower.getCurrentCommand() != 0) {
                                    switch (consoleFlower.getCurrentCommand()) {
                                        case 1: {
                                            std::cout << "Введите название цветка: ";
                                            std::string temp;
                                            std::cin >> temp;
                                            flower->setSpecies(temp);
                                        }
                                            break;
                                        case 2: {
                                            std::string temp;
                                            std::cout << "Введите название цветка: ";
                                            std::cin >> temp;
                                            flower->setName(temp);
                                        }
                                            break;
                                        case 3: {
                                            input(
                                                    flower,
                                                    &Flower::setMaxDayWithoutSun,
                                                    my_stoi,
                                                    std::string(
                                                            "Введите максимальное количество дней, в течении которых цветок не умрёт без солнца: "),
                                                    std::string("Допущена ошибка при вводе, повторите ввод: "));
                                        }
                                            break;
                                        case 4: {
                                            input(
                                                    flower,
                                                    &Flower::setMaxDayWithoutWater,
                                                    my_stoi,
                                                    std::string(
                                                            "Введите максимальное количество дней, в течении которых цветок не умрёт без воды: "),
                                                    std::string("Допущена ошибка при вводе, повторите ввод: "));
                                        }
                                            break;
                                        case 5: {
                                            input(
                                                    flower,
                                                    &Flower::setLastSunnyDay,
                                                    my_stoi,
                                                    std::string(
                                                            "Введите сколько дней назад цветок был под солнцем. : "),
                                                    std::string("Допущена ошибка при вводе, повторите ввод: "));
                                        }
                                            break;
                                        case 6: {
                                            input(
                                                    flower,
                                                    &Flower::setLastWatering,
                                                    my_stoi,
                                                    std::string("Введите сколько дней назад цветок был полит : "),
                                                    std::string("Допущена ошибка при вводе, повторите ввод: "));
                                        }
                                            break;
                                        case 7: {
                                            input(
                                                    flower,
                                                    &Flower::setRotationToSun,
                                                    stob,
                                                    std::string("Повёрнут ли цветок к солнцу? :"),
                                                    std::string("Допущена ошибка при вводе, повторите ввод: "));
                                        }
                                        case 8:
                                        {
                                            std::cout << flower->toString();
                                        }
                                        break;
                                    }
                                    input(&consoleFlower,
                                          &ConsoleFlower::setCurrentCommand,
                                          my_stoi,
                                          choice_flower_message,
                                          error_message
                                    );
                                }
                                old_file.close();
                                std::ofstream rewrite = std::ofstream(src);
                                rewrite << flower->serialize();
                            } else {
                                std::cout << "Объект повреждён. \n";
                            }
                        }
                    } else {
                        std::cout << "Файл повреждён. \n";
                    }
                } else {
                    std::cout << "Файл не найден или нет прав доступа к нему. \n";
                }
            }
            break;
            case 2: {
                std::string src = "";
                std::cout << "Введите название файла: ";
                std::cin >> src;
                std::ofstream newfile = std::ofstream (src);
                if (newfile.is_open()){
                    Flower flower = Flower();
                    flower.read_from_console();
                    newfile << flower.serialize();
                }
                else {
                    std::cout<< "Нет доступа к файлу.";
                }
            }
        }
        input(&consoleFile,
              &ConsoleFile::setCurrentCommand,
              my_stoi,
              choice_file_message,
              error_message);
    }

}
