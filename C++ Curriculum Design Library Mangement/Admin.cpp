#include "Admin.h"
#include "User.h"

Admin::Admin()
{
    currentAdmin = NULL;
    
    // 加载管理员数据，如果加载失败，则创建默认管理员
    if (!Load_AdminData() || adminList.empty()) 
    {
        //建立默认管理员结构体，初始化账号和密码
        AdminInfo defaultAdmin; 
        defaultAdmin.name = "admin";
        defaultAdmin.password = "password";
        
        adminList.push_back(defaultAdmin);  // 添加默认管理员到adminList容器中
        Save_AdminData();   // 保存默认管理员数据到文件
    }
}

Admin::~Admin()
{
    Save_AdminData(); // 析构时保存数据
}

/*每次cout前用/t/t，让登录界面更加的美观*/

bool Admin::Admin_Login()
{
    string inputName, inputPassword;
    cout << "\n\t\t请输入管理员账号：";
    
    // 清除输入缓冲区
    while (cin.get() != '\n') continue;
    
    getline(cin, inputName);
    cout << "\t\t请输入管理员密码：";
    getline(cin, inputPassword);
    
    for (size_t i = 0; i < adminList.size(); i++) 
    {
        // 检查输入的账号和密码是否与管理员列表中的匹配
        if (adminList[i].name == inputName && adminList[i].password == inputPassword) 
        {
            currentAdmin = &adminList[i];   // adminList的指针指向当前登录的管理员
            cout << "\n\t\t《登录成功！》\n" << endl;
            return true;
        }
    }
    
    cout << "\n\t\t《账号或密码有误！》\n" << endl;
    return false;
}

//读文件
bool Admin::Load_AdminData()
{
    ifstream inFile("admin.dat", ios::in);  //admin.dat文件储存管理员账号和密码
    if (!inFile) 
    {
        return false;
    }
    
    adminList.clear();  
    string name, password;
    
    // 从文件中加载管理员数据
    while (getline(inFile, name)) 
    {
        if (getline(inFile, password)) 
        {
            AdminInfo admin;
            admin.name = name;
            admin.password = password;
            adminList.push_back(admin);
        }
    }
    
    inFile.close();
    return true;
}

//保存管理员数据到文件
bool Admin::Save_AdminData()
{
    ofstream outFile("admin.dat", ios::out);
    if (!outFile) 
    {
        cout << "\n\t\t无法打开文件保存管理员数据！" << endl;
        return false;
    }
    
    for (const AdminInfo& admin : adminList) 
    {
        outFile << admin.name << endl;
        outFile << admin.password << endl;
    }
    
    outFile.close();
    return true;
}

//修改密码:1.验证旧密码2.新密码两次输出一致
void Admin::Change_Password()
{
    if (!currentAdmin) 
    {
        cout << "\n\t\t《请先登录！》\n" << endl;
        return;
    }
    
    string oldPwd, newPwd, confirmPwd;
    
    cout << "\n\t\t请输入当前密码：";
    // 确保清除输入缓冲区
    if (cin.fail())
    {
        cin.clear();
        while (cin.get() != '\n') continue;
    }
    else
    {
        // 清除可能残留的换行符
        cin.ignore(10000, '\n');
    }
    
    getline(cin, oldPwd);
    
    if (oldPwd != currentAdmin->password) 
    {
        cout << "\n\t\t《密码错误！无法修改》\n" << endl;
        return;
    }
    
    cout << "\t\t请输入新密码：";
    getline(cin, newPwd);
    cout << "\t\t请再次输入新密码：";
    getline(cin, confirmPwd);
    
    if (newPwd != confirmPwd) 
    {
        cout << "\n\t\t《两次输入的密码不一致！修改失败》\n" << endl;
        return;
    }
    
    currentAdmin->password = newPwd;
    if (Save_AdminData()) 
    {
        cout << "\n\t\t《密码修改成功！》\n" << endl;
    }

    else 
    {
        cout << "\n\t\t《密码修改失败！》\n" << endl;
    }
}

//添加新的管理员
void Admin::Add_NewAdmin()
{
    if (!currentAdmin) 
    {
        cout << "\n\t\t《请先登录！》\n" << endl;
        return;
    }
    
    string verifyPwd, newName, newPwd, confirmPwd;
    
    cout << "\n\t\t请输入当前管理员密码进行验证：";
    // 确保清除输入缓冲区
    if (cin.fail())
    {
        cin.clear();
        while (cin.get() != '\n') continue;
    }
    else
    {
        // 清除可能残留的换行符
        cin.ignore(10000, '\n');
    }
    
    getline(cin, verifyPwd);
    
    if (verifyPwd != currentAdmin->password) 
    {
        cout << "\n\t\t《密码错误！无法添加新管理员》\n" << endl;
        return;
    }
    
    cout << "\t\t请输入新管理员账号：";
    getline(cin, newName);
    
    // 检查账号是否已存在
    for (const AdminInfo& admin : adminList) 
    {
        if (admin.name == newName) 
        {
            cout << "\n\t\t《该管理员账号已存在！》\n" << endl;
            return;
        }
    }
    
    cout << "\t\t请输入新管理员密码：";
    getline(cin, newPwd);
    cout << "\t\t请再次输入新管理员密码：";
    getline(cin, confirmPwd);
    
    if (newPwd != confirmPwd) 
    {
        cout << "\n\t\t《两次输入的密码不一致！添加失败》\n" << endl;
        return;
    }
    
    // 创建新的管理员对象并添加到列表中
    AdminInfo newAdmin;
    newAdmin.name = newName;
    newAdmin.password = newPwd;
    adminList.push_back(newAdmin);
    
    if (Save_AdminData()) 
    {
        cout << "\n\t\t《新管理员添加成功！》\n" << endl;
    } 
    
    else 
    {
        cout << "\n\t\t《新管理员添加失败！》\n" << endl;
    }
}

// 显示所有管理员
void Admin::Show_AllAdmins()
{
    if (!currentAdmin) 
    {
        cout << "\n\t\t【请先登录！】\n" << endl;
        return;
    }
    
    cout << "\n\t+------------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                  管理员列表                                        |" << endl;
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
    cout << "\t|  编号  |               管理员账号               |              状态               |" << endl;
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
    
    if (adminList.empty()) 
    {
        cout << "\t|                               暂无管理员                                         |" << endl;
    } 
    
    // 遍历管理员列表并显示信息
    else 
    {
        // 控制空格的数量让输出更加美观
        for (size_t i = 0; i < adminList.size(); i++) 
        {
            string status = (currentAdmin == &adminList[i]) ? "当前登录" : "未登录";
            
            cout << "\t|   " << (i + 1);
            for (size_t j = 0; j < 5 - to_string(i + 1).length(); j++) 
            {
                cout << " ";
            }
            
            cout << "|  " << adminList[i].name;
            for (size_t j = 0; j < 35 - adminList[i].name.length(); j++) 
            {
                cout << " ";
            }
            
            cout << "|  " << status;
            for (size_t j = 0; j < 31 - status.length(); j++) 
            {
                cout << " ";
            }
            
            cout << "|" << endl;
        }
    }
    
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
}

void Admin::Delete_Admin()
{
    if (!currentAdmin) 
    {
        cout << "\n\t\t【请先登录！】\n" << endl;
        return;
    }
    
    if (adminList.size() <= 1) 
    {
        cout << "\n\t\t【系统至少需要保留一个管理员账号！】\n" << endl;
        return;
    }
    
    Show_AllAdmins();
    
    string verifyPwd;
    cout << "\n\t\t请输入当前管理员密码进行验证：";
    getline(cin, verifyPwd);
    
    if (verifyPwd != currentAdmin->password) 
    {
        cout << "\n\t\t【密码错误！无法删除管理员】\n" << endl;
        return;
    }
    
    int index;
    cout << "\t\t请输入要删除的管理员编号：";
    cin >> index;
    
    // 防止无限循环的输入检查
    while (cin.fail() || index < 1 || index > (int)adminList.size())    // 错误检查
    {
        cin.clear(); // 清除错误标志
        cin.ignore(10000, '\n'); // 忽略输入缓冲区中的所有内容
        cout << "\t\t输入无效，请重新输入编号（1-" << adminList.size() << "）：";
        cin >> index;
    }
    
    index--; // 转换为数组索引
    
    // 不能删除当前登录的管理员
    if (&adminList[index] == currentAdmin) 
    {
        cout << "\n\t\t【不能删除当前登录的管理员账号！】\n" << endl;
        return;
    }
    
    // 确认删除
    char confirm;
    cout << "\t\t确认删除管理员 \"" << adminList[index].name << "\" 吗？(Y/N)：";
    cin >> confirm;
    
    if (toupper(confirm) == 'Y') 
    {
        adminList.erase(adminList.begin() + index);
        
        if (Save_AdminData()) 
        {
            cout << "\n\t\t【管理员删除成功！】\n" << endl;
        } 
        
        else 
        {
            cout << "\n\t\t【管理员删除失败！】\n" << endl;
        }
    } 
    
    else 
    {
        cout << "\n\t\t【已取消删除操作】\n" << endl;
    }
    
    // 清空输入缓冲区
    cin.ignore(10000, '\n');
}

// 删除用户功能
void Admin::Delete_User(User* userSystem)
{
    if (!currentAdmin) 
    {
        cout << "\n\t\t【请先登录！】\n" << endl;
        return;
    }
    
    // 显示所有用户
    userSystem->Show_User();
    
    // 检查是否有用户可删除
    if (!userSystem->Has_Users()) 
    {
        cout << "\n\t\t【系统中无用户可删除！】\n" << endl;
        return;
    }
    
    string verifyPwd;
    cout << "\n\t\t请输入当前管理员密码进行验证：";
    getchar(); // 清除输入缓冲区
    getline(cin, verifyPwd);
    
    if (verifyPwd != currentAdmin->password) 
    {
        cout << "\n\t\t【密码错误！无法删除用户】\n" << endl;
        return;
    }
    
    int index;
    cout << "\t\t请输入要删除的用户编号：";
    cin >> index;
    
    // 错误检查
    while (cin.fail() || index < 1)
    {
        cin.clear(); // 清除错误标志
        cin.ignore(10000, '\n'); // 忽略输入缓冲区中的所有内容
        cout << "\t\t输入无效，请重新输入编号：";
        cin >> index;
    }
    
    // 确认删除
    char confirm;
    cout << "\t\t确认删除该用户吗？(Y/N)：";
    cin >> confirm;
    
    if (toupper(confirm) == 'Y') 
    {
        if (userSystem->Delete_UserByIndex(index - 1)) 
        {
            cout << "\n\t\t【用户删除成功！】\n" << endl;
        } 
        else 
        {
            cout << "\n\t\t【用户删除失败！编号不存在或无法删除当前登录的用户】\n" << endl;
        }
    } 
    else 
    {
        cout << "\n\t\t【已取消删除操作】\n" << endl;
    }
    
    // 清空输入缓冲区
    cin.ignore(10000, '\n');
}
