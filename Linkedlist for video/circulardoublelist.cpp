#include <iostream>
using namespace std;

struct Node{
    int angka;
    Node *next;
    Node *prev;
};
struct LinkList{
    Node *head;
    Node *tail;
};
Node *cur, *newnode, *curraf;

void init(LinkList *list){
    list->head = NULL;
    list->tail = NULL;
}

int counter(LinkList *list){
    int count = 1;
    cur = list->head;
    while(cur->next != list->head){
        count++;
        cur = cur->next;
    }
}

void AddFirst(LinkList *list, int angka){
    Node *newnode = new Node;
    newnode->angka = angka;
    if(list->head == NULL){
        list->head = newnode;
        list->tail = newnode;
        newnode->next = list->tail;
        newnode->prev = list->tail;
        list->tail->next = newnode;
        list->tail->prev = newnode;
    }
    else{
        newnode->next = list->head;
        newnode->prev = list->tail;
        list->head->prev = newnode;
        list->tail->next = newnode;
        list->head = newnode;
    }
}

void AddMid(LinkList *list, int angka, int pos){
    if(1 > pos || pos > counter(list)){
        cout << "bukan posisi yang benar" << endl;
    }
    else if(pos == 1){
        cout << "posisi tidak tepat di tengah" << endl;
    }
    else{
        Node *newnode = new Node;
        newnode->angka = angka;
        int count = 1;
        cur = list->head;
        curraf = list->head->next;
        while(count < pos-1){
            count++;
            cur = cur->next;
            curraf = curraf->next;
        }
        newnode->next = curraf;
        newnode->prev = cur;
        cur->next = newnode;
        curraf->prev = newnode;
        
    }
}

void AddLast(LinkList *list, int angka){
    Node *newnode = new Node;
    newnode->angka = angka;
    if(list->tail == list->head){
        newnode = list->tail;
        newnode->next = list->head;
        newnode->prev = list->head;
        list->head->next = newnode;
        list->head->prev = newnode;
    }
    else{
        list->tail->next = newnode;
        list->head->prev = newnode;
        newnode->next = list->head;
        newnode->prev = list->tail;
        list->tail = newnode;
    }
}

void Print(LinkList *list){
    cur = list->head;
    if(cur->next == list->head){
        cout << cur->angka;
    }
    else{
        while(cur->next != list->head){
        cout << cur->angka << " ";
        cur = cur->next;
        if(cur->next == list->head){
            cout << cur->angka;
            }
        }
    }
    cout << endl;
}





int main(){
    LinkList list;
    init(&list);
    AddFirst(&list, 3);
    Print(&list);
    AddFirst(&list, 1);
    Print(&list);
    AddFirst(&list, 0);
    Print(&list);
    AddLast(&list, 33);
    Print(&list);
    AddFirst(&list, 1);
    Print(&list);
    AddLast(&list, 100);
    Print(&list);
    AddMid(&list, 56, 5);
    Print(&list);
    
}