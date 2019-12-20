//
//  Map.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/20.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include "Map.hpp"

Map::Map() {
    num = 0;
    for (int i = 0; i < ADDRESS_MAX_NUM; i++) {
        merchant[i].x = 0;
        merchant[i].y = 0;
        merchant[i].shop_name = "";
    }
}

void Map::InitMap() {
    ifstream OutMyFile1;
    OutMyFile1.open(MAP_FILE_NAME);
    int i = 0, j = 0;
    while (!OutMyFile1.eof()) {
        for (; j < MAP_LENGTH; j++) {
            OutMyFile1>>market_map[i][j];
            if (market_map[i][j] == '@')
                num ++;
        }
        i++;
        j = 0;
    }
    OutMyFile1.close();
    ifstream OutMyFile2;
    OutMyFile2.open(MERCHANT_ADDRESS_FILE_NAME);
    i = 0;
    while (!OutMyFile2.eof()) {
        OutMyFile2>>merchant[i].shop_name>>merchant[i].x>>merchant[i].y;
        i++;
    }
    OutMyFile2.close();
}
void Map::SaveMap() {
    ofstream InMyFile1;
    InMyFile1.open(MAP_FILE_NAME);
    for (int i = 0; i < MAP_WIDTH; i++){
        for (int j = 0; j < MAP_LENGTH; j++){
            InMyFile1<<market_map[i][j];
            if ( j != MAP_LENGTH - 1)
                InMyFile1 << " ";
        }
        if (i != MAP_WIDTH - 1)
            InMyFile1 << endl;
    }
    InMyFile1.close();
    ofstream InMyFile2;
    InMyFile2.open(MERCHANT_ADDRESS_FILE_NAME);
    for (int i = 0; i < num; i++) {
        InMyFile2<<merchant[i].shop_name<<" "<<merchant[i].x<<" "<<merchant[i].y;
        if (i != num - 1)
            InMyFile2<<endl;
    }
    InMyFile2.close();
}
void Map::ShowMap() {
    char cc = 'a';
    for (int i = 0; i < 4; i++)
        cout << " ";
    for (int i = 0; i < MAP_LENGTH - 3; i++)
        cout << char(cc + i) << " ";
    cout << endl;
    for (int i = 0, k = 0; i < MAP_WIDTH; i++) {
        if (i > 0 && i < MAP_WIDTH-1){
            cout << char(cc + k) << " ";
            k++;
        }
        else
            cout << "  ";
        for (int j = 0; j < MAP_LENGTH; j++) {
            if (market_map[i][j] == '1')
                cout << "* ";
            else if (market_map[i][j] == '#')
                cout << "  ";
            else if (market_map[i][j] == '+')
                cout << "+ ";
            else if (market_map[i][j] == '@')
                cout << "@ ";
            else
                cout << "  " ;
        }
        cout << endl;
    }
}
bool Map::AddAddress(string &shop_name) {
    if (num == ADDRESS_MAX_NUM)
        return false;
    for (int i = 2; i <= 18; i += 4)
        for(int j = 2; j <= 26; j += 4){
            if (market_map[i][j] == '#') {
                market_map[i][j] = '@';
                merchant[num].shop_name = shop_name;
                merchant[num].x = i;
                merchant[num].y = j;
                num++;
                return true;
            }
        }
    return true;
}
MapNode Map::SearchMap(string &shop_name) {
    for (int i = 0; i < num; i++) {
        if (merchant[i].shop_name == shop_name)
            return merchant[i];
    }
    MapNode node;
    node.x = -1;
    return node;
}
path_node Map::locate(char x, char y) {
    path_node node;
    node.x = (x - 97) + 1;
    node.y = (y - 97) + 1;
    return node;
}
void Map::ChangeMap(const MapNode &merchant_address, path_node &start) {
    int visit[MAP_WIDTH][MAP_LENGTH];
    for (int i = 0 ; i < MAP_WIDTH; i++) {
        memset(visit[i], 0, sizeof(int)*MAP_LENGTH);
    }
    path_node *q = &start;
    queue<path_node*> bfsnode;
    start.front_node = NULL;
    bfsnode.push(q);
    stack<path_node*> path;
    while (!bfsnode.empty()) {
        path_node *node = bfsnode.front();
        bfsnode.pop();
        visit[node->x][node->y] = 1;
        printf("(%d, %d)\n", node->x, node->y);
        printf("visit[%d][%d]被设置为%d\n", node->x, node->y, visit[node->x][node->y]);
        if (node->x == merchant_address.x && node->y == merchant_address.y) {
            while(node->front_node != NULL) {
                path.push(node);
                node = node->front_node;//花开富贵
            }
            while(!bfsnode.empty()) {
                path_node *node = bfsnode.front();
                bfsnode.pop();
                delete node;
            }
            break;
        }
        if (market_map[node->x][node->y-1] != '1' && visit[node->x][node->y-1] == 0) {
            printf("visit[%d][%d] = %d\n", node->x, node->y-1, visit[node->x][node->y-1]);
            path_node *p = new path_node;
            *p = {node->x, node->y-1};
            p->front_node = node;
            bfsnode.push(p);
        }
        if (market_map[node->x-1][node->y] != '1' && visit[node->x-1][node->y] == 0){
            printf("visit[%d][%d] = %d\n", node->x-1, node->y, visit[node->x-1][node->y]);
            path_node *p = new path_node;
            *p = {node->x-1, node->y};
            p->front_node = node;
            bfsnode.push(p);
        }
        if (market_map[node->x][node->y+1] != '1' && visit[node->x][node->y+1] == 0){
            printf("visit[%d][%d] = %d\n", node->x, node->y+1, visit[node->x][node->y+1]);
            path_node *p = new path_node;
            *p = {node->x, node->y+1};
            p->front_node = node;
            bfsnode.push(p);
        }
        if (market_map[node->x+1][node->y] != '1' && visit[node->x+1][node->y] == 0){
            printf("visit[%d][%d] = %d\n", node->x+1, node->y, visit[node->x+1][node->y]);
            path_node *p = new path_node;
            *p = {node->x+1, node->y};
            p->front_node = node;
            bfsnode.push(p);
        }
//        delete node;
    }
    while (!path.empty()) {
        path_node *node = path.top();
        printf("(%d, %d)\n", node->x, node->y);
        market_map[node->x][node->y] = '+';
        path.pop();
    }
}

//bool flag = false; //判断是否找到
//stack<path_node> path;
//void Map::BFS(queue<path_node> &bfsnode, const MapNode &merchant_address) {
//    path_node node = bfsnode.front();
//    if (node.x == merchant_address.x && node.y == merchant_address.y) {
//        flag = true;
//        return;
//    }
//    if (market_map[node.x][node.y+1] == '0') {
//        path_node node1 = {node.x, node.y+1};
//        node1.front_node = &node;
//        bfsnode.push(node1);
//    }
//    if (market_map[node.x-1][node.y] == '0'){
//        path_node node1 = {node.x-1, node.y};
//        node1.front_node = &node;
//        bfsnode.push(node1);
//    }
//    if (market_map[node.x][node.y-1] == '0'){
//        path_node node1 = {node.x, node.y-1};
//        node1.front_node = &node;
//        bfsnode.push(node1);
//    }
//    if (market_map[node.x+1][node.y] == '0'){
//        path_node node1 = {node.x, node.y-1};
//        node1.front_node = &node;
//        bfsnode.push(node1);
//    }
//    bfsnode.pop();
//    BFS(bfsnode, merchant_address);
//}
