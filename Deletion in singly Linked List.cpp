#include<iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

int calcSize (Node * node)
{
  int size = 0;

  while (node != NULL)
    {
      node = node->next;
      size++;
    }
  return size;
}

void deleteStart (Node ** head)
{
  Node *temp = *head;

  // if there are no nodes in Linked List can't delete
  if (*head == NULL)
    {
      printf ("Linked List Empty, nothing to delete");
      return;
    }

  cout << "\nValue Deleted: " << temp->data;

  // move head to next node
  *head = (*head)->next;
  free (temp);
}

void deleteEnd (Node ** head)
{
  Node *temp = *head;
  Node *previous;

  // Can't delete from empty Linked List
  if (*head == NULL)
    {
      cout << ("Empty List, can't delete");
      return;
    }

  // if Linked List has only 1 node
  if (temp->next == NULL)
    {
      cout << "\nValue Deleted: " << (*head)->data;
      *head = NULL;
      return;
    }

  // else traverse to the last node
  while (temp->next != NULL)
    {
      // store previous link node as we need to change its next val
      previous = temp;
      temp = temp->next;
    }

  // Curr assign 2nd last node's next to Null
  previous->next = NULL;

  cout << "\nValue Deleted: " << temp->data;
  // delete the last node
  free (temp);
  // 2nd last now becomes the last node
}

void deletePos (Node ** head, int n)
{
  Node *temp = *head;
  Node *previous;


  int size = calcSize (*head);

  if (n < 1 || n > size)
    {
      cout << "\nEnter valid position\n";
      return;
    }

  // if first node has to be deleted
  if (n == 1)
    {
      deleteStart (head);
      return;
    }

  //traverse till the nth node
  while (--n)
    {
      // store previous link as we need to change its next val
      previous = temp;
      temp = temp->next;
    }

  // previous node's next changed to nth node's next
  previous->next = temp->next;
  cout << "\nValue deleted: " << temp->data;

  free (temp);
}

void insert (Node ** head, int data)
{

  Node *newNode = new Node ();

  newNode->data = data;
  newNode->next = *head;

  // assigned head to newNode
  *head = newNode;
}

void display (Node * node)
{
  cout << "\n";

  //as linked list will end when Node is Null
  while (node != NULL)
    {
      cout << node->data << " ";
      node = node->next;
    }
  cout << endl;
}

int main ()
{
  Node *head = NULL;

  insert (&head, 10);
  insert (&head, 20);
  insert (&head, 30);
  insert (&head, 40);
  insert (&head, 50);
  insert (&head, 60);
  insert (&head, 70);

  display (head);

  deleteStart (&head);
  display (head);

  deleteEnd (&head);
  display (head);

  // delete 4th node
  deletePos (&head, 4);
  display (head);

  // delete the 1st node
  deletePos (&head, 1);
  display (head);

  deletePos (&head, -2);	// invalid pos
  deletePos (&head, 10);	// invalid pos

  return 0;
}
