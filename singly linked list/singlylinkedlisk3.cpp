#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Insert node at end
void insert(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display linked list
void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Find multiple occurrences
void findOccurrences(Node* head, int value)
{
    Node* temp = head;
    int position = 1;
    int count = 0;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << "Value found at position: "
                 << position << endl;

            count++;
        }

        temp = temp->next;
        position++;
    }

    if (count == 0)
    {
        cout << "Value not found." << endl;
    }
    else
    {
        cout << "Total occurrences: " << count << endl;
    }
}

int main()
{
    Node* head = NULL;

    // Creating list
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 20);
    insert(head, 40);
    insert(head, 20);
    insert(head, 50);

    cout << "Linked List: ";
    display(head);

    // Search value
    int value = 20;

    cout << "Searching for: " << value << endl;

    findOccurrences(head, value);

    return 0;
}
