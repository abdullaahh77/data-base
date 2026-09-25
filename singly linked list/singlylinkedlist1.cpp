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

// Reverse display using loop
void reverseUsingLoop(Node* head)
{
    int count = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int arr[count];

    temp = head;

    for (int i = 0; i < count; i++)
    {
        arr[i] = temp->data;
        temp = temp->next;
    }

    cout << "Reverse using Loop: ";

    for (int i = count - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// Reverse display using recursion
void reverseUsingRecursion(Node* head)
{
    if (head == NULL)
        return;

    reverseUsingRecursion(head->next);

    cout << head->data << " ";
}

int main()
{
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    cout << "Original List: ";

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    reverseUsingLoop(head);

    cout << "Reverse using Recursion: ";
    reverseUsingRecursion(head);

    return 0;
}
