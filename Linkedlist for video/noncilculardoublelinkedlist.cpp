#include <iostream>
using namespace std;

struct Node{
    int angka;
    Node *next;
    Node *prev;
};

struct List{
    Node *head;
    Node *tail;
};

Node *curr, *newnode, *del;

void Init(List *list){
    list->head = NULL;
    list->tail = NULL;
}

int counter(List *list){
    int count = 0;
    curr = list->head;
    while(curr != NULL){
        count++;
        curr = curr->next;
    }
    return count;
}

void AddFirst(List *list, int angka){
    Node *newnode = new Node;
    newnode->angka = angka;
    newnode->next = list->head;
    newnode->prev = NULL;
    list->head->prev = newnode;
    list->head = newnode;
}

void AddMid(List *list, int angka, int pos){
    if(pos < 1 || pos > counter(list)){
        cout << "posisi kurang tepat" << endl;
    }
    else if(pos == 1 ){
        cout << "posisi tidak tepat di tengah";
    }
    else{
        Node *newnode = new Node;
        newnode->angka = angka;
        //tras
        int count = 1;
        curr = list->head;
        while(count < pos-1){
            curr = curr->next;
            count++; 
        }
        newnode->next = curr->next;
        newnode->prev = curr->prev;
        curr->next->prev = newnode;
        curr->next = newnode;
    }
}

void AddLast(List *list, int angka){
    Node *newnode = new Node;
    newnode->angka = angka;
    newnode->next = NULL;
    newnode->prev = list->tail;
    if(list->head == NULL){
        list->head = newnode;
        list->tail = newnode;
    }
    else{
        list->tail->next = newnode;
        list->tail = newnode;
    }
}

void Print(List *list){
    curr = list->head;
    while(curr != NULL){
        cout << curr->angka << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main(){
    List list;
    Init(&list);
    AddLast(&list, 9);
    Print(&list);
    AddFirst(&list, 2);
    Print(&list);
    AddLast(&list, 4);
    
    Print(&list);
    AddLast(&list, 4);
    AddFirst(&list, 3);
    AddLast(&list, 5);
    AddLast(&list, 8);
    Print(&list);
    AddMid(&list, 6, 5);
    Print(&list);
}