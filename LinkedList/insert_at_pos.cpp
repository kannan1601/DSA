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

Node *insert_at_pos(Node *head){
  int N;
  cout << "Enter position at which you want enter the new node: " << "\n";
  cin >> N;
  cout << "enter data: " << "\n";
  Node *new_node = new Node();
  cin >> new_node -> data;
  Node *temp = head;
  --N;
  if(N == 0){
    new_node -> next = head;
    head = new_node;
    return head;
  }
  --N;
  while(N--){
    temp = temp -> next;
  }

  new_node -> next = temp -> next;
  temp -> next = new_node;
  return head;
}



void display(Node *head){
  Node *temp = head;
  while(temp != NULL){
    cout << temp -> data << ' ';
    temp = temp -> next;
  }
  cout << '\n';
}

int main(){
  Node *head = NULL;
  insert(&head);
  display(head);
  head = insert_at_pos(head);
  cout << "After insertion at the end\n";
  display(head);

}