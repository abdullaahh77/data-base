#include <iostream>
using namespace std;

int main() {
    int arr[100], size, search, i;
    
    cout << "Enter number of elements: ";
    cin >> size;
    
    cout << "Enter " << size << " elements: ";
    for (i = 0; i < size; i++)
        cin >> arr[i];
    
    cout << "Enter value to search: ";
    cin >> search;
    
    i = 0;
    while (i < size && arr[i] != search)
        i++;
    
    if (i < size)
        cout << search << " found at index " << i << endl;
    else
        cout << search << " not found!" << endl;
    
    return 0;
}
