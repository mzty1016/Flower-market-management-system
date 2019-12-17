//
//  Global.hpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/6.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#ifndef Global_hpp
#define Global_hpp

#include <iostream>
#include <string>

using namespace std;

const int MAXSIZE = 500; //哈希表长度
const string ADMIN_PASSERWORD = "12345"; //管理员密码
const string FLOWER_FILE_NAME = "/Users/xumingfei/Desktop/data.txt"; //存放花卉信息的文件名
const string MERCHANT_FILE_NAME = "/Users/xumingfei/Desktop/merchant.txt"; //存放商家账号密码和店名的文件名
const string PURCHASER_FILE_NAME = "/Users/xumingfei/Desktop/purchaser.txt"; //存放买家账号密码的文件名
const string LEFT_AD_FILE_NAME = "/Users/xumingfei/Desktop/leftad.txt"; //存放左栏广告信息的文件名
const string RIGHT_AD_FILE_NAME = "/Users/xumingfei/Desktop/rightad.txt"; //存放右栏广告信息的文件名
const string ANNOUNCEMENT_FILE_NAME = "/Users/xumingfei/Desktop/announcement.txt"; //存放公告信息的文件名
const string FILE_ADDRESS = "/Users/xumingfei/Desktop/"; //文件所在地址
const string FILE_TYPE = ".txt"; //文件类型

//关于菜单
const string STAR = "★★★★★★★★★★★";
const string LHEAD = "╔═════════════";
const string HEAD = "═════════════════════";
const string RHEAD = "═════════════╗";
const string LBOTM = "╚═════════════";
const string BOTM = "═════════════════════";
const string RBOTM = "═════════════╝";
const string TT = "    ";
const string T = "     ";
const string FF = "║";
const string KK = "********************";
const string MM = "                    ";
const string KONGGE = "                  ";
const string KKK = "　　　　　　　　  ";
const string SOFTWARE = "青岛市枯桃花卉市场交易管理系统";
const string AUTHOR = "Dousir9";
const string VERSION = "1.0";
const string NEW_LINE = "\n";

#endif /* Global_hpp */
