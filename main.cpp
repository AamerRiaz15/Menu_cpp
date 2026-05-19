#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void print_menu();
void print_vector(const std::vector<int>& numbers);
void add_number(std::vector<int>& numbers);
void calculate_mean(std::vector<int>& numbers);
void display_smallest_number(const std::vector<int>& numbers);
void display_largest_number(const std::vector<int>& numbers);
void remove_number(std::vector<int>& numbers);
void sort_numbers_ascending(std::vector<int>& numbers);
void sort_numbers_descending(std::vector<int>& numbers);

int main() {
    char choice {};
    std::vector<int> numbers {};
    
    do {
        print_menu();
        std::string input;
        std::getline(std::cin, input);
        
        if (input.length() != 1) {
            std::cout << "Invalid input. Please enter a single character.\n\n";
            continue;
        }
        
        choice = input[0];
        
        switch (choice) {
            case 'P':
            case 'p':
                print_vector(numbers);
                break;
            case 'A':
            case 'a':
                add_number(numbers);
                break;
            case 'M':
            case 'm':
                calculate_mean(numbers);
                break;
            case 'S':
            case 's':
                display_smallest_number(numbers);
                break;
            case 'L':
            case 'l':
                display_largest_number(numbers);
                break;
            case 'R':
            case 'r':
                remove_number(numbers);
                break;
            case 'Q':
            case 'q':
                std::cout << "Goodbye." << std::endl;
                break;
            case 'O':
            case 'o':
                sort_numbers_ascending(numbers);
                break;
            case 'W':
            case 'w':
                sort_numbers_descending(numbers);
                break;
            default:
                std::cout << "Unknown selection - Please try again.\n\n";
                break;
        }
        
        
    } while (choice != 'Q' && choice != 'q');
    
    return 0;
}

void print_menu() {
    std::cout <<
        "======================\n"
        "        Menu\n"
        "======================\n"
        "P - Print numbers\n"
        "A - Add a number\n"
        "M - Display the mean of the numbers\n"
        "S - Display the smallest number\n"
        "L - Display the largest number\n"
        "R - Remove a number\n"
        "O - Sort numbers (ascending)\n"
        "W - Sort numbers (descedning)\n"
        "Q - Quit\n"
        "\n"
        "Enter your choice: ";
}

void print_vector(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        std::cout << "[] - List is empty - Nothing to display.";
    } else {
        std::cout << "[ ";
        
        for (size_t i = 0; i < numbers.size(); ++i) {
            std::cout << numbers.at(i) << " ";
        }
        
        std::cout << "]";
    }
    std::cout << "\n\n";
}

void add_number(std::vector<int>& numbers) {
    int number_to_add {};
    std::cout << "Enter number to add: ";
    
    if (!(std::cin >> number_to_add)) {
        std::cout << "Invalid input. Please enter a number.\n\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        
        return;
    }
    
    numbers.push_back(number_to_add);
    std::cout << number_to_add << " added." << "\n\n";
}

void calculate_mean(std::vector<int>& numbers) {
    if (numbers.size() == 0) {
        std::cout << "Failed to calculate mean - No data [].\n\n";
    } else {
        double mean {0.0};
        int total {0};
    
        for (size_t i = 0; i < numbers.size(); ++i) {
            total += numbers.at(i);
        }
    
        mean = static_cast<double>(total) / numbers.size();
        std::cout << "The mean is: " << mean << "\n\n";
    }
}

void display_smallest_number(const std::vector<int>& numbers) {
    if (numbers.size() == 0) {
        std::cout << "Failed to display smallest number - No data [].\n\n";
    } else {
        int smallest_number = numbers.at(0);
    
        for (size_t i = 0; i < numbers.size(); ++i) {
            if (numbers[i] < smallest_number) {
                smallest_number = numbers[i];
            }
        }
    
        std::cout << "The smallest number is: " << smallest_number << "\n\n";
    }
}

void display_largest_number(const std::vector<int>& numbers) {
    if (numbers.size() == 0) {
        std::cout << "Failed to display largest number - No data [].\n\n";
    } else {
        int largest_number = numbers.at(0);
    
        for (size_t i = 0; i < numbers.size(); ++i) {
            if (numbers[i] > largest_number) {
                largest_number = numbers[i];
            }
        }
        std::cout << "The largest number is: " << largest_number << "\n\n";
    }
}

void remove_number(std::vector<int>& numbers) {
    if (numbers.size() == 0) {
        std::cout << "Failed to remove number - List is empty.\n\n";
        return;
    }
    
    int value {};

    while (true) {
        std::cout << "Enter the number you want to remove (Or press C to cancel): ";
        
        std::string input;
        std::getline(std::cin, input);
        
        if (input == "C" || input == "c") {
            std::cout << "Remove operation cancelled.\n\n";
            return;
        }
        
        try {
            value = std::stoi(input);
            break;
        } catch (...) {
            std::cout << "Invalid input. Please enter a number or press 'C' to cancel.\n\n";
        }
    }
    
    bool found = false;
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == value) {
            numbers.erase(numbers.begin() + i);
            found = true;
            break;
        }
    }
    
    if (found) {
        std::cout << value << " removed.\n\n";
    } else {
        std::cout << value << " not found in list.\n\n"; 
    }
}

void sort_numbers_ascending(std::vector<int>& numbers) {
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Numbers sorted in ascending order.\n\n"; 
}

void sort_numbers_descending(std::vector<int>& numbers) {
    std::sort(numbers.rbegin(), numbers.rend());
    std::cout << "Numbers sorted in descending order.\n\n";
}