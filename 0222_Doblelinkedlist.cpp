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
}