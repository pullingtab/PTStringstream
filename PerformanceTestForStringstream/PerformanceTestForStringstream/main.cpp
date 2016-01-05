//
//  main.cpp
//  PerformanceTestForStringstream
//
//  Created by 爽 张 on 16/1/5.
//  Copyright © 2016年 爽 张. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::stringstream;
using std::string;
using std::cout;
using std::endl;
using std::vector;

const unsigned int oneMillion = 1000000;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Performance test for stringstream (alpha).\n";
    
    cout << "integer value, 1 million loop, 1 object each loop.\n";
    srand(1);
    int intSet[oneMillion];
    string* strSet = new string[oneMillion];
    for (int i=0; i<oneMillion; ++i) {
        intSet[i] = rand();
    }
    clock_t timeStamp1 = clock();
    //string str;
    for (int i=0; i<oneMillion; ++i) {
        stringstream int2string;
        int2string << intSet[i];
        int2string >> strSet[i];
        
        // test
//        cout << intSet[i] <<endl;
//        cout << str <<endl;
    }
    clock_t timeStamp2 = clock();
    clock_t ms = timeStamp2 - timeStamp1;
    cout << ms << " ms." <<endl;
    
    cout << "integer value, 1 million loop, only 1 object.\n";
    timeStamp1 = clock();
    stringstream int2string;
    for (int i=0; i<oneMillion; ++i) {
        //string str;
        int2string << intSet[i];
        int2string >> strSet[i];
        
        int2string.clear();
    }
    timeStamp2 = clock();
    ms = timeStamp2 - timeStamp1;
    cout << ms << " ms." <<endl;
    
    cout << "integer value, 1 million loop, spintf().\n";
    timeStamp1 = clock();
    for (int i=0; i<oneMillion; ++i) {
        char buf[100];
        sprintf(buf, "%d", intSet[i]);
        //string str(buf);
        strSet[i] = buf;
    }
    timeStamp2 = clock();
    ms = timeStamp2 - timeStamp1;
    cout << ms << " ms." <<endl;
    
    cout << "double value, 1 million loop, 1 object each loop.\n";
    double *doubleSet = new double[oneMillion];
    for (int i=0; i<oneMillion; ++i) {
        doubleSet[i] = double(rand())/double(RAND_MAX);
    }
    timeStamp1 = clock();
    for (int i=0; i<oneMillion; ++i) {
        stringstream double2string;
        //string str;
        double2string << doubleSet[i];
        double2string >> strSet[i];
        
        // test
        //cout << doubleSet[i] <<endl;
        //cout << str <<endl;
    }
    timeStamp2 = clock();
    ms = timeStamp2 - timeStamp1;
    cout << ms << " ms." <<endl;
    
    cout << "double value, 1 million loop, only 1 object.\n";
    timeStamp1 = clock();
    stringstream double2string;
    for (int i=0; i<oneMillion; ++i) {
        //string str;
        double2string << doubleSet[i];
        double2string >> strSet[i];
        
        double2string.clear();
    }
    timeStamp2 = clock();
    ms = timeStamp2 - timeStamp1;
    cout << ms << " ms." <<endl;
    
    cout << "double value, 1 million loop, spintf().\n";
    timeStamp1 = clock();
    for (int i=0; i<oneMillion; ++i) {
        char buf[100];
        sprintf(buf, "%lf", doubleSet[i]);
        //string str(buf);
        strSet[i] = buf;
    }
    timeStamp2 = clock();
    ms = timeStamp2 - timeStamp1;
    cout << ms << " ms." <<endl;

    delete [] doubleSet;
    delete [] strSet;
    
    return 0;
}
