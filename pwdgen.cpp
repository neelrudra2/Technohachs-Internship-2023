#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

using namespace std;

string generatePassword(int length, bool useUppercase, bool useLowercase, bool useNumbers, bool useSpecialChars)
{
    const string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    const string numberChars = "0123456789";
    const string specialChars = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    string availableChars = "";

    if (useUppercase)
    {
        availableChars += uppercaseChars;
    }
    if (useLowercase)
    {
        availableChars += lowercaseChars;
    }
    if (useNumbers)
    {
        availableChars += numberChars;
    }
    if (useSpecialChars)
    {
        availableChars += specialChars;
    }

    if (availableChars.empty())
    {
        return "No character types selected. Please enable at least one character type.";
    }

    srand(static_cast<unsigned int>(time(nullptr)));
    string password;

    for (int i = 0; i < length; ++i)
    {
        int randomIndex = rand() % availableChars.length();
        password += availableChars[randomIndex];
    }

    return password;
}

int main()
{
    int passwordLength;
    bool useUppercase, useLowercase, useNumbers, useSpecialChars;

    cout << "\n\n";
    cout << "Enter the desired password length: ";
    cin >> passwordLength;

    if (passwordLength <= 0)
    {
        cout << "Password length must be a positive integer." << endl;
        return 1;
    }

    cout << "Include Uppercase Letters (Y/N): ";
    char uppercaseChoice;
    cin >> uppercaseChoice;
    useUppercase = (toupper(uppercaseChoice) == 'Y');

    cout << "Include Lowercase Letters (Y/N): ";
    char lowercaseChoice;
    cin >> lowercaseChoice;
    useLowercase = (toupper(lowercaseChoice) == 'Y');

    cout << "Include Numbers (Y/N): ";
    char numbersChoice;
    cin >> numbersChoice;
    useNumbers = (toupper(numbersChoice) == 'Y');

    cout << "Include Special Characters (Y/N): ";
    char specialCharsChoice;
    cin >> specialCharsChoice;
    useSpecialChars = (toupper(specialCharsChoice) == 'Y');

    string password = generatePassword(passwordLength, useUppercase, useLowercase, useNumbers, useSpecialChars);

    cout << "Generated Password: " << password << endl;

    return 0;
}
