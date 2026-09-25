#include <iostream>
using namespace std;

class ArrayList {
private:
    int arr[100];
    int size;
    
public:
    ArrayList() {
        size = 0;
    }
    
    // 1. Insert at end
    void insertEnd(int val) {
        if (size < 100) {
            arr[size] = val;
            size++;
            cout << "Inserted " << val << " at end\n";
        } else {
            cout << "List full!\n";
        }
    }
    
    // 2. Insert at start
    void insertStart(int val) {
        if (size < 100) {
            for (int i = size; i > 0; i--)
                arr[i] = arr[i - 1];
            arr[0] = val;
            size++;
            cout << "Inserted " << val << " at start\n";
        } else {
            cout << "List full!\n";
        }
    }
    
    // 3. Insert after specific value
    void insertAfter(int after, int val) {
        int pos = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == after) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << after << " not found!\n";
            return;
        }
        if (size < 100) {
            for (int i = size; i > pos + 1; i--)
                arr[i] = arr[i - 1];
            arr[pos + 1] = val;
            size++;
            cout << "Inserted " << val << " after " << after << endl;
        } else {
            cout << "List full!\n";
        }
    }
    
    // 4. Insert before specific value
    void insertBefore(int before, int val) {
        int pos = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == before) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << before << " not found!\n";
            return;
        }
        if (size < 100) {
            for (int i = size; i > pos; i--)
                arr[i] = arr[i - 1];
            arr[pos] = val;
            size++;
            cout << "Inserted " << val << " before " << before << endl;
        } else {
            cout << "List full!\n";
        }
    }
    
    // 5. Display
    void display() {
        if (size == 0) {
            cout << "List is empty!\n";
            return;
        }
        cout << "List: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    
    // 6. Delete from end
    void deleteEnd() {
        if (size == 0) {
            cout << "List empty!\n";
            return;
        }
        cout << "Deleted " << arr[size - 1] << " from end\n";
        size--;
    }
    
    // 7. Delete from start
    void deleteStart() {
        if (size == 0) {
            cout << "List empty!\n";
            return;
        }
        cout << "Deleted " << arr[0] << " from start\n";
        for (int i = 0; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }
    
    // 8. Delete specific value
    void deleteVal(int val) {
        int pos = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == val) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << val << " not found!\n";
            return;
        }
        for (int i = pos; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
        cout << "Deleted " << val << endl;
    }
    
    // Lab Task 3: Linear Search using while loop
    void linearSearch(int val) {
        int i = 0;
        int found = 0;
        
        while (i < size) {
            if (arr[i] == val) {
                cout << val << " found at index " << i << endl;
                found = 1;
                break;
            }
            i++;
        }
        
        if (found == 0)
            cout << val << " not found!\n";
    }
};

int main() {
    ArrayList list;
    int choice, val, target;
    
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Insert at end" << endl;
        cout << "2. Insert at start" << endl;
        cout << "3. Insert after specific value" << endl;
        cout << "4. Insert before specific value" << endl;
        cout << "5. Display list" << endl;
        cout << "6. Delete from end" << endl;
        cout << "7. Delete from start" << endl;
        cout << "8. Delete specific value" << endl;
        cout << "9. Linear Search (while loop)" << endl;
        cout << "10. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertEnd(val);
                break;
                
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertStart(val);
                break;
                
            case 3:
                cout << "Enter after value: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> val;
                list.insertAfter(target, val);
                break;
                
            case 4:
                cout << "Enter before value: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> val;
                list.insertBefore(target, val);
                break;
                
            case 5:
                list.display();
                break;
                
            case 6:
                list.deleteEnd();
                break;
                
            case 7:
                list.deleteStart();
                break;
                
            case 8:
                cout << "Enter value to delete: ";
                cin >> val;
                list.deleteVal(val);
                break;
                
            case 9:
                cout << "Enter value to search: ";
                cin >> val;
                list.linearSearch(val);
                break;
                
            case 10:
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 10);
    
    return 0;
}
