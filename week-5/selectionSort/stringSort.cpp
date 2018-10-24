/*********************************************************************************************
 ***** Author: Jed Piezas
 ***** Date: October 23 2018
 ****** Description:  Uses the Selection sort algorithm to rearrange an array of strings
 ******               in alphabetical order. Sorting is case insensitive, e.g. zepplin > Zebra
 *********************************************************************************************/

#include <string>

using std::string;

// Function prototypes for helper methods
string convertToUpper(string);
bool isBefore(string, string);

void stringSort(string arr[], int size)
{
    int startScan, minIndex; 
    string minString;
    
    // Iterate through the array of strings up to the n-1th index
    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minString = arr[startScan];
        // Iterate through start + 1 to the end of the array
        for (int index = startScan + 1; index < size; index++) {
            // If our iterand comes before our minString
            // Keep track of the iterand's position and make the 
            // minString the iterand's value
            if (isBefore(arr[index], minString)) {
                minString = arr[index];
                minIndex = index;
            }
        }
        // Swap the values between the value of the iterand and
        // the value of the startScan string
        arr[minIndex] = arr[startScan];
        arr[startScan] = minString;
    }
}


/****************************************************************
 ** Takes a C++ string and converts each character to uppercase.
 ** Used as a helper method to compare strings regardless of case
 *****************************************************************/
string convertToUpper(string str)
{
    for (int i =0; i < str.length(); i++) {
        str[i] = toupper(str[i]); 
    }
    return str; 
}

/****************************************************************
 ** Compares two string inputs and uses the string library's
 ** lexicographic comparator to determine if one string comes 
 ** before another
 *****************************************************************/
bool isBefore(string first, string second)
{
    // Make upper-case copies of both strings
    string upcasedFirst = convertToUpper(first); 
    string upcasedSecond = convertToUpper(second);
    
    // Do a comparison to see which string takes precedence
    if (upcasedFirst < upcasedSecond) {
        return true;
    } else {
        return false;
    } 
}
