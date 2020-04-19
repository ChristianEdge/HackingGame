#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void PrintIntro(int level)
{
    cout << "\nYou are attempting to access a LEVEL " << level << " secure system.";
    cout << "\nEnter the correct code to continue.";
}

int RandomInt(int range) //Returns int between 1 and range (inclusive)
{
    return (rand() % range) + 1;
}

bool PlayGame(int level)
{
    PrintIntro(level);

    //Set random time seed
    srand(time(0));

    const int CodeA = RandomInt(level + 3);
    const int CodeB = RandomInt(level + 3);
    const int CodeC = RandomInt(level + 3);

    //Testing
    //cout << "A, B, C = " << CodeA << ", " << CodeB << ", " << CodeC << "\n\n";
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    cout << "\n\t- There are 3 numbers in the code.";
    cout << "\n\t- The numbers are between 1 and " << level + 3 << ".";
    cout << "\n\t- The sum of the code numbers is equal to " << CodeSum << ".";
    cout << "\n\t- The product of the code numbers is equal to " << CodeProduct << ".";

    int GuessA, GuessB, GuessC, GuessSum, GuessProduct;

    cout << "\n\nEnter your 3 guesses. Please input 3 integers (1-" << level + 3;
    cout << ") separated by spaces : ";
    cin >> GuessA >> GuessB >> GuessC;
    cout << "\nYou entered " << GuessA << GuessB << GuessC << endl;

    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    //Testing
    //cout << "\nYour guess sum : " << GuessSum;
    //cout << "\nYour guess product : " << GuessProduct << "\n";

    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        cout << "\n\t***SUCCESS*** \tLevel permission granted!\n\n";
        return true;
    }
    else
    {
        cout << "\n\t***FAILED*** \tAttempt failed. Try again.\n\n";
        return false;
    }
}

int main()
{
    int LevelDifficulty = 1;
    const int MaxDifficulty = 3;

    cout << "\n\t\t*****   TRIPLE X HACKER   *****\n"; //Game Title

    while (LevelDifficulty <= MaxDifficulty) //Loop until all levels completed
    {
        bool b_Gaming = PlayGame(LevelDifficulty);  //Conventional to name bools starting with lowercase 'b'

        cin.clear(); //Clears any errors
        cin.ignore(); //Clears buffer

        if (b_Gaming)
        {
            LevelDifficulty++; //Level completed: increase difficulty.
        }
    }

    cout << "\n\n******************************************\n";
    cout << "\t*** MISSION COMPLETE ***\n";
    cout << "\t*** ALL LEVELS HACKED ***";
    cout << "\n\n******************************************\n";
    cout << "\n\n\t\t\tGame Over.\n\t\t    Thanks for playing!"<< endl;
    
    return 0;
}//end main()