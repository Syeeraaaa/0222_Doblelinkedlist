#include <iostream>
using namespace std;

// membuat struktur untuk object double linkedlist
struct Node
{
    int noMhs;
    string name;

    Node*next;
    Node*prev;
};

Node*START = NULL;

// deklarasi prosedur addnode 
void addNode(){
    Node *newNode = new Node();
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs;
    cout << "\nEnter the name of the student: ";
    cin >> newNode->name;

    // insert the new node in the list 
    //kondisi jika start == null atau noMhs node baru <=noMhs start

    if (START == NULL || newNode->noMhs <= START->noMhs)
    {
        // step 2: insert the new node at the beginning 
        //kondisi jika start tidak kosong dan noMhs node baru sama dengan noMhs
        if (START != NULL && newNode ->noMhs == START->noMhs)
        {
            /* code */
        }
        
    }
    
}