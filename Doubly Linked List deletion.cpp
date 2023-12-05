#include<iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next, *prev;
};

class DoublyLinkedList
{
private:
  Node * head;
public:
  DoublyLinkedList ()
  {
    head = NULL;
  }
  int countItems ();
  void insert (int data);
  void deleteStart ();
  void deleteLast ();
  void deleteNthNode (int pos);
  void display ();
};

void DoublyLinkedList::insert (int data)
{
  Node *new_node = new Node ();

  new_node->data = data;
  new_node->next = head;
  new_node->prev = NULL;


  if (head != NULL)
    head->prev = new_node;


  head = new_node;
}

void DoublyLinkedList::deleteStart ()
{

  Node *temp = head;


  if (head == NULL)
    {
      cout << "Linked List Empty, nothing to delete\n";
      return;
    }


  if (temp->next == NULL)
    {
      cout << temp->data << " deleted\n";
      head = NULL;
      return;
    }


  head = head->next;

  head->prev = NULL;

  cout << temp->data << " deleted\n";
  free (temp);
}

void DoublyLinkedList::deleteLast ()
{

  Node *temp = head;

  // if DLL is empty
  if (head == NULL)
    {
      cout << ("DLL empty can't delete\n");
      return;
    }

  // if Linked List has only 1 node
  if (temp->next == NULL)
    {
      cout << temp->data << " deleted\n";
      head = NULL;
      return;
    }				// else traverse to the last node

  while (temp->next != NULL)
    temp = temp->next;

  Node *secondLast = temp->prev;

  // Curr assign 2nd last node's next to Null
  secondLast->next = NULL;

  cout << temp->data << " deleted\n";
  free (temp);
}

void DoublyLinkedList::deleteNthNode (int n)
{

  int len = countItems ();


  if (n < 1 || n > len)
    {
      cout << "Not a valid position\n";
      return;
    }


  if (n == 1)
    {
      deleteStart ();
      return;
    }

  if (n == len)
    {
      deleteLast ();
      return;
    }

  Node *temp = head;


  while (--n)
    {
      temp = temp->next;
    }

  Node *previousNode = temp->prev;
  Node *nextNode = temp->next;

  previousNode->next = temp->next;


  nextNode->prev = temp->prev;


  cout << temp->data << " deleted\n";
  free (temp);
}

int DoublyLinkedList::countItems ()
{

  Node *node = new Node ();
  node = head;
  int items = 0;

  while (node != NULL)
    {
      node = node->next;
      items++;
    }
  return items;
}

void DoublyLinkedList::display ()
{

  Node *node = head;
  Node *end = NULL;

  cout << "Reading DLL Forward: ";
  while (node != NULL)
    {
      cout << node->data << " ";
      end = node;
      node = node->next;
    }

  cout << "\nReading DLL Backward: ";

  while (end != NULL)
    {
      cout << end->data << " ";
      end = end->prev;
    }
  cout << "\n\n";
}

int main ()
{
  DoublyLinkedList *dll = new DoublyLinkedList ();
  dll->insert (2);
  dll->insert (4);
  dll->insert (8);
  dll->insert (10);
  dll->insert (12);
  dll->insert (14);

  dll->display ();

  dll->deleteStart ();
  dll->display ();

  dll->deleteLast ();
  dll->display ();


  dll->deleteNthNode (3);
  dll->display ();


  dll->deleteNthNode (1);
  dll->display ();


  dll->deleteLast ();
  dll->display ();


  dll->deleteStart ();
  dll->display ();

  return 0;
}
