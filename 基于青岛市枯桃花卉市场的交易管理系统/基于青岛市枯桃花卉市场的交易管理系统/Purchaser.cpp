//
//  Purchaser.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/16.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include "Purchaser.hpp"

#include "Hash.hpp"
extern HashTable hashtable;

//默认构造函数
Purchaser::Purchaser() {
    LinkList = NULL;
    log_success = false;
}
//进行初始化的构造函数
Purchaser::Purchaser(const string &user_name, const string &password) : User(user_name, password){
    LinkList = NULL;
    log_success = false;
}
//修改登录状态
void Purchaser::ModifyLogStatus(bool judge) {
    log_success = judge;
}
//是否登录成功，登录成功返回true，失败返回false
bool Purchaser::IsLogSuccess() {
    return log_success;
}
//买家注册
void Purchaser::Logging() {
    string user_name;
    string password;
    cout << "请输入用户名: ";
    cin >> user_name;
    //验证用户名是否存在
    string file_name = FILEADDRESS + user_name + FILETYPE;
    cout << "请输入密码（不小于8位）: ";
    cin >> password;
    if (password.length() < 8) {
        cout << "密码小于8位注册失败" << endl;
        return ;
    }
    ofstream struct_file(file_name);
    fstream InMyFile;
    InMyFile.open(PURCHASERFILENAME, ios::app);
    InMyFile.seekg(0, ios::end); //将文件指针指向文件末端
    streampos fp = InMyFile.tellg(); //fp为文件指针的偏移量
    if (int(fp) != 0) // 偏移量为0，证明文件为空，为首次进入系统,不是首次进入系统就换行
        InMyFile<<endl;
    InMyFile<<user_name<<" "<<password;
    InMyFile.close();
}
//买家登录
Purchaser Purchaser::Loggin() {
    string user_name;
    string password;
    cout << "请输入用户名: ";
    cin >> user_name;
    cout << "请输入密码: ";
    cin >> password;
    string file_user_name; //文件中的用户名
    string file_password; //文件中的密码
    ifstream OutMyFile;
    OutMyFile.open(PURCHASERFILENAME);
    while (!OutMyFile.eof()) {
        OutMyFile>>file_user_name>>file_password;
        if (file_user_name == user_name) {
            if (file_password == password) {
                OutMyFile.close();
                cout << "登录成功" <<endl;
                Purchaser p(user_name, password);
                p.ModifyLogStatus(true);
                return p;
            } else {
                OutMyFile.close();
                cout << "密码错误" <<endl;
                Purchaser p;
                return p;
            }
        }
    }
    OutMyFile.close();
    Purchaser p;
    return p;
}
//查看所有上架花卉
void Purchaser::CheckALLFlower() const {
    cout << " 花卉名称 " << " 花店名 " << " 颜色 " << " 单价 " << "数量" << " 上架日期 " << endl;
    for (int i = 0; i < MAXSIZE; ++i) {
        LNode *p = hashtable.first[i];
        while (p != NULL) {
            cout<<p->flower->FlowerNameInfo()<<"  "<<p->flower->ShopNameInfo()<<"  "<<p->flower->PetalColorInfo()<<"  "<<p->flower->FlowerPriceInfo()<<"  "<<p->flower->FlowerNumberInfo()<<" "<<p->flower->YearInfo()<<"/"<<p->flower->MonthInfo()<<"/"<<p->flower->DayInfo()<<endl;
            p = p->next;
        }
    }
}
//查找花卉
void Purchaser::SearchFlower() const {
    LNode* linklist;
    linklist = NULL;
    string flower_name;
    cout << "请输入你要查找的花卉名称 :";
    cin >> flower_name;
    fflush(stdin);
    int index = hashtable.SearchFlower(flower_name, 1);
    if (index == -1) {
        cout << "你要查找的花卉不存在" << endl;
        return ;
    } else {
        LNode *p = hashtable.first[index];
        linklist = p;
        cout << "你要查找的花卉信息为: " << endl;
        cout << " 花卉名称 " << " 花店名 " << " 颜色 " << " 单价 " << "数量" << " 上架日期 " << endl;
        while (p != NULL) {
            cout<<p->flower->FlowerNameInfo()<<"  "<<p->flower->ShopNameInfo()<<"  "<<p->flower->PetalColorInfo()<<"  "<<p->flower->FlowerPriceInfo()<<"  "<<p->flower->FlowerNumberInfo()<<" "<<p->flower->YearInfo()<<"/"<<p->flower->MonthInfo()<<"/"<<p->flower->DayInfo()<<endl;
            p = p->next;
        }
//        bool flag = 1;
//        LNode *q;
//        while (flag) {
//            cout << "1.按单价排序" << endl;
//            cout << "2.按上架日期排序" << endl;
//            cout << "3.返回" << endl;
//            char ch;
//            cin >> ch;
//            fflush(stdin);
//            switch (ch) {
//                case '1':
//                    linklist = MergeSort1(linklist);
//                    q = LinkList;
//                    cout << "按单价排序: " << endl;
//                    while (q != NULL) {
//                        cout<<q->flower->FlowerNameInfo()<<"  "<<q->flower->ShopNameInfo()<<"  "<<q->flower->PetalColorInfo()<<"  "<<q->flower->FlowerPriceInfo()<<"  "<<q->flower->YearInfo()<<"/"<<q->flower->MonthInfo()<<"/"<<q->flower->DayInfo()<<endl;
//                        q = q->next;
//                    }
//                    break;
//                case '2':
//                    break;
//                case '3':
//                    flag = 0;
//                    break;
//                default:
//                    cout << "无效的输入,请重新输入" << endl;
//            }
//        }
        return ;
    }
}

//LNode* Purchaser::MergeList1(LNode *L1, LNode *L2) const {
//    LNode *p, *q, *L, *r;
//    L = L1;
//    p = L1;
//    q = L2;
//    if(p&&q&&p->flower->FlowerPriceInfo()<=q->flower->FlowerPriceInfo()){
//        L->flower->ModifyFlowerPrice(p->flower->FlowerPriceInfo());
//        L->next = p->next;
//        p = p->next;
//        r = L;
//    }
//    else if(p&&q){
//        L->flower->ModifyFlowerPrice(q->flower->FlowerPriceInfo());
//        L->next = q->next;
//        q = q->next;
//        r = L;
//    }
//    while(p&&q){
//        if(p->flower->FlowerPriceInfo()<=q->flower->FlowerPriceInfo()){
//            r->next = p;
//            r = p;
//            p = p->next;
//        }
//        else{
//            r->next = q;
//            r = q;
//            q = q->next;
//        }
//    }
//    p = p?p:q;
//    r->next = p;
//    return L;
//}
//
//LNode* Purchaser::MergeSort1(LNode *head) const {
//    if(head==NULL||head->next==NULL)
//        return head;
//    LNode *slow, *fast;
//    slow = head;
//    fast = head->next;
//    while(fast!=NULL){
//        fast = fast->next;
//        if(fast!=NULL){
//            fast = fast->next;
//            slow = slow->next;
//        }
//    }
//    LNode *lefthead = head, *righthead = slow->next;
//    slow->next = NULL;
//    lefthead = MergeSort1(lefthead);
//    righthead = MergeSort1(righthead);
//    return MergeList1(lefthead, righthead);
//}

void Purchaser::ReserveFlower() const {
    string flower_name;
    cout << "请输入您要预约的花卉名称 :";
    cin >> flower_name;
    fflush(stdin);
    int index = hashtable.SearchFlower(flower_name, 1);
    if (index == -1) {
        cout << "您要预约的花卉不存在" << endl;
        return ;
    } else {
        LNode *p = hashtable.first[index];
        cout << "您可以预约的花卉如下: " << endl;
        cout << " 花卉名称 " << " 花店名 " << " 颜色 " << " 单价 " << "数量" << " 上架日期 " << endl;
        while (p != NULL) {
            cout<<p->flower->FlowerNameInfo()<<"  "<<p->flower->ShopNameInfo()<<"  "<<p->flower->PetalColorInfo()<<"  "<<p->flower->FlowerPriceInfo()<<"  "<<p->flower->FlowerNumberInfo()<<" "<<p->flower->YearInfo()<<"/"<<p->flower->MonthInfo()<<"/"<<p->flower->DayInfo()<<endl;
            p = p->next;
        }
        string shop_name;
        cout << "请输入您要预约花卉的花店名: ";
        cin >> shop_name;
        fflush(stdin);
        p = hashtable.first[index];
        while (p != NULL) {
            if (p->flower->ShopNameInfo() == shop_name) {
                cout << "请输入您要预约的数量: ";
                int num;
                cin >> num;
                if (p->flower->FlowerNumberInfo() < num) {
                    cout << "预约数量大于库存，预约失败" << endl;
                } else {
                    p->flower->ModifyFlowerNumber(p->flower->FlowerNumberInfo() - num);
                    string file_name = FILEADDRESS + UserNameInfo() + FILETYPE;
                    fstream InMyFile;
                    InMyFile.open(file_name, ios::app);
                    InMyFile.seekg(0, ios::end); //将文件指针指向文件末端
                    streampos fp = InMyFile.tellg(); //fp为文件指针的偏移量
                    if (int(fp) != 0) // 偏移量为0，证明文件为空，为首次进入系统,不是首次进入系统就换行
                        InMyFile<<endl;
                    InMyFile<<p->flower->FlowerNameInfo()<<" "<<p->flower->ShopNameInfo()<<" "<<p->flower->PetalColorInfo()<<" "<<p->flower->FlowerPriceInfo()<<" "<<num<<" "<<p->flower->YearInfo()<<" "<<p->flower->MonthInfo()<<" "<<
                    p->flower->DayInfo();
                    InMyFile.close();
                    cout << "预约成功" << endl;
                    return ;
                }
            }
        }
        cout << "该商家不存在" << endl;
        return ;
    }
}
void Purchaser::CheckReservation() const{
    string flower_name;
    string shop_name;
    string flower_color;
    float flower_price;
    int flower_number;
    int year, month, day;
    fstream OutMyFile;
    string file_name = FILEADDRESS + UserNameInfo() + FILETYPE;
    OutMyFile.open(file_name);
    OutMyFile.seekg(0, ios::end); //将文件指针指向文件末端
    streampos fp = OutMyFile.tellg(); //fp为文件指针的偏移量
    if (int(fp) == 0) { // 偏移量为0，证明文件为空，为首次进入系统,不是首次进入系统就换行
        cout << "您没有预约花卉" << endl;
        return ;
    }
    OutMyFile.close();
    OutMyFile.open(file_name);
    cout << " 花卉名称 " << " 花店名 " << " 颜色 " << " 单价 " << "数量" << " 上架日期 " << endl;
    while (!OutMyFile.eof()) {

        OutMyFile>>flower_name>>shop_name>>flower_color>>flower_price>>flower_number>>year>>month>>day;
        cout<<flower_name<<" "<<shop_name<<" "<<flower_color<<" "<<flower_price<<" "<<flower_number<<" "<<year<<"/"<<month<<"/"<<day<<endl;
    }
    OutMyFile.close();
}
