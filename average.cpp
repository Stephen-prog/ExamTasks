#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    vector<double> numbers;
    double input;
    char choice;
    
    cout << "=== Mean Calculator ===" << endl;
    cout << "Enter numbers one by one. Enter 'q' to finish and calculate." << endl;
    
    // user can enter inputs and then 'q' to quit
    int counter = 1;
    while (true) {
        cout << "Enter number " << counter << " (or 'q' to quit): ";
        
        // check if input is valid
        if (!(cin >> input)) {
            // clear error state
            cin.clear();
            // check if user entered 'q' or 'Q'
            cin >> choice;
            if (choice == 'q' || choice == 'Q') {
                break;
            } else {
                cout << "Invalid input. Please enter a number or 'q' to quit." << endl;
                // Clear the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        }
        
        numbers.push_back(input);
        counter++;
        
        // to check if at least 2 numbers are entered
        if (numbers.size() < 2) {
            cout << "Please enter at least 2 numbers." << endl;
        }
    }
    
    // check if we have enough numbers
    if (numbers.size() < 2) {
        cout << "Error: You need to enter at least 2 numbers!" << endl;
        return 1;
    }
    
    // calculating sum and then the mean
    double sum = 0;
    for (double num : numbers) {
        sum += num;
    }
    double mean = sum / numbers.size();
    
    // displaying results
    cout << "\n=== Solution ===" << endl;
    cout << "Numbers entered: ";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
        if (i < numbers.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "Sum: " << sum << endl;
    cout << "Count: " << numbers.size() << endl;
    cout << "Mean: " << mean << endl;
    
    return 0;
}
