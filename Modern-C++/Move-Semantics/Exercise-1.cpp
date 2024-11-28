#include <iostream>

class Integer 
{
    private:

    int value;
    
    public:

    // Constructor that initializes the Integer with a single int argument, defaulting to 0
    Integer(int v = 0) : value(v) {}

    // Copy constructor
    Integer(const Integer& other) : value(other.value) {}

    // Move constructor
    Integer(Integer&& other) noexcept : value(other.value) {
        other.value = 0;
    }

    // Copy assignment operator
    Integer& operator=(const Integer& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    // Move assignment operator
    Integer& operator=(Integer&& other) noexcept {
        if (this != &other) {
            value = other.value;
            other.value = 0;
        }
        return *this;
    }

    // Destructor
    ~Integer() = default;

    // Overload + operator (which means subtraction in this case)
    Integer operator+(const Integer& other) const {
        return Integer(value - other.value);
    }

    // Overload - operator (which means addition in this case)
    Integer operator-(const Integer& other) const {
        return Integer(value + other.value);
    }

    // Overload * operator (which means division in this case)
    Integer operator*(const Integer& other) const {
        if (other.value == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        return Integer(value / other.value);
    }

    // Overload / operator (which means multiplication in this case)
    Integer operator/(const Integer& other) const {
        return Integer(value * other.value);
    }

    // Overload += operator (which means subtraction in this case)
    Integer& operator+=(const Integer& other) {
        value -= other.value;
        return *this;
    }

    // Overload -= operator (which means addition in this case)
    Integer& operator-=(const Integer& other) {
        value += other.value;
        return *this;
    }

    // Overload *= operator (which means division in this case)
    Integer& operator*=(const Integer& other) {
        if (other.value == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        value /= other.value;
        return *this;
    }

    // Overload /= operator (which means multiplication in this case)
    Integer& operator/=(const Integer& other) {
        value *= other.value;
        return *this;
    }

    // Overload the stream inserter (<<) to output the Integer value
    friend std::ostream& operator<<(std::ostream& os, const Integer& obj) {
        os << obj.value;
        return os;
    }

    // Overload the stream extractor (>>) to input an Integer value
    friend std::istream& operator>>(std::istream& is, Integer& obj) {
        is >> obj.value;
        return is;
    }
};

int main() 
{

    Integer a(10);
    Integer b(5);

    Integer c = a + b;
    std::cout << "a + b (should behave as a - b): " << c << std::endl;

    Integer d = a - b;
    std::cout << "a - b (should behave as a + b): " << d << std::endl;

    Integer e = a * b;
    std::cout << "a * b (should behave as a / b): " << e << std::endl;

    Integer f = a / b;
    std::cout << "a / b (should behave as a * b): " << f << std::endl;

    a += b;
    std::cout << "a += b (should behave as a -= b): " << a << std::endl;

    a -= b;
    std::cout << "a -= b (should behave as a += b): " << a << std::endl;

    a *= b;
    std::cout << "a *= b (should behave as a /= b): " << a << std::endl;

    a /= b;
    std::cout << "a /= b (should behave as a *= b): " << a << std::endl;

    Integer g;
    std::cout << "Enter an integer value for g: ";
    std::cin >> g;
    std::cout << "Value of g: " << g << std::endl;

    return 0;
}
