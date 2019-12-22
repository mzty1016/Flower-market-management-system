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
    cout<<endl; cout<<"                ";
    cout<<STAR<<" "<<SOFTWARE<<" "<<STAR<<NEW_LINE<<NEW_LINE;
}
//输出菜单底部
void MainMenu::ShowMenuBottom() {
    cout << "\n\n                                                  【公告】 \n";
    usleep(40000);
    cout << "                     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
    usleep(40000);
    cout << "            {@}"; ShowAnnouncement(announcement1); cout << "       {@}\n";
    usleep(40000);
    cout << "             | "; ShowAnnouncement(announcement2); cout << "        |\n";
    usleep(40000);
    cout << "            \\|/"; ShowAnnouncement(announcement3); cout << "       \\|/\n";
    usleep(40000);
    cout << "             | "; ShowAnnouncement(announcement4); cout << "        |\n";
    usleep(40000);
    cout << "             | "; ShowAnnouncement(announcement5); cout << "        |\n";
    usleep(40000);
    cout << "                     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
    usleep(40000);
    cout << "                                                    :";
    usleep(40000);
}
//输出版本信息
void MainMenu::ShowVersion() {
    cout<<endl; cout<<"                ";
    cout<<STAR<<" "<<SOFTWARE<<" "<<STAR<<NEW_LINE<<NEW_LINE;
    cout<<endl<<"                                             版本信息： V1.0"<<endl<<endl;
    cout<<endl<<"                              如果您发现该系统在某些地方,存在bug或者可以优化"<<endl<<
           "                                      请联系我，我的QQ是: 736191200"<<endl<<endl;
    cout<<endl<<"                               如果您想继续完善该系统或者想进行有关内容的学习"<<endl<<
    "                                 可以访问该系统的github网站进行fork或者查看"<<endl<<endl;
    cout<<"                   github: https://github.com/Dousir9/Flower-market-management-system"<<endl;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<"                             Copyright c 2019 Dousir9. All rights reserved."<<endl<<endl;
    cout<<endl<<"\n                                            ";
    MY_PAUSE();
}
//输出错误信息
void MainMenu::ShowError() {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n                                         ";
    cout << " 无效的输入，请重新输入" << endl;
    usleep(1500000);
    system("clear");
}
//接收指令
char MainMenu::Input() {
    char ch;
    cin>>ch;
    MY_FLUSH();
    return ch;
}
//加载广告
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
//逐行输出广告
void MainMenu::ShowAd(char ad[]) {
    cout << "* ";
    for (int i = 0; i < 24; i += 3) {
        if (ad[i] != '\0' && ad[i+1] != '\0' && ad[i+2] != '\0')
            cout << ad[i] << ad[i+1] << ad[i+2];
        else if (i % 3 == 0)
            cout << "　";
    }
    cout << " *";
}
//加载公告
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
        else if (i >= 270 && i < 360)
            announcement4[i%90] = Announcement.get();
        else if (i >= 360 && i < 450)
            announcement5[i%90] = Announcement.get();
        ++i;
        if (i == 450)
            break;
    }
}
//逐行输出公告
void MainMenu::ShowAnnouncement(char an[]){
    cout<<("      ");
    cout<<("┃ ");
    for(int i = 0; i < 90; i += 3){
        if(an[i] != '\0' && an[i+1] != '\0' && an[i+2] != '\0')
            cout << an[i] << an[i+1] << an[i+2];
        else if (i % 3 == 0)
            cout << "　";
    }
    cout<<(" ┃");
}
//输出主菜单信息
void MainMenu::ShowMenuInfo() {
    usleep(40000);
    cout<<TT;cout<<KK; cout<<("    ╔════════════════════════════════════════════════╗     ");cout<<KK; cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad1); cout<<"    ║                  ①  买家入口                   ║     "; ShowAd(rightad1); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad2); cout<<"    ║                                                ║     ";ShowAd(rightad2); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad3); cout<<"    ║                  ②  商家入口                   ║     "; ShowAd(rightad3); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad4); cout<<"    ║                                                ║     ";ShowAd(rightad4); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad5); cout<<"    ║                  ③  管理员入口                 ║     "; ShowAd(rightad5); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad6); cout<<"    ║                                                ║     ";ShowAd(rightad6); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad7); cout<<"    ║                  ④  版本信息　                 ║     "; ShowAd(rightad7); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad8); cout<<"    ║                                                ║     ";ShowAd(rightad8); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad9); cout<<"    ║                  ⑤  退出系统                   ║     "; ShowAd(rightad9); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad10); cout<<"    ║                 请按提示进行输入:              ║     ";ShowAd(rightad10); cout<<endl;
    usleep(40000);
    cout<<TT;cout<<KK; cout<<("    ╚════════════════════════════════════════════════╝     ");cout<<KK; cout<<endl;
    usleep(40000);
}
//主菜单运行
void MainMenu::MenuRun() {
    system("clear");
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    char ch = Input();
    static PurchaserLogMenu purchaser_log_menu;
    static MerchantLogMenu merchant_log_menu;
    static AdminLogMenu admin_log_menu;
    switch (ch) {
        case '1': //买家登录、注册入口
            system("clear");
            purchaser_log_menu.MenuRun();
            MenuRun();
            break;
        case '2': //商家入驻、登录入口
            system("clear");
            merchant_log_menu.MenuRun();
            MenuRun();
            break;
        case '3': //管理员入口
            system("clear");
            admin_log_menu.MenuRun();
            MenuRun();
            break;
        case '4': //版本信息
            system("clear");
            ShowVersion();
            MenuRun();
        case '5': //退出系统
            exit(0);
        default: //应对异常输入
            system("clear");
            ShowError();
            MenuRun();
    }
}
//基类====================================================================

//商家====================================================================
//输出商家入驻、登录菜单
void MerchantLogMenu::ShowMenuInfo() {
    usleep(40000);
    cout<<TT;cout<<KK; cout<<"    ╔════════════════════════════════════════════════╗     ";cout<<KK; cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad1); cout<<"    ║                                                ║     "; ShowAd(rightad1); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad2); cout<<"    ║                  ①  商家登录                   ║     ";ShowAd(rightad2); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad3); cout<<"    ║                                                ║     "; ShowAd(rightad3); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad4); cout<<"    ║                  ②  商家入驻                   ║     ";ShowAd(rightad4); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad5); cout<<"    ║                                                ║     "; ShowAd(rightad5); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad6); cout<<"    ║                  ③   返回                      ║     ";ShowAd(rightad6); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad7); cout<<"    ║                                                ║     "; ShowAd(rightad7); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad8); cout<<"    ║                  ④  退出系统                   ║     ";ShowAd(rightad8); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad9); cout<<"    ║                                                ║     "; ShowAd(rightad9); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad10); cout<<"    ║                 请按提示进行输入:              ║     ";ShowAd(rightad10); cout<<endl;
    usleep(40000);
    cout<<TT;cout<<KK; cout<<"    ╚════════════════════════════════════════════════╝     "; cout<<KK; cout<<endl;
    usleep(40000);
}
//商家入驻、登录菜单运行
void MerchantLogMenu::MenuRun() {
    system("clear");
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    char ch = Input();
    static Merchant merchant;
    static MerchantDoMenu merchant_do_menu;
    switch (ch) {
        case '1': //商家登录
            system("clear");
            merchant = merchant.Loggin();
            if (merchant.IsLogSuccess())
                merchant_do_menu.MenuRun(merchant);
            MenuRun();
            break;
        case '2': //商家入驻
            system("clear");
            merchant.Logging();
            MenuRun();
            break;
        case '3': //返回主菜单
            return ;
            break;
        case '4': //退出系统
            exit(0);
        default: //应对异常输入
            system("clear");
            ShowError();
            MenuRun();
    }
}
//输出商家操作菜单
void MerchantDoMenu::ShowMenuInfo() {
    usleep(40000);
    cout<<TT;cout<<KK;    cout<<"    ╔════════════════════════════════════════════════╗     "; cout<<KK;     cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad1); cout<<"    ║                ①  查看所有花卉信息             ║     ";ShowAd(rightad1); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad2); cout<<"    ║                ②  花卉上架                     ║     ";ShowAd(rightad2); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad3); cout<<"    ║                ③  花卉下架                     ║     ";ShowAd(rightad3); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad4); cout<<"    ║                ④  花卉信息修改                 ║     ";ShowAd(rightad4); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad5); cout<<"    ║                ⑤  花卉自动折扣                 ║     "; ShowAd(rightad5); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad6); cout<<"    ║                ⑥  返回                         ║     ";ShowAd(rightad6); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad7); cout<<"    ║                ⑦  退出系统                     ║     "; ShowAd(rightad7); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad8); cout<<"    ║                     　　                       ║     ";ShowAd(rightad8); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad9); cout<<"    ║                请按提示进行输入:               ║     "; ShowAd(rightad9); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad10);cout<<"    ║                                                ║     ";ShowAd(rightad10); cout<<endl;
    usleep(40000);
    cout<<TT;cout<<KK; cout<<"    ╚════════════════════════════════════════════════╝     ";cout<<KK; cout<<endl;
    usleep(40000);
}
//商家操作菜单运行
void MerchantDoMenu::MenuRun(const Merchant &merchant) {
    system("clear");
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    char ch = Input();
    switch (ch) {
        case '1': //查看上架花卉
            system("clear");
            merchant.CheckFlower();
            MY_PAUSE();
            MenuRun(merchant);
            break;
        case '2': //花卉上架
            system("clear");
            merchant.AddFlower();
            MY_PAUSE();
            MenuRun(merchant);
            break;
        case '3': //花卉下架
            system("clear");
            merchant.DeleteFlower();
            MY_PAUSE();
            MenuRun(merchant);
            break;
        case '4': //花卉信息修改
            system("clear");
            merchant.ModifyFlowerInfo();
            MY_PAUSE();
            MenuRun(merchant);
            break;
        case '5': //花卉自动折扣
            system("clear");
            merchant.AutoDiscountFlower();
            MY_PAUSE();
            MenuRun(merchant);
            break;
        case '6': //返回上级菜单
            return ;
            break;
        case '7': //退出系统
            exit(0);
        default: //应对异常输入
            system("clear");
            ShowError();
            MenuRun(merchant);
    }
}
//商家====================================================================

//买家====================================================================
//输出买家注册、登录菜单
void PurchaserLogMenu::ShowMenuInfo() {
    usleep(40000);
    cout<<TT;cout<<KK; cout<<"    ╔════════════════════════════════════════════════╗     ";cout<<KK; cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad1); cout<<"    ║                                                ║     "; ShowAd(rightad1); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad2); cout<<"    ║                  ①   登录                      ║     ";ShowAd(rightad2); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad3); cout<<"    ║                                                ║     "; ShowAd(rightad3); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad4); cout<<"    ║                  ②   注册                      ║     ";ShowAd(rightad4); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad5); cout<<"    ║                                                ║     "; ShowAd(rightad5); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad6); cout<<"    ║                  ③   返回                      ║     ";ShowAd(rightad6); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad7); cout<<"    ║                                                ║     "; ShowAd(rightad7); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad8); cout<<"    ║                  ④  退出系统                   ║     ";ShowAd(rightad8); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad9); cout<<"    ║                                                ║     "; ShowAd(rightad9); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad10);cout<<"    ║                 请按提示进行输入:              ║     ";ShowAd(rightad10); cout<<endl;
    usleep(40000);
    cout<<TT;cout<<KK; cout<<"    ╚════════════════════════════════════════════════╝     ";cout<<KK; cout<<endl;
    usleep(40000);
}
//买家入驻、登录菜单运行
void PurchaserLogMenu::MenuRun() {
    system("clear");
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    char ch = Input();
    static Purchaser purchaser;
    static PurchaserDoMenu purchaser_do_menu;
    switch (ch) {
        case '1': //买家登录
            system("clear");
            purchaser = purchaser.Loggin();
            if (purchaser.IsLogSuccess())
                purchaser_do_menu.MenuRun(purchaser);
            MenuRun();
            break;
        case '2': //买家注册
            system("clear");
            purchaser.Logging();
            MenuRun();
            break;
        case '3': //返回主菜单
            return ;
            break;
        case '4': //退出系统
            exit(0);
        default: //应对异常输入
            system("clear");
            ShowError();
            MenuRun();
    }
}
//输出买家操作菜单
void PurchaserDoMenu::ShowMenuInfo() {
    usleep(40000);
    cout<<TT;cout<<KK; cout<<"    ╔════════════════════════════════════════════════╗     ";cout<<KK; cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad1); cout<<"    ║                 ①  查看所有上架花卉            ║     "; ShowAd(rightad1); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad2); cout<<"    ║                 ②  花卉查找                    ║     ";ShowAd(rightad2); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad3); cout<<"    ║                 ③  花卉预约                    ║     "; ShowAd(rightad3); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad4); cout<<"    ║                 ④  查看预约                    ║     ";ShowAd(rightad4); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad5); cout<<"    ║                 ⑤  花卉推荐                    ║     "; ShowAd(rightad5); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad6); cout<<"    ║                 ⑥  花店地址导航                ║     ";ShowAd(rightad6); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad7); cout<<"    ║                 ⑦  退出登录                    ║     "; ShowAd(rightad7); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad8); cout<<"    ║                 ⑧  退出系统                    ║     ";ShowAd(rightad8); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad9); cout<<"    ║                                                ║     "; ShowAd(rightad9); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad10);cout<<"    ║                 请按提示进行输入:              ║     ";ShowAd(rightad10); cout<<endl;
    usleep(40000);
    cout<<TT;cout<<KK; cout<<"    ╚════════════════════════════════════════════════╝     ";cout<<KK; cout<<("\n");
    usleep(40000);
}
//买家操作菜单运行
void PurchaserDoMenu::MenuRun(const Purchaser &purchaser) {
    system("clear");
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    char ch = Input();
    switch (ch) {
        case '1': //查看所有上架花卉
            system("clear");
            purchaser.CheckALLFlower();
            MY_PAUSE();
            MenuRun(purchaser);
            break;
        case '2': //查找花卉
            system("clear");
            purchaser.SearchFlower();
            MY_PAUSE();
            MenuRun(purchaser);
            break;
        case '3': //花卉预约
            system("clear");
            purchaser.ReserveFlower();
            MY_PAUSE();
            MenuRun(purchaser);
            break;
        case '4': //查看预约
            system("clear");
            purchaser.CheckReservation();
            MY_PAUSE();
            MenuRun(purchaser);
            break;
        case '5': //花卉推荐
            system("clear");
            purchaser.RecommendFlower();
            MY_PAUSE();
            MenuRun(purchaser);
            break;
        case '6': //花店地址导航
            system("clear");
            purchaser.NavigateShopAddress();
            MY_PAUSE();
            MenuRun(purchaser);
            break;
        case '7': //返回上级菜单
            return ;
            break;
        case '8': //退出系统
            exit(0);
        default: //应对异常输入
            system("clear");
            ShowError();
            MenuRun(purchaser);
    }
}
//买家====================================================================

//管理员===================================================================
//输出管理员登录菜单
void AdminLogMenu::ShowMenuInfo() {
    cout <<endl<<endl<<endl;
}
//商家入驻、登录菜单运行
void AdminLogMenu::MenuRun() {
    system("clear");
    ShowMenuHead();
    ShowMenuInfo();
    static Admin admin;
    static AdminDoMenu admin_do_menu;
    if (admin.Loggin() == true)
        admin_do_menu.MenuRun();
}
//输出管理员操作菜单
void AdminDoMenu::ShowMenuInfo() {
    cout<<TT;cout<<KK; cout<<"    ╔════════════════════════════════════════════════╗     ";cout<<KK; cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad1); cout<<"    ║                                                ║     "; ShowAd(rightad1); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad2); cout<<"    ║                 ①  公告发布                    ║     ";ShowAd(rightad2); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad3); cout<<"    ║                 ②  广告设置                    ║     "; ShowAd(rightad3); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad4); cout<<"    ║                 ③  广告一键清空                ║     ";ShowAd(rightad4); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad5); cout<<"    ║                 ④  买家找回密码                ║     "; ShowAd(rightad5); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad6); cout<<"    ║                 ⑤  商家找回密码                ║     ";ShowAd(rightad6); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad7); cout<<"    ║                 ⑥  返回主菜单                  ║     "; ShowAd(rightad7); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad8); cout<<"    ║                 ⑦  退出系统                    ║     ";ShowAd(rightad8); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad9); cout<<"    ║                                                ║     "; ShowAd(rightad9); cout<<endl;
    usleep(40000);
    cout<<TT;ShowAd(leftad10);cout<<"    ║                 请按提示进行输入:              ║     ";ShowAd(rightad10); cout<<endl;
    usleep(40000);
    cout<<TT;cout<<KK; cout<<("    ╚════════════════════════════════════════════════╝     ");cout<<KK; cout<<endl;
    usleep(40000);
}
//管理员操作菜单运行
void AdminDoMenu::MenuRun() {
    system("clear");
    ShowMenuHead();
    ShowMenuInfo();
    ShowMenuBottom();
    static Admin admin;
    char ch = Input();
    switch (ch) {
        case '1': //发布公告
            system("clear");
            admin.Announce();
            LoadAnnouncement();
            MY_PAUSE();
            MenuRun();
            break;
        case '2': //设置广告
            system("clear");
            admin.SetAd();
            LoadAd();
            MY_PAUSE();
            MenuRun();
            break;
        case '3': //广告一键清空
            system("clear");
            admin.ClearAd();
            LoadAd();
            MY_PAUSE();
            MenuRun();
            break;
        case '4': //买家找回密码
            system("clear");
            admin.PurchaserRetrievePassword();
            MY_PAUSE();
            MenuRun();
            break;
        case '5': //商家找回密码
            system("clear");
            admin.MerchantRetrievePassword();
            MY_PAUSE();
            MenuRun();
            break;
        case '6': //返回主菜单
            return ;
        case '7': //退出系统
            exit(0);
        default: //应对异常输入
            system("clear");
            ShowError();
            MenuRun();
    }
}
//管理员===================================================================
