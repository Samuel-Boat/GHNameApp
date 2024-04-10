#include <iostream>
#include <string>
#include <map>
#include <algorithm> // For std::transform and std::tolower
#include <cctype> // For std::tolower
#include <random> // For random number generation
#include <vector> // For storing days of the week
#include <limits> // For std::numeric_limits

class GhanaianNameFinder {
private:
    std::map<std::string, std::pair<std::string, std::string>> dayToNamesAndHistory;
    std::vector<std::string> daysOfWeek = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

public:
    GhanaianNameFinder() {
        // Initialize dayToNamesAndHistory with the mapping of days to names and histories
        dayToNamesAndHistory = {
            {"monday", {"Kojo/Adwoa", "In Ghanaian culture, names like Kojo (male) and Adwoa (female) are given to children born on Monday, symbolizing peace and calmness."}},
            {"tuesday", {"Kwabena/Abena", "Children born on Tuesday are named Kwabena (male) or Abena (female), reflecting qualities like bravery and strength."}},
            {"wednesday", {"Kwaku/Akua", "Wednesday's children are named Kwaku (male) or Akua (female), representing adaptability and versatility."}},
            {"thursday", {"Yaw/Yaa", "Yaw (male) and Yaa (female) are names for Thursday-borns, often associated with cultural depth and spirituality."}},
            {"friday", {"Kofi/Efia", "Friday's children, named Kofi (male) or Efia (female), symbolize fertility and affection."}},
            {"saturday", {"Kwame/Ama", "Kwame (male) and Ama (female) are names for those born on Saturday, signifying wisdom and nurturing qualities."}},
            {"sunday", {"Kwasi/Akos", "Sunday-borns are named Kwasi (male) or Akos (female), denoting leadership and charismatic qualities."}}
        };
    }

    void generateRandomDay() {
        // Random number generation setup
        std::random_device rd; // Obtain a random number from hardware
        std::mt19937 gen(rd()); // Seed the generator
        std::uniform_int_distribution<> distr(0, daysOfWeek.size() - 1); // Define the range

        // Generate a random day
        int randomIndex = distr(gen);
        std::string randomDay = daysOfWeek[randomIndex];

        // Find the corresponding names and history
        auto it = dayToNamesAndHistory.find(randomDay);
        if (it != dayToNamesAndHistory.end()) {
            std::cout << "\nRandomly selected day: " << capitalizeFirstLetter(randomDay) << "\n";
            std::cout << "Associated Ghanaian names: " << it->second.first << "\n";
            std::cout << it->second.second << std::endl; // Print the history
        }
    }

    // Utility function to convert a string to lowercase
    std::string toLowerCase(const std::string& input) {
        std::string output = input;
        std::transform(output.begin(), output.end(), output.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        return output;
    }

    // Utility function to capitalize the first letter of a string
    std::string capitalizeFirstLetter(const std::string& input) {
        if (input.empty()) return input;
        std::string output = input;
        output[0] = std::toupper(output[0]);
        return output;
    }
};

int main() {
    GhanaianNameFinder finder;

    char userChoice;
    do {
        finder.generateRandomDay();
        
        std::cout << "\nGenerate another random day? (Y/N): ";
        std::cin >> userChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character from the input buffer

    } while (userChoice == 'Y' || userChoice == 'y');

    return 0;
}
