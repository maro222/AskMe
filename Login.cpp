#include <iostream>
#include <fstream>
#include "global.h"

using namespace std;

void login(){
    int choice,id=1;
    string Username,Password,check;
    cout<<"Menu:\n\t"<<"1-Login\n\t"<<"2-SignUp\n";
    cout<<"Enter a number in range 1 - 2 : ";
    cin>>choice;
    if(choice==1){
        string username,password;                       //username && password with small letters --means--> They are used to help in reading from users file
        cout<<"Enter user name and password: ";
        cin>>Username>>Password;                              //Username && Password with capital letters --means--> They are used to be printed in users files enter them
        ifstream inusers;
        inusers.open("users.txt");
        while(inusers>>id>>username>>password){
            if(username==Username && password==Password)
                menu(id);                                      //goto function menu   //id of current user
            else{
                while(inusers>>check)
                    if(check=="1" || check=="0")            // as anonymous is either 1 or 0 (we do not depend on \n as a delimeter) ,we can depend on on(,) either (1,0) as another solution as we did in Ask_questions.cpp
                        break;
            }
        }
        if(inusers.eof()
        )
        cout<<"Invalid user";
        inusers.close();
    }

    else{
        string name,email,anonymous;
        cout<<"Enter user name: ";   cin>>Username;
        cout<<"Enter password: ";    cin>>Password;
        cout<<"Enter name: ";        cin>>name;
        cout<<"Enter email: ";       cin>>email;
        cout<<"Allow Anonymous questions: "; cin>>anonymous;      // we reuse variable choice;
        ifstream inusers;         //inusers used for reading from users files
        ofstream ousers;          //ousers used for printing in users file
        inusers.open("users.txt");
        ousers.open("users.txt",ios::app);
        while(inusers>>id){
            while(inusers>>check){
                if(check=="0" || check=="1"){         // as anonymous is either 1 or 0 (we do not depend on \n as a delimeter) ,we can depend on on(,) either (1,0) as another solution as we did in Ask_questions.cpp
                    id++;
                    break;
                }
            }
        }
        ousers<<id<<" "<<Username<<" "<<" "<<Password<<" "<<name<<" "<<email<<" "<<anonymous<<" "<<"\n";       // we put whitespaces between words to be able to read it separately
        inusers.close();
        ousers.close();
        menu(id);
    }
}
