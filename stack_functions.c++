#include <iostream>
using namespace std;
//PUSH FUNCTION
int top=-1;
 int S[5];
int push(int S[],int size,int value){
    int top1=top;
    if( size==(top1+1) ){
        cout<<"Stack is full"<<endl;
        return 0;
    }
    else{
        top++;
        S[top]=value;
        return 0;
    } 
     
}
//POP FUNCTION
int pop(int S[]){
    int top1=top;
    if(top1==-1){
        cout<<"Stack is Empty"<<endl;
        return 0;
    }
    else{
        cout<<"Element POPPED: ";
        top--;
        cout<<S[top1];
        return S[top1];
    }

}
//DISPLAY FUNCTION
 int display(int arr[],int size){
    int top1=top;
    cout<<endl<<"Stack Elements: ";
    for(int i=0;i<=top1;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
 }
 //STACK IS EMPTY
 void stackisempty(){
    if(top==-1)
        cout<<"Stack is Empty";
    else
    cout<<"Stack is NOT Empty";
 }
 //ELIZABETH'S BRANCH STARTS HERE