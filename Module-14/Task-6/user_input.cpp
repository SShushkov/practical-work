#include "user_input.hpp"

#include <iostream>
#include <limits>

using namespace std;

int getNumericUserInput(const string msg, const int low, const int high)
{
    cout << msg;
    int input;
    bool isError = false;
    while ((cin >> noskipws >> input >> skipws).fail() || cin.get() != '\n' ||
           input < low || input > high)
    {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');

        cout << "\033[" << ((isError) ? 2 : 1) << "A\033[J\033[3;31m"
             << "Error: Invalid input. Please try again...\033[0m\n"
             << msg;
        isError = true;
    }

    if (isError) cout << "\033[2A\033[J" << msg << input << endl;

    return input;
}

unsigned getPositiveNumericUserInput(const string msg, const unsigned low, const unsigned high)
{
    cout << msg;
    unsigned input;
    bool isError = false;
    while (cin.peek() == '-' || (cin >> noskipws >> input >> skipws).fail() || cin.get() != '\n' ||
           input < low || input > high)
    {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');

        cout << "\033[" << ((isError) ? 2 : 1) << "A\033[J\033[3;31m"
             << "Error: Invalid input. Please try again...\033[0m\n"
             << msg;
        isError = true;
    }

    if (isError) cout << "\033[2A\033[J" << msg << input << endl;

    return input;
}

float getFloatingPointNumericUserInput(const string msg, const float low, const float high)
{
    cout << msg;
    float input;
    bool isError = false;
    while ((cin >> noskipws >> input >> skipws).fail() || cin.get() != '\n' ||
           input < low || input > high)
    {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');

        cout << "\033[" << ((isError) ? 2 : 1) << "A\033[J\033[3;31m"
             << "Error: Invalid input. Please try again...\033[0m\n"
             << msg;
        isError = true;
    }

    if (isError) cout << "\033[2A\033[J" << msg << input << endl;

    return input;
}

string getStringUserInput(const string msg)
{
    cout << msg;
    string input;
    bool isError = false;
    while ((cin >> noskipws >> input >> skipws).fail() || cin.get() != '\n')
    {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');

        cout << "\033[" << ((isError) ? 2 : 1) << "A\033[J\033[3;31m"
             << "Error: Invalid input. Please try again...\033[0m\n"
             << msg;
        isError = true;
    }

    if (isError) cout << "\033[2A\033[J" << msg << input << endl;

    return input;
}

vector<int> getNumericSequenceOfUserInput(const string msg, const size_t size, const int low, const int high)
{
    cout << msg;
    int input;
    bool isError = false;
    vector<int> sequence;
    while (true)
    {
        if ((cin >> noskipws >> input >> skipws).fail() ||
            (cin.peek() != ' '  && cin.peek() != '\n') ||
            (cin.peek() == '\n' && size != 0  && sequence.size() != size - 1) ||
            (input < low || input > high))
        {
            sequence.clear();
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');

            cout << "\033[" << ((isError) ? 2 : 1) << "A\033[J\033[3;31m"
                 << "Error: Invalid input. Please try again...\033[0m\n"
                 << msg;
            isError = true;
        }
        else
        {
            sequence.push_back(input);
            if (cin.get() == '\n') break;
        }
    }

    if (isError)
    {
        cout << "\033[2A\033[J" << msg;
        for (size_t i = 0; i < size; i++) cout << sequence[i] << ' ';
        cout << endl;
    }
    return sequence;
}

vector<float> getFloatNumberSequenceOfUserInput(const string msg, const size_t size, const float low, const float high)
{
    cout << msg;
    float input;
    bool isError = false;
    vector<float> sequence;
    while (true)
    {
        if ((cin >> noskipws >> input >> skipws).fail() ||
            (cin.peek() != ' '  && cin.peek() != '\n') ||
            (cin.peek() == '\n' && size != 0  && sequence.size() != size - 1) ||
            (input < low || input > high))
        {
            sequence.clear();
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');

            cout << "\033[" << ((isError) ? 2 : 1) << "A\033[J\033[3;31m"
                 << "Error: Invalid input. Please try again...\033[0m\n"
                 << msg;
            isError = true;
        }
        else
        {
            sequence.push_back(input);
            if (cin.get() == '\n') break;
        }
    }

    if (isError)
    {
        cout << "\033[2A\033[J" << msg;
        for (size_t i = 0; i < size; i++) cout << sequence[i] << ' ';
        cout << endl;
    }
    return sequence;
}

void getNumericArrayOfUserInput(const std::string msg, int arr[], const size_t size, const int low, const int high)
{
    cout << msg;
    int input;
    bool isError = false;
    for (size_t i = 1;;)
    {
        if ((cin >> noskipws >> input >> skipws).fail() ||
            ((i != size) && cin.peek() != ' ') ||
            ((i == size) && cin.peek() != '\n') ||
            (input < low || input > high))
        {
            i = 1;
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');

            cout << "\033[" << ((isError) ? 2 : 1) << "A\033[J\033[3;31m"
                 << "Error: Invalid input. Please try again...\033[0m\n"
                 << msg;
            isError = true;
        }
        else
        {
            arr[i - 1] = input;
            if (cin.get() == '\n') break;
            i++;
        }
    }

    if (isError)
    {
        cout << "\033[2A\033[J" << msg;
        for (size_t i = 0; i < size; i++) cout << arr[i] << ' ';
        cout << endl;
    }
}

void getPositiveNumericArrayOfUserInput(const std::string msg, unsigned arr[], const size_t size, const unsigned low, const unsigned high)
{
    cout << msg;
    unsigned input;
    bool isError = false;
    for (size_t i = 1;;)
    {
        if (cin.peek() == '-' ||
            (cin >> noskipws >> input >> skipws).fail() ||
            ((i != size) && cin.peek() != ' ') ||
            ((i == size) && cin.peek() != '\n') ||
            (input < low || input > high))
        {
            i = 1;
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');

            cout << "\033[" << ((isError) ? 2 : 1) << "A\033[J\033[3;31m"
                 << "Error: Invalid input. Please try again...\033[0m\n"
                 << msg;
            isError = true;
        }
        else
        {
            arr[i - 1] = input;
            if (cin.get() == '\n') break;
            i++;
        }
    }

    if (isError)
    {
        cout << "\033[2A\033[J" << msg;
        for (size_t i = 0; i < size; i++) cout << arr[i] << ' ';
        cout << endl;
    }
}

void getFloatNumberArrayOfUserInput(const std::string msg, float arr[], const size_t size, const float low, const float high)
{
    cout << msg;
    float input;
    bool isError = false;
    for (size_t i = 1;;)
    {
        if ((cin >> noskipws >> input >> skipws).fail() ||
            ((i != size) && cin.peek() != ' ') ||
            ((i == size) && cin.peek() != '\n') ||
            (input < low || input > high))
        {
            i = 1;
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');

            cout << "\033[" << ((isError) ? 2 : 1) << "A\033[J\033[3;31m"
                 << "Error: Invalid input. Please try again...\033[0m\n"
                 << msg;
            isError = true;
        }
        else
        {
            arr[i - 1] = input;
            if (cin.get() == '\n') break;
            i++;
        }
    }

    if (isError)
    {
        cout << "\033[2A\033[J" << msg;
        for (size_t i = 0; i < size; i++) cout << arr[i] << ' ';
        cout << endl;
    }
}

void preventConsoleClosing()
{
    cin.clear();
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    cin.get();
}
