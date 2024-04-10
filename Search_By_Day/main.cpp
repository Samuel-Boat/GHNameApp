#include <iostream>
#include <string>
#include <map>
#include <algorithm> // For std::transform and std::tolower
#include <cctype> // For std::tolower

class GhanaianNameFinder {
private:
    std::map<std::string, std::pair<std::string, std::string>> nameToDayAndHistory;
    std::map<std::string, std::pair<std::string, std::string>> dayToNamesAndHistory;

public:
    GhanaianNameFinder() {
        // Initialize the map with lowercase keys for names
        nameToDayAndHistory = {
            // Initialization as previously described...
        };

        // Initialize the map for days of the week to names and a brief history
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

    void searchByDay(const std::string& day) {
        std::string lowerCaseDay = toLowerCase(day);
        auto it = dayToNamesAndHistory.find(lowerCaseDay);
        if (it != dayToNamesAndHistory.end()) {
            std::cout << "\nFor " << capitalizeFirstLetter(day) << ", the associated Ghanaian names are " << it->second.first << ".\n";
            std::cout << it->second.second << std::endl; // Print the history
        } else {
            std::cout << "\nThe day " << capitalizeFirstLetter(day) << " is not recognized. Please enter a valid day of the week." << std::endl;
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

    std::string day;
    std::cout << "\nEnter a day of the week to learn about the associated Ghanaian names and their significance: ";
    std::cin >> day;

    finder.searchByDay(day);

    return 0;
}
