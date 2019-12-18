# 基于青岛市枯桃花卉市场的交易管理系统
---
## 开发者前言              
**本系统开发者为青岛科技大学信息学院计算机科学与技术（开发）专业的两名大二学生，本项目是我们的C++课程设计作业。利用git的目的是规范我们的软件开发流程，并为其他学习者提供参考，代码编写参考《GoogleC++编程规范》。数据结构期末考试结束，想借此机会强化并使用数据结构的相关内容。本系统开发环境为macOS Mojave和Win 10，因IDE不同，参考者不必关注工程文件，只需关注.cpp与.hpp文件即可。**

---
## 系统简介
+ 本系统旨在提高青岛市枯桃花卉市场的运作效率，为买家、商家、管理者提供便利。
+ 本系统根据作业要求，包含以下内容：类、类的组合、继承、多态、虚函数、虚基类，运算符重载，STL标准模板库，文件读写等。
+ 本系统包含的数据结构内容：链表，栈，链表归并排序，哈希表等
---
## 系统基本功能
+ 商家：商家入驻，商家登录，查看自家已上架花卉，上架、下架花卉，修改花卉信息，花卉自动折扣。
+ 买家：买家注册，买家登录，查看所有商家花卉，查找花卉，预约花卉，花卉排序， 花卉推荐，花店地址导航。
+ 管理员 ：广告设置，发布公告，找回密码（并能进行商家和买家的所有操作，方便系统优化）。
---
## 系统框架
+ 系统框架总体基于哈希表，系统开始运行时建立哈希表（对于同名但不同商家的花卉采用链地址法处理冲突，对不同名花卉采用二次探测法处理冲突（查找、删除时处理冲突的方式与之相同，将花卉名称代入哈希函数返回哈希值，通过二次探测函数不断更新哈希值对哈希表进行搜索，若搜索次数超过设定的阈值，则花卉不存在或哈希函数离散程度有问题，需要重新建立哈希函数）），完成广告、公告的加载。通过各种菜单类对象的嵌套实例化，实现多级菜单进入不同的功能模块，在各个菜单通过实例化买家、商家或管理员对象对花卉类对象进行操作（对哈希表进行操作）或对文件操作，整个系统运行过程共同维护一张哈希表，哈希表保存函数写在哈希表类的析构函数中，实现退出系统时对操作后的哈希表进行保存。
---
## 数据结构的相关内容
+ 哈希表（链地址法处理冲突与二次探测法处理冲突相结合）
  - 优点：因为花卉种类有限，所以哈希表长度不会太长（设置为500），并且所有商家的信息可以存放在一张哈希表上（同种花不同商家链地址法处理冲突，不同种花卉二次探测法处理冲突），哈希表进行查找（修改、删除）时效率高。
  - 缺点：因为所有商家花卉信息存放在一张哈希表上，商家查看自己商家花卉时需对所有花卉信息遍历去寻找自己的花卉，效率较低。
  - 综合分析：因为商家数量远远小于买家，买家对花卉频繁的查找（预约也需查找）对系统运行效率的提升将使采用哈希表的缺点被忽略。
+ 链表
  - 哈希表的链地址法处理冲突用到链表，插入删除效率高。
+ 栈
  - 花店地址导航功能类似走迷宫，用到栈。
---
## 功能模块
+ 商家模块，买家模块，管理员模块。
---
## C++类
+ 用户类：用户类派生出：商家、买家，管理员类继承商家和买家类，所以商家买家类继承虚基类
+ 花卉类：花卉类包含组合类日期类
+ 菜单类：主菜单类派生出商家入驻登录菜单、商家操作菜单、买家注册登录菜单、买家操作菜单、管理员登录菜单类、管理员操作菜单类
+ 哈希表类
---
## 作业要求的实现
1. 类的组合：花卉类中包含日期类
2. 继承、派生：（1）商家、买家类继承用户类。（2）商家菜单、买家菜单、管理员菜单继承菜单类。
3. 虚基类：管理员类继承商家和买家类，由于存在二义性，商家和买家类要设置虚基类。
4. 多态、虚函数：不同类的菜单对象展示不同的菜单。
5. 运算符重载：对花卉类”<<"运算符进行重载，直接输出花卉信息。
6. STL标准模板库：哈希表类中用到vector容器
7. 文件读写：将花卉信息从文件读取到内存中。
---
## 开发文档
+ 2019年12月10日：设计系统要实现的功能，完成功能模块图。
+ 2019年12月12日：完成花卉类和日期类的定义及成员函数的实现），实现哈希表类的建立，初步设计哈希函数。
+ 2019年12月13日：测试花卉名称通过哈希函数计算后在哈希表中的离散程度，对哈希函数进行改进。测试两种处理冲突函数，完成哈希表类，菜单类（主菜单类派生出：买家登录注册菜单类、买家操作菜单类，商家入驻登录菜单类，商家操作菜单类，管理员菜单类），用户类（买家类，商家类，管理员类）的编写，各个类的成员函数暂未实现。完成系统基本框架的设计。
+ 2019年12月14日：对菜单类部分成员函数定义进行修改，完成类的UML图。
+ 2019年12月16日：对系统框架进行微调（修改部分类的定义），完成大部分成员函数（完成哈希表类、商家类的所有成员函数的编写并进行测试，实现文件读写，完成菜单类部分派生类成员函数，完成买家类部分成员函数）。
+ 2019年12月17日：除归并排序，商家、买家找回密码，花店地址导航，和界面美化外实现其它所有功能。
+ 2019年12月18日：实现买家、商家找回密码、实现各菜单输出时的界面美化（实现功能时的界面美化暂未实现）
