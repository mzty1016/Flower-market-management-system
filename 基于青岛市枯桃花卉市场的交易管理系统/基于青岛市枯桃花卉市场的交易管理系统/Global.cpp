//
//  Global.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/6.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include "Global.hpp"

//清空缓存区
void MY_FLUSH() {
    char ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}
//按任意键返回
void MY_PAUSE() {
    MY_FLUSH();
    cout <<endl<< "                                              按任意键返回..." << endl;
    getchar();
}
