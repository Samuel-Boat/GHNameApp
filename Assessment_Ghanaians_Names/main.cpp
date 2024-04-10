#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include <limits>
#include <utility>

class GhanaianNameFinder {
private:
    std::map<std::string, std::pair<std::string, std::string>> nameToDayAndHistory;
    std::vector<std::string> daysOfWeek = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

public:
    GhanaianNameFinder() {
        initializeData();
    }

    void initializeData() {
        // Initialize with both male and female names for each day
        nameToDayAndHistory = {
            // Note: Adjust the cultural significances as needed
            {"Kojo/Adwoa", {"Monday", "Peace and calmness"}},
            {"Kwabena/Abena", {"Tuesday", "Bravery and strength"}},
            {"Kwaku/Akua", {"Wednesday", "Adaptability and versatility"}},
            {"Yaw/Yaa", {"Thursday", "Cultural depth and spirituality"}},
            {"Kofi/Efia", {"Friday", "Fertility and affection"}},
            {"Kwame/Ama", {"Saturday", "Wisdom and nurturing qualities"}},
            {"Kwasi/Akos", {"Sunday", "Leadership and charismatic qualities"}}
        };
    }

    void runAssessment() {
        std::string userChoice;
        do {
            askRandomQuestion();

            std::cout << "\nDo you want to continue? (Y/N): ";
            std::getline(std::cin, userChoice);
        } while (userChoice == "Y" || userChoice == "y");
    }

private:
    void askRandomQuestion() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(0, 1); // Decide between asking for name -> day (0) or day -> name (1)

        if (distr(gen) == 0) {
            askNameToDayQuestion();
        } else {
            askDayToNameQuestion();
        }
    }

    void askNameToDayQuestion() {
        // Randomly select a name and ask for the associated day
        auto item = selectRandomItemFromMap();
        std::cout << "What day is associated with the name(s) " << item.first << "? ";
        std::string userAnswer;
        std::getline(std::cin, userAnswer);

        // Check and provide feedback
        if (toLowerCase(userAnswer) == toLowerCase(item.second.first)) {
            std::cout << "Correct!\n";
        } else {
            std::cout << "\nIncorrect. The correct answer is " << item.second.first << ".\n";
        }
    }

    void askDayToNameQuestion() {
        // Randomly select a day and ask for the associated name(s)
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dayDistr(0, daysOfWeek.size() - 1);
        std::string selectedDay = daysOfWeek[dayDistr(gen)];
        
        std::cout << "\nWhat are the Ghanaian names associated with " << selectedDay << "? ";
        std::string userAnswer;
        std::getline(std::cin, userAnswer);

        // Find the correct answer
        auto correctAnswer = findNameByDay(selectedDay);
        if (toLowerCase(userAnswer) == toLowerCase(correctAnswer)) {
            std::cout << "Correct!\n";
        } else {
            std::cout << "Incorrect. The correct names are " << correctAnswer << ".\n";
        }
    }

    std::pair<std::string, std::pair<std::string, std::string>> selectRandomItemFromMap() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(0, nameToDayAndHistory.size() - 1);
        auto it = std::next(nameToDayAndHistory.begin(), distr(gen));
        return *it;
    }

    std::string findNameByDay(const std::string& day) {
        for (const auto& pair : nameToDayAndHistory) {
            if (toLowerCase(pair.second.first) == toLowerCase(day)) {
                return pair.first;
            }
        }
        return "No name found"; // Should not happen if data is correctly initialized
    }

    std::string toLowerCase(const std::string& input) {
        std::string output = input;
        std::transform(output.begin(), output.end(), output.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        return output;
    }
};

int main() {
    GhanaianNameFinder finder;
    finder.runAssessment();
    return 0;
}