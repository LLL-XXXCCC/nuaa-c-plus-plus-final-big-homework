#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

Book::Book()
{
    head = NULL;
    userSystem = NULL;
    Create_Node();
    Load_Books(); // 初始化时加载图书数据
}

Book::Book(User* userSys)
{
    head = NULL;
    userSystem = userSys;
    Create_Node();
    Load_Books(); // 初始化时加载图书数据
}

Book::~Book()
{
    Save_Books(); // 析构时保存数据
    
    // 释放链表内存
    Nbook* current = head;
    while (current != NULL) 
    {
        Nbook* temp = current;
        current = current->next;
        delete temp;
    }
}

// 创建链表头节点
void Book::Create_Node()
{
    if (head == NULL) 
    {
        head = new Nbook;
        head->next = NULL;
    }
}

// 用链表知识遍历链表并且格式化输出
void Book::Show_Book()
{
    cout << "\n\t+-----------------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                    图书信息列表                                         |" << endl;
    cout << "\t+-----------------------------------------------------------------------------------------+" << endl;
    cout << "\t|    编号    |       书名       |       作者       |      出版社      |      余存        |" << endl;
    cout << "\t+-----------------------------------------------------------------------------------------+" << endl;
    if (head->next == NULL)
    {
        cout << "\t|                               暂无书籍信息                                            |" << endl;
    }

    else
    {
        Nbook* pshow = head;
        while (pshow->next != NULL)
        {
            pshow = pshow->next;
            
            cout << "\t|    " << pshow->book_number;
            for (size_t i = 0; i < 9 - pshow->book_number.length(); i++) 
            {
                cout << " ";
            }
            
            cout << "|  " << pshow->book_name;
            for (size_t i = 0; i < 17 - pshow->book_name.length(); i++) 
            {
                cout << " ";
            }
            
            cout << "|  " << pshow->book_author;
            for (size_t i = 0; i < 17 - pshow->book_author.length(); i++) 
            {
                cout << " ";
            }
            
            cout << "|  " << pshow->book_concern;
            for (size_t i = 0; i < 17 - pshow->book_concern.length(); i++) 
            {
                cout << " ";
            }
            
            cout << "|  " << pshow->book_surplus;
            for (size_t i = 0; i < 16 - pshow->book_surplus.length(); i++) 
            {
                cout << " ";
            }
            
            cout << "|" << endl;
        }
    }
    cout << "\t+-----------------------------------------------------------------------------------------+" << endl;
}

// 插入链表节点，即添加图书
void Book::Add_Book()
{
    Nbook* Insert = head;
    while (Insert->next != NULL)
    {
        Insert = Insert->next;
    }

    Nbook* pnew = new Nbook;
    pnew->next = NULL;
    getchar();
    cout << "\n\t\t请录入书编号：";

    getline(cin, pnew->book_number);
    cout << "\t\t请录入书名：";

    getline(cin, pnew->book_name);
    cout << "\t\t请录入作者名：";

    getline(cin, pnew->book_author);
    cout << "\t\t请录入出版社：";

    getline(cin, pnew->book_concern);
    cout << "\t\t请录入册量：";

    getline(cin, pnew->book_surplus);
    Insert->next = pnew;
    cout << "\n\t\t【录入成功，更新一条信息！】\n" << endl;
    
    // 添加后立即保存到文件
    Save_Books();
}

// 删除链表节点，即删除图书
void Book::Del_Book()
{
    getchar();
    string s;
    cout << "\n\t\t请输入要删除的书名：";
    getline(cin, s);
    Nbook* pdel = head;
    while ((pdel->next != NULL) && (pdel->next->book_name != s))
    {
        pdel = pdel->next;
    }

    if (pdel->next != NULL)
    {
        Nbook* pnew = pdel->next->next;
        delete pdel->next;
        pdel->next = pnew;
        cout << "\n\t\t【删除完成！】\n" << endl;
        
        // 删除后立即保存到文件
        Save_Books();
    }
	
    else
    {
        cout << "\n\t\t【无此书！】\n" << endl;
    }
}  

// 遍历查找链表，即搜索图书
void Book::Search_Book()
{
    getchar();
    string s;
    cout << "\n\t\t请输入要搜索的图书名：";
    getline(cin, s);
    
    cout << "\n\t+-----------------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                    搜索结果                                             |" << endl;
    cout << "\t+-----------------------------------------------------------------------------------------+" << endl;
    cout << "\t|    编号    |       书名       |       作者       |      出版社      |      余存        |" << endl;
    cout << "\t+-----------------------------------------------------------------------------------------+" << endl;
    
    Nbook* pserch = head;
    bool found = false;
    
    while (pserch->next != NULL)
    {
        pserch = pserch->next;
        // 改为部分匹配而不是完全匹配
        if (pserch->book_name.find(s) != string::npos)
        {
            found = true;
            cout << "\t|    " << pserch->book_number;
            for (size_t i = 0; i < 9 - pserch->book_number.length(); i++) 
            {
                cout << " ";
            }
            
            cout << "|  " << pserch->book_name;
            for (size_t i = 0; i < 17 - pserch->book_name.length(); i++) 
            {
                cout << " ";
            }
            
            cout << "|  " << pserch->book_author;
            for (size_t i = 0; i < 17 - pserch->book_author.length(); i++) 
            {
                cout << " ";
            }
            
            cout << "|  " << pserch->book_concern;
            for (size_t i = 0; i < 17 - pserch->book_concern.length(); i++)
            {
                cout << " ";
            }
            
            cout << "|  " << pserch->book_surplus;
            for (size_t i = 0; i < 16 - pserch->book_surplus.length(); i++) 
            {
                cout << " ";
            }
            
            cout << "|" << endl;
        }
    }

    if (!found)
    {
        cout << "\t|                               没有找到此书！                                          |" << endl;
    }
    
    cout << "\t+-----------------------------------------------------------------------------------------+" << endl;
}

// 借阅功能：遍历链表查找图书、检查余额、更新余额、更新用户借阅信息
void Book::Borrow_Book()
{
    if (!userSystem || !userSystem->Is_UserLoggedIn())
    {
        cout << "\n\t\t【请先登录！】\n" << endl;
        return;
    }
    
    if (!userSystem->Can_BorrowBook())
    {
        cout << "\n\t\t【您已达到借阅上限，无法继续借阅！】" << endl;
        cout << "\t\t【普通用户只能借阅1本书，可以升级为高级用户获得无限借阅权限】\n" << endl;
        return;
    }
    
    getchar();
    string bookName;
    cout << "\n\t\t请输入要借阅的图书名：";
    getline(cin, bookName);
    
    // 查找图书
    Nbook* pbook = head;
    while (pbook->next != NULL)
    {
        pbook = pbook->next;
        if (pbook->book_name == bookName)
        {
            // 检查余额
            int surplus = stoi(pbook->book_surplus);    //stoi函数：将字符串转换为整数
            if (surplus <= 0)
            {
                cout << "\n\t\t【此书已无余额，无法借阅！】\n" << endl;
                return;
            }
            
            // 更新余额
            surplus--;
            pbook->book_surplus = to_string(surplus);
            
            // 更新用户借阅信息
            userSystem->Borrow_Book(pbook->book_name, pbook->book_number);
            
            // 保存图书数据
            Save_Books();
            
            return;
        }
    }
    
    cout << "\n\t\t【没有找到此书！】\n" << endl;
}

// 归还功能：遍历链表查找图书、检查余额、更新余额、更新用户借阅信息
void Book::Return_Book()
{
    if (!userSystem || !userSystem->Is_UserLoggedIn())
    {
        cout << "\n\t\t【请先登录！】\n" << endl;
        return;
    }
    
    // 显示用户已借阅的图书
    userSystem->Show_BorrowedBooks();
    
    if (userSystem->Get_CurrentUser()->borrowedBooks.empty())
    {
        cout << "\n\t\t【您没有借阅任何图书！】\n" << endl;
        return;
    }
    
    getchar();
    string bookName;
    cout << "\n\t\t请输入要归还的图书名：";
    getline(cin, bookName);
    
    // 查找图书
    Nbook* pbook = head;
    bool bookFound = false;
    
    while (pbook->next != NULL)
    {
        pbook = pbook->next;
        if (pbook->book_name == bookName)
        {
            bookFound = true;
            break;
        }
    }
    
    if (!bookFound)
    {
        cout << "\n\t\t【图书馆中没有此书记录，无法归还！】\n" << endl;
        return;
    }
    
    // 确认用户是否借阅了此书
    bool borrowed = false;
    for (const string& book : userSystem->Get_CurrentUser()->borrowedBooks)
    {
        if (book.find(bookName) != string::npos)
        {
            borrowed = true;
            break;
        }
    }
    
    if (!borrowed)
    {
        cout << "\n\t\t【您没有借阅此书！】\n" << endl;
        return;
    }
    
    // 更新余额
    int surplus = stoi(pbook->book_surplus);
    surplus++;
    pbook->book_surplus = to_string(surplus);
    
    // 更新用户借阅信息
    userSystem->Return_Book(bookName);
    
    // 保存图书数据
    Save_Books();
    
    cout << "\n\t\t成功归还" << pbook->book_name << "！\n" << endl;
}

// 检查图书是否可借
bool Book::Check_BookAvailable(const string& bookName)
{
    Nbook* pbook = head;
    while (pbook->next != NULL)
    {
        pbook = pbook->next;
        if (pbook->book_name == bookName)
        {
            int surplus = stoi(pbook->book_surplus);
            return surplus > 0;
        }
    }
    return false;
}

// 更新图书数量（归还）
bool Book::Update_BookQuantity(const string& bookName, int delta)
{
    Nbook* pbook = head;
    while (pbook->next != NULL)
    {
        pbook = pbook->next;
        if (pbook->book_name == bookName)
        {
            int surplus = stoi(pbook->book_surplus);
            surplus += delta;
            if (surplus < 0) 
            {
                surplus = 0;
            }

            pbook->book_surplus = to_string(surplus);
            Save_Books();
            return true;
        }
    }
    return false;
}

// 保存图书数据到文件(读)
bool Book::Save_Books() 
{
    ofstream outFile("books.dat", ios::out);
    if (!outFile) 
    {
        cout << "\n\t\t无法打开文件保存图书数据！" << endl;
        return false;
    }
    
    Nbook* current = head->next;
    while (current != NULL) 
    {
        outFile << current->book_number << endl;
        outFile << current->book_name << endl;
        outFile << current->book_author << endl;
        outFile << current->book_concern << endl;
        outFile << current->book_surplus << endl;
        current = current->next;
    }
    
    outFile.close();
    return true;
}

// 从文件加载图书数据（写）
bool Book::Load_Books() 
{
    ifstream inFile("books.dat");
    if (!inFile) 
    {
        // 如果文件不存在，返回false，但不报错
        return false;
    }
    
    // 清空现有链表
    while (head->next != NULL) 
    {
        Nbook* temp = head->next;
        head->next = temp->next;
        delete temp;
    }
    
    // 读取文件并构建链表
    string number, name, author, concern, surplus;
    Nbook* last = head;
    
    while (getline(inFile, number)) 
    {
        getline(inFile, name);
        getline(inFile, author);
        getline(inFile, concern);
        getline(inFile, surplus);
        
        Nbook* newNode = new Nbook;
        newNode->book_number = number;
        newNode->book_name = name;
        newNode->book_author = author;
        newNode->book_concern = concern;
        newNode->book_surplus = surplus;
        newNode->next = NULL;
        
        last->next = newNode;
        last = newNode;
    }
    
    inFile.close();
    return true;
}
