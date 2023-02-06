#include <iostream>
#include <fstream>
#include "global.h"

using namespace std;


int main() {
    login();

    return 0;
}

/*
 * noticies about files:
 * 1- \n does not considered in reading from files but is considered as a character as we must be aware of it during tellg(),seekg()
 */