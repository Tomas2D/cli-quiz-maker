#include <utility>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <random>

using namespace std;

random_device r;
seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
mt19937 eng(seed);

class Question {
private:
    vector<pair<string, bool> > answers;
    string title;
public:
    void setTitle(const string & str) {
        this->title = str;
    }
    void addQuestion(const string& question, bool isCorrect) {
        this->answers.push_back(make_pair(question, isCorrect));
    }
    const string & getTitle() {
        return title;
    }
    const vector<pair<string, bool> > & getAnswers() {
        return answers;
    }
    void shuffleAnswers() {
        shuffle(answers.begin(), answers.end(), eng);
    }
    bool isEmpty() {
        return title.empty();
    }
};

bool loadFile(vector <Question *> & questions, const string &filename) {
    string line;
    ifstream file(filename);
    if (file.bad()) {
        return false;
    }

    bool newQuestion = true;
    Question * question = new Question();

    if (file.is_open()) {
        while (getline(file, line)) {
            if (!newQuestion && (line == "" || line == "\r" || line == "\n" || line == "\r\n")) {
                if (question != nullptr) {
                    if (!question->isEmpty()) {
                        question->shuffleAnswers();
                        questions.push_back(question);
                    } else {
                        free(question);
                    }
                }
                question = new Question();
                newQuestion = true;
                continue;
            }
            
            // Title setup
            if (newQuestion) {
                if (line.size() <= 2 || (line.substr(0, 2) == "//")) {
                    continue;
                }
                question->setTitle(line);
                newQuestion = false;
                continue;
            }

            // Question setup
            line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
            line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());

            string end = line.substr(line.length() - 2 );
            bool isCorrect = false;
            if (end == "//") {
                isCorrect = true;
                line.pop_back();
                line.pop_back();
            }
            question->addQuestion(line, isCorrect);
        }
        if (question != nullptr) {
            if (!question->isEmpty()) {
                question->shuffleAnswers();
                questions.push_back(question);
            } else {
                free(question);
            }
        }
        file.close();
        return true;
    }
    return false;
}

set<string> split(string s, const string delimiter){
    set<string> list;
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        if (token == "") {
            s.erase(0, pos + delimiter.length());
            continue;
        }
        std::transform(token.begin(), token.end(), token.begin(), ::toupper);
        list.insert(token);
        s.erase(0, pos + delimiter.length());
    }
    if (s != "") {
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
        list.insert(s);
    }
    return list;
}

bool runTest(vector <Question *> & questions) {

    vector <Question *> failedQuestions;
    shuffle(questions.begin(), questions.end(), eng);

    size_t totalCount = questions.size();

    size_t counter = 0;
    size_t passed = 0;
    size_t failed = 0;

    size_t totalCorrect = 0;
    size_t totalIncorrect = 0;
    size_t totalAnswered = 0;

    bool endTest = false;

    for (auto const &question : questions) {
		question->shuffleAnswers();
        ++counter;
        cout << counter << ". " << question->getTitle() << endl << endl;
        string response;

        const vector<pair<string, bool> > & answers = question->getAnswers();

        char strChar = (char)64;

        set<string> correctAnswers;
        for (auto const &answer: answers) {
            cout << ++strChar << ": " << answer.first << endl;
            if (answer.second) {
                string str = "X";
                str[0] = strChar;
                correctAnswers.insert(str);
            }
        }

        set<string> userAnswers;

        while (true) {
            cout << endl << "Your answer: ";
            bool err = false;
            std::getline(std::cin, response);

            if (response == "quit") {
                --counter;
                endTest = true;
                break;
            }
            userAnswers = split(response, " ");
            for (auto const &answer : userAnswers) {
                int index = toupper(answer[0]) - 65;
                if (index > (answers.size() - 1)) {
                    cout << "Invalid input!!! Try again..." << endl;
                    err = true;
                    break;
                }
            }
            totalAnswered += answers.size();
            if (err == false) {
                break;
            }
        }

        if (endTest) {
            break;
        }

        // Verify
        if (userAnswers == correctAnswers || (userAnswers.empty() && correctAnswers.empty())) {
            ++passed;
            totalCorrect += answers.size();
            cout << "\U00002705";
            cout << " Correct! :-)" << endl << endl;
        } else {
            set<string> different;
            set_symmetric_difference(correctAnswers.begin(), correctAnswers.end(), userAnswers.begin(), userAnswers.end(), inserter(different, different.end()));

            size_t correct = answers.size() - different.size();
            totalCorrect += correct;

            size_t incorrect = (answers.size() - correct);
            totalIncorrect += incorrect;

            cout << "\U00002757";
            cout << "Wrong! Success rate: " << 100 * ((float)correct / answers.size()) << "%" << endl;
            cout << "\U00002757";
            cout << "Correct was: ";
            for (auto const &chr : correctAnswers) {
                cout << chr << " ";
            }
            cout << endl << endl;
            ++failed;
            failedQuestions.push_back(question);
        }
    }

    cout << "=========================================" << endl << endl;

    cout << "Test finished!" << endl << endl;
    cout << "Questions answered: " << counter << "/" << totalCount << endl;

    cout << "Questions answered (correct): " << passed << "/" << totalCount << endl;
    cout << "Questions answered (incorrect): " << failed << "/" << totalCount << endl;

    cout << "Total correct answers: " << totalCorrect << "/" << totalAnswered << endl;
    cout << "Total incorrect answers: " << totalIncorrect << "/" << totalAnswered << endl;

    cout << "Success rate: " << passed << "/" << counter << endl;
    float percentageRes = ((float)passed / (float)counter) * 100;
    cout << "Percentage: " << percentageRes << "%" << endl << endl;

    if (!failedQuestions.empty() && !endTest) {
        cout << "Do you want to rerun the test with failed answers only? [yes/no]" << endl;
        cout << "Your answer: ";
        string response;
        std::getline(std::cin, response);
        std::transform(response.begin(), response.end(), response.begin(), ::toupper);
        if (response == "YES") {
            cout << endl << endl << "New test with " << failedQuestions.size() << " questions!" << endl;
            runTest(failedQuestions);
        } else {
            cout << endl;
        }
    }
    return !endTest;
}

int main(int argc, char **argv) {

    if (argc < 2) {
        cout << "Usage ./quiz questions.txt" << endl;
        return 1;
    }

    vector <Question *> questions;

    if (!loadFile(questions, argv[1])) {
        cout << "File is not okay..." << endl;
        return 2;
    }

    cout << endl << "Instructions:" << endl << endl;
    cout << "This is a multi-choice tester. Any answer can be correct or incorrect." << endl;
    cout << "In your answer, type letters of answers you think are correct, delimited by space. Other answers are considered as incorrect by default." << endl;
    cout << endl << "Get ready!" << endl << endl;

    while (runTest(questions)) {
        cout << endl << "Do you want to start a new test? [yes/no]" << endl;
        cout << "Your answer: ";
        string response;
        std::getline(std::cin, response);
        std::transform(response.begin(), response.end(), response.begin(), ::toupper);
        if (response != "YES") {
            break;
        }
        cout << endl << endl;
    }

    return 0;
}