#include <iostream>
#include "string"
#include <fstream>
#include <limits>
#include "global.h"

using namespace std;

void Ask_questions(int Me_id){
    int user_id,ques_id=200,thread_id ;   //default initialization for new questions will start from 200
    string question,check, anonymous;
    cout<<"Enter user id or -1 to cancel: ";
    cin>>user_id;
    if(user_id==-1)
        return;
    cout<<"\nEnter question_id For thread question or -1 for new question: ";
    cin>>thread_id;
    cout<<"\nEnter question: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // this line should be used before getline to ignore \n from old stream
    getline(cin,question);

    ifstream inquestions;
    inquestions.open("questions.txt");
    ofstream oquestions;
    oquestions.open("questions.txt",ios::app);


    //--this part is for generating IDs for new and thread questions--//
    int temp_ques_id,temp_thread_id;
    if(thread_id==-1){       //this means generating new ques_id
        while(inquestions>>temp_ques_id>>temp_thread_id){
            if(temp_ques_id==ques_id)
                ques_id++;
            while(inquestions>>check){
                if(check==",") break;   // (,) --> we use it as a delimeter to stop reading from file
            }
        }
    }
    else{
        ques_id=thread_id;
        thread_id=400;     //default thread_id initialization (start if IDs for thread questions)
        while(inquestions>>temp_ques_id>>temp_thread_id){
            if(temp_thread_id==thread_id)
                thread_id++;
            while(inquestions>>check){
                if(check==",") break;      // (,) --> we use it as a delimeter to stop reading from file
            }
        }
    }

    // this part is for handling questions and users files and printing questions
    ifstream inusers;
    inusers.open("users.txt");
    long long i,location;  //i is been used like a checker for IDs
    while(inusers>>i){
        while(inusers>>check){
            if(check=="0" || check=="1"){
                break;
            }
        }
        if(i==user_id){
          // location = inusers.tellg();
          // inusers.seekg(location-2);  //we make location-2 to go backward to 2 steps(one for anonymous and another for \n string before anonymous
          // inusers>>anonymous;
           anonymous=check;
           break;
        }
    }
    oquestions<<ques_id<<" "<<thread_id<<" "<<Me_id<<" "<<user_id<<" "<<anonymous<<" "<<question<<" "<<",\n";  // (,) --> we use it as a delimeter to stop reading from file       // we put whitespaces between words to be able to read it separately
    inusers.close();
    inquestions.close();
    oquestions.close();
}
