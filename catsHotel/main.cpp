//
//  main.cpp
//  catsHotel
//
//  Created by Дмитрий Сергеевич on 14.02.2024.
//

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

// Создаем класс кота с полями: имя, порода, владелец
class Cat {
public:
    Cat(const std::string& name, const std::string& breed, const std::string& owner)
        : name(name), breed(breed), owner(owner) {}

    std::string getName() const { return name; }
    std::string getBreed() const { return breed; }
    std::string getOwner() const { return owner; }

private:
    std::string name;
    std::string breed;
    std::string owner;
};

// Создаем класс гостиницы для котов
class CatHotel {
public:
    CatHotel(int capacity) : capacity(capacity) {}

    // Размещение кота, если есть место
    void checkInCat(const Cat& cat) {
        if (cats.size() < capacity) {
            cats.push_back(cat);
            std::cout << cat.getName() << " поселен в гостиницу для котов." << std::endl;
        } else {
            throw std::runtime_error("Гостиница заполнена. Нельзя разместить больше котов.");
        }
    }

    // Выселение кота
    void checkOutCat(const std::string& catName) {
        for (auto it = cats.begin(); it != cats.end(); ++it) {
            if (it->getName() == catName) {
                cats.erase(it);
                std::cout << catName << " выселен из гостиницы." << std::endl;
                return;
            }
        }
        throw std::runtime_error("Кот не найден в гостинице.");
    }

    // Поиск кота по имени
    void findCat(const std::string& catName) const {
        for (const auto& cat : cats) {
            if (cat.getName() == catName) {
                std::cout << "Кот найден - Имя: " << cat.getName() << " Порода: " << cat.getBreed() << " Владелец: " << cat.getOwner() << std::endl;
                return;
            }
        }
        std::cout << "Кот не найден в гостинице." << std::endl;
    }

private:
    int capacity; // Предельное число котов
    std::vector<Cat> cats; // Вектор для хранения котов в гостинице
};

int main() {
    CatHotel hotel(3); // Создаем объект гостиницы с предельным числом котов 3
    
    // Создаем котов
    Cat cat1("Васька", "Персидский", "Анна");
    Cat cat2("Мурзик", "Сиамский", "Иван");
    Cat cat3("Барсик", "Мейн-кун", "Мария");
    
    try {
        hotel.checkInCat(cat1);
        hotel.checkInCat(cat2);
        hotel.checkInCat(cat3); // Это вызовет исключение, так как гостиница заполнена
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    
    hotel.findCat("Васька"); // Поиск кота
    hotel.checkOutCat("Мурзик"); // Выселение кота
    hotel.findCat("Мурзик"); // А этого кота уже нет в гостинице
    
    return 0;
}
