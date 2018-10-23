string convertToUpper(string str)
{
    for (int i =0; i < str.length; i++) {
        str[i] = toupper(str[i]); 
    }
    return str; 
}

bool isBefore(string first, string second)
{
    string upcasedFirst = convertToUpper(first); 
    string upcasedSecond = convertToUpper(second);

    if (upcasedFirst < upcasedSecond) {
        return true;
    } else {
        return false;
    } 
}

void stringSort(string arr[], int size)
{
    int startScan, minIndex, minString;

    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minString = arr[startScan];

        for (int index = startScan + 1; index < size; index++) {
            if (isBefore(arr[index], minString)) {
                minString = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minString;
    }
}

int main()
{
    string arr[3] = {"abra", "zebra", "Kadabra"};
    stringSort(arr, 3); 
    return 0;
}
