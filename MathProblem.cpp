#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>

class MathProblem {
private:
    int operand1;
    int operand2;
    int answer;
    char operation;

public:
    MathProblem(int minOperand, int maxOperand, char selectedOperation) {
        // Seed the random number generator with the current time
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        // Set the operation based on the selectedOperation
        operation = selectedOperation;

        // Generate random operands based on the given range
        operand1 = minOperand + std::rand() % (maxOperand - minOperand + 1);
        operand2 = minOperand + std::rand() % (maxOperand - minOperand + 1);

        // Calculate the answer based on the selected operation
        switch (operation) {
            case '+':
                answer = operand1 + operand2;
                break;
            case '-':
                answer = operand1 - operand2;
                break;
            case '*':
                answer = operand1 * operand2;
                break;
            case '/':
                // Ensure division is valid (no division by zero) and get an integer result
                operand2 = (operand2 == 0) ? 1 : operand2;
                answer = operand1 / operand2;
                break;
        }
    }

    int getAnswer() {
        return answer;
    }

    std::string getQuestion() {
        return std::to_string(operand1) + " " + operation + " " + std::to_string(operand2);
    }

    bool checkAnswer(int userAnswer) {
        return userAnswer == answer;
    }
};