#ifndef HEADER_H
#define HEADER_H
#pragma once
#include <iostream>

using namespace std;

class Movies
{
    string category;
    int year;
    string actor;
    string director;
protected:
    string title;
    int score;
public:
    Movies* next;
    string get_Title();
    void set_Title(string&title);
    string get_Category();
    void set_Category(string& category);
    int get_Year();
    void set_Year(int&year);
    string get_Actor();
    void set_Actor(string& actor);
    string get_Director();
    void set_Director(string& director);
    int get_Score();
    void set_Score(int& score);
};

class Review:public Movies
{
    string nick;
    string comment;
public:
    Review* next;
    string get_Title();
    void set_Title(string& title);
    string get_Nick();
    void set_Nick(string& nick);
    string get_Comment();
    void set_Comment(string& comment);
    int get_Score();
    void set_Score(int& score);
    void set_Pointer(Review*& pointer);

};

class List
{
public:
    void addNode(string&title, string& category, int& year, string& actor, string& director, int& score, Movies*& Head);
    void addNode_Review(string&title,string&nick,string&comment,int&score,Review*&Head_Review);
    void show_Movies(Movies*& Head);
    void show_Comments(Review*& Head_Review);
    bool check_Title(string& title,Movies*&Head);
    void edit_Information(string& title, string& category, int& year, string& actor, string& director, Movies*& Head);
    void find_Title(Movies*&Head,string&title);
    void find_Category(Movies*& Head, string& category);
    void find_Year(Movies*& Head, int& year);
    void find_Actor(Movies*& Head, string& actor);
    void find_Director(Movies*& Head, string& director);
    void find_Score(Movies*& Head, int& score);
    void add_Score(Movies*& Head, string&title ,int& score);
    void find_Review_Title(Review*& Head_Review, string& title);
    void find_Review_Nick(Review*& Head_Review,string&nick);
    void delete_Comment(Review*&Head_Review);
};

class File
{
public:
    static void load_information(string&file,Movies*&Head,List*&list);
    static void save_information(string&file,Movies*&Head);
    static void load_reviews(string& file, Review*& Head_Review, List*& List);
    static void save_Reviews(string& file, Review*& Head_Review);
};

class Menu
{
public:
     static void help();
     static void change(string& word);
     static void add_Movie(Movies*&Head, List*& list);
     static void edit_Movie(Movies*& Head, List*& list);
     static void find_By(Movies*& Head, List*& list);
     static void add_Review(Movies*&Head,Review*& Head_Review, List*& list,string&nick);
     static void show_Reviews(Review*& Head_Review,List*&list);
     static void find_Reviews_Title(Movies*& Head,Review*& Head_Review, List*& list);
     static void add_Score(Movies*& Head,List*& list);
     static void find_Review_Nick(Review*& Head_Review, List*& list);
};

class Account
{
protected:
    string nick;
public:
    Account(string nick);
    virtual string get_Nick()=0;
    void log_in(string& nick, Account*& wsk);
    virtual void Menu(Movies*& Head, Review*& Head_Review, List*& list, string& file, string& file2)=0;
};

class User :public Account
{
public:
    User(string nick): Account(nick) {};
    string get_Nick();
    void Menu(Movies*& Head, Review*& Head_Review, List*& list,string&file,string&file2);
};

class Admin :public Account
{
    string password;
public:
    Admin(string nick,string password): Account(nick) {};
    string get_Nick();
    string get_Password();
    void Menu(Movies*& Head, Review*& Head_Review, List*& list, string& file, string& file2);
};

#endif