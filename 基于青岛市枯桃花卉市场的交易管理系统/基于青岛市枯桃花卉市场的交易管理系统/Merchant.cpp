//
//  Merchant.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/16.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include "Merchant.hpp"

#include "Hash.hpp"
extern HashTable hashtable;

//默认构造函数
Merchant::Merchant() {
    shop_name = "";
    log_success = false;
}
//进行初始化的构造函数
Merchant::Merchant(const string &user_name, const string &password, const string &shop_name) : User(user_name, password){
    this->shop_name = shop_name;
    log_success = false;
}
//修改登录状态
void Merchant::ModifyLogStatus(bool judge) {
    log_success = judge;
}
//是否登录成功，登录成功返回true，失败返回false
bool Merchant::IsLogSuccess() {
    return log_success;
}
//商家入驻
void Merchant::Logging() {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
//    Sleep(5);
    string user_name;
    string password1, password2;
    string shop_name;
    cout<<endl<<"                                           请输入注册用户名: ";
    cin >> user_name;
    //验证用户名是否存在
    ifstream InMyFile1;
    InMyFile1.open(MERCHANT_FILE_NAME);
    string file_user_name, file_password, file_shop_name;
    while (!InMyFile1.eof()) {
        InMyFile1>>file_user_name>>file_password>>file_shop_name;
        if (file_user_name == user_name) {
            InMyFile1.close();
            fflush(stdin);
            cout<<endl<<"                               该用户名已被注册，入驻失败，正在返回商家界面....\n";
//            Sleep(2000);
//            system("CLS");
            return ;
        }
    }
    InMyFile1.close();
    //输入两次密码
    cout<<endl<<"                                         请输入密码(不小于8位): ";
    cin >> password1;
    if (password1.length() < 8) {
        fflush(stdin);
        cout<<endl<<"                              密码长度应不小于8位，入驻失败，正在返回商家界面....";
//        Sleep(2000);
//        system("CLS");
        return ;
    }
    cout<<endl<<"                                           请再次输入密码: ";
    cin >> password2;
    if (password1 != password2) {
        fflush(stdin);
        cout<<endl;
        cout<<"                            两次输入的密码不一致，入驻失败，正在返回商家界面....";
//        Sleep(2000);
//        system("CLS");
        return ;
    }
    cout<<endl<<"                                           请输入花店名: ";
    cin >> shop_name;
    fflush(stdin);
    //验证花店名已存在
    ifstream InMyFile2;
    InMyFile2.open(MERCHANT_FILE_NAME);
    while (!InMyFile2.eof()) {
        InMyFile2>>file_user_name>>file_password>>file_shop_name;
        if (file_shop_name == shop_name) {
            cout<<endl<<"                                 该店名已存在， 入驻失败，正在返回商家界面....";
            //        Sleep(2000);
            //        system("CLS");
            return ;
        }
    }
    InMyFile2.close();
    fstream InMyFile3;
    InMyFile3.open(MERCHANT_FILE_NAME, ios::app);
    InMyFile3.seekg(0, ios::end); //将文件指针指向文件末端
    streampos fp = InMyFile3.tellg(); //fp为文件指针的偏移量
    if (int(fp) != 0) // 偏移量为0，证明文件为空，为首次进入系统,不是首次进入系统就换行
        InMyFile3<<endl;
    InMyFile3<<user_name<<" "<<password1<<" "<<shop_name;
    InMyFile3.close();
    Map m;
    m.InitMap();
    m.AddAddress(shop_name);
    m.SaveMap();
    cout<<endl<<"                                           入驻成功 ";
}
//商家登录
Merchant Merchant::Loggin() {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    //    Sleep(5);
    string user_name;
    string password;
    cout<<endl<<"                                       请 输 入 用 户 名:";
    cin >> user_name;
    cout<<endl<<"                                        请 输 入 密 码:";
    cin >> password;
    fflush(stdin);
    string file_user_name; //文件中的用户名
    string file_password; //文件中的密码
    string file_shop_name; //文件中的店名
    ifstream OutMyFile;
    OutMyFile.open(MERCHANT_FILE_NAME);
    while (!OutMyFile.eof()) {
        OutMyFile>>file_user_name>>file_password>>file_shop_name;
        if (file_user_name == user_name) {
            if (file_password == password) {
                OutMyFile.close();
                cout<<endl<<"                                           密码正确,正在登录...."<<endl;
//                Sleep(2000);
//                system("CLS");
                Merchant m(user_name, password, file_shop_name);
                m.ModifyLogStatus(true);
                return m;
            } else {
                OutMyFile.close();
                cout<<endl<<"                                     密码错误，正在返回商家界面...."<<endl;
//                Sleep(2000);
//                system("CLS");
                Merchant m;
                return m;
            }
        }
    }
    OutMyFile.close();
    cout<<endl<<"                                     该用户名不存在，正在返回商家界面...."<<endl;
    //                Sleep(2000);
    //                system("CLS");
    Merchant m;
    return m;
}
//查看自家上架花卉
void Merchant::CheckFlower() const {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    //    Sleep(5);
    printf("    花卉名称          花店名          花卉颜色             单价              数量             上架日期  \n");
    for (int i = 0; i < MAXSIZE; ++i) {
        LNode *p = hashtable.first[i];
        while (p != NULL) {
            if(p->flower->ShopNameInfo() == shop_name) {
                printf("      %-8s         %-8s           %-5s              %5.1f               %-3d            ", p->flower->FlowerNameInfo().c_str(), p->flower->ShopNameInfo().c_str(), p->flower->PetalColorInfo().c_str(),p->flower->FlowerPriceInfo(),  p->flower->FlowerNumberInfo());
                //用到运算符重载 <<
                cout<<p->flower->FlowerDateInfo();
            }
            p = p->next;
        }
    }
}
//花卉上架
void Merchant::AddFlower() const {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    //    Sleep(5);
    string flower_name;
    string shop_name = this->shop_name;
    string flower_color;
    float flower_price;
    int flower_number;
    int year, month, day;
    cout << "                                           请输入花卉名称: ";
    cin >> flower_name;
    cout << "                                           请输入花卉颜色: ";
    cin >> flower_color;
    cout << "                                           请输入花卉价格: ";
    cin >> flower_price;
    cout << "                                           请输入花卉数量: ";
    cin >> flower_number;
    cout << "                                         请输入花卉上架日期(年 月 日): ";
    cin >> year >> month >> day;
    fflush(stdin);
    LNode *p = new LNode;
    p->flower = new Flower(flower_name, shop_name, flower_color, flower_price, flower_number, year, month, day);
    hashtable.AddFlower(p, 1);
    cout <<endl<< "                                              花卉上架成功" << endl;
}
//花卉下架
void Merchant::DeleteFlower() const {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    //    Sleep(5);
    string flower_name;
    string shop_name = this->shop_name;
    cout << "                                      请输入你要下架花卉的名称 :";
    cin >> flower_name;
    fflush(stdin);
    if (hashtable.DeleteFlower(flower_name, shop_name, 1))
        cout <<endl<< "                                               花卉下架成功" <<endl;
    else
        cout <<endl<< "                                            要下架的花卉不存在" << endl;
}
//花卉信息修改
void Merchant::ModifyFlowerInfo() const {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    //    Sleep(5);
    string flower_name;
    cout<<endl<<"                                      请输入你要修改的花卉名称: ";
    cin >> flower_name;
    fflush(stdin);
    int index = hashtable.SearchFlower(flower_name, 1);
    if (index == -1) {
        cout<<endl<<"                                          您要修改的花卉不存在"<<endl;
        return ;
    } else {
        LNode *p = hashtable.first[index];
        while(p != NULL) {
            if (p->flower->ShopNameInfo() == shop_name) {
                cout<<endl<<"                                             您要修改哪个信息: "<<endl;
                cout<<endl<<"                                                1.花卉颜色 "<<endl;
                cout<<endl<<"                                                2.花卉价格 "<<endl;
                cout<<endl<<"                                                3.花卉数量 "<<endl;
                cout<<endl<<"                                                4.花卉上架日期 "<<endl;
                char ch;
                string color;
                float price;
                int number;
                int yy, mm, dd;
                cin >> ch;
                fflush(stdin);
                switch (ch) {
                    case '1':
                        cout << "                                           当前花卉颜色为: " << p->flower->PetalColorInfo() <<endl;
                        cout << "                                         请输入修改后的花卉颜色: ";
                        cin >> color;
                        fflush(stdin);
                        p->flower->ModifyPetalColor(color);
                        cout <<endl<<"                                             "<< p->flower->FlowerNameInfo() <<"颜色修改成功" << endl;
                        break;
                    case '2':
                        cout << "                                          当前花卉价格为: " << p->flower->FlowerPriceInfo() <<endl;
                        cout << "                                         请输入要修改后的价格: ";
                        cin >> price;
                        fflush(stdin);
                        p->flower->ModifyFlowerPrice(price);
                        cout <<endl<<"                                             "<< p->flower->FlowerNameInfo() <<"价格修改成功" << endl;
                        break;
                    case '3':
                        cout << "                                          当前花卉数量为: " << p->flower->FlowerNumberInfo() <<endl;
                        cout << "                                         请输入要修改后的数量: ";
                        cin >> number;
                        fflush(stdin);
                        p->flower->ModifyFlowerNumber(number);
                        cout <<endl<<"                                             "<< p->flower->FlowerNameInfo() <<"数量修改成功" << endl;
                        break;
                    case '4':
                        cout << "                                          当前花卉上架日期为: " << p->flower->YearInfo() <<"/"<<p->flower->MonthInfo()<<"/"<<p->flower->DayInfo()<<endl;
                        cout << "                                       请输入要修改后的上架日期(yy mm dd): ";
                        cin >> yy >> mm >> dd;
                        fflush(stdin);
                        p->flower->ModifyFlowerDate(yy, mm, dd);
                        cout <<endl<<"                                             "<< p->flower->FlowerNameInfo() <<"上架日期修改成功" << endl;
                        break;
                    default:
                        cout << "                                     无效的输入" << endl;
                }
                return ;
            }
            p = p->next;
        }
    }
    cout << "                                            你要修改的花卉不存在" << endl;
}
//花卉自动折扣
void Merchant::AutoDiscountFlower() const {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    //    Sleep(5);
    cout << "                                     请输入折扣花卉的已上架天数: ";
    int num;
    cin >> num;
    int yy2, mm2, dd2;
    time_t timep;
    struct tm *p;
    time(&timep);
    p=gmtime(&timep);
    yy2 = 1900+p->tm_year;
    mm2 = 1+p->tm_mon;
    dd2 = p->tm_mday;
    cout << "                                      请输入折扣(0.0——1.0): ";
    float discount;
    cin >> discount;
    fflush(stdin);
    for (int i = 0; i < MAXSIZE; ++i) {
        LNode *p = hashtable.first[i];
        while (p != NULL) {
            if(p->flower->ShopNameInfo()==shop_name && FlowerDateCompare(p->flower->YearInfo(), p->flower->MonthInfo(), p->flower->DayInfo(), yy2, mm2, dd2) >= num) {
                cout <<endl<<"                                       "<< p->flower->FlowerNameInfo() << "的价格从"<< p->flower->FlowerPriceInfo() << "变为";
                p->flower->ModifyFlowerPrice(p->flower->FlowerPriceInfo() * discount);
                cout << p->flower->FlowerPriceInfo() <<endl;
            }
            p = p->next;
        }
    }
}

//比较日期，返回差值 (yy2/mm2/dd2 - yy1/mm1/dd1)
const int Merchant::FlowerDateCompare(int yy1, int mm1, int dd1, int yy2, int mm2, int dd2) const {
    int sum = 0;
    if (mm1==mm2) {
        return dd2 - dd1;
    }
    else if (mm1 < mm2-1) {
        switch (mm1) {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                sum += 31 - dd1 + 1;
                break;
            case 4:case 6:case 9:case 11:
                sum += 30 - dd1 + 1;
                break;
            case 2:
                if ((yy1%4==0 && yy1%100!=0) || yy1%400==0)
                    sum += 29 - dd1 + 1;
                else
                    sum += 28 - dd1 + 1;
        }
        while (mm1 < mm2) {
            switch (mm1) {
                case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                    sum += 31;
                    break;
                case 4:case 6:case 9:case 11:
                    sum += 30;
                    break;
                case 2:
                    if((yy1%4==0 && yy1%100!=0) || yy1%400==0)
                        sum += 29;
                    else
                        sum += 28;
            }
            sum += dd2 - 1;
            return sum;
        }
    }
    else if (mm1 < mm2) {
        switch (mm1) {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                sum += 31 - dd1 + 1;
                break;
            case 4:case 6:case 9:case 11:
                sum += 30 - dd1 + 1;
                break;
            case 2:
                if((yy1%4==0 && yy1%100!=0) || yy1%400==0)
                    sum += 29 - dd1 + 1;
                else
                    sum += 28 - dd1 + 1;
        }
        sum += dd2 - 1;
        return sum;
    }
    else if (mm1 > mm2) {
        switch (mm1) {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                sum += 31 - dd1 + 1;
                break;
            case 4:case 6:case 9:case 11:
                sum += 30 - dd1 + 1;
                break;
            case 2:
                if((yy1%4==0 && yy1%100!=0) || yy1%400==0)
                    sum += 29 - dd1 + 1;
                else
                    sum += 28 - dd1 + 1;
        }
        while (mm1 < 13) {
            switch (mm1) {
                case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                    sum += 31;
                    break;
                case 4:case 6:case 9:case 11:
                    sum += 30;
                    break;
                case 2:
                    if((yy1%4==0 && yy1%100!=0) || yy1%400==0)
                        sum += 29;
                    else
                        sum += 28;
            }
        }
        mm1 = 1;
        if(mm1 < mm2-1){
            switch (mm1) {
                case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                    sum += 31 - dd1 + 1;
                    break;
                case 4:case 6:case 9:case 11:
                    sum += 30 - dd1 + 1;
                    break;
                case 2:
                    if((yy2%4==0 && yy2%100!=0)||yy2%400==0)
                        sum += 29 - dd1 + 1;
                    else
                        sum += 28 - dd1 + 1;
            }
            while(mm1 < mm2) {
                switch (mm1) {
                    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                        sum += 31;
                        break;
                    case 4:case 6:case 9:case 11:
                        sum += 30;
                        break;
                    case 2:
                        if((yy2%4==0 && yy2%100!=0) || yy2%400==0)
                            sum += 29;
                        else
                            sum += 28;
                }
                sum += dd2 - 1;
                return sum;
            }
        }
        else if (mm1 < mm2) {
            switch (mm1) {
                case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                    sum += 31 - dd1 + 1;
                    break;
                case 4:case 6:case 9:case 11:
                    sum += 30 - dd1 + 1;
                    break;
                case 2:
                    if((yy1%4==0 && yy1%100!=0) || yy1%400==0)
                        sum += 29 - dd1 + 1;
                    else
                        sum += 28 - dd1 + 1;
            }
            sum += dd2 - 1;
            return sum;
        }
    }
    return 0;
}
