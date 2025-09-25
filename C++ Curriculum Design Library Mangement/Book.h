#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstring>
#include <fstream>
#include "User.h"
using namespace std;

class Book
{
    public:
        struct Nbook            // 图书链表
        {
            string book_number; // 书编号   
            string book_name;   // 书名
            string book_author; // 作者
            string book_concern;// 出版社
            string book_surplus;// 余存
            Nbook* next;        // 指向下一个节点
        };
    
    private:
        Nbook* head;
        User* userSystem;  // 指向用户系统的指针，用于借书功能
    
    public:
        Book();
        Book(User* userSys);  // 添加构造函数，接收用户系统指针
        ~Book();
        void SetUserSystem(User* userSys)   // 设置用户系统指针
        { 
            userSystem = userSys; 
        }  
        
        void Create_Node();    // 创建空表头
        void Show_Book();      // 打印图书信息
        void Add_Book();       // 添加图书
        void Del_Book();       // 删除图书
        void Search_Book();    // 搜索图书
        bool Save_Books();     // 保存图书数据到文件
        bool Load_Books();     // 从文件加载图书数据
        
        void Borrow_Book();    // 借阅图书
        void Return_Book();    // 归还图书
        bool Check_BookAvailable(const string& bookName);  // 检查图书是否可借
        bool Update_BookQuantity(const string& bookName, int delta);  // 更新图书数量（借出/归还）
};

#endif
