#include <iostream>
#include "factory_vegan.hpp"
#include "factory_wild.hpp"

int main(int argc, char** argv) {
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "              ABSTRACT FACTORY PATTERN" << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "The abstract factory pattern provides a way to encapsulate a group\\
    \n\rof individual factories that have a common theme without specifying\\
    \n\rtheir concrete classes." << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    

    while(true) {
        std::cout << "\n 1. Vegan\n 2. Wild\n 2. Exit" << std::endl;
        int option;

        std::cin >> option;
        if (option == 3)
            break;
        else if (option == 2 || option == 1) {
            FactoryAnimal *animal_factory = NULL;
            std::string name;

            if (option == 1) {
                animal_factory = new FactoryVegan();
                std::cout << "Enter [Cow, Rabbit] selection? ";
            }
            else if(option == 2) {
                animal_factory = new FactoryWild();
                std::cout << "Enter [Tiger] selection? ";
            }
            
            std::cin >> name;
            Animal *new_animal = animal_factory->create_animal(name);
            if (new_animal) {
                new_animal->which_animal();
                Food *new_food = animal_factory->create_food(name);
                new_animal->feed_food(new_food);
            }
            else
                std::cout << "We cannot create!..." << std::endl;
        }
    }

    return 0;
}