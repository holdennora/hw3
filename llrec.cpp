#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  // Base case there's nothing in the list
  if (head == nullptr)
  {
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  // Recurssive step 
  // split the elements of a singly-linked list into two output lists
  Node* current = head;
  llpivot(head->next, smaller, larger, pivot);

  if ( current->val <= pivot)
  {
    current->next = smaller;
    smaller = current;
  }
  else
  {
    current->next = larger;
    larger = current;
  }

  head = nullptr;
}
