//This headerfile contain all the elements that are required in order to work with the Graphics
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <iostream>
 
// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
 // Function to draw the array as bars
void drawArray(sf::RenderWindow &window, const std::vector<int> &arr, int pivot, int i, int j) {
    window.clear(sf::Color::Black);
    float barWidth = window.getSize().x / static_cast<float>(arr.size());
    int max_value = *std::max_element(arr.begin(), arr.end());
 
    for (int k = 0; k < arr.size(); ++k) {
        sf::RectangleShape bar(sf::Vector2f(barWidth - 1, arr[k] * (window.getSize().y / static_cast<float>(max_value))));
        bar.setPosition(k * barWidth, window.getSize().y - bar.getSize().y);
 
        if (k == pivot)
            bar.setFillColor(sf::Color::Red);
        else if (k == i)
            bar.setFillColor(sf::Color::Green);
        else if (k == j)
            bar.setFillColor(sf::Color::Blue);
        else
            bar.setFillColor(sf::Color::White);
 
        window.draw(bar);
    }
    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(700)); // Sleep for 200 milliseconds to visualize the process
}

// Partition function to place the pivot element at the correct position
int partition(sf::RenderWindow &window, std::vector<int>& arr, int low, int high) {
    int pivot = high; // Choose the rightmost element as pivot
    int i = low - 1; // Index of smaller element
 
    for (int j = low; j <= high - 1; ++j) {
        drawArray(window, arr, pivot, i, j);
        // If current element is smaller than or equal to pivot
        if (arr[j] <= arr[pivot]) {
            ++i; // Increment index of smaller element
            swap(arr[i], arr[j]);
            drawArray(window, arr, pivot, i, j);
        }
    }
    swap(arr[i + 1], arr[high]); // Place the pivot element at the right position
    drawArray(window, arr, pivot, i + 1, high);
    return i + 1;
}
// Quicksort function
void quicksort(sf::RenderWindow &window, std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(window, arr, low, high);
 
        // Recursively sort elements before and after partition
        quicksort(window, arr, low, pi - 1);
        quicksort(window, arr, pi + 1, high);
    }
}
 
int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
 
    std::vector<int> arr(n);
    std::cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
        sf::RenderWindow window(sf::VideoMode(800, 600), "Quicksort Visualization");
 
    // Run the quicksort algorithm with visualization
    std::thread quicksortThread(quicksort, std::ref(window), std::ref(arr), 0, n - 1);
 
    // Main loop to keep the window open
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
 
    // Wait for the sorting thread to finish
    quicksortThread.join();
 
    return 0;

}

     

