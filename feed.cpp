#include <iostream>
#include <fstream>
#include "global.h"

using namespace std;

void feed(){
    int ques_id,thread_id,from_id,to_id,location;
    string anonymous,question,check;
    ifstream questions;
    questions.open("questions.txt");
    while(questions>>ques_id>>thread_id>>from_id>>to_id>>anonymous){
        getline(questions,question);
        if(thread_id==-1)
            cout << "Question Id " << ques_id << " from user " << from_id << " to user " << to_id
                 << " QUESTION: "<< question << "\n";
        else
            cout << "Thread parent question id "<<ques_id<<" Question Id "<<thread_id <<" from user id: "
                 <<from_id<<" to user id "<< to_id<<" Question" << question<<"\n";
    }
}










/*
 *     int cnt=0,old_cnt;
    while(inquestions>>ques_id>>thread_id>>from_id>>to_id>>anonymous) {
        getline(inquestions, question);
        cnt++;
        if (thread_id == -1){
            cout << "Question Id " << ques_id << " from user " << from_id << " to user " << to_id
            << " QUESTION: "<< question << "\n";
            //location = inquestions.tellg();
            int temp_ques_id, temp_thread_id;
            while (inquestions >> temp_ques_id >> temp_thread_id >> from_id >> to_id >> anonymous){
                getline(inquestions, question);
                cnt++;
                if (ques_id == temp_ques_id)
                    cout << "Thread parent question id "<<temp_ques_id<<" Question Id "<<temp_thread_id <<" from user id: "
                    <<from_id<<" to user id "<< to_id<<" Question" << question<<"\n";
            }
           // inquestions.clear(ios_base::eofbit);
           //inquestions.seekg(location);
           old_cnt=cnt;
           inquestions.close();
           inquestions.open("questions.txt");
           while(--old_cnt){
               inquestions>>ques_id>>thread_id>>from_id>>to_id>>anonymous;
               getline(inquestions, question);
           }
        }
    }
 */