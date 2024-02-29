#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

// All structs taken from llrec_tests.cpp
struct IsOdd
  {
    bool operator()(int num) {
        return (num % 2) != 0;
    }
};

struct IsEven
{
    bool operator()(int num) {
        return (num % 2) == 0;
    }
};
struct IsGreater
{
	int num2;
	IsGreater(int val) : num2(val){}
    bool operator()(int num1) {
        return (num1 > num2);
    }
};
struct IsLessEquals
{
	int num2;
	IsLessEquals(int val) : num2(val){}
    bool operator()(int num1) {
        return (num1 <= num2);
    }
};


int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    Node* head2 = readList(argv[1]);
    Node* head3 = readList(argv[1]);
    Node* head4 = readList(argv[1]);

    cout << "Original list: ";
    print(head);
    cout << endl;

    /*
    // PIVOT
    Node* smaller = nullptr;
    Node* larger = nullptr;
    int pivot = 10;

    llpivot(head, smaller, larger, pivot);

    cout << "Smaller list:" << endl;
    Node* curr = smaller;
    print(curr);
    dealloc(smaller);

    cout << "Larger list:" << endl;
    Node* curr2 = larger;
    print(curr2);
    dealloc(larger);
    */

  // FILTER
  head = llfilter(head, IsOdd());
  cout << "Evens only: " << endl;
  print(head);
  cout << endl;
  dealloc(head);

  head2 = llfilter(head2, IsEven());
  cout << "Odds only: " << endl;
  print(head2);
  cout << endl;
  dealloc(head2);

  head3 = llfilter(head3, IsGreater(8));
  cout << "Less than or equal to 8 only: " << endl;
  print(head3);
  cout << endl;
  dealloc(head3);

  head4 = llfilter(head4, IsLessEquals(8));
  cout << "Greater than 8 only: " << endl;
  print(head4);
  cout << endl;
  dealloc(head4);
  

  



  return 0;

}
