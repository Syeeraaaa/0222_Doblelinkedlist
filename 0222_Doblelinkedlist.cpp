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

        // kondisi jika current tidak sama dengan null
        if (current != NULL)
        {
            current->prev = newNode;
        }

        if (previous != NULL)
        {
            previous->next = newNode;
        }
        else
        {
            START = newNode;
        }
    }
};

bool search(int rollNo, Node **previous, Node **current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

void deleteNode()
{
    Node *previous, *current;
    int rollNo;

    cout << "\nEntr the roll number of the student whose record is to be delete: ";
    cin >> rollNo;

    if (START = NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    current = START;
    previous = NULL;

    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }
    if (current = NULL)
    {
        cout << "\033[31mThe record with roll number" << rollNo << "not found/033[0m" << endl;
        return;
    }

    if (current = START)
    {
        START = START->next;
        if (START != NULL)
        {
            START->prev = NULL;
        }
    }
    else
    {
        previous->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = previous;
        }
    }

    delete current;
    cout << "\x1b[32mRecod with roll numbr " << rollNo << "delete\x1b[0m" << endl;
}

// method untuk mengecek apakah list kosng
bool ListEmpty()
{
    return (START == NULL);
}

// prosedur traverse untuk menampilkan data secara urut
void traverse()
{
    if (ListEmpty())
        cout << "\nList is empty\n";
    else
    {
        cout << "\nRecored in ascending order of roll number are: " << endl;
        Node *currentNode = START;
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << "" << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
    }
}

void revtraverse()
{
    if (ListEmpty())
        cout << "\nList is empty\n";
    else
    {
        cout << "\nRecored in ascending order of roll number are: " << endl;
        Node *currentNode = START;
        while (currentNode->next != NULL)
        
            currentNode = currentNode->next;
        
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << "" << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
    }
}