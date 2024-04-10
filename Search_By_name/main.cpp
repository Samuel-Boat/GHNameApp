#include <iostream>
#include <string>
#include <map>
#include <algorithm> // For std::transform and std::tolower
#include <cctype> // For std::tolower

class GhanaianNameFinder {
private:
    std::map<std::string, std::pair<std::string, std::string>> nameToDayAndHistory;

public:
    GhanaianNameFinder() {
    // Initialize the map with lowercase keys
    // Ensure all names are stored in lowercase for consistent internal use
    nameToDayAndHistory = {
        {"kwame", {"Saturday", "Historically, Kwame is associated with being born on a Saturday, symbolizing qualities such as uniqueness and leadership."}},
        {"kwasi", {"Sunday", "Kwasi signifies a person born on a Sunday, often associated with wisdom and creativity."}},
        {"kojo", {"Monday", "Kojo represents those born on a Monday, symbolizing peace and calmness."}},
        {"kwabena", {"Tuesday", "Kwabena denotes being born on a Tuesday, reflecting qualities like bravery and strength."}},
        {"kwaku", {"Wednesday", "Kwaku is linked with Wednesday births, representing adaptability and versatility."}},
        {"yaw", {"Thursday", "Yaw signifies a Thursday birth, often associated with cultural depth and spirituality."}},
        {"kofi", {"Friday", "Kofi is for those born on a Friday, symbolizing fertility and affection."}},
        {"ama", {"Saturday", "Ama, for females born on Saturday, signifies wisdom and nurturing qualities."}},
        {"akos", {"Sunday", "Akos is associated with females born on Sunday, denoting leadership and charismatic qualities."}},
        {"adwoa", {"Monday", "Adwoa represents females born on a Monday, symbolizing peace and mediation."}},
        {"abena", {"Tuesday", "Abena signifies females born on a Tuesday, reflecting courage and tenacity."}},
        {"akua", {"Wednesday", "Akua is linked to females born on Wednesday, representing intelligence and curiosity."}},
        {"yaa", {"Thursday", "\nYaa denotes females born on Thursday, symbolizing respect and family values."}},
        {"efia", {"Friday", "Efia is for females born on a Friday, indicating creativity and passion."}}
  
        };
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

    // Function to search by Ghanaian name
    void searchByName(const std::string& name) {
        std::string lowerCaseName = toLowerCase(name);
        auto it = nameToDayAndHistory.find(lowerCaseName);
        if (it != nameToDayAndHistory.end()) {
            std::string capitalizedDay = capitalizeFirstLetter(it->second.first); // Capitalize the first letter of the day
            std::string capitalizedName = capitalizeFirstLetter(name); // Capitalize the first letter of the name for output
            std::cout << "\nPlease, the name you entered is "<< name << "." << std::endl;
            std::cout << capitalizedName << " is associated with being born on a " << capitalizedDay << ".\n";
            std::cout << it->second.second << std::endl; // Print the history
        } else {
            std::cout << "\nThe name " << capitalizeFirstLetter(name) << " is not recognized. Please ensure it is spelled correctly." << std::endl;
        }
    }
};

int main() {
    GhanaianNameFinder finder;

    std::string name;
    std::cout << "\nEnter a Ghanaian name to learn about its significance: ";
    std::cin >> name;

    finder.searchByName(name);

    return 0;
}

