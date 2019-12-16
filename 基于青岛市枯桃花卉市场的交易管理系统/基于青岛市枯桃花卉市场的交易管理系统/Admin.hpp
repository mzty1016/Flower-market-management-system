//
//  Admin.hpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/16.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#ifndef Admin_hpp
#define Admin_hpp

#include <stdio.h>

////管理员类,可进行任何操作,方便对系统进行测试，继承买家、卖家类，此时买家卖家类要设置虚基类
//class Admin : public Merchant, public Purchaser {
// public:
//    Admin();
//    bool Loggin(); //管理员登录，登录成功返回true，失败返回false
//    void Announce(); //发布公告
//    void SetAd(); //设置广告
//    void RetrievePassword(); //找回密码
//    void ClearLeftAd(); //清空左广告栏并显示: 广告位招租
//    void ClearrightAd(); //清空右广告栏并显示: 广告位招租
//    void ClearAnnouncement(); //清空公告
// private:
//    const string admin_password = ADMINPASSERWORD; //管理员密码
//};

#endif /* Admin_hpp */
