#include <iostream>
// allows you to read data from files
#include <fstream>
#include <string>

using namespace std;

// const int means int user cannot manipulate
const int teamnames = 31;
const int winnings = 115;
// can be either true or false
bool namecheck = false;
// no numbers only letter values
string linerec;
string username;
string teamwins[winnings];
string teamarray[teamnames];
// manipulatable number
int counter = 0;

int main()
{
    // opens the txt doc outside of program
    ifstream WorldSeriesWinners("WorldSeriesWinners.txt");
    ifstream Teams("Teams.txt");

    // getline pulls info (letters) from outside txt doc
    while (getline(Teams, linerec))
    {
        cout << linerec << endl;
    }
    
    cout << "Please enter name of team from above list. Case sensitive: " << endl;
    getline(cin, username);

    // clears value at 0
    Teams.clear(0);
    // moves pointer to first value listed in () example file.seekg(10)
    Teams.seekg(0);

    // If the condition is true, the loop body is executed. If it is false, the loop terminates.
    for (int index = 0; index < teamnames; index++)
    {
        while (getline(Teams, linerec))
        {
            // creates array to hold name and checks against users chosen name
            teamarray[index] = linerec;
            if (teamarray[index] == username)
            {
                namecheck = true;
                break;;
            }
        }
    }
    // checks the users chosen name agains number of wins.
    if (namecheck)
    {
        // counter. Counts number of wins and stores in array
        for (int index = 0; index < winnings; index++)
        {
            while (getline(WorldSeriesWinners, linerec))
            {
                teamwins[index] = linerec;

                // everytime users chosen name is found ticks on the counter until end of file when it holds the total number of wins
                if (teamwins[index] == username)
                {
                    counter++;
                }
            }
        }
        cout << username << " has won " << counter++ << " World Series." << endl;
    }
    else
    {
        cout << "Choice not valid." << endl;
    }
   
    return 0;

}
