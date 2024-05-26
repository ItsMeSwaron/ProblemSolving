#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;


};

class mystack{
    public:
    node*head;
    int stk_sz;
    mystack(){
        head = NULL;
        stk_sz=0;
    }

    void push(int val){
        node* tmp = new node();
        tmp->data=val;
        tmp->next = head;
        head = tmp;
        stk_sz++;
    }

    int pop(){
        if(head==NULL){
            cout<<"Stack underflow\n";
            return -1;
        }
        else{
            node* tmp= head;
            head=tmp->next;
            tmp->next=NULL;
            stk_sz--;
            int x= tmp->data;
            delete tmp;
            return x;
        }

    }
    int peek(){
         if(head==NULL){
            cout<<"Stack underflow\n";
            return -1;
        }

        return head->data;
      
    }

    int size(){
        return stk_sz;
    }
    
    void display(){
        if(head==NULL){
            cout<<"Stack is Empty\n";
            return;
        }
        node* temp=head;
        while(temp!=NULL){
            std :: cout<<temp->data<<" ";
            temp = temp->next;
         }
    }

};

int main()
{
    mystack stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);

    cout << stk.pop();

    stk.push(50);

    stk.display();
    // stk.display();
}