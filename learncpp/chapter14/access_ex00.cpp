#include <iostream>
#include <string>

class Person
{
	private:
		std::string m_name;
	public:
		void	kisses(const Person *p)
		{
			if (!p || p->m_name.empty())
				return ;
			std::cout << m_name << " kisses " << p->m_name << std::endl;
		}
		void	setName(std::string name)
		{
			m_name = name;
		}
};

int main()
{
	Person alex;
	alex.setName("Alex");

	Person kate;
	kate.setName("Kate");

	alex.kisses(&kate);
}