#include <iostream>

class UserInterface {
public:
    void displayQuestion(const std::string& question) {
        std::cout << "Solve the math problem: " << question << std::endl;
    }

    void displayFeedback(bool isCorrect) {
        if (isCorrect) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect. The correct answer is shown below." << std::endl;
        }
    }

    int getUserInput() {
        int userAnswer;
        std::cin >> userAnswer;
        return userAnswer;
    }
};