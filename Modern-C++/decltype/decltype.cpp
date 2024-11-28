#include <iostream>
#include <vector>
#include <numeric>  // For std::accumulate

using namespace std;

// Function to calculate moving average
auto calculateMovingAverage(vector<double>& samples, int windowSize) -> vector<decltype(samples[0])> 
{
    // Ensure windowSize is valid
    if (windowSize <= 0 || samples.size() < windowSize) 
    {
        return {};  // Return an empty vector if windowSize is invalid
    }

    vector < decltype(samples[0]) > movingAverages;  // Uniform initialization

    // Calculate moving averages
    double  sum = 0;
    for(int i = 0 ; i < windowSize ; i++)
    {
        sum += samples[i];
    }

    double average = sum/windowSize;

    movingAverages.push_back(average);

    for (int i = windowSize; i < samples.size() - windowSize; ++i) 
    {
        sum -= samples[i - windowSize];
        sum += samples[i];
        average = sum/windowSize;
        movingAverages.push_back(average);
    }

    return movingAverages;
}

int main() 
{
    vector<double> sensorSamples{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    int windowSize = 3;

    // Calculate moving average
    auto result = calculateMovingAverage(sensorSamples, windowSize);

    // Print the result
    cout << "Moving Averages: ";

    for (auto value : result) 
    {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}
