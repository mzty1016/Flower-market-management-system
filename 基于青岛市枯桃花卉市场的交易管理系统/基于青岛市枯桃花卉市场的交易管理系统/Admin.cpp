//
//  Admin.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/16.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include "Admin.hpp"

//默认构造函数
Admin::Admin() { }
//管理员登录
bool Admin::Loggin() {
    string pass_word;
    cin >> pass_word;
    fflush(stdin);
    if (pass_word == admin_password) {
        cout << "密码正确" << endl;
        return true;
    }
    cout << "密码错误" << endl;
    return false;
}
//发布公告
void Admin::Announce() {
    cout << "请输入公告内容: ";
    string announcement;
    cin >> announcement;
    ofstream InMyFile;
    InMyFile.open(ANNOUNCEMENT_FILE_NAME);
    InMyFile<<announcement;
    cout << "公告发布成功" << endl;
}
//广告设置
void Admin::SetAd() {
    cout << "您要设置左栏广告（1）还是右栏广告（2）" << endl;
    char ch;
    cin >> ch;
    fflush(stdin);
    if (ch == '1') {
        cout << "请输入新的左栏广告(小于80字): ";
        string ad;
        cin >> ad;
        ofstream InMyFile;
        InMyFile.open(LEFT_AD_FILE_NAME);
        InMyFile<<ad;
        cout << "左栏广告设置成功" << endl;
    } else {
        cout << "请输入新的右栏广告(小于80字): ";
        string ad;
        cin >> ad;
        ofstream InMyFile;
        InMyFile.open(RIGHT_AD_FILE_NAME);
        InMyFile<<ad;
        cout << "右栏广告设置成功" << endl;
    }
}
//广告一键清空
void Admin::ClearAd() {
    cout << "您要清空左栏广告（1）还是右栏广告（2）" << endl;
    char ch;
    cin >> ch;
    fflush(stdin);
    if (ch == '1') {
        ofstream InMyFile;
        InMyFile.open(LEFT_AD_FILE_NAME);
        string ad = "　　　广　　　　　　　　　　　　　　　告　　　　　　　　　　　　　　　位　　　　　　　　　　　　　　　招　　　　　　　　　　　　　　　租　　　　　　　　　　　　";
        InMyFile<<ad;
        cout << "左栏广告清空成功" << endl;
    } else {
        ofstream InMyFile;
        InMyFile.open(RIGHT_AD_FILE_NAME);
        string ad = "　　　广　　　　　　　　　　　　　　　告　　　　　　　　　　　　　　　位　　　　　　　　　　　　　　　招　　　　　　　　　　　　　　　租　　　　　　　　　　　　";
        InMyFile<<ad;
        cout << "右栏广告清空成功" << endl;
    }
}
//商家找回密码
void Admin::MerchantRetrievePassword() {
    cout << "请输入用户名: ";
    string user__name;
    cin >> user__name;
    typedef struct node {
        string username;
        string password;
        string shopname;
        struct node *next;
    }Node;
    Node *L = new Node;
    Node *p = L->next;
    ifstream OutMyFile;
    OutMyFile.open(MERCHANT_FILE_NAME);
    while (!OutMyFile.eof()) {
        
    }
}
