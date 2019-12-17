//
//  Menu.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/13.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include "Menu.hpp"
#include "Hash.hpp"
extern HashTable hashtable;
extern char leftad1[30], leftad2[30], leftad3[30], leftad4[30], leftad5[30], leftad6[30], leftad7[30], leftad8[30], leftad9[30], leftad10[30];
extern char rightad1[30], rightad2[30], rightad3[30], rightad4[30], rightad5[30], rightad6[30], rightad7[30], rightad8[30], rightad9[30], rightad10[30];
extern char announcement1[100], announcement2[100], announcement3[100], announcement4[100], announcement5[100];

//基类====================================================================
//默认构造函数
MainMenu::MainMenu() { }
//输出菜单头部
void MainMenu::ShowMenuHead() {
    cout << "==" << endl;
}
//输出菜单底部
void MainMenu::ShowMenuBottom() {
    cout << "__" << endl;
}
void MainMenu::ShowError() {
    fflush(stdin); //先清空缓存区
    cout << "无效的输入，请重新输入" << endl;
}
//接收指令
char MainMenu::Input() {
    char ch;
    cin>>ch;
    fflush(stdin);
    return ch;
}
void MainMenu::LoadAd() {
    ifstream LeftAd, RightAd;
    LeftAd.open(LEFT_AD_FILE_NAME);
    RightAd.open(RIGHT_AD_FILE_NAME);
    int i = 0;
    while (!LeftAd.eof()) {
        if (i < 24)
            leftad1[i%24] = LeftAd.get();
        else if (i >= 24 && i < 48)
            leftad2[i%24] = LeftAd.get();
        else if (i >= 48 && i < 72)
            leftad3[i%24] = LeftAd.get();
        else if (i >= 72 && i < 96)
            leftad4[i%24] = LeftAd.get();
        else if (i >= 96 && i < 120)
            leftad5[i%24] = LeftAd.get();
        else if (i >= 120 && i < 144)
            leftad6[i%24] = LeftAd.get();
        else if (i >= 144 && i < 168)
            leftad7[i%24] = LeftAd.get();
        else if (i >= 168 && i < 192)
            leftad8[i%24] = LeftAd.get();
        else if (i >= 192 && i < 216)
            leftad9[i%24] = LeftAd.get();
        else if (i >= 216 && i < 240)
            leftad10[i%24] = LeftAd.get();
        ++i;
        if (i == 240)
            break;
    }
    i = 0;
    while (!RightAd.eof()) {
        if (i < 24)
            rightad1[i%24] = RightAd.get();
        else if (i >= 24 && i < 48)
            rightad2[i%24] = RightAd.get();
        else if (i >= 48 && i < 72)
            rightad3[i%24] = RightAd.get();
        else if (i >= 72 && i < 96)
            rightad4[i%24] = RightAd.get();
        else if (i >= 96 && i < 120)
            rightad5[i%24] = RightAd.get();
        else if (i >= 120 && i < 144)
            rightad6[i%24] = RightAd.get();
        else if (i >= 144 && i < 168)
            rightad7[i%24] = RightAd.get();
        else if (i >= 168 && i < 192)
            rightad8[i%24] = RightAd.get();
        else if (i >= 192 && i < 216)
            rightad9[i%24] = RightAd.get();
        else if (i >= 216 && i < 240)
            rightad10[i%24] = RightAd.get();
        ++i;
        if (i == 240)
            break;
    }
}
void MainMenu::ShowAd(char ad[]) {
    for (int i = 0; i < 24; i += 3) {
        if (ad[i] != '\0' && ad[i+1] != '\0' && ad[i+2] != '\0')
            cout << ad[i] << ad[i+1] << ad[i+2];
        else if (i % 3 == 0)
            cout << "　";
    }
}
void MainMenu::LoadAnnouncement() {
    ifstream Announcement;
    Announcement.open(ANNOUNCEMENT_FILE_NAME);
    int i = 0;
    while (!Announcement.eof()) {
        if (i < 90)
            announcement1[i%90] = Announcement.get();
        else if (i >= 90 && i < 180)
            announcement2[i%90] = Announcement.get();
        else if (i >= 180 && i < 270)
            announcement3[i%90] = Announcement.get();
        else if (i >= 270  && i < 360)
            announcement4[i%90] = Announcement.get();
        else if (i >= 360 && i < 450)
            announcement5[i%90] = Announcement.get();
        ++i;
        if (i == 450)
            break;
    }
}
void MainMenu::ShowAnnouncement(char an[]){
    printf("      ");
    printf("┃ ");
    int i;
    for(i = 0; i < 90; i += 3){
        if(an[i] != '\0' && an[i+1] != '\0' && an[i+2] != '\0')
            cout << an[i] << an[i+1] << an[i+2];
        else if (i % 3 == 0)
            cout << "　";
    }
    printf(" ┃");
}
//输出主菜单信息
void MainMenu::ShowMenuInfo() {
    cout << "1.买家入口" <<endl;
    cout << "2.商家入口" <<endl;
    cout << "3.管理员入口" <<endl;
    cout << "4.退出系统" <<endl;
}
//主菜单运行
void MainMenu::MenuRun() {
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    char ch = Input();
    static PurchaserLogMenu purchaser_log_menu;
    static MerchantLogMenu merchant_log_menu;
    static AdminLogMenu admin_log_menu;
    switch (ch) {
        case '1': //买家登录、注册入口
            purchaser_log_menu.MenuRun();
            MenuRun();
            break;
        case '2': //商家入驻、登录入口
            merchant_log_menu.MenuRun();
            MenuRun();
            break;
        case '3': //管理员入口
            admin_log_menu.MenuRun();
            MenuRun();
            break;
        case '4': //退出系统
            exit(0);
        default: //应对异常输入
            ShowError();
            MenuRun();
    }
}
//基类====================================================================

//商家====================================================================
//输出商家入驻、登录菜单
void MerchantLogMenu::ShowMenuInfo() {
    cout << "1.商家登录" <<endl;
    cout << "2.商家入驻" <<endl;
    cout << "3.返回" <<endl;
    cout << "4.退出系统" <<endl;
}
//商家入驻、登录菜单运行
void MerchantLogMenu::MenuRun() {
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    char ch = Input();
    static Merchant merchant;
    static MerchantDoMenu merchant_do_menu;
    switch (ch) {
        case '1': //商家登录
            merchant = merchant.Loggin();
            if (merchant.IsLogSuccess())
                merchant_do_menu.MenuRun(merchant);
            MenuRun();
            break;
        case '2': //商家入驻
            merchant.Logging();
            MenuRun();
            break;
        case '3': //返回主菜单
            return ;
            break;
        case '4': //退出系统
            exit(0);
        default: //应对异常输入
            ShowError();
            MenuRun();
    }
}
//输出商家操作菜单
void MerchantDoMenu::ShowMenuInfo() {
    cout << "1.查看上架花卉" <<endl;
    cout << "2.花卉上架" <<endl;
    cout << "3.花卉下架" <<endl;
    cout << "4.花卉信息修改" <<endl;
    cout << "5.花卉自动折扣" <<endl;
    cout << "6.返回" <<endl;
    cout << "7.退出系统" <<endl;
}
//商家操作菜单运行
void MerchantDoMenu::MenuRun(const Merchant &merchant) {
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    char ch = Input();
    switch (ch) {
        case '1': //查看上架花卉
            merchant.CheckFlower();
            MenuRun(merchant);
            break;
        case '2': //花卉上架
            merchant.AddFlower();
            MenuRun(merchant);
            break;
        case '3': //花卉下架
            merchant.DeleteFlower();
            MenuRun(merchant);
            break;
        case '4': //花卉信息修改
            merchant.ModifyFlowerInfo();
            MenuRun(merchant);
            break;
        case '5': //花卉自动折扣
            merchant.AutoDiscountFlower();
            MenuRun(merchant);
            break;
        case '6': //返回上级菜单
            return ;
            break;
        case '7': //退出系统
            exit(0);
        default: //应对异常输入
            ShowError();
            MenuRun(merchant);
    }
}
//商家====================================================================

//买家====================================================================
//输出买家注册、登录菜单
void PurchaserLogMenu::ShowMenuInfo() {
    cout << "1.买家登录" <<endl;
    cout << "2.买家注册" <<endl;
    cout << "3.返回" <<endl;
    cout << "4.退出系统" <<endl;
}
//买家入驻、登录菜单运行
void PurchaserLogMenu::MenuRun() {
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    char ch = Input();
    static Purchaser purchaser;
    static PurchaserDoMenu purchaser_do_menu;
    switch (ch) {
        case '1': //买家登录
            purchaser = purchaser.Loggin();
            if (purchaser.IsLogSuccess())
                purchaser_do_menu.MenuRun(purchaser);
            MenuRun();
            break;
        case '2': //买家注册
            purchaser.Logging();
            MenuRun();
            break;
        case '3': //返回主菜单
            return ;
            break;
        case '4': //退出系统
            exit(0);
        default: //应对异常输入
            ShowError();
            MenuRun();
    }
}
//输出买家操作菜单
void PurchaserDoMenu::ShowMenuInfo() {
    cout << "1.查看所有上架花卉" <<endl;
    cout << "2.查找花卉" <<endl;
    cout << "3.花卉预约" <<endl;
    cout << "4.查看预约" <<endl;
    cout << "5.花卉推荐" <<endl;
    cout << "6.花店地址导航" <<endl;
    cout << "7.返回" <<endl;
    cout << "8.退出系统" <<endl;
    
}
//买家操作菜单运行
void PurchaserDoMenu::MenuRun(const Purchaser &purchaser) {
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    char ch = Input();
    switch (ch) {
        case '1': //查看所有上架花卉
            purchaser.CheckALLFlower();
            MenuRun(purchaser);
            break;
        case '2': //查找花卉
            purchaser.SearchFlower();
            MenuRun(purchaser);
            break;
        case '3': //花卉预约
            purchaser.ReserveFlower();
            MenuRun(purchaser);
            break;
        case '4': //查看预约
            purchaser.CheckReservation();
            MenuRun(purchaser);
            break;
        case '5': //花卉推荐
            purchaser.RecommendFlower();
            MenuRun(purchaser);
            break;
        case '6': //花店地址导航
            
            MenuRun(purchaser);
            break;
        case '7': //返回上级菜单
            return ;
            break;
        case '8': //退出系统
            exit(0);
        default: //应对异常输入
            ShowError();
            MenuRun(purchaser);
    }
}
//买家====================================================================

//管理员===================================================================
//输出管理员登录菜单
void AdminLogMenu::ShowMenuInfo() {
    cout << "请输入管理员密码: " <<endl;
}
//商家入驻、登录菜单运行
void AdminLogMenu::MenuRun() {
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    static Admin admin;
    static AdminDoMenu admin_do_menu;
    if (admin.Loggin() == true)
        admin_do_menu.MenuRun();
}
//输出管理员操作菜单
void AdminDoMenu::ShowMenuInfo() {
    cout << "1.发布公告" <<endl;
    cout << "2.设置广告" <<endl;
    cout << "3.广告一键清空" <<endl;
    cout << "4.买家找回密码" <<endl;
    cout << "5.商家找回密码" <<endl;
    cout << "6.系统测试" <<endl;
    cout << "7.返回主菜单" <<endl;
    cout << "8.退出系统" <<endl;
}
//管理员操作菜单运行
void AdminDoMenu::MenuRun() {
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    static Admin admin;
    char ch = Input();
    switch (ch) {
        case '1': //发布公告
            admin.Announce();
            LoadAnnouncement();
            MenuRun();
            break;
        case '2': //设置广告
            admin.SetAd();
            LoadAd();
            MenuRun();
            break;
        case '3': //广告一键清空
            admin.ClearAd();
            LoadAd();
            MenuRun();
            break;
        case '4': //买家找回密码
            
            MenuRun();
            break;
        case '5': //商家找回密码
            
            MenuRun();
            break;
        case '6': //系统测试
            
            MenuRun();
            break;
        case '7': //返回主菜单
            return ;
        case '8': //退出系统
            exit(0);
        default: //应对异常输入
            ShowError();
            MenuRun();
    }
}
//管理员===================================================================
