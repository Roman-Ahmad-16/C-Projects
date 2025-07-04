#include <iostream>
#include <vector>
#include <limits> // cin.ignore ?? ???

using namespace std;

// Structure to store quiz questions
struct Question {
    string questionText;
    vector<string> options;
    int correctAnswer; // Index of the correct answer (1-based)

    // Constructor for C++98
    Question(string q, string op1, string op2, string op3, string op4, int correct) {
        questionText = q;
        options.push_back(op1);
        options.push_back(op2);
        options.push_back(op3);
        options.push_back(op4);
        correctAnswer = correct;
    }
};

// Function to run the quiz
void startQuiz(const vector<Question> &quiz) {
    int score = 0;

    cout << "Welcome to the Quiz Game!\n";
    cout << "Answer the following questions:\n\n";

    for (size_t i = 0; i < quiz.size(); i++) {
        cout << "Q" << (i + 1) << ": " << quiz[i].questionText << "\n";

        for (size_t j = 0; j < quiz[i].options.size(); j++) {
            cout << j + 1 << ". " << quiz[i].options[j] << "\n";
        }

        int choice;
        cout << "Enter your choice (1-" << quiz[i].options.size() << "): ";

        while (true) {
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > quiz[i].options.size()) {
                cout << "Invalid input! Try again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        if (choice == quiz[i].correctAnswer) {
            cout << "? Correct!\n";
            score++;
        } else {
            cout << "? Wrong! The correct answer was: " << quiz[i].options[quiz[i].correctAnswer - 1] << "\n";
        }
        cout << "---------------------------------\n";
    }

    cout << "?? Quiz Completed!\n";
    cout << "Your Final Score: " << score << " / " << quiz.size() << "\n";
}

int main() {
    vector<Question> quiz;

    // Adding questions manually (C++98 style)
    quiz.push_back(Question("What is the capital of France?", "Berlin", "Madrid", "Paris", "Rome", 3));
    quiz.push_back(Question("Which planet is known as the Red Planet?", "Earth", "Mars", "Jupiter", "Venus", 2));
    quiz.push_back(Question("Who wrote 'Hamlet'?", "Charles Dickens", "William Shakespeare", "Leo Tolstoy", "Mark Twain", 2));
    quiz.push_back(Question("What is 5 + 3?", "6", "7", "8", "9", 3));
    quiz.push_back(Question("Which gas do plants use for photosynthesis?", "Oxygen", "Carbon Dioxide", "Nitrogen", "Hydrogen", 2));

    // Start the quiz
    startQuiz(quiz);

    return 0;
}

