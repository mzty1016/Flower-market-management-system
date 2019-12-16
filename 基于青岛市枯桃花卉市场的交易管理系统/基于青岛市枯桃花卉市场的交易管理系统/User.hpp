//
//  User.hpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/13.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <iostream>
#include <string>
#include <fstream>

#include "Global.hpp"
#include "Flower.hpp"
#include "Hash.hpp"

using namespace std;

//用户类
class User {
 public:
    User(); //默认构造函数
    User(const string &user_name, const string &password); //构造函数
    const string& UserNameInfo() const; //返回返回用户名，用于对应买家文件名
 private:
    string user_name; //用户名
    string password; //密码
};

#endif /* User_hpp */
