#include <iostream>
#include <fstream>
#include "global.h"

using namespace std;

void print_questions_to_me(int Me_id){    //same thing in feed (but delete question from u by ur id)
    int ques_id,thread_id,from_id,to_id;
    string anonymous,question;
    ifstream inquestions;
    inquestions.open("questions.txt");

    while(inquestions>>ques_id>>thread_id>>from_id>>to_id>>anonymous) {
        getline(inquestions, question);
        long long location = inquestions.tellg();
        if (thread_id != -1 || to_id!=Me_id) continue;
        cout << "Question Id " << ques_id << " from user " << from_id << " to user " << to_id << " QUESTION: "
             << question << "\n";
        int temp_ques_id, temp_thread_id;
        while (inquestions >> temp_ques_id >> temp_thread_id >> from_id >> to_id >> anonymous) {
            getline(inquestions, question);
            if (ques_id == temp_ques_id && Me_id==to_id)
                cout << "Thread parent question id "<<temp_ques_id<<" Question Id "<<temp_thread_id <<" from user id: "<<from_id<<" to user id "<< to_id
                <<"      Question" << question<<"\n";
        }
        inquestions.seekg(location);
    }
}

//--- this function should be used in line 19 instead of statements from line 19 to 26 (note not experimented can e wrong or correct)

void print_thread_questions(int id){
    int ques_id,thread_id,from_id,to_id;
    string anonymous,question;
    fstream questions;
    questions.open("questions.txt",ios::in);
    while(questions>>ques_id>>thread_id>>from_id>>to_id>>anonymous){
        getline(questions,question);
        if(ques_id==id)
            cout << "Thread parent question id "<<ques_id<<" Question Id "<<thread_id <<" from user id: "<<from_id<<" to user id "<< to_id
                 <<"      Question" << question<<"\n";
    }
    questions.close();
}
