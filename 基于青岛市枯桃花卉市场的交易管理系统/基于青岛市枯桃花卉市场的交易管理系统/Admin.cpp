//
//  Admin.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/16.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include "Admin.hpp"

extern char leftad1[30], leftad2[30], leftad3[30], leftad4[30], leftad5[30], leftad6[30], leftad7[30], leftad8[30], leftad9[30], leftad10[30];
extern char rightad1[30], rightad2[30], rightad3[30], rightad4[30], rightad5[30], rightad6[30], rightad7[30], rightad8[30], rightad9[30], rightad10[30];
extern char announcement1[120], announcement2[120], announcement3[120], announcement4[120], announcement5[120];

//默认构造函数
Admin::Admin() { }
//管理员登录
bool Admin::Loggin() {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    cout<<endl<<"                                           请输入管理员密码: ";
    string pass_word;
    cin >> pass_word;
    fflush(stdin);
    if (pass_word == admin_password) {
        cout<<endl<<"                                           密码正确,正在登录...."<<endl;
        //                Sleep(2000);
        //                system("CLS");
        return true;
    }
    cout<<endl<<"                                     密码错误，正在返回主菜单...."<<endl;
    //                Sleep(2000);
    //                system("CLS");
    return false;
}
//发布公告
void Admin::Announce() {
    ClearAn();
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    cout<<endl<<"                                           请输入公告内容: "<<endl;
    string announcement;
    cin >> announcement;
    fflush(stdin);
    ofstream InMyFile;
    InMyFile.open(ANNOUNCEMENT_FILE_NAME);
    InMyFile<<announcement;
    InMyFile.close();
    cout<<endl<<"                                               公告发布成功"<<endl;
}
//清空公告
void Admin::ClearAn() {
    for (int i = 0; i < 120; i++)
        announcement1[i] = '\0';
    for (int i = 0; i < 120; i++)
        announcement2[i] = '\0';
    for (int i = 0; i < 120; i++)
        announcement3[i] = '\0';
    for (int i = 0; i < 120; i++)
        announcement4[i] = '\0';
    for (int i = 0; i < 120; i++)
        announcement5[i] = '\0';
}
//广告设置
void Admin::SetAd() {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    cout<<endl<<"                                   您要设置左栏广告（1）还是右栏广告（2）: ";
    char ch;
    cin >> ch;
    fflush(stdin);
    if (ch == '1') {
        ClearAd2('1');
        cout<<endl<<"                                        请输入新的左栏广告(小于80字): "<<endl;
        string ad;
        cin >> ad;
        fflush(stdin);
        ofstream InMyFile;
        InMyFile.open(LEFT_AD_FILE_NAME);
        InMyFile<<ad;
        cout<<endl<<"                                             左栏广告设置成功"<<endl;
    } else if (ch == '2'){
        ClearAd2('2');
        cout<<endl<<"                                        请输入新的右栏广告(小于80字): "<<endl;
        string ad;
        cin >> ad;
        fflush(stdin);
        ofstream InMyFile;
        InMyFile.open(RIGHT_AD_FILE_NAME);
        InMyFile<<ad;
        cout<<endl<<"                                             右栏广告设置成功"<<endl;
    } else {
        cout<<endl<<"                                                输入有误"<<endl;
    }
}
//广告一键清空
void Admin::ClearAd() {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    cout<<endl<<"                                   您要清空左栏广告（1）还是右栏广告（2）: ";
    char ch;
    cin >> ch;
    fflush(stdin);
    if (ch == '1') {
        ofstream InMyFile;
        InMyFile.open(LEFT_AD_FILE_NAME);
        string ad = "　　　广　　　　　　　　　　　　　　　告　　　　　　　　　　　　　　　位　　　　　　　　　　　　　　　招　　　　　　　　　　　　　　　租　　　　　　　　　　　　";
        InMyFile<<ad;
        cout<<endl<<"                                             左栏广告清空成功"<<endl;
    } else if (ch == '2'){
        ofstream InMyFile;
        InMyFile.open(RIGHT_AD_FILE_NAME);
        string ad = "　　　广　　　　　　　　　　　　　　　告　　　　　　　　　　　　　　　位　　　　　　　　　　　　　　　招　　　　　　　　　　　　　　　租　　　　　　　　　　　　";
        InMyFile<<ad;
        cout<<endl<<"                                             右栏广告清空成功"<<endl;
    } else {
        cout<<endl<<"                                                输入有误"<<endl;
    }
}
//广告置空，设置新的广告前先将广告置空;
void Admin::ClearAd2(char ch) {
    switch (ch) {
        case '1':
            for (int i = 0; i < 30; i++)
                leftad1[i] = '\0';
            for (int i = 0; i < 30; i++)
                leftad2[i] = '\0';
            for (int i = 0; i < 30; i++)
                leftad3[i] = '\0';
            for (int i = 0; i < 30; i++)
                leftad4[i] = '\0';
            for (int i = 0; i < 30; i++)
                leftad5[i] = '\0';
            for (int i = 0; i < 30; i++)
                leftad6[i] = '\0';
            for (int i = 0; i < 30; i++)
                leftad7[i] = '\0';
            for (int i = 0; i < 30; i++)
                leftad8[i] = '\0';
            for (int i = 0; i < 30; i++)
                leftad9[i] = '\0';
            for (int i = 0; i < 30; i++)
                leftad10[i] = '\0';
            break;
        case '2':
            for (int i = 0; i < 30; i++)
                rightad1[i] = '\0';
            for (int i = 0; i < 30; i++)
                rightad2[i] = '\0';
            for (int i = 0; i < 30; i++)
                rightad3[i] = '\0';
            for (int i = 0; i < 30; i++)
                rightad4[i] = '\0';
            for (int i = 0; i < 30; i++)
                rightad5[i] = '\0';
            for (int i = 0; i < 30; i++)
                rightad6[i] = '\0';
            for (int i = 0; i < 30; i++)
                rightad7[i] = '\0';
            for (int i = 0; i < 30; i++)
                rightad8[i] = '\0';
            for (int i = 0; i < 30; i++)
                rightad9[i] = '\0';
            for (int i = 0; i < 30; i++)
                rightad10[i] = '\0';
            break;
    }
}
//买家找回密码
void Admin::PurchaserRetrievePassword() {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    cout<<endl<<"                                            请输入用户名:";
    string user__name;
    cin >> user__name;
    fflush(stdin);
    typedef struct node {
        string username;
        string password;
        struct node *next;
    }Node;
    Node *L = new Node;
    Node *p = L;
    bool flag = false; //判断是否找到该用户
    ifstream OutMyFile;
    OutMyFile.open(PURCHASER_FILE_NAME);
    while (!OutMyFile.eof()) {
        Node *q = new Node;
        q->next = NULL;
        OutMyFile>>q->username>>q->password;
        if (q->username == user__name) {
            string password1, password2;
            cout<<endl<<"                                            请输入修改后的密码: ";
            cin >> password1;
            if (password1.length() < 8) {
                cout<<endl<<"                                     密码长度小于8位，修改失败"<<endl;
                OutMyFile.close();
                return ;
            }
            cout<<endl<<"                                             请再次输入密码:";
            cin >> password2;
            fflush(stdin);
            if (password1 == password2) {
                flag = true;
                q->password = password1;
                cout<<endl<<"                                              密码修改成功"<<endl;
            } else {
                cout<<endl<<"                                   两次输入的密码不一致，修改失败"<<endl;
                OutMyFile.close();
                return ;
            }
        }
        p->next = q;
        p = q;
    }
    OutMyFile.close();
    if (flag == false)
        cout<<endl<<"                                          未找到该用户"<<endl;
    ofstream InMyFile;
    InMyFile.open(PURCHASER_FILE_NAME);
    L = L->next;
    while (L != NULL) {
        Node *p = L;
        InMyFile<<p->username<<" "<<p->password;
        if (L->next != NULL)
            InMyFile<<endl;
        L = L->next;
        delete p;
    }
    InMyFile.close();
}
//商家找回密码
void Admin::MerchantRetrievePassword() {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    cout<<endl<<"                                             请输入用户名:";
    string user__name;
    cin >> user__name;
    fflush(stdin);
    typedef struct node {
        string username;
        string password;
        string shopname;
        struct node *next;
    }Node;
    Node *L = new Node;
    Node *p = L;
    bool flag = false; //判断是否找到该用户
    ifstream OutMyFile;
    OutMyFile.open(MERCHANT_FILE_NAME);
    while (!OutMyFile.eof()) {
        Node *q = new Node;
        q->next = NULL;
        OutMyFile>>q->username>>q->password>>q->shopname;
        if (q->username == user__name) {
            string password1, password2;
            cout<<endl<<"                                            请输入修改后的密码: ";
            cin >> password1;
            if (password1.length() < 8) {
                cout<<endl<<"                                     密码长度小于8位，修改失败"<<endl;
                OutMyFile.close();
                return ;
            }
            cout<<endl<<"                                             请再次输入密码:";
            cin >> password2;
            fflush(stdin);
            if (password1 == password2) {
                flag = true;
                q->password = password1;
                cout<<endl<<"                                              密码修改成功"<<endl;
            } else {
                cout<<endl<<"                                   两次输入的密码不一致，修改失败"<<endl;
                OutMyFile.close();
                return ;
            }
        }
        p->next = q;
        p = q;
    }
    OutMyFile.close();
    if (flag == false)
        cout<<endl<<"                                          未找到该用户"<<endl;
    ofstream InMyFile;
    InMyFile.open(MERCHANT_FILE_NAME);
    L = L->next;
    while (L != NULL) {
        Node *p = L;
        InMyFile<<p->username<<" "<<p->password<<" "<<p->shopname;
        if (L->next != NULL)
            InMyFile<<endl;
        L = L->next;
        delete p;
    }
    InMyFile.close();
}
