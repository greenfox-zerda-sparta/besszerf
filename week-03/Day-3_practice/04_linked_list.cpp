#include <iostream>

using namespace std;

// Linked list

// Implement a linked list using structs that stores doubles A struct called Node should represent one node in the list.
// The linked lists should stored by a pointer that points to it's head.

struct Node{
  double data;
  Node* next;
};

// Functions

// Construct One
// It should set the next element to nullptr
// It should set it's value

 Node* list_construct_one(double value) {
   Node* new_node = new Node;
   new_node->data = value;
   new_node->next = 0;
   return new_node;
 }

 // Length
// It should return the size of the list

 unsigned int list_length(Node& head) {
   Node* temp = &head;
   unsigned int node_counter = 0;
   do {
     temp = temp->next;
     node_counter++;
   } while (temp != 0);
   return node_counter;
 }

 // Get Last
 // It should return the last node

Node* list_get_last(Node& head) {
  Node* counter = &head;
  Node* last_node;
  while (counter != 0) {
    last_node = counter;
    counter = counter->next;
  }
  return last_node;
}

// Append
// It should append a new node to the end of the list with the given value

 void list_append(Node& head, double value) {
   Node* new_node = list_construct_one(value);
   Node* last_node = list_get_last(head);
   last_node->next = new_node;
 }
// At
// It should return the node with the given index counted from it's head

Node* list_at(Node& head, unsigned int index) {
  if (list_length(head) - 1 < index) {
    cout << "The given index is out of the range. Returning the last node." << endl;
    return list_get_last(head);
  }
  long node_counter = 0;
  Node* node_at_index = &head;
  while (node_counter != index) {
    node_at_index = node_at_index->next;
    node_counter++;
  }
  return node_at_index;
}

// Insert
// It should insert a node to the given index

void list_insert(Node& head, unsigned int index, double value) {
  unsigned int last_index = list_length(head)-1;
  if (last_index < index) {
    cout << "The given index is too high to insert. Data is appended at the end of the list." << endl;
    list_append(head, value);
    return;
  }
  Node* new_node = list_construct_one(value);
  if (last_index == 0) {
    new_node->data = head.data;
    head.data = value;
    head.next = new_node;
    return;
  }
  Node* node_before_index = list_at(head, index-1);
  Node* node_after_index = list_at(head, index);
  node_before_index->next = new_node;
  new_node->next = node_after_index;
}

// Find
// It should return the index of the given value

unsigned int list_find(Node& head, double value) {
  Node* temp = &head;
  unsigned int index_of_searched_node = 0;
  unsigned int list_length = list_length(head);
  for (; index_of_searched_node < list_length; index_of_searched_node++) {
    if (temp->data == value) {
      return index_of_searched_node;
    }
    temp = temp->next;
  }
  cout << "The given value is not in the list." << endl;
  return index_of_searched_node + 1;
}

// Remove
// It should remove the node with the given value

void list_remove(Node& head, double value) {
  unsigned int index_of_node_to_remove = list_find(head, value);
  unsigned int last_index = list_length(head)-1;
  if (index_of_node_to_remove > last_index) {
    cout << "Nothing to remove." << endl;
    return;
  }
  Node* node_to_remove = list_at(head, index_of_node_to_remove);
  if (last_index > 0) {
    if (node_to_remove == &head) {
      Node* second = list_at(head, 1);
      head = *second;
      delete second;
      return;
    } else if (list_get_last(head) == node_to_remove){
      Node* new_tail = list_at(head, index_of_node_to_remove - 1);
      new_tail->next = 0;
    } else {
      Node* node_before_to_remove = list_at(head, index_of_node_to_remove - 1);
      Node* node_after_to_remove = list_at(head, index_of_node_to_remove + 1);
      node_before_to_remove->next = node_after_to_remove;
    }
  }
  delete node_to_remove;
}


// Concat
// It should concat the other list to the and of the list

void list_concat(Node& head, Node& other_list) {
  Node* last_node_of_first_list = list_get_last(head);
  last_node_of_first_list->next = &other_list;
}

int main() {
  Node* head = list_construct_one(1.1);
  cout << "The value of the head node: " << head->data << endl;
  list_append(*head, 5.5);
  list_append(*head, 3.1);
  cout << "Length of the list after appending two nodes: " << list_length(*head) << endl;
  Node* node_at_index1 = list_at(*head, 1);
  cout << "The value of node at index 1: " << node_at_index1->data << endl;
  Node* last_node = list_get_last(*head);
  cout << "The value of the last (2nd) node: " << last_node->data << endl;
  list_insert(*head, 1, 9.9);
  node_at_index1 = list_at(*head, 1);
  cout << "The value of node at index 1 after inserting there a new node: " << node_at_index1->data << endl;
  node_at_index1 = list_at(*head, 3);
  cout << "The value of node at index 3: " << node_at_index1->data << endl;
  cout << "Length of the list now: " << list_length(*head) << endl;
  cout << "The index of node having value of 3.1: " << list_find(*head, 3.1) << endl;
  list_remove(*head, 1.1);
  cout << "The value of the new head after removing the old by its value of 1.1: " << head->data << endl;
  cout << "Length of the list now: " << list_length(*head) << endl;
  Node* another_head = list_construct_one(1.1);
  list_append(*another_head, 5.5);
  list_append(*another_head, 3.1);
  list_append(*another_head, 7.3);
  cout << "Length of the newly created list: " << list_length(*another_head) << endl;
  list_concat(*head, *another_head);
  cout << "Length of the list now after appending the second list: " << list_length(*head) << endl;
  cout << "Values of the list: " << endl;
  for (int i = 0; i < 7; i++) {
    node_at_index1 = list_at(*head, i);
    cout << "Value of the element " << i+1 << ": " << node_at_index1->data<< endl;
  }
  for (int i = 0; i < 7; i++) {
  node_at_index1 = list_at(*head, 0);
  double value = node_at_index1->data;
  list_remove(*head, value);
  }
  return 0;
}
