#include <iostream>
#include <fstream>
#include "global.h"

using namespace std;

void delete_questions(int Me_id){
    int ques_id,check_id,thread_id,from_id,to_id ;
    string question, anonymous;
    fstream questions;
    questions.open("questions.txt",ios::in);
    fstream temp;
    temp.open("temp.txt",ios::out);
    cout<<"Enter question id or -1 for cancel : ";
    cin>>check_id;

    while(questions>>ques_id>>thread_id>>from_id>>to_id>>anonymous){
        getline(questions,question);
        if(ques_id==check_id && Me_id==from_id){
            continue;
        }
        else if(thread_id==check_id && Me_id==from_id){
            continue;
        }
        else{
            temp<<ques_id<<" "<<thread_id<<" "<<from_id<<" "<<to_id<<" "<<anonymous<<" "<<question<<"\n";
        }
    }
    questions.close();
    temp.close();

    questions.open("questions.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(temp>>ques_id>>thread_id>>from_id>>to_id>>anonymous){
        getline(temp,question);
        questions<<ques_id<<" "<<thread_id<<" "<<from_id<<" "<<to_id<<" "<<anonymous<<" "<<question<<"\n";
    }
    questions.close();
    temp.close();
    remove("temp.txt");
    cout<<"question has been deleted\n";
}
