#include <bits/stdc++.h>

using namespace std;

template < int PIN, int BRIGHTNESS>
class LED
{
    private:

    int brightness = BRIGHTNESS;
    int pin = PIN;

    public:

    void setBrightness(int brightness)
    {
        this -> brightness = brightness;
    }

    int getBrightness()
    {
        return this -> brightness;
    }
};

int main()
{
    LED <1 , 50> led1;
    led1.setBrightness(75);
    cout << "Brightness: " << led1.getBrightness() << endl;
    return 0;
}