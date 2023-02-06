#include <iostream>
#include <fstream>
#include "global.h"

using namespace std;

void print_questions_from_me(int Me_id){
    int ques_id,thread_id,from_id,to_id;
    string anonymous,question;
    ifstream inquestions;
    inquestions.open("questions.txt");
    while(inquestions>>ques_id>>thread_id>>from_id>>to_id>>anonymous){
        //cout<<ques_id<<" "<<thread_id<<" "<<from_id<<" "<<" "<<to_id<<" "<<anonymous;   //there is something wrong if i move this line from while to line 13 ( maybe bec of inquestons.eof() )
        getline(inquestions,question);
        if (anonymous=="0") anonymous="!AQ";
        else anonymous="";
        if(from_id==Me_id){
            cout<<"question id "<<ques_id<<" "<<anonymous<<" to user id "<<to_id<<"\t\t question : "<<question<<"\n";
        }
    }
}
