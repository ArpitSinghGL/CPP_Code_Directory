#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

// Scoped enum to represent light states
enum class LightState 
{
    OFF,
    ON,
    DIMMED
};

// LightController class
class LightController 
{
    private:

    vector<LightState> lights;  // Vector to store states of lights
    
    public:

    // Constructor to initialize light states using std::initializer_list
    LightController(initializer_list<LightState> initList) 
    {
        for (const auto& state : initList) 
        {
            lights.push_back(state);
        }
    }

    // Method to set the state of all lights to a given state
    void setState(LightState newState) 
    {
        for (auto& light : lights) 
        {
            light = newState;
        }
    }

    // Method to print the current state of all lights
    void printStates()
    {
        for (const auto& light : lights) 
        {
            switch (light) 
            {
                case LightState::OFF:
                    cout << "OFF ";
                    break;

                case LightState::ON:
                    cout << "ON ";
                    break;

                case LightState::DIMMED:
                    cout << "DIMMED ";
                    break;
            }
        }
        cout << endl;
    }
};

int main() 
{
    // Initializing the light states using std::initializer_list
    LightController controller = {LightState::OFF, LightState::ON, LightState::DIMMED, LightState::OFF};

    // Print initial states
    cout << "Initial States: ";
    controller.printStates();

    // Set all lights to ON
    controller.setState(LightState::ON);
    cout << "After setting all to ON: ";
    controller.printStates();

    // Set all lights to DIMMED
    controller.setState(LightState::DIMMED);
    cout << "After setting all to DIMMED: ";
    controller.printStates();

    return 0;
}
