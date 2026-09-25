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

// Merge two lists into a third new list
Node* mergeLists(Node* head1, Node* head2)
{
    Node* newHead = NULL;
    Node* tail = NULL;

    // Copy first list
    Node* temp = head1;

    while (temp != NULL)
    {
        Node* newNode = new Node;
        newNode->data = temp->data;
        newNode->next = NULL;

        if (newHead == NULL)
        {
            newHead = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        temp = temp->next;
    }

    // Copy second list
    temp = head2;

    while (temp != NULL)
    {
        Node* newNode = new Node;
        newNode->data = temp->data;
        newNode->next = NULL;

        if (newHead == NULL)
        {
            newHead = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        temp = temp->next;
    }

    return newHead;
}

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head3 = NULL;

    // First list
    insert(head1, 10);
    insert(head1, 20);
    insert(head1, 30);

    // Second list
    insert(head2, 40);
    insert(head2, 50);
    insert(head2, 60);

    cout << "First List: ";
    display(head1);

    cout << "Second List: ";
    display(head2);

    // Merge
    head3 = mergeLists(head1, head2);

    cout << "Third List after Merging: ";
    display(head3);

    return 0;
}
