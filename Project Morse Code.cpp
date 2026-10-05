#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main()
{
    // Morse code for letters A-Z
    string morseCode[26];

    morseCode[0] = ".-";    // A
    morseCode[1] = "-...";  // B
    morseCode[2] = "-.-.";  // C
    morseCode[3] = "-..";   // D
    morseCode[4] = ".";     // E
    morseCode[5] = "..-.";  // F
    morseCode[6] = "--.";   // G
    morseCode[7] = "....";  // H
    morseCode[8] = "..";    // I
    morseCode[9] = ".---";  // J
    morseCode[10] = "-.-";  // K
    morseCode[11] = ".-.."; // L
    morseCode[12] = "--";   // M
    morseCode[13] = "-.";   // N
    morseCode[14] = "---";  // O
    morseCode[15] = ".--."; // P
    morseCode[16] = "--.-"; // Q
    morseCode[17] = ".-.";  // R
    morseCode[18] = "...";  // S
    morseCode[19] = "-";    // T
    morseCode[20] = "..-";  // U
    morseCode[21] = "...-"; // V
    morseCode[22] = ".--";  // W
    morseCode[23] = "-..-"; // X
    morseCode[24] = "-.--"; // Y
    morseCode[25] = "--.."; // Z

    string morseNumbers[10];

    morseNumbers[0] = "-----"; //0
    morseNumbers[1] = ".----"; //1
    morseNumbers[2] = "..---"; //2
    morseNumbers[3] = "...--"; //3
    morseNumbers[4] = "....-"; //4
    morseNumbers[5] = "....."; //5
    morseNumbers[6] = "-...."; //6
    morseNumbers[7] = "--..."; //7
    morseNumbers[8] = "---.."; //8
    morseNumbers[9] = "----."; //9


    int choice;

    cout << "==============================" << endl;
    cout << "     MORSE CODE TRANSLATOR" << endl;
    cout << "==============================" << endl;
    cout << "1. English -> Morse" << endl;
    cout << "2. Morse -> English" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an option: ";

    cin >> choice;
    cin.ignore();

    // English -> Morse
    if (choice == 1)
    {
        string userInput;

        cout << "Enter an English message: ";
        getline(cin, userInput);

        string translate = "";

        for (int i = 0; i < userInput.length(); i++)
        {
            char currentChar = tolower(userInput[i]);

            if (currentChar == ' ')
            {
                translate += "/ ";
                continue;
            }

            int j = currentChar - 'a';

            if (currentChar >= 'a' && currentChar <= 'z')
            {
                int j = currentChar - 'a';
                
                translate += morseCode[j];
                translate += "";

            }
            else if (currentChar >= '0' && currentChar <= '9')
            {
                int j = currentChar - '0';

                translate += morseNumbers[j];
                translate += " ";
            }
        }

        cout << "Morse Code: " << translate << endl;
    }

    // Morse -> English
    else if (choice == 2)
    {
        string userInput;

        cout << "Enter Morse code: ";
        getline(cin, userInput);

        stringstream ss(userInput);
        string code;
        string translate = "";


        while (ss >> code)
        {

            if (code == "/")
            {
                translate += " ";
            }
            else
            {

                bool found = false;
                for (int i = 0; i<26; i++)
                {
                    if (morseCode[i] == code)
                    {
                        translate += char('A' + i);
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    for (int i = 0; i < 10; i++)
                    {
                        if (morseNumbers[i] == code)
                        {
                            translate += char('0' + i);
                            found = true;
                            break;
                        }
                    }
                }
            }
        }

        cout << "English: " << translate << endl;
    }

    // Exit
    else if (choice == 3)
    {
        cout << "Goodbye!" << endl;
    }

    // Invalid option
    else
    {
        cout << "Invalid option!" << endl;
    }

    return 0;
}