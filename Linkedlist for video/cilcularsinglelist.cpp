#include <iostream>
using namespace std;

struct Node{
    int angka;
    Node *next;
};

struct List{
    Node *head;
    Node *tail;
};
Node *curr, *newnode;

void Init(List *list){
    list->head = NULL;
    list->tail = NULL;
}

int count(List *list){
    int count = 1;
    curr = list->head;
    while(curr->next != list->head){
        count++;
        curr = curr->next;
    }
}

void Addfirst(List *list, int angka){
    Node *newnode = new Node;
    newnode->angka = angka;
    if(list->head == NULL){
        list->head = newnode;
        list->tail = newnode;
        newnode->next = list->tail;
        newnode->next= list->head;
    }
    else{
        newnode->next = list->head;
        list->head = newnode;
        list->tail->next = list->head;
    }
}

void AddMid(List *list, int angka, int pos){
    if(pos < 1 || pos > count(list)){
        cout << "bukan posisi yang benar" << endl;
    }
    else if(pos == 1){
        cout << "posisi tidak tepat di tengah" << endl;
    }
    else{
        Node *newnode = new Node;
        newnode->angka = angka;
        int count = 1;
        curr = list->head;
        while (count < pos-1)
        {
            count++;
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;
    }
}

void AddLast(List *list, int angka){
    Node *newnode = new Node;
    newnode->angka = angka;
    if(list->head == NULL){
        list->head = newnode;
        list->tail = newnode;
        list->head->next = list->tail;
        list->tail->next = list->head;
    }
    else{
        newnode->next = list->head;
        list->tail->next = newnode;
        list->tail = newnode;
    }
}

void Print(List *list){
    curr = list->head;
    if(curr->next == list->head){
        cout<< curr->angka << endl;
    }
    else{
        while(curr->next != list->head){
            cout << curr->angka;
            curr = curr->next;
            cout << " ";
            if(curr->next == list->head){
                cout << curr->angka;
            }
    }
    cout << endl;
    }
    
}



int main(){
    List list;
    Init(&list);
    Addfirst(&list, 3);
    Print(&list);
    Addfirst(&list, 1);
    Print(&list);
    Addfirst(&list, 5);
    Print(&list);
    Addfirst(&list, 6);
    Print(&list);
    AddLast(&list, 9);
    Print(&list);
    Addfirst(&list, 2);
    Print(&list);
    AddMid(&list, 7, 4);
    Print(&list);
}