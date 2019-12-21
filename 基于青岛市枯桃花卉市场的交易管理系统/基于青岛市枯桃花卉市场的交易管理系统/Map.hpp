//
//  Map.hpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/20.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <cmath>

#include "Global.hpp"

using namespace std;

typedef struct {
    int x;
    int y;
    string shop_name;
}MapNode;

typedef struct path_node{
    int x;
    int y;
    struct path_node *front_node;
}path_node;

class Map {
public:
    Map();
    void InitMap();
    void SaveMap();
    void ShowMap();
    MapNode SearchMap(string &shop_name);
    void ChangeMap(const MapNode &merchant_address, path_node &start);
    path_node locate(char x, char y);
    bool AddAddress(string &shop_name);
//    void BFS(queue<path_node> &bfsnode, const MapNode &merchant_address);
private:
    char market_map[MAP_WIDTH][MAP_LENGTH];
    MapNode merchant[ADDRESS_MAX_NUM];
    int num;
};

#endif /* Map_hpp */
