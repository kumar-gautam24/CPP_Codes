// Linked list basic
#include<bits/stdc++.h>
using namespace std;

struct node {
  int x;
  node *next;
};
 
int main()
{
  node *root;       // This won't change, or we would lose the list in memory
  node *conductor;  // This will point to each node as it traverses the list
 
  root = new node;  // Sets it to actually point to something
  root->next = 0;   //  Otherwise it would not work well
  root->x = 12;
  conductor = root; // The conductor points to the first node
  if ( conductor != 0 ) {
    while ( conductor->next != 0)
      conductor = conductor->next;
  }
  conductor->next = new node;  // Creates a node at the end of the list
  conductor = conductor->next; // Points to that node
  conductor->next = 0;         // Prevents it from going any further
  conductor->x = 42;

  return 0;
}
// theory
