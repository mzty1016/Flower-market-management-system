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
#include <vector>

#include "Global.hpp"
#include "Flower.hpp"
#include "Hash.hpp"
#include "Menu.hpp"
#include "Map.hpp"

using namespace std;

HashTable hashtable;
char leftad1[30], leftad2[30], leftad3[30], leftad4[30], leftad5[30], leftad6[30], leftad7[30], leftad8[30], leftad9[30], leftad10[30];
char rightad1[30], rightad2[30], rightad3[30], rightad4[30], rightad5[30], rightad6[30], rightad7[30], rightad8[30], rightad9[30], rightad10[30];
char announcement1[100], announcement2[100], announcement3[100], announcement4[100], announcement5[100];

int main() {
    hashtable.InitHashTable();
    MainMenu M;
    M.LoadAd();
    M.LoadAnnouncement();
    M.MenuRun();
    return 0;
}
