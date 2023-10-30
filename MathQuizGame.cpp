#include <iostream>
#include "MathProblem.cpp"
#include "UserInterface.cpp"
using namespace std;

class MathQuizGame {
private:
    int numProblems;
    int minOperand;
    int maxOperand;
    UserInterface ui;  // Create an instance of the UserInterface class

public:
    MathQuizGame(int numProblems, int minOperand, int maxOperand) : numProblems(numProblems), minOperand(minOperand), maxOperand(maxOperand) {}

    void startGame(char selectedOperation, int maxOperand) {
        int score = 0;  // Initialize the score for each game

        for (int i = 0; i < numProblems; i++) {
            MathProblem problem(minOperand, maxOperand, selectedOperation);
            ui.displayQuestion(problem.getQuestion());

            int userAnswer = ui.getUserInput();

            if (problem.checkAnswer(userAnswer)) {
                ui.displayFeedback(true);
                score++;
            } else {
                ui.displayFeedback(false);
                cout << "The correct answer is: " << problem.getAnswer() << endl;
            }
        }

        cout << "Game Over! Your score: " << score << " out of " << numProblems << endl;

        char playAgain;
        cout << "Do you want to play the same game mode and difficulty level again? (Y/N): ";
        cin >> playAgain;

        if (playAgain == 'Y' || playAgain == 'y') {
            // If the user wants to play again, recursively call startGame with the same game mode and difficulty level
            startGame(selectedOperation, maxOperand);
        }
    }
};

int main() {
    int numProblems = 5;
    int minOperand = 1;
    
    cout << "Enter your name: ";
    string name;
    cin >> name;
    cout << "Welcome to the Math Quiz, " << name << "!" << endl;

    while (true) {
        cout << "Select a game mode:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        
        int gameMode;
        cin >> gameMode;
        
        char selectedOperation;
        switch (gameMode) {
            case 1:
                selectedOperation = '+';
                break;
            case 2:
                selectedOperation = '-';
                break;
            case 3:
                selectedOperation = '*';
                break;
            case 4:
                selectedOperation = '/';
                break;
            default:
                cout << "Invalid game mode. Exiting." << endl;
                return 1;
        }

        // Prompt the user for the difficulty level
        cout << "Select a difficulty level:" << endl;
        cout << "1. Easy (Numbers between 1 to 10)" << endl;
        cout << "2. Medium (Numbers between 1 to 100)" << endl;
        cout << "3. Hard (Numbers between 1 to 1000)" << endl;

        int difficultyLevel;
        cin >> difficultyLevel;
        
        int maxOperand;
        switch (difficultyLevel) {
            case 1:
                maxOperand = 10; // Easy
                break;
            case 2:
                maxOperand = 100; // Medium
                break;
            case 3:
                maxOperand = 1000; // Hard
                break;
            default:
                cout << "Invalid difficulty level. Exiting." << endl;
                return 1;
        }

        MathQuizGame game(numProblems, minOperand, maxOperand);
        game.startGame(selectedOperation, maxOperand);

        char playAgain;
        cout << "Do you want to play a different game mode or difficulty level? (Y/N): ";
        cin >> playAgain;

        if (playAgain != 'Y' && playAgain != 'y') {
            break; // Exit the loop if the user doesn't want to play again
        }
    }

    return 0;
}
