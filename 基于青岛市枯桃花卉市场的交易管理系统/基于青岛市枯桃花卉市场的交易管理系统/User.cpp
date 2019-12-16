//
//  User.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/13.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include "User.hpp"

//默认构造函数
User::User() {
    user_name = "";
    password = "";
}
//进行初始化的构造函数
User::User(const string &user_name, const string &password) {
    this->user_name = user_name;
    this->password = password;
}
