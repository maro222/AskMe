#include <iostream>
#include <fstream>
#include <limits>
#include "global.h"

using namespace std;

void update(int answer_ques_id,string new_answer){
    int answer_id;
    string old_answer;
    fstream temp,answers;
    //-------this section is responsible for moving old info and the new update from answer.txt file to temp file----//
    answers.open("answers.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(answers>>answer_id){
        getline(answers,old_answer);
        if(answer_ques_id==answer_id)
            temp<<answer_id<<" "<<new_answer<<"\n";
        else
            temp<<answer_id<<" "<<old_answer<<"\n";
    }
    answers.close();
    temp.close();


    //-------this section is responsible for moving old info and the new update from temp.txt file to answers.txt file back again----//
    answers.open("answers.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(temp>>answer_id){
        getline(temp,new_answer);
        answers<<answer_id<<" "<<new_answer<<"\n";
    }
    answers.close();
    temp.close();
    remove("temp.txt");
}



void Answer_questions(){

    int answer_ques_id,ques_id,thread_id,from_id,to_id,location;
    string answer,anonymous,question;
    ofstream oanswers;
    ifstream inanswers;
    oanswers.open("answers.txt",ios::app);
    inanswers.open("answers.txt");
    cout<<"Enter Question id or -1 for cancel : ";
    cin>>answer_ques_id;             // user enter id of wanted question to be answered
    if(answer_ques_id==-1) return;   // -1 for cancelling answering operation
    ifstream inquestions;
    inquestions.open("questions.txt");

    while(inquestions>>ques_id>>thread_id>>from_id>>to_id>>anonymous){     //reading IDs and info of questions
        getline(inquestions,question);
        if(answer_ques_id==ques_id && thread_id==-1){   // to check if question is exist in question.txt or not
            cout << "Question Id " << ques_id << " from user " << from_id << " to user " << to_id << "        QUESTION: "<< question << "\n";
        while(inanswers>>answer_ques_id){    //reading IDs and its answers
                getline(inanswers, answer);
                if (answer_ques_id == ques_id) {       // to check if there is an old answer for question or not
                    cout << "\t\tAnswer: " << answer << "\n\n";
                    cout << "warning there is an answer already your answer is going to be updated now\n";
                    cout << "Enter your answer : ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // this line should be used before getline to ignore \n from old stream
                    getline(cin , answer);
                    update(answer_ques_id,answer);
                    return;
                  }
            }
            cout << "Enter your answer : ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // this line should be used before getline to ignore \n from old stream
            getline(cin , answer);
            oanswers<<answer_ques_id <<" "<<answer;
            return;
        }

        else if(answer_ques_id==thread_id){
            cout << "Question parent Id " << ques_id <<" thread Question Id "<<thread_id
            <<" from user " << from_id << " to user " << to_id << "        QUESTION: "<< question << "\n";
            while(inanswers>>answer_ques_id) {  //reading IDs and its answers
                getline(inanswers, answer);
                if (answer_ques_id == thread_id) {       // to check if there is an old answer for question or not
                    cout << "\tthread:\t\tAnswer: " << answer << "\n\n";
                    cout << "warning there is an answer already your answer is going to be updated now\n";
                    cout << "Enter your answer : ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // this line should be used before getline to ignore \n from old stream
                    getline(cin , answer);
                    update(answer_ques_id,answer);
                    return;
                }
            }
            cout << "Enter your answer : ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // this line should be used before getline to ignore \n from old stream
            getline(cin , answer);
            oanswers<<answer_ques_id <<" "<<answer;
            return;
        }
    }
    cout<<"Invalid Question ID\n";
}


