#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"



int main()
{
    std::cout << "\n--- Test Animal copy & assignment ---\n";
    Animal a1;
    Animal a2(a1);   // copy constructor
    Animal a3;
    a3 = a1;         // assignment operator

    std::cout << "\n--- Test Dog copy & assignment ---\n";
    Dog d1;
    Dog d2(d1);      // copy constructor
    Dog d3;
    d3 = d1;         // assignment operator
    d1.makeSound();
    d2.makeSound();
    d3.makeSound();

    std::cout << "\n--- Test Cat copy & assignment ---\n";
    Cat c1;
    Cat c2(c1);      // copy constructor
    Cat c3;
    c3 = c1;         // assignment operator
    c1.makeSound();
    c2.makeSound();
    c3.makeSound();

    std::cout << "\n--- Test WrongAnimal copy & assignment ---\n";
    WrongAnimal wa1;
    WrongAnimal wa2(wa1);   // copy constructor
    WrongAnimal wa3;
    wa3 = wa1;              // assignment operator
    wa1.makeSound();
    wa2.makeSound();
    wa3.makeSound();

    std::cout << "\n--- Test WrongCat copy & assignment ---\n";
    WrongCat wc1;
    WrongCat wc2(wc1);      // copy constructor
    WrongCat wc3;
    wc3 = wc1;              // assignment operator
    wc1.makeSound();
    wc2.makeSound();
    wc3.makeSound();

    return 0;
}
// int main()
// {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();

//     std::cout << j->getType() << std::endl;
//     std::cout << i->getType() << std::endl;

//     i->makeSound();
//     j->makeSound();
//     meta->makeSound();

//     delete meta;
//     delete j;
//     delete i;

//     std::cout << "\n------- WrongAnimal test -------" << std::endl;
//     const WrongAnimal* wrongCat = new WrongCat();
//     std::cout << wrongCat->getType() << std::endl;
//     wrongCat->makeSound();
//     delete wrongCat;

//     std::cout << "\n----------- Classic polymorphism -----------\n";
//     Animal* animals[4];

//     animals[0] = new Dog();
//     animals[1] = new Cat();
//     animals[2] = new Dog();
//     animals[3] = new Animal();

//     for (int i = 0; i < 4; i++) {
//         std::cout << animals[i]->getType() << ": ";
//         animals[i]->makeSound();
//     }

//     for (int i = 0; i < 4; i++)
//         delete animals[i];

//     return 0;
// }

/* 
Что нужно поправить, чтобы код полностью соответствовал правилам:

Orthodox Canonical Form (OCF)
В задании написано:

From Module 02 to Module 09, your classes must be designed in the Orthodox Canonical Form.

Это значит, что в каждом классе (Animal, Dog, Cat, WrongAnimal, WrongCat) должны быть:

Конструктор по умолчанию

Конструктор копирования

Оператор присваивания

Деструктор

У тебя сейчас есть только конструктор по умолчанию и деструктор.
→ Нужно дописать copy constructor и operator= (даже если они простые).
 */