#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

void insertStart(Node** head, int data){

    Node* newNode = new Node();


    newNode->data = data;


    newNode->next = *head;


    *head = newNode;

}

void insertLast(Node** head, int data){

    Node* newNode = new Node();

    newNode->data = data;

    newNode->next = NULL;


    if(*head==NULL){
        *head = newNode;
        return;
    }

    struct Node* temp = *head;


    while(temp->next!=NULL)
        temp = temp->next;


    temp->next = newNode;
}

int calcSize(Node* node){
    int size=0;

    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}

void insertPosition(int n, int data, Node** head)
{
    int size = calcSize(*head);


    if(n < 1 || size < n)
    {
        cout << "Not Valid position to insert" << endl;
    }
    else {

        Node* temp = *head;
        Node* newNode = new Node();

        newNode->data = data;
        newNode->next = NULL;


        while(--n)
            temp=temp->next;


        newNode->next= temp->next;

        temp->next = newNode;

    }
}

void display(Node* node){


    while(node!=NULL){
        cout << node->data << " "; node = node->next;
    }
    cout << endl;
}

int main(){

    Node* head = NULL;


    insertStart(&head,5);
    insertStart(&head,10);
    insertStart(&head,15);

    insertLast(&head,20);
    insertLast(&head,25);
    insertLast(&head,30);
    insertLast(&head,35);


    insertPosition(3,100,&head);


    display(head);
    return 0;
}
