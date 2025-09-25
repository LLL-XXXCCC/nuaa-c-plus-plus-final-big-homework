/*
巧妙之处：用户和书籍的存储都采用链表的形式
*/

#ifndef USER_H
#define USER_H

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class User
{
    public:
        struct Nuser
        {
            string name;
            string sex;
            string old;
            string tel;
            string pwd;
            bool isPremium;       // 是否为高级用户
            double balance;       // 账户余额
            vector<string> borrowedBooks; // 借阅的图书列表
            
            Nuser* next;
        };

    private:
        Nuser* head;
        Nuser* currentUser;   // 当前登录的用户

    public:
        User();
        ~User();
        void Create_Node();    // 创建user头
        void Show_User();      // 打印用户列表
        void Add_User();       // 注册用户
        bool User_login();     // 判断密码
        bool Save_Users();     // 保存用户数据到文件
        bool Load_Users();     // 从文件加载用户数据
        
        void Borrow_Book(string bookName, string bookNumber);  // 借阅图书
        void Return_Book(string bookName);                     // 归还图书
        void TopUp_Account();                                  // 充值账户
        void Upgrade_ToPremium();                              // 升级为高级用户
        void Show_CurrentUserInfo();                           // 显示当前用户信息
        void Show_BorrowedBooks();                             // 显示已借阅图书
        bool Can_BorrowBook();                                 // 判断用户是否能借书
        bool Has_Users()                                       // 判断是否有用户
        {
            return head != NULL && head->next != NULL;
        }

        bool Delete_UserByIndex(int index);                    // 按索引删除用户
        Nuser* Get_CurrentUser() 
        { 
            return currentUser; 
        }
        // 获取当前用户

        bool Is_UserLoggedIn() 
        { 
            return currentUser != NULL; 
        } // 判断是否有用户登录
};

#endif
