// Map Percentage Calculator for The Legend of Zelda: Breath of the Wild 
// By Sean Allgaier

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void errorMessage();

int main()
{
    // Variable declarations

    // Variables that represent total values of the collectibles and the percentage.
    float 
    mapTotal = 99.99, divineBeastTotal = 4, shrineTotal = 120, locationTotal = 188, korokTotal = 900;

    // Variables representing the different percentage weights.
    float
    individualWeight = 0.0825, divineBeastWeight = 0.33, shrineWeight = 9.9, locationWeight = 15.51, korokWeight = 74.25;        
    
    // Variables necessary for performing the math and for user information.
    float
        mapPercent, remainingMapPercent, divineBeastPercent, shrinePercent, korokPercent, locationPercent,
        divineBeastCount, shrineCount, korokCount;
    // Even more variables necessary for performing the math and for user information.
    int locationCount, remainingLocations, remainingKoroks, remainingDivineBeasts, remainingShrines;


    // Numbers being used to make it easier to line up the text in the menus.  
    


    // Menu displaying the percentage weights of each collectible category.
    cout << endl
    //      0         1         2         3         4         5           
    //      012345678901234567890123456789012345678901234567890
        << "###################################################" << endl
        << "                 Breath of the Wild                " << endl
        << "         Remaining Collectible Calculator          " << endl
        << "                 By Sean Allgaier                  " << endl
        << "###################################################" << endl
        << "    4 Divine Beasts = 0.33% total (0.0825% each)   " << endl
        << "      120 shrines = 9.9% total (0.0825% each)      " << endl
        << "  188 Map Locations = 15.51% total (0.0825% each)  " << endl 
        << "   900 korok seeds = 74.25% total (0.0825% each)   " << endl
        << "###################################################" << endl;
    // Overall all the percentages total up to only 99.99%, hence why the variable "mapTotal" is equal to 99.99 and not 100
    // The reason why it's 99.99% instead of 100% is because the game adds an additional 0.01% in order to evenly round it up.
    
    // Point in program to return to in the event of invalid user input that *could* result in a calculation error.
    userInput:

    // Prompts users to input data of their save files.
    cout << "Percentage shown on your map: ";
    cin >> mapPercent;
    cout << "# of completed divine beasts: ";
    cin >> divineBeastCount;
    cout << "# of completed shrines: ";
    cin >> shrineCount;
    cout << "# of discovered korok seeds: ";
    cin >> korokCount;

    // Checks if the values inputted by the user are equivalent to each categories respective total value required for 100%.
    if (
        (mapPercent == 100)
        &&
        (divineBeastCount == 4)
        &&
        (shrineCount == 120)
        &&
        (korokCount == 900)
        )
    {
        cout << endl << "Congratulations! You have no life!" << endl << endl;
        return 0;
    }
    // Checks if the user inputted values are possible to begin with.
    else if (
        (divineBeastCount < 0 || divineBeastCount > 4)
        ||
        (shrineCount < 0 || shrineCount > 120)
        ||
        (korokCount < 0 || korokCount > 900)
        )
    {
        errorMessage();
        goto userInput;
    }

    // If all failure checks are passed, calculate the percentages of each collection category based on the user's inputs.
    divineBeastPercent = divineBeastCount * individualWeight;
    shrinePercent = shrineCount * individualWeight;
    korokPercent = korokCount * individualWeight;

 

    // Math to calculate 2 things:
    // 1) The number of discovered and undiscovered locations the percentage value of the discovered locations
    remainingMapPercent = mapPercent - (divineBeastPercent + shrinePercent + korokPercent);
    locationCount = remainingMapPercent / individualWeight;
    locationPercent = locationCount * individualWeight;
    // 2) The number of remaining collectibles of each collection
    remainingDivineBeasts = divineBeastTotal - divineBeastCount;
    remainingKoroks = korokTotal - korokCount;
    remainingLocations = locationTotal - locationCount;
    remainingShrines = shrineTotal - shrineCount;

    // If the sum of all the calculated percentages are not equal to the percentage displayed on the user's map,
    // then that means the user made an invalid input. 

    // if (mapPercent != (divineBeastPercent + shrinePercent + korokPercent + locationPercent))
    // {
    //     errorMessage();
    //     goto userInput;
    // }

    // ....or I'm a dumbass and forgot that I'm using floats for my percentage values in order for my math to be percise
    // However, that means my math is actually more percise than the percentage value shown on the map.
    // The map percentage meter is percise up to 2 decimal places, but the math is actually as percise as 4 decimal places at some points.



    // Final failure check: 
    // The remaining values of each collection category is the difference between the total number of the collectibles
    // and the number of collectibles that the user has collected.
    // If the remaining value is equal to 0, then that means the user has collected all possible collectibles,
    // If the remaining value is more than 0, then that means the user is missing some collectibles,
    // If the remaining value is somehow less than 0, that means a previous error check didn't stop a mistake from the
    // user that *could* result in a calculation error.  

    if ((remainingDivineBeasts < 0) || (remainingKoroks < 0) || (remainingLocations < 0) || (remainingShrines < 0))
    {
        errorMessage();
        goto userInput;
    }       

    // Menu to output all the calculations.
    cout
        << "###################################################" << endl
        << "Results:" << endl

        << "Divine Beasts: " << endl
        << divineBeastCount << " / " << divineBeastTotal << " completed (" << remainingDivineBeasts << " remaining)" << endl
        << divineBeastPercent << "% / " << divineBeastWeight << "% completed" << endl

        << endl << "Shrines: " << endl
        << shrineCount << " / " << shrineTotal << " completed (" << remainingShrines << " remaining)" << endl
        << shrinePercent << "% / " << shrineWeight << "% completed" << endl 

        << endl << "Koroks: " << endl
        << korokCount << " / " << korokTotal << " completed (" << remainingKoroks << " remaining)" << endl
        << korokPercent << "% / " << korokWeight << "% completed" << endl

        << endl << "Locations: " << endl
        << locationCount << " / " << locationTotal << " discovered (" << remainingLocations << " remaining)" << endl
        << locationPercent << "% / " << locationWeight << "% completed" << endl

        << "###################################################" << endl << endl;
    return 0;
}

// Function that displays error message when the program detects an error.
void errorMessage()
{
    cout << "Invalid input, please try again." << endl << endl;
}