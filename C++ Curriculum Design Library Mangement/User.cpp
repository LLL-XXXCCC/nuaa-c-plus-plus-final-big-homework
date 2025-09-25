#include "User.h"

User::User()
{
    head = NULL;
    currentUser = NULL;
    Create_Node();
    Load_Users(); // 初始化时加载用户数据
}

User::~User()
{
    Save_Users(); // 析构时保存数据
    
    // 释放链表内存
    Nuser* current = head;
    while (current != NULL) 
    {
        Nuser* temp = current;
        current = current->next;
        delete temp;
    }
}

// 创建用户链表头节点
void User::Create_Node()
{
    if (head == NULL) 
    {
        head = new Nuser;
        head->next = NULL;
    }
}

// 用链表知识遍历链表并且格式化输出
void User::Show_User()
{
    cout << "\n\t+------------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                  用户信息列表                                      |" << endl;
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
    cout << "\t|  用户名        |  性别  |  年龄  |        电话        |  用户类型  |  借阅数量    |" << endl;
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
    
    if (head->next == NULL)
    {
        cout << "\t|                            暂无用户信息                                        |" << endl;
    }

    else
    {
        Nuser* pshow = head;
        while (pshow->next != NULL)
        {
            pshow = pshow->next;
            string userType = pshow->isPremium ? "高级用户" : "普通用户";
            cout << "\t|  " << pshow->name;
            // 填充空格使表格对齐
            for (size_t i = 0; i < 14 - pshow->name.length(); i++) 
            {
                cout << " ";
            }
            cout << "|  " << pshow->sex;

            for (size_t i = 0; i < 6 - pshow->sex.length(); i++) 
            {
                cout << " ";
            }
            cout << "|  " << pshow->old;

            for (size_t i = 0; i < 6 - pshow->old.length(); i++) 
            {
                cout << " ";
            }
            cout << "|  " << pshow->tel;

            for (size_t i = 0; i < 18 - pshow->tel.length(); i++) 
            {
                cout << " ";
            }
            cout << "|  " << userType;

            for (size_t i = 0; i < 10 - userType.length(); i++) 
            {
                cout << " ";
            }
            cout << "|  " << pshow->borrowedBooks.size() << "           |" << endl;
        }
    }
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
}

// 插入节点即增加新的用户
void User::Add_User()
{
    Nuser* insert = head;
    while (insert->next != NULL)
    {
        insert = insert->next;
    }
    Nuser* pnew = new Nuser;
    pnew->next = NULL;
    pnew->isPremium = false;
    pnew->balance = 0.0;
    
    cout << "\n\t\t请输入用户姓名：";
    getchar();
    // 使用getline允许输入空格
    getline(cin, pnew->name);
    cout << "\t\t请输入性别：";

    getline(cin, pnew->sex);
    cout << "\t\t请输入年龄：";

    getline(cin, pnew->old);
    cout << "\t\t请输入电话：";

    getline(cin, pnew->tel);
    cout << "\t\t请输入密码：";

    getline(cin, pnew->pwd);
    
    insert->next = pnew;
    cout << "\n\t\t【恭喜您！注册成功】\n" << endl;
    
    // 添加用户后立即保存到文件
    Save_Users();
}

// 判断用户登录密码是否正确
bool User::User_login()
{
    getchar();
    string s1, s2;
    cout << "\n\t\t用户名：";
    getline(cin, s1);
    cout << "\t\t密码：";
    getline(cin, s2);
    
    Nuser* pserch = head;
    while (pserch->next != NULL && pserch->next->name != s1)
    {
        pserch = pserch->next;
    }

    if (pserch->next == NULL)
    {
        cout << "\n\t\t【用户名不存在！】\n" << endl;
        return false;
    }

    if ((pserch->next != NULL) && (s2 == pserch->next->pwd))
    {
        currentUser = pserch->next;
        cout << "\n\t\t【登录成功！】\n" << endl;
        return true;
    }

    else
    {
        cout << "\n\t\t【登录失败！】\n" << endl;
        return false;
    }
}

// 保存用户数据到文件（读）
bool User::Save_Users() 
{
    ofstream outFile("users.dat", ios::out);
    if (!outFile) 
    {
        cout << "\n\t\t无法打开文件保存用户数据！" << endl;
        return false;
    }
    
    Nuser* current = head->next;
    while (current != NULL) 
    {
        outFile << current->name << endl;
        outFile << current->sex << endl;
        outFile << current->old << endl;
        outFile << current->tel << endl;
        outFile << current->pwd << endl;
        outFile << (current->isPremium ? "1" : "0") << endl;  // 保存用户类型
        outFile << current->balance << endl;                   // 保存余额
        outFile << current->borrowedBooks.size() << endl;      // 保存借阅书籍数量
        
        // 保存借阅书籍
        for (const string& book : current->borrowedBooks)   //这句话是遍历借阅书籍并写到文件中
        {
            outFile << book << endl;
        }
        
        current = current->next;
    }
    
    outFile.close();
    return true;
}

// 从文件加载用户数据（写）
bool User::Load_Users() 
{
    ifstream inFile("users.dat", ios::in);
    if (!inFile) 
    {
        // 如果文件不存在，返回false，但不报错
        return false;
    }
    
    // 清空现有链表
    while (head->next != NULL) 
    {
        Nuser* temp = head->next;
        head->next = temp->next;
        delete temp;
    }
    
    // 读取文件并构建链表
    string name, sex, old, tel, pwd, isPremium, balance;
    string bookCount;
    Nuser* last = head;
    
    while (getline(inFile, name)) 
    {
        getline(inFile, sex);
        getline(inFile, old);
        getline(inFile, tel);
        getline(inFile, pwd);
        getline(inFile, isPremium);
        getline(inFile, balance);
        getline(inFile, bookCount);
        
        Nuser* newNode = new Nuser;
        newNode->name = name;
        newNode->sex = sex;
        newNode->old = old;
        newNode->tel = tel;
        newNode->pwd = pwd;
        newNode->isPremium = (isPremium == "1");
        newNode->balance = stod(balance);
        newNode->next = NULL;
        
        // 读取借阅书籍
        int count = stoi(bookCount);
        for (int i = 0; i < count; i++)
        {
            string book;
            getline(inFile, book);
            newNode->borrowedBooks.push_back(book);
        }
        
        last->next = newNode;
        last = newNode;
    }
    
    inFile.close();
    return true;
}

// 判断普通或高级用户是否能借阅图书
void User::Borrow_Book(string bookName, string bookNumber)
{
    if (!currentUser)
    {
        cout << "\n\t\t【请先登录！】\n" << endl;
        return;
    }
    
    // 检查是否可以借阅
    if (!Can_BorrowBook())
    {
        if (!currentUser->isPremium)
        {
            cout << "\n\t\t【普通用户只能借阅1本书，您已达到上限！】" << endl;
            cout << "\t\t【可以升级为高级用户获得无限借阅权限】\n" << endl;
        }
        return;
    }
    
    // 添加到借阅列表
    currentUser->borrowedBooks.push_back(bookName + " (" + bookNumber + ")");
    
    cout << "\n\t\t【成功借阅"" << bookName << ""！】\n" << endl;
    
    // 保存用户数据
    Save_Users();
}

// 判断用户是否可以还书 
void User::Return_Book(string bookName)
{
    if (!currentUser)
    {
        cout << "\n\t\t【请先登录！】\n" << endl;
        return;
    }
    
    bool found = false;
    for (auto it = currentUser->borrowedBooks.begin(); it != currentUser->borrowedBooks.end(); it++)
    {
        if (it->find(bookName) != string::npos)
        {
            currentUser->borrowedBooks.erase(it);
            found = true;
            break;
        }
    }
    
    if (found)
    {
        cout << "\n\t\t【成功归还"" << bookName << ""！】\n" << endl;
        Save_Users();
    }
	
    else
    {
        cout << "\n\t\t【您未借阅"" << bookName << ""！】\n" << endl;
    }
}

// 充值
void User::TopUp_Account()
{
    if (!currentUser)
    {
        cout << "\n\t\t【请先登录！】\n" << endl;
        return;
    }
    
    double amount;
    cout << "\n\t\t当前余额：" << currentUser->balance << " 元" << endl;
    cout << "\t\t请输入充值金额：";
    cin >> amount;
    
    if (amount <= 0)
    {
        cout << "\n\t\t【充值金额必须大于0！】\n" << endl;
        return;
    }
    
    currentUser->balance += amount;
    Save_Users();
    
    cout << "\n\t\t【充值成功！当前余额：" << currentUser->balance << " 元】\n" << endl;
}

// 升级为高级用户
void User::Upgrade_ToPremium()
{
    if (!currentUser)
    {
        cout << "\n\t\t【请先登录！】\n" << endl;
        return;
    }
    
    if (currentUser->isPremium)
    {
        cout << "\n\t\t【您已经是高级用户！】\n" << endl;
        return;
    }
    
    const double premiumFee = 50.0;
    
    cout << "\n\t\t升级为高级用户需要支付 " << premiumFee << " 元" << endl;
    cout << "\t\t当前余额：" << currentUser->balance << " 元" << endl;
    
    if (currentUser->balance < premiumFee)
    {
        cout << "\n\t\t【余额不足，请先充值！】\n" << endl;
        return;
    }
    
    char choice;
    cout << "\t\t确认升级为高级用户吗？(Y/N)：";
    cin >> choice;
    
    if (toupper(choice) == 'Y')
    {
        currentUser->balance -= premiumFee;
        currentUser->isPremium = true;
        Save_Users();
        
        cout << "\n\t\t【恭喜，升级成功！您现在是高级用户】" << endl;
        cout << "\t\t【高级用户可以无限借阅图书】\n" << endl;
    }

    else
    {
        cout << "\n\t\t【已取消升级】\n" << endl;
    }
}

// 显示当前用户信息
void User::Show_CurrentUserInfo()
{
    if (!currentUser)
    {
        cout << "\n\t\t【请先登录！】\n" << endl;
        return;
    }
    
    cout << "\n\t+------------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                  用户个人信息                                      |" << endl;
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
    cout << "\t| 用户名：" << currentUser->name;

	// 填充空格使表格对齐
    for (size_t i = 0; i < 73 - currentUser->name.length(); i++) 
	{
		cout << " ";
	}
    cout << "|" << endl;
    cout << "\t| 性别：" << currentUser->sex;

	// 填充空格使表格对齐
    for (size_t i = 0; i < 75 - currentUser->sex.length(); i++) 
	{
		cout << " ";
	}
    cout << "|" << endl;
    cout << "\t| 年龄：" << currentUser->old;

	// 填充空格使表格对齐
    for (size_t i = 0; i < 75 - currentUser->old.length(); i++) 
	{
		cout << " ";
	}
    cout << "|" << endl;
    cout << "\t| 电话：" << currentUser->tel;

	// 填充空格使表格对齐
    for (size_t i = 0; i < 75 - currentUser->tel.length(); i++) 
	{
		cout << " ";
	}
    cout << "|" << endl;
    
    string userType = currentUser->isPremium ? "高级用户" : "普通用户";
    cout << "\t| 用户类型：" << userType;
    for (size_t i = 0; i < 71 - userType.length(); i++) 
	{
		cout << " ";
	}
    cout << "|" << endl;
    cout << "\t| 账户余额：" << currentUser->balance << " 元";

    string balanceStr = to_string(currentUser->balance);
    for (size_t i = 0; i < 69 - balanceStr.length(); i++) 
	{
		cout << " ";
	}
    cout << "|" << endl;
    cout << "\t| 已借阅书籍数量：" << currentUser->borrowedBooks.size();

    string bookCountStr = to_string(currentUser->borrowedBooks.size());
    for (size_t i = 0; i < 65 - bookCountStr.length(); i++) 
	{
		cout << " ";
	}
    cout << "|" << endl;
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
}

// 显示已借阅图书
void User::Show_BorrowedBooks()
{
    if (!currentUser)
    {
        cout << "\n\t\t【请先登录！】\n" << endl;
        return;
    }
    
    cout << "\n\t+------------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                已借阅图书列表                                      |" << endl;
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
    
    if (currentUser->borrowedBooks.empty())
    {
        cout << "\t|                                 暂无借阅图书                                     |" << endl;
    }
	
    else
    {
        for (size_t i = 0; i < currentUser->borrowedBooks.size(); i++)
        {
            cout << "\t| " << (i + 1) << ". " << currentUser->borrowedBooks[i];
            for (size_t j = 0; j < 80 - currentUser->borrowedBooks[i].length() - 3 - to_string(i + 1).length(); j++)
            {
                cout << " ";
            }
                
            cout << "|" << endl;
        }
    }
    
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
}

//用已借阅书籍的数量来判断用户是否可以借书
bool User::Can_BorrowBook()
{
    if (!currentUser)
        return false;
    
    // 高级用户可以无限借阅
    if (currentUser->isPremium)
        return true;
    
    // 普通用户只能借阅1本
    return currentUser->borrowedBooks.size() < 1;
}

// 按索引删除用户
bool User::Delete_UserByIndex(int index)
{
    if (index < 0 || head == NULL || head->next == NULL)
        return false;
    
    Nuser* current = head;
    int currentIndex = 0;
    
    // 找到要删除的节点的前一个节点
    while (current->next != NULL && currentIndex < index)
    {
        current = current->next;
        currentIndex++;
    }
    
    // 如果找不到索引或者下一个节点为空，返回失败
    if (current->next == NULL || currentIndex != index)
        return false;
    
    // 检查是否要删除当前登录的用户
    if (current->next == currentUser)
        return false;
    
    // 删除节点
    Nuser* toDelete = current->next;
    current->next = toDelete->next;
    
    delete toDelete;
    
    // 保存更新后的用户数据
    Save_Users();
    
    return true;
}
