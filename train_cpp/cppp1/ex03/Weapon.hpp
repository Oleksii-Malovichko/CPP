#pragma once

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(const std::string &name);
		~Weapon();
		const std::string &getType() const;
		void setType(const std::string &type);
};

/* 
тут нужна реферная ссылка чтобы не создавать копию строки, так как с длинными
строками это может быть дорого по памяти и производительности

Передавать большие объекты (строки, векторы, пользовательские классы) по const & — 
это экономично и безопасно.

Для маленьких примитивов (int, char, double) такой подход излишен — 
лучше передавать по значению. 

зачем нужен const в конце?
благодаря const в конце мы убираем возможность у ф-ии менять объект
const std::string &Weapon::getType() const {
    return type;  // всё ок
}

void Weapon::changeType() const {
    type = "new type";  // ошибка! нельзя изменять поле
}*/