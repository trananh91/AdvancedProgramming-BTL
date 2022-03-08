#include <iostream>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

string animals[] = {"cat", "dog", "fish", "bird", "snake", "rabbit", "bear", "horse", "lion", "tiger", "chicken", "deer", "cow", "goose", "swan", "wolf", "eagle", "alligator", "frog"};

string players[] = {"Mount", "Reece", "Chalobah", "Mendy", "Azpi", "Silva", "Rudiger", "Chillwell", "Kovacic", "Jorginho", "Kante", "Pulisic", "Havertz", "Werner", "Lukaku", "Odoi", "Kepa", "Kenedy"};

string colors[] = {"yellow", "red", "blue", "purple", "pink", "black", "white", "brown", "green", "grey", "orange"};

string brands[] = {"Toyota", "Kia", "Hyundai", "Lamborghini", "Chevorlet", "MG", "Ferrari", "Telsa", "RollRoyce", "Bugatti", "Bentley", "Porsche", "AstonMartin", "Mercedes", "BMW", "Volvo", "Vinfast"};


#define MAX_BAD_GUESSES 7

const string FIGURE[] = {
    "  -------------   \n"
    "  |               \n"
    "  |               \n"
    "  |               \n"
    "  |               \n"
    "  |      \n"
    "-----    \n",
    "  -------------   \n"
    "  |           |    \n"
    "  |               \n"
    "  |               \n"
    "  |               \n"
    "  |      \n"
    "-----    \n",
    "  -------------   \n"
    "  |           |   \n"
    "  |           o   \n"
    "  |               \n"
    "  |               \n"
    "  |      \n"
    "-----    \n",
    "  -------------   \n"
    "  |           |   \n"
    "  |           o   \n"
    "  |           |   \n"
    "  |               \n"
    "  |      \n"
    "-----    \n",
    "  -------------   \n"
    "  |           |   \n"
    "  |           o   \n"
    "  |          /|   \n"
    "  |               \n"
    "  |      \n"
    "-----    \n",
    "  -------------   \n"
    "  |           |   \n"
    "  |           o   \n"
    "  |          /|\\ \n"
    "  |               \n"
    "  |      \n"
    "-----    \n",
    "  -------------   \n"
    "  |           |   \n"
    "  |           o   \n"
    "  |          /|\\ \n"
    "  |          /    \n"
    "  |      \n"
    "-----    \n",
    "  -------------   \n"
    "  |           |   \n"
    "  |           o   \n"
    "  |          /|\\ \n"
    "  |          / \\ \n"
    "  |      \n"
    "-----    \n",
};

string toLower(string& word)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = tolower(word[i]);
    }
    return word;
}

void initGame(string& secretW, string& guessW, int& badGuessCount, int topic)
{
    badGuessCount = 0;
    cout << "(1): Animals\n" << "(2): Chelsea Players\n" << "(3): Colors\n" << "(4): Car brands\n";
    cout << "Type the number of the topic you would like to play: ";
    cin >> topic;
    int index;
    switch(topic)
    {
        case 1:{index = rand() % sizeof(animals)/sizeof(string);
                secretW = animals[index];
                break;}
        case 2:{index = rand() % sizeof(players)/sizeof(string);
                secretW = players[index];
                break;}
        case 3:{index = rand() % sizeof(colors)/sizeof(string);
                secretW = colors[index];
                break;}
        case 4:{index = rand() % sizeof(brands)/sizeof(string);
                secretW = brands[index];
                break;}
    }
    secretW = toLower(secretW);
    guessW = string(secretW.length(), '-');
}

void display(string& secretW, string& guessW, int badGuessCount)
{
    cout << guessW << " " << badGuessCount << endl;
    // Ve Hangman
    cout << FIGURE[badGuessCount] << endl;
}

bool contains(string& W, char c)
{
    return (W.find_first_of(c)!= string::npos);
}

void UpdateGame(char input, string& secretW, string& guessW, int& badGuessCount)
{
    if (contains(secretW,input))
    {
        for (int i = 0; i < guessW.length(); i++)
        {
            if(secretW[i] == input)
            {
                guessW[i] = input;
            }
        }
    }
    else{
        badGuessCount++;
    }
}

bool GameOver (const string &secretW, const string &guessW, int badGuessCount)
{
    return (secretW == guessW || badGuessCount >= MAX_BAD_GUESSES);
}

void displayResult(const string& secretW, int& badGuessCount)
{
        if (badGuessCount >= MAX_BAD_GUESSES)
        {
            cout << "You lost!\n";
            cout << "The secret word is: " << secretW << endl;
        }
        else{
            if (badGuessCount > 1)
            {
                printf("Congrats! You won after %d wrong guesses! ", badGuessCount);
                cout << "The secret word is: " << secretW << endl;
            }
            else{
                printf("Congrats! You won after %d wrong guess! ", badGuessCount);
                cout << "The secret word is: " << secretW << endl;}
        }
}

char getInput()
{
    string input;
    cin >> input;
    return tolower(input[0]);
}

int main()
{
    srand(time(0));
    string secretW;
    string guessW;
    int badGuessCount;
    int topic;
    char ans;
    do{
    initGame(secretW, guessW, badGuessCount, topic);
    do
    {
        display(secretW, guessW, badGuessCount );
        char input = getInput();
        UpdateGame(input, secretW, guessW, badGuessCount);
    }while(!GameOver(secretW, guessW, badGuessCount));
    displayResult(secretW, badGuessCount);
    cout << endl;
    cout << "Do you want to replay? y/n ";
    cin >> ans;
    }while(ans == 'y');
}

