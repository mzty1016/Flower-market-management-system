//
//  main.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/6.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>

#include "Global.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream myFile;
    myFile.open("/Users/xumingfei/Desktop/data.txt");
    myFile>>sd;
    printf("%s\n", sd+3);
    printf("%d%d%d\n", sd[3],sd[4],sd[5]);
    cout << "Hello, World!\n"<<sd<<endl;
    double value[] = {1.23, 35.36, 653.7, 4358.24};
    string names[] = {"Zoot", "Jimmy", "Al", "Stan"};
    for ( int i = 0; i < 4; i++) {
        cout<<hex<<(float)value[i]<<endl;
    }
    cout<<setiosflags(ios_base::left)<<setw(6)<<names[2]<<endl;
    cout<<setw(6)<<names[0]<<endl;
    cout<<resetiosflags(ios_base::left);
    cout<<setw(6)<<names[1]<<endl;
    return 0;
}

