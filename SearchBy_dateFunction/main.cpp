#include <iostream>
#include <string>
#include <limits> // For std::numeric_limits<std::streamsize>

class GhanaianNameFinder {
public:
    // This function also returns the name of the day of the week
    std::pair<int, std::string> calculateDayOfWeek(int day, int month, int year) {
        static const char* daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
        
        if (month < 3) {
            month += 12;
            year -= 1;
        }
        int k = year % 100;
        int j = year / 100;
        int dayOfWeek = (day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
        
        return {dayOfWeek, daysOfWeek[dayOfWeek]};
    }

    std::string getGhanaianName(int dayOfWeek, char gender) {
        static const char* maleNames[] = {"Kwame", "Kwasi", "Kojo", "Kwabena", "Kwaku", "Yaw", "Kofi"};
        static const char* femaleNames[] = {"Ama", "Akos", "Adwoa", "Abena", "Akua", "Yaa", "Efia"};

        if (gender == 'M' || gender == 'm') {
            return maleNames[(dayOfWeek) % 7]; // Adjusted for Zeller's Congruence to the table provided
        } else {
            return femaleNames[(dayOfWeek) % 7]; // Adjusted for Zeller's Congruence to the table provided
        }
    }

    void searchByDate(int day, int month, int year, char gender) {
        auto [dayOfWeek, dayName] = calculateDayOfWeek(day, month, year);
        std::string name = getGhanaianName(dayOfWeek, gender);
        std::cout << "\nAccording to the date entered, you were born on " << dayName << ".\n";
        std::cout << "\nThe Ghanaian name for a " << (gender == 'M' || gender == 'm' ? "male" : "female") << " born on " << month << "/" << day << "/" << year << " is: " << name << std::endl << std::endl;
    }
};

int main() {
    
    std::cout <<"Gahanaian names finding using your date of birth\n"<<std::endl; 
    
    GhanaianNameFinder finder;

    int day, month, year;
    char gender;

    std::cout << "Enter your gender (M for male, F for female): ";
    std::cin >> gender;

    // Validate gender input
    while (gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f') {
        std::cout << "Invalid gender. Please enter M for male or F for female: ";
        std::cin >> gender;
    }

    bool validDate = false;
    while (!validDate) {
        std::cout << "Enter your date of birth (MM DD YYYY): ";
        if (std::cin >> month >> day >> year) {
            // Basic check for valid date ranges
            if (month >= 1 && month <= 12 && day >= 1 && day <= 31 && year > 0) {
                validDate = true;
            } else {
                std::cout << "Invalid date. Please make sure you enter a valid date in MM DD YYYY format.\n";
            }
        } else {
            std::cout << "Invalid input. Please enter your date of birth as MM DD YYYY: ";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the input
        }
    }

    finder.searchByDate(day, month, year, gender);

    return 0; 
}
