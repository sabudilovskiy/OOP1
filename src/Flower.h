//
// Created by asus on 09.09.2021.
//
#include "input.h"
#include "windows.h"
#include <iostream>
#ifndef OOP1_FLOWER_H
#define OOP1_FLOWER_H
class Flower {
    std::string species = "";
    std::string name = "";
    int max_day_without_sun;
    int max_day_without_water;
    int last_sunny_day;
    int last_watering;
    bool rotation_to_sun;
public:
    Flower(){

    }
    void read_from_console() {
        SetConsoleCP(1251 );
        SetConsoleOutputCP( 1251  );
        std::cout << "Введите название вида: ";
        std::cin >> species;
        std::cout << "Введите название цветка: ";
        std::cin >> name;
        input(
                this,
                &Flower::setMaxDayWithoutSun,
                my_stoi,
                std::string("Введите максимальное количество дней, в течении которых цветок не умрёт без солнца: "),
                std::string("Допущена ошибка при вводе, повторите ввод: "));
        input(
                this,
                &Flower::setMaxDayWithoutWater,
                my_stoi,
                std::string("Введите максимальное количество дней, в течении которых цветок не умрёт без воды: "),
                std::string("Допущена ошибка при вводе, повторите ввод: "));
        input(
                this,
                &Flower::setLastSunnyDay,
                my_stoi,
                std::string("Введите сколько дней назад цветок был под солнцем. : "),
                std::string("Допущена ошибка при вводе, повторите ввод: "));
        input(
                this,
                &Flower::setLastWatering,
                my_stoi,
                std::string("Введите сколько дней назад цветок был полит : "),
                std::string("Допущена ошибка при вводе, повторите ввод: "));
        input(
                this,
                &Flower::setRotationToSun,
                stob,
                std::string("Повёрнут ли цветок к солнцу? :"),
                std::string("Допущена ошибка при вводе, повторите ввод: "));
    }
    Flower(std::string species, std::string name, int max_day_without_sun, int max_day_without_water, int last_sunny_day, int last_watering, bool rotation_to_sun) {
        setSpecies(species);
        setName(name);
        setMaxDayWithoutSun(max_day_without_sun);
        setMaxDayWithoutWater(max_day_without_water);
        setLastSunnyDay(last_sunny_day);
        setLastWatering(last_watering);
        setRotationToSun(rotation_to_sun);
    }
    std::string getSpecies() {
        return species;
    }
    void setSpecies( std::string species) {
        Flower::species = species;
    }

    std::string getName() {
        return name;
    }

    void setName(const std::string name) {
        Flower::name = name;
    }

    int getMaxDayWithoutSun() {
        return max_day_without_sun;
    }

    void setMaxDayWithoutSun(int maxDayWithoutSun) {
        if (maxDayWithoutSun>=0) max_day_without_sun = maxDayWithoutSun;
        else throw std::invalid_argument("");
    }

    int getMaxDayWithoutWater() {
        return max_day_without_water;
    }

    void setMaxDayWithoutWater(int maxDayWithoutWater) {
        if (maxDayWithoutWater >= 0) max_day_without_water = maxDayWithoutWater;
        else throw std::invalid_argument("");
    }

    int getLastSunnyDay() {
        return last_sunny_day;
    }

    void setLastSunnyDay(int lastSunnyDay) {
        if (lastSunnyDay >= 0) last_sunny_day = lastSunnyDay;
        else throw std::invalid_argument("");
    }

    int getLastWatering() {
        return last_watering;
    }

    void setLastWatering(int lastWatering) {
        if (lastWatering >= 0) last_watering = lastWatering;
        else throw std::invalid_argument("");
    }

    bool isRotationToSun() {
        return rotation_to_sun;
    }
    void setRotationToSun(bool rotationToSun) {
        rotation_to_sun = rotationToSun;
    }

    std::string serialize() {
        std::string temp = "{\n";
        temp += "species: " + species + "\n";
        temp += "name: " + name + "\n";
        temp += "max_day_without_sun: " + std::to_string(max_day_without_sun) + "\n";
        temp += "max_day_without_water: " + std::to_string(max_day_without_water) + "\n";
        temp += "last_sunny_day: " + std::to_string(last_sunny_day) + "\n";
        temp += "last_watering: " + std::to_string(last_watering) + "\n";
        temp += "rotation_to_sun: " + std::to_string(rotation_to_sun) + "\n";
        temp += "}";
        return temp;
    }
    std::string toString(){
        std::string temp = "";
        temp += "Вид: " + species + "\n";
        temp += "Название: " + name + "\n";
        temp += "Может прожить без солнца: " + std::to_string(max_day_without_sun) + "\n";
        temp += "Может прожить без воды: " + std::to_string(max_day_without_water) + "\n";
        temp += "Сколько дней назад видел солнце: " + std::to_string(last_sunny_day) + "\n";
        temp += "Последний полив был дней назад: " + std::to_string(last_watering) + "\n";
        temp += "Повёрнут к солнцу: " + std::to_string(rotation_to_sun) + "\n";
        return temp;
    }
};

#endif //OOP1_FLOWER_H
