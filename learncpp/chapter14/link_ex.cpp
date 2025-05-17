#include <iostream>
#include <string>

/* 
Здесь показано различие по стоимости компьютера в выводе значений */

// Пример "дорогостоящего вывода (m_name в getName)"
class Employee
{
	std::string m_name;

	public:
		void		setName(std::string name) { m_name = name; }
		std::string getName() const { return m_name; }
};

// Пример использования ссылки, вместо создания новой строки (обе ф-ии идентичны)
class Employee2
{
	std::string m_name;
	public:
		void	setName(std::string name) {m_name = name; }
		const std::string &getName() const { return m_name; }
};

int main()
{
	Employee2 joe;
	joe.setName("Joe");
	std::cout << joe.getName() << std::endl;
}