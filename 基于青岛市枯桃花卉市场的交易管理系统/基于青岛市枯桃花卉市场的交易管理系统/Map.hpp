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

//商家坐标
typedef struct {
    int x;
    int y;
    string shop_name;
}MapNode;
//路径
typedef struct path_node{
    int x;
    int y;
    struct path_node *front_node;
}path_node;
//地图类
class Map {
public:
    Map(); //默认构造函数
    void InitMap(); //读取文件建立地图
    void SaveMap(); //写入文件保存地图
    void ShowMap(); //输出地图
    MapNode SearchMap(string &shop_name); //根据商家店名搜索商家，返回该商家所在的坐标
    void ChangeMap(const MapNode &merchant_address, path_node &start); //广度优先搜索与剪枝建立画出最短路径
    path_node locate(char x, char y); //根据地图坐标返回在数组中的位置
    bool AddAddress(string &shop_name); //商家入驻时改变坐标，若商家已满，返回false
private:
    char market_map[MAP_WIDTH][MAP_LENGTH]; //地图
    MapNode merchant[ADDRESS_MAX_NUM]; //商家坐标信息
    int num; //当前商家数量
};

#endif /* Map_hpp */
