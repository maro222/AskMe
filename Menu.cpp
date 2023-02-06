#include <iostream>
#include "global.h"

using namespace std;

void menu(int id){
    int choice = 0;     // we initialized in order not to have unexpected answer in switch case (initialization cannot be 8)

    cout<<"Menu: \n\t\t";
    cout<<"1: print questions to me\n\t\t";
    cout<<"2: print question from me\n\t\t";
    cout<<"3: Answer questions\n\t\t";
    cout<<"4: delete questions\n\t\t";
    cout<<"5: Ask questions\n\t\t";
    cout<<"6: list system users\n\t\t";
    cout<<"7: feed\n\t\t";
    cout<<"8: logout\n\n";

    while(choice!=8){
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1: print_questions_to_me(id);   break;
            case 2: print_questions_from_me(id); break;
            case 3: Answer_questions();        break;
            case 4: delete_questions(id);        break;
            case 5: Ask_questions(id);           break;
            case 6: list_system_users();       break;
            case 7: feed();                    break;
            case 8: choice=8;                          break;
            default : cout<<"invalid number \nTry again please: ";
        }
    }

}


