#include <iostream>
#include <fstream>
#include "global.h"

using namespace std;

void list_system_users(){
    string userInfo;
    ifstream inusers;
    inusers.open("users.txt");
    while(getline(inusers,userInfo))
        cout<<userInfo<<"\n";
}
