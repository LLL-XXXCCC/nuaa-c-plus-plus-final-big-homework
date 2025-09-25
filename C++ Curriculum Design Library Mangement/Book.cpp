#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

Book::Book()
{
    head = NULL;
    userSystem = NULL;
    Create_Node();
    Load_Books(); // ��ʼ��ʱ����ͼ������
}

Book::Book(User* userSys)
{
    head = NULL;
    userSystem = userSys;
    Create_Node();
    Load_Books(); // ��ʼ��ʱ����ͼ������
}

Book::~Book()
{
    Save_Books(); // ����ʱ��������
    
    // �ͷ������ڴ�
    Nbook* current = head;
    while (current != NULL) 
    {
        Nbook* temp = current;
        current = current->next;
        delete temp;
    }
}

// ��������ͷ�ڵ�
void Book::Create_Node()
{
    if (head == NULL) 
    {
        head = new Nbook;
        head->next = NULL;
    }
}

// ������֪ʶ���������Ҹ�ʽ�����
void Book::Show_Book()
{
    cout << "\n\t+-----------------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                    ͼ����Ϣ�б�                                         |" << endl;
    cout << "\t+-----------------------------------------------------------------------------------------+" << endl;
    cout << "\t|    ���    |       ����       |       ����       |      ������      |      ���        |" << endl;
    cout << "\t+-----------------------------------------------------------------------------------------+" << endl;
    if (head->next == NULL)
    {
        cout << "\t|                               �����鼮��Ϣ                                            |" << endl;
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

// ��������ڵ㣬�����ͼ��
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
    cout << "\n\t\t��¼�����ţ�";

    getline(cin, pnew->book_number);
    cout << "\t\t��¼��������";

    getline(cin, pnew->book_name);
    cout << "\t\t��¼����������";

    getline(cin, pnew->book_author);
    cout << "\t\t��¼������磺";

    getline(cin, pnew->book_concern);
    cout << "\t\t��¼�������";

    getline(cin, pnew->book_surplus);
    Insert->next = pnew;
    cout << "\n\t\t��¼��ɹ�������һ����Ϣ����\n" << endl;
    
    // ��Ӻ��������浽�ļ�
    Save_Books();
}

// ɾ������ڵ㣬��ɾ��ͼ��
void Book::Del_Book()
{
    getchar();
    string s;
    cout << "\n\t\t������Ҫɾ����������";
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
        cout << "\n\t\t��ɾ����ɣ���\n" << endl;
        
        // ɾ�����������浽�ļ�
        Save_Books();
    }
	
    else
    {
        cout << "\n\t\t���޴��飡��\n" << endl;
    }
}  

// ������������������ͼ��
void Book::Search_Book()
{
    getchar();
    string s;
    cout << "\n\t\t������Ҫ������ͼ������";
    getline(cin, s);
    
    cout << "\n\t+-----------------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                    �������                                             |" << endl;
    cout << "\t+-----------------------------------------------------------------------------------------+" << endl;
    cout << "\t|    ���    |       ����       |       ����       |      ������      |      ���        |" << endl;
    cout << "\t+-----------------------------------------------------------------------------------------+" << endl;
    
    Nbook* pserch = head;
    bool found = false;
    
    while (pserch->next != NULL)
    {
        pserch = pserch->next;
        // ��Ϊ����ƥ���������ȫƥ��
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
        cout << "\t|                               û���ҵ����飡                                          |" << endl;
    }
    
    cout << "\t+-----------------------------------------------------------------------------------------+" << endl;
}

// ���Ĺ��ܣ������������ͼ�顢����������������û�������Ϣ
void Book::Borrow_Book()
{
    if (!userSystem || !userSystem->Is_UserLoggedIn())
    {
        cout << "\n\t\t�����ȵ�¼����\n" << endl;
        return;
    }
    
    if (!userSystem->Can_BorrowBook())
    {
        cout << "\n\t\t�����Ѵﵽ�������ޣ��޷��������ģ���" << endl;
        cout << "\t\t����ͨ�û�ֻ�ܽ���1���飬��������Ϊ�߼��û�������޽���Ȩ�ޡ�\n" << endl;
        return;
    }
    
    getchar();
    string bookName;
    cout << "\n\t\t������Ҫ���ĵ�ͼ������";
    getline(cin, bookName);
    
    // ����ͼ��
    Nbook* pbook = head;
    while (pbook->next != NULL)
    {
        pbook = pbook->next;
        if (pbook->book_name == bookName)
        {
            // ������
            int surplus = stoi(pbook->book_surplus);    //stoi���������ַ���ת��Ϊ����
            if (surplus <= 0)
            {
                cout << "\n\t\t�������������޷����ģ���\n" << endl;
                return;
            }
            
            // �������
            surplus--;
            pbook->book_surplus = to_string(surplus);
            
            // �����û�������Ϣ
            userSystem->Borrow_Book(pbook->book_name, pbook->book_number);
            
            // ����ͼ������
            Save_Books();
            
            return;
        }
    }
    
    cout << "\n\t\t��û���ҵ����飡��\n" << endl;
}

// �黹���ܣ������������ͼ�顢����������������û�������Ϣ
void Book::Return_Book()
{
    if (!userSystem || !userSystem->Is_UserLoggedIn())
    {
        cout << "\n\t\t�����ȵ�¼����\n" << endl;
        return;
    }
    
    // ��ʾ�û��ѽ��ĵ�ͼ��
    userSystem->Show_BorrowedBooks();
    
    if (userSystem->Get_CurrentUser()->borrowedBooks.empty())
    {
        cout << "\n\t\t����û�н����κ�ͼ�飡��\n" << endl;
        return;
    }
    
    getchar();
    string bookName;
    cout << "\n\t\t������Ҫ�黹��ͼ������";
    getline(cin, bookName);
    
    // ����ͼ��
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
        cout << "\n\t\t��ͼ�����û�д����¼���޷��黹����\n" << endl;
        return;
    }
    
    // ȷ���û��Ƿ�����˴���
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
        cout << "\n\t\t����û�н��Ĵ��飡��\n" << endl;
        return;
    }
    
    // �������
    int surplus = stoi(pbook->book_surplus);
    surplus++;
    pbook->book_surplus = to_string(surplus);
    
    // �����û�������Ϣ
    userSystem->Return_Book(bookName);
    
    // ����ͼ������
    Save_Books();
    
    cout << "\n\t\t�ɹ��黹" << pbook->book_name << "��\n" << endl;
}

// ���ͼ���Ƿ�ɽ�
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

// ����ͼ���������黹��
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

// ����ͼ�����ݵ��ļ�(��)
bool Book::Save_Books() 
{
    ofstream outFile("books.dat", ios::out);
    if (!outFile) 
    {
        cout << "\n\t\t�޷����ļ�����ͼ�����ݣ�" << endl;
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

// ���ļ�����ͼ�����ݣ�д��
bool Book::Load_Books() 
{
    ifstream inFile("books.dat");
    if (!inFile) 
    {
        // ����ļ������ڣ�����false����������
        return false;
    }
    
    // �����������
    while (head->next != NULL) 
    {
        Nbook* temp = head->next;
        head->next = temp->next;
        delete temp;
    }
    
    // ��ȡ�ļ�����������
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
