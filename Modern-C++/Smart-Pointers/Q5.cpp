#include <iostream>
#include <memory> // for std::shared_ptr
#include <string>

using namespace std;

class Person
{
    private:

	std::string m_name;
	std::shared_ptr<Person> m_partner; // initially created empty
    
    public:

	Person(const std::string &name): m_name(name)
	{
		std::cout << m_name << " created\n";
	}
	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
        {
            return false;
        }

		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';

		return true;
	}
};

int main()
{
	std :: shared_ptr<Person> lucy { std::make_shared<Person>("Lucy") }; // create a Person named "Lucy"
	std :: shared_ptr<Person> ricky { std::make_shared<Person>("Ricky") }; // create a Person named "Ricky"

	partnerUp(lucy, ricky); // Make "Lucy" point to "Ricky" and vice-versa

    cout << "Reference count of lucy: " << lucy.use_count() << endl;
    cout << "Reference count of ricky: " << ricky.use_count() << endl;
    cout << "Unique reference: " << lucy.unique() << endl;
    cout << "Unique reference: " << ricky.unique() << endl;

	return 0;
}