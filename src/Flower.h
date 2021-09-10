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
        std::cout << "������� �������� ����: ";
        std::cin >> species;
        std::cout << "������� �������� ������: ";
        std::cin >> name;
        input(
                this,
                &Flower::setMaxDayWithoutSun,
                my_stoi,
                std::string("������� ������������ ���������� ����, � ������� ������� ������ �� ���� ��� ������: "),
                std::string("�������� ������ ��� �����, ��������� ����: "));
        input(
                this,
                &Flower::setMaxDayWithoutWater,
                my_stoi,
                std::string("������� ������������ ���������� ����, � ������� ������� ������ �� ���� ��� ����: "),
                std::string("�������� ������ ��� �����, ��������� ����: "));
        input(
                this,
                &Flower::setLastSunnyDay,
                my_stoi,
                std::string("������� ������� ���� ����� ������ ��� ��� �������. : "),
                std::string("�������� ������ ��� �����, ��������� ����: "));
        input(
                this,
                &Flower::setLastWatering,
                my_stoi,
                std::string("������� ������� ���� ����� ������ ��� ����� : "),
                std::string("�������� ������ ��� �����, ��������� ����: "));
        input(
                this,
                &Flower::setRotationToSun,
                stob,
                std::string("������� �� ������ � ������? :"),
                std::string("�������� ������ ��� �����, ��������� ����: "));
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
        temp += "���: " + species + "\n";
        temp += "��������: " + name + "\n";
        temp += "����� ������� ��� ������: " + std::to_string(max_day_without_sun) + "\n";
        temp += "����� ������� ��� ����: " + std::to_string(max_day_without_water) + "\n";
        temp += "������� ���� ����� ����� ������: " + std::to_string(last_sunny_day) + "\n";
        temp += "��������� ����� ��� ���� �����: " + std::to_string(last_watering) + "\n";
        temp += "������� � ������: " + std::to_string(rotation_to_sun) + "\n";
        return temp;
    }
};

#endif //OOP1_FLOWER_H
