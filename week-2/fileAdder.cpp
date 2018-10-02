/********************************************************************************* Author: Jed Piezas
** Date: October 1 2018
** Description:  Prompts the user to enter the name of a file containing numbers**               delimited by a single line. 
**               If it is able to read the file, it will sum the numbers and 
**               notify the user that it outputted the sum to sum.txt. 
**               Otherwise, it will print that it was unable to read the file.
*********************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    string fileName;
    string outputFileName = "sum.txt";

    // Prompt the user for a filename
    cout << "Please enter your filename." << endl;
    cin >> fileName;
    
    // Try and open the file
    inputFile.open(fileName);
    if ( inputFile.fail() ) {
        // Let the user know that file couldn't be accessed
        cout << "could not access file" << endl;
    } else {
        int numberToAdd;
        int total;
        
        // Loop through values in the file and add them to the total
        while (inputFile >> numberToAdd) {
            total += numberToAdd;
        }
        // Close the inputFile
        inputFile.close();

        // Open a file stream, write the total, and close the file
        outputFile.open(outputFileName);
        outputFile << total;
        outputFile.close();
        
        cout << "result written to " << outputFileName << endl;
    }
    
    return 0;    
}
