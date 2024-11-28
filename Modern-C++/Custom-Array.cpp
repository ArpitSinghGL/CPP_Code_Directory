// #include <bits/stdc++.h>

// using namespace std;

// template < typename T , int SIZE >
// class Array
// {
//     private:

//     int len = SIZE;

//     T arr[SIZE];

//     public:

//     // Initializing the array using the initializer_list
//     Array(initializer_list<T> init_list)
//     {
//         for(auto it = init_list.begin() ; it != init_list.end() ; it++)
//         {
//             arr[it - it.begin()] = *it;
//         }
//         for(int i = init_list.size() ; i < SIZE ; i++)
//         {
//             arr[i] = 0;
//         }
//     }

//     constexpr int size()
//     {
//         return SIZE;
//     }

//     // fill function
//     void fill(T val)
//     {
//         for(auto& it : arr)
//         {
//             it = val;
//         }
//     }

//     // overloading the subscript operator
//     T operator[] (int index)
//     {
//         return arr[index];
//     }

//     // Copy constructor
//     Array(Array& new_array)
//     {
//         this -> len = new_array.len;
//         for(int i = 0 ; i < size ; i++)
//         {
//             arr[i] = new_array.arr[i];
//         }
//     }

//     // Assignment operator
//     void operator= (Array& new_array)
//     {
//         this -> len = new_array.len;
//         for(int i = 0 ; i < len ; i++)
//         {
//             arr[i] = new_array.arr[i];
//         }
//     }

//     // Overload << operator for a fixed-size int array
//     ostream& operator<<(ostream& os, int arr[] , int n) 
//     {
//         os << "[";
//         for (int i = 0; i < n; ++i) 
//         {
//             os << arr[i];
//             if (i < n - 1) 
//             {
//                 os << ", "; // Add comma between elements
//             }
//         }
//         os << "]";
//         return os;
//     }

// };

#include <iostream>
#include <initializer_list>
#include <algorithm> // for std::fill
#include <utility>   // for std::move

template <typename T, std::size_t N>
class Array {
private:
    T data[N];  // Fixed-size array

public:
    using Value = T;  // Member type alias for array elements

    // Constructor from std::initializer_list
    Array(std::initializer_list<T> list) {
        std::size_t i = 0;
        for (auto& elem : list) {
            data[i++] = elem;
        }
        // Fill remaining elements with 0 if initializer list is smaller
        for (; i < N; ++i) 
        {
            data[i] = T();
        }
    }

    // (3) Copy constructor
    Array(const Array& other) {
        std::copy(other.data, other.data + N, data);
    }

    // Move constructor
    Array(Array&& other) noexcept {
        std::move(other.data, other.data + N, data);
    }

    // Copy assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            std::copy(other.data, other.data + N, data);
        }
        return *this;
    }

    // Move assignment operator
    Array& operator=(Array&& other) noexcept {
        if (this != &other) {
            std::move(other.data, other.data + N, data);
        }
        return *this;
    }

    // Destructor
    ~Array() = default;  // No dynamic memory, so default destructor is fine

    // Subscript operator
    T& operator[](std::size_t index) {
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        return data[index];
    }

    // size() member function (constexpr)
    constexpr std::size_t size() const {
        return N;
    }

    // fill() member function to fill the array with a specified value
    void fill(const T& value) {
        std::fill(data, data + N, value);
    }

    // Stream inserter (<<) operator overload for writing to std::ostream
    friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
        os << "[";
        for (std::size_t i = 0; i < N; ++i) {
            os << arr.data[i];
            if (i < N - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
};

int main() 
{
    // (2) Constructing Array using initializer_list
    Array<int, 5> arr1 = {1, 2, 3};
    std::cout << "Array 1: " << arr1 << std::endl;

    // (4) Accessing elements using the subscript operator
    arr1[3] = 10;
    std::cout << "Array 1 after modification: " << arr1 << std::endl;

    // (5) Getting the size of the array
    std::cout << "Size of Array 1: " << arr1.size() << std::endl;

    // (6) Filling the array with a specified value
    arr1.fill(7);
    std::cout << "Array 1 after filling: " << arr1 << std::endl;

    // (3) Testing copy constructor
    Array<int, 5> arr2 = arr1;
    std::cout << "Array 2 (copy of Array 1): " << arr2 << std::endl;

    // (3) Testing move constructor
    Array<int, 5> arr3 = std::move(arr1);
    std::cout << "Array 3 (moved from Array 1): " << arr3 << std::endl;

    return 0;
}
