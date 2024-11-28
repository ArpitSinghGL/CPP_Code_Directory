#include <bits/stdc++.h>

using namespace std;

class Car
{
    private:

    string color;

    string model;

    string engine;

    public:

    Car(string color , string model , string engine)
    {
        this -> color = color;
        this -> model = model;
        this -> engine = engine;
    }

    void getDetails()
    {
        cout << "Color: " << this -> color << endl;
        cout << "Model: " << this -> model << endl;
        cout << "Engine: " << this -> engine << endl;
    }
};

unique_ptr<Car>  create_car_object()
{
    return make_unique<Car>("Black" , "Audi Q7" , "XYZ");
}

void printDetails(unique_ptr<Car> ptr)
{
    ptr -> getDetails();

}

int main()
{
    unique_ptr<Car> ptr_to_car = create_car_object();
    printDetails(std::move(ptr_to_car));
    return 0;
}