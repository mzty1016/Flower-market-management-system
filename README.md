# 基于青岛市枯桃花卉市场的交易管理系统
## 开发者前言
###                                   本开发者为青岛科技大学信息学院计算机科学与技术（开发）专业的一名大二学生，本项目是我C++的课程设计作业。利用git的目的是规范自己的软件开发流程，并可供其他学习者参考。数据结构期末考试结束，想借此机会强化并使用数据结构的相关内容。本系统前期开发环境为macOS Mojave，后期页面设计因为用到DOS界面转移至Win10。
## 系统简介
### 本系统旨在提高青岛市枯桃花卉市场的运作效率，为买家、商家、管理者提供便利。
### 本系统根据作业要求，包含以下内容：类、继承、多态、虚函数、虚基类，文件读写等。
### 本系统包含的数据结构内容：链表等数据结构、哈希表等
## 系统基本功能
### 商家：查看上架花卉，上架、下架花卉，修改花卉信息，花卉折扣。
### 买家：查看所有花卉、查找花卉，购买花卉
## C++类
### 用户类：商家、买家、VIP买家、管理员
### 花卉类：多肉、草本、木本、水生、观花、观叶。
### 菜单类：商家菜单、买家菜单、VIP买家菜单、管理员菜单
## 作业要求的实现
### 虚函数：（1）商家可设置花卉折扣，对上架天数超过花期的花卉按设置进行折扣，但不同种类的花花期未必相同，所以虽然调用同名函数，但折扣不同。（2）不同的菜单对象展示不同的菜单。
### 继承、派生：（1）商家、买家、VIP买家、管理员类继承用户类。（2）观花、观叶类继承草本、木本类。（3）商家菜单、买家菜单、VIP买家菜单、管理员菜单继承菜单类。
### 虚基类：观花、观叶类继承草本、木本类，多肉、水生继承观花、观叶类，此时草本、木本类设置为虚基类。
### 文件读写：将花卉信息从文件读取到内存中。
## 数据结构的相关内容
### 哈希表（链地址法处理冲突）
#### 对本系统采用哈希表的分析：
#### 优点：因为花卉种类有限，所以哈希表长度不会太长（设置为500），并且所有商家的信息可以存放在一张哈希表上，哈希表进行查找（修改、删除）时效率高。
#### 缺点：因为所有商家花卉信息存放在一张哈希表上，商家查看自己商家花卉时需对所有花卉信息遍历去寻找自己的花卉，效率较低。
#### 综合分析：因为商家数量远远小于买家，买家对花卉频繁的查找（购买也需查找）对系统运行效率的提升将使采用哈希表的缺点被忽略。
### 链表
#### 哈希表的链地址法处理冲突用到链表，增加删除效率高。

