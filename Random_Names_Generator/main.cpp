#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm> // For std::transform and std::tolower
#include <cctype> // For std::tolower
#include <random> // For random number generation
#include <limits> // For std::numeric_limits<std::streamsize>

class GhanaianNameFinder {
private:
    std::map<std::string, std::pair<std::string, std::string>> nameToDayAndHistory;

public:
    GhanaianNameFinder() {
        // Correctly initialize the map with names as keys
        nameToDayAndHistory = {
            {"kojo", {"Monday", "In Ghanaian culture, names like Kojo (male) and Adwoa (female) are given to children born on Monday, symbolizing peace and calmness."}},
            {"kwabena", {"Tuesday", "Children born on Tuesday are named Kwabena (male) or Abena (female), reflecting qualities like bravery and strength."}},
            {"kwaku", {"Wednesday", "Wednesday's children are named Kwaku (male) or Akua (female), representing adaptability and versatility."}},
            {"yaw", {"Thursday", "Yaw (male) and Yaa (female) are names for Thursday-borns, often associated with cultural depth and spirituality."}},
            {"kofi", {"Friday", "Friday's children, named Kofi (male) or Efia (female), symbolize fertility and affection."}},
            {"kwame", {"Saturday", "Kwame (male) and Ama (female) are names for those born on Saturday, signifying wisdom and nurturing qualities."}},
            {"kwasi", {"Sunday", "Sunday-borns are named Kwasi (male) or Akos (female), denoting leadership and charismatic qualities."}}
        };
    }

    void generateRandomName() {
        // Convert the map to a vector of keys (names)
        std::vector<std::string> names;
        for (const auto& pair : nameToDayAndHistory) {
            names.push_back(pair.first);
        }

        // Random number generation setup
        std::random_device rd; // Obtain a random number from hardware
        std::mt19937 gen(rd()); // Seed the generator
        std::uniform_int_distribution<> distr(0, names.size() - 1); // Define the range

        // Generate a random index
        int randomIndex = distr(gen);
        std::string randomName = names[randomIndex];

        // Find the corresponding day and history
        auto it = nameToDayAndHistory.find(randomName);
        if (it != nameToDayAndHistory.end()) {
            std::cout << "\nRandomly selected name: " << capitalizeFirstLetter(randomName) << "\n";
            std::cout << "Associated day: " << it->second.first << "\n";
            std::cout << "History: " << it->second.second << std::endl; // Print the history
        }
    }

    // Utility function to capitalize the first letter of a string
    std::string capitalizeFirstLetter(const std::string& input) {
        if (input.empty()) return input;
        std::string output = input;
        output[0] = std::toupper(output[0]); // Corrected to directly modify the first character
        return output;
    }
};

int main() {
    GhanaianNameFinder finder;

    char userChoice;
    do {
        finder.generateRandomName();

        std::cout << "\nGenerate another random name? (Y/N): ";
        std::cin >> userChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character from the input buffer

    } while (userChoice == 'Y' || userChoice == 'y');

    return 0;
}
