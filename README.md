# 基于青岛市枯桃花卉市场的交易管理系统
---
## 开发者前言              
**本系统开发者为青岛科技大学信息学院计算机科学与技术（开发）专业的一名大二学生，本项目是我的C++课程设计。利用git的目的是规范我的软件开发流程，并可为其他学习者提供参考，代码编写参考《GoogleC++编程规范》。数据结构期末考试结束，想借此机会强化并使用数据结构的相关内容。本系统开发环境为MacOS Mojave和Win 10，因IDE不同，参考者不必关注工程文件，只需关注.cpp与.hpp文件即可。**

---
## 系统简介
+ 本系统旨在提高青岛市枯桃花卉市场的运作效率，为买家、商家、管理者提供便利。
+ 本系统根据作业要求，包含以下内容：类、类的组合、继承、多态、虚基类，运算符重载，STL标准模板库，文件读写等。
+ 本系统包含的数据结构内容：哈希表，广度优先搜索（BFS），剪枝，分治法（归并排序），链表，栈，队列等
---
## 系统基本功能
+ 商家：商家入驻，商家登录，查看自家已上M架花卉，上架、下架花卉，修改花卉信息，花卉自动折扣。
+ 买家：买家注册，买家登录，查看所有商家花卉，查找花卉，预约花卉，花卉排序， 花卉推荐，花店地址导航。
+ 管理员 ：广告设置，广告一键清空，发布公告，买家、商家找回密码。
---
## 系统框架
+ 系统框架总体基于哈希表，系统开始运行时完成广告、公告的加载，建立哈希表（对于同名但不同商家的花卉采用链地址法处理冲突，对不同名花卉采用二次探测法处理冲突（查找、删除时处理冲突的方式与之相同，将花卉名称代入哈希函数返回哈希值，通过二次探测函数不断更新哈希值对哈希表进行搜索，若搜索次数超过设定的阈值，则花卉不存在或哈希函数离散程度可能有问题，此时需要重新建立哈希函数））。通过各种菜单类对象的嵌套实例化，实现多级菜单进入不同的功能模块，在各个菜单通过实例化买家、商家或管理员对象对花卉类对象进行操作（对哈希表进行操作）或对文件操作，整个系统运行过程共同维护一张哈希表，哈希表保存函数写在哈希表类的析构函数中，实现退出系统时对操作后的哈希表进行保存。
---
## 数据结构的相关内容
+ 哈希表（链地址法处理冲突与二次探测法处理冲突相结合）
  - 优点：因为花卉种类有限，所以哈希表长度不会太长（设置为500），并且所有商家的信息可以存放在一张哈希表上（同种花不同商家链地址法处理冲突，不同种花卉二次探测法处理冲突），哈希表进行查找（修改、删除）时效率高（时间复杂度为O(1)，链表和数组查找时时间复杂度为O(n)，空间复杂度为O(n)，与链表相同（同样是动态创建结点）小于数组的空间复杂度。
  - 缺点：因为所有商家花卉信息存放在一张哈希表上，商家查看自己商家花卉时需对所有花卉信息遍历去寻找自己的花卉，效率较低。
  - 综合分析：因为商家数量远远小于买家，买家对花卉频繁的查找（预约也需查找）对系统运行效率的提升将使采用哈希表的缺点被忽略。
+ 链表
  - 哈希表的链地址法处理冲突的方法用到链表，插入删除效率高。
+ 广度优先搜索BFS
  - 花店地址导航功能时，需要进行广度优先搜索求最短路径，
+ 剪枝
  - 在广度优先搜索过程中不断更新基准点，利用基准点完成剪枝，能大幅提高搜索效率（经过比较，如果商家位于左上角，在未剪枝的情况下从中心点或者从右下角开始搜索，几乎会搜索整张地图，具体搜索次数为：中心点（l，n）（292次），右下角（t，x）（295次），右上角（d，x）（213次），下方（106次）（l，d）若进行剪枝处理：中心点（l，n）（79次），右下角（t，x）（142次），右上角（d，x）（100次），下方（l，
  d）（48次））。
+ 队列
  - 广度优先搜索需要用到队列。
+ 栈
  - 回溯时用来保存最短路径（其实数组也可以实现）。
+ 分治法（归并排序）
  -  对链地址处理冲突法建立的链表进行排序。
---
## 功能模块
+ 商家模块，买家模块，管理员模块。
---
## C++类
+ 用户类：用户类派生出：商家类、买家类，管理员类继承商家和买家类，所以商家买家类继承虚基类
+ 花卉类：花卉类包含组合类花卉上架日期类
+ 菜单类：主菜单类派生出商家入驻登录菜单类、商家操作菜单类、买家注册登录菜单类、买家操作菜单类、管理员登录菜单类、管理员操作菜单类。
+ 哈希表类
+ 地图类
---
## 作业要求的实现
1. 类的组合：花卉类中包含花卉上架日期类
2. 继承、派生：（1）商家、买家类继承用户类，管理员类继承商家和买家类。（2）主菜单类派生出商家入驻登录菜单类、商家操作菜单类、买家注册登录菜单类、买家操作菜单类、管理员登录菜单类、管理员操作菜单类。
3. 虚基类：管理员类继承商家和买家类，由于存在二义性，商家和买家类要设置虚基类。
4. 运算符重载：对花卉上架日期类”<<"运算符进行重载，直接输出花卉上架日期信息。
5. STL标准模板库：用到vector、queue、stack容器。
6. 文件读写：将花卉信息和其它等等信息从文件读取到内存中，并从内存写入文件实现保存。
---
## 开发文档
+ 2019年12月10日：设计系统要实现的功能，完成功能模块图。
+ 2019年12月12日：完成花卉类和日期类的定义及成员函数的实现），实现哈希表类的建立，初步设计哈希函数。
+ 2019年12月13日：测试花卉名称通过哈希函数计算后在哈希表中的离散程度，对哈希函数进行改进。测试两种处理冲突函数，完成哈希表类，菜单类（主菜单类派生出：买家登录注册菜单类、买家操作菜单类，商家入驻登录菜单类，商家操作菜单类，管理员菜单类），用户类（买家类，商家类，管理员类）的编写，各个类的成员函数暂未实现。完成系统基本框架的设计。
+ 2019年12月14日：对菜单类部分成员函数定义进行修改，完成类的UML图。
+ 2019年12月16日：对系统框架进行微调（修改部分类的定义），完成大部分成员函数（完成哈希表类、商家类的所有成员函数的编写并进行测试，实现文件读写，完成菜单类部分派生类成员函数，完成买家类部分成员函数）。
+ 2019年12月17日：除归并排序，商家、买家找回密码，花店地址导航，和界面美化外实现其它所有功能。
+ 2019年12月18日：实现买家、商家找回密码、实现各菜单输出时的界面美化（实现功能时的界面美化暂未实现）。
+ 2019年12月20日：建立并实现Map类，实现花店地址导航功能。
+ 2019年12月21日：对花店地址导航功能进行优化，实现剪枝。实现归并排序，实现系统所有功能，完成界面美化。
+ 2019年12月22日：进一步美化系统界面，完成对系统的测试，解决出现的问题，系统开发完成。
---
## 注意事项
1. 本系统文字采用通用的UTF-8编码方式，如若运行代码，请先将txt文件和IDE的汉字编码修改为UTF-8格式。
2. 对于类Unix系统（Lunix、MacOS），只需创建工程并将cpp和hpp文件加入工程并修改Global.hpp中的FILE_ADDRESS即可运行代码。
3. 如果您的系统为Windows，您还需要对部分代码进行修改：系统包含的头文件<unistd.h>Windows系统下不可用，它类似于Windows系统下的<windows.h>，所以，您需要将#include <unistd.h>更换为#include <windows.h>，并将<unistd.h>下的函数更换为<windows.h>下的函数：休眠函数sleep( )、usleep( )更换为Sleep( )，清屏函数system("clear")更换为system("CLS")。其中sleep参数为秒，usleep参数为微秒 = 1000毫秒。
4. 除头文件<unistd.h>下的sleep( )、usleep( )、system("clear")函数外，本系统均采用标准C++库编写。
5. 本系统中名字为大写的函数或者变量均在Global.hpp全局头文件中。
