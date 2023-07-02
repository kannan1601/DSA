#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node *next;
};

void insert(Node **head){ 
  int N;
  cout << "Enter no of nodes: \n";
  cin >> N;
  Node *temp, *new_node;
  for(int i = 0; i < N; i++){
    new_node = new Node();
    int X;
    cin >> X;
    new_node -> data = X;
    new_node -> next = NULL;

    if(*head == NULL){
      *head = temp = new_node;
    } 
    else{
      temp -> next = new_node;
      temp = new_node;
    }
  }
}
void display(Node *head){
  Node *temp = head;
  while(temp != NULL){
    cout << temp -> data << ' ';
    temp = temp -> next;
  }
}

int main(){
  Node *head = NULL;
  cout << "address of main " << &head << '\n';
  insert(&head);
  display(head);
}