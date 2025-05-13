#include <iostream>
using namespace std;

// membuat struktur untuk object double linkedlist
struct Node
{
    int noMhs;
    string name;

    Node *next;
    Node *prev;
};

Node *START = NULL;

// deklarasi prosedur addnode
void addNode()
{
    Node *newNode = new Node();
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs;
    cout << "\nEnter the name of the student: ";
    cin >> newNode->name;

    // insert the new node in the list
    // kondisi jika start == null atau noMhs node baru <=noMhs start

    if (START == NULL || newNode->noMhs <= START->noMhs)
    {
        // step 2: insert the new node at the beginning
        // kondisi jika start tidak kosong dan noMhs node baru sama dengan noMhs
        if (START != NULL && newNode->noMhs == START->noMhs)
        {
            cout << "\033[31mDuplicate roll numbers not allowe\033[0m" << endl;
            return;
        }
        // jika list kosong, maka node text nya adalah START
        newNode->next = START;
        // kondisi jika start tidak memiliki nilai atau tidak kosong
        if (START != NULL)
        {
            START->prev = newNode;
        }
        newNode->prev = NULL;
        START = newNode;
    }
    // kondisi jika semua kondisi if tidak terpenuhi
    else
    {

        Node *current = START;
        Node *previous = NULL;

        while (current != NULL && current->noMhs < newNode->noMhs)
        {
            previous = current;
            current = current->next;
        }

        newNode->next = current;
        newNode->prev = previous;
    }

    // kondisi jika current tidak sama dengan null
    if (current != NULL)
    {
        current->prev = newNode;
    }

    if (previous != NULL)
    {
        previous->next = newNode;
    }
    
}