#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// 前向声明 User 类
class User;

class Admin
{
    private:
        struct AdminInfo    
        {
            string name;    // 管理员账号
            string password;    // 管理员密码
        };
        
        vector<AdminInfo> adminList;  // 在adminList容器中存储多个管理员账号
        AdminInfo* currentAdmin;      // AdminInfo指针，指向当前登录的管理员账号
    
    public:
        Admin();
        ~Admin();
        bool Admin_Login();                 // 管理员登录
        bool Load_AdminData();              // 从文件加载管理员数据
        bool Save_AdminData();              // 保存管理员数据到文件
        void Change_Password();             // 修改管理员密码
        void Add_NewAdmin();                // 添加新管理员
        void Show_AllAdmins();              // 显示所有管理员
        void Delete_Admin();                // 删除管理员
        void Delete_User(User* userSystem); // 删除用户
        bool Is_AdminLoggedIn()             // 检查是否有管理员登录
        {
            return currentAdmin != NULL; 
        } 
};

#endif
