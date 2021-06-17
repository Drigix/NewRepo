#include "Header.h"
#include <iostream>
#include <fstream>
#include<string>
#include<algorithm>
using namespace std;


void Movies::set_Title(string& title) { this->title = title; }

string Movies::get_Title() { return title; }

void Movies::set_Category(string& category) { this->category = category; }

string Movies::get_Category() { return category; }

void Movies::set_Year(int& year) { this->year = year; }

int Movies::get_Year() { return year; };

void Movies::set_Actor(string& actor) { this->actor = actor; }

string Movies::get_Actor() { return actor; };

void Movies::set_Director(string& director) { this->director = director; }

string Movies::get_Director() { return director; };

void Movies::set_Score(int& score) { this->score=score; }

int Movies::get_Score() { return score; };

void Review::set_Title(string& title) { this->title = title; }

string Review::get_Title() { return title; }

void Review::set_Nick(string& nick) { this->nick = nick; }

string Review::get_Nick() { return nick; }

void Review::set_Comment(string& comment) { this->comment = comment; }

string Review::get_Comment() { return comment; }

void Review::set_Score(int& score) { this->score = score; }

int Review::get_Score() { return score; };

void Review::set_Pointer(Review*& pointer) { this->next = pointer; }

void List::addNode(string& title, string& category, int& year, string& actor, string& director, int& score, Movies*& Head)
{
	Movies* newnode = new Movies();
    newnode->set_Title(title);
    newnode->set_Category(category);
    newnode->set_Year(year);
    newnode->set_Actor(actor);
    newnode->set_Director(director);
    newnode->set_Score(score);
    newnode->next = NULL;
    if (Head == NULL)
    {
        Head = newnode;
    }
    else
    {
        Movies* temp = Head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void List::addNode_Review(string&title,string& nick, string& comment,int&score,Review*&Head_Review)
{
    Review* newnode = new Review();
    newnode->set_Title(title);
    newnode->set_Nick(nick);
    newnode->set_Comment(comment);
    newnode->set_Score(score);
    newnode->next = NULL;
    if (Head_Review == NULL)
    {
        Head_Review = newnode;
    }
    else
    {
        Review* temp = Head_Review;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void List::show_Movies(Movies*&Head)
{
    if (Head != NULL)
    {
        Movies* temp = Head;
        while (temp != NULL)
        {
            cout << "Title:" << temp->get_Title() << endl << "Film category:" << temp->get_Category() << endl << "Year of production:" << temp->get_Year() << endl << "Main actor:" << temp->get_Actor() << endl << "Director of production:" << temp->get_Director() << endl << "Rating from viewers(from 1 to 10)" << temp->get_Score() << endl << endl;
            temp = temp->next;
        }
    }
}

void List::show_Comments(Review*& Head_Review)
{
    if (Head_Review != NULL)
    {
        Review* temp = Head_Review;
        while (temp != NULL)
        {
            cout << "***************************************************************************" << endl;
            cout << "Nick:" << temp->get_Nick() << endl <<"Comment:"<< temp->get_Comment() <<endl<<"Score:"<< temp->get_Score()<<endl;
            cout << "***************************************************************************" << endl;
            temp = temp->next;
        }
    }
}

bool List::check_Title(string& title,Movies*&Head)
{
    if (Head != NULL)
    {
        Movies* temp = Head;
        while (temp != NULL)
        {
            if (temp->get_Title() == title)
                return false;
            temp = temp->next;
        }
    }
    return true;
}

void List::edit_Information(string& title, string& category, int& year, string& actor, string& director, Movies*& Head)
{
    if (Head != NULL)
    {
        Movies* temp = Head;
        while (temp != NULL)
        {
            if (temp->get_Title() == title)
            {
                temp->set_Category(category);
                temp->set_Year(year);
                temp->set_Actor(actor);
                temp->set_Director(director);
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
}

void List::find_Title(Movies*& Head, string&title)
{
    if (Head != NULL)
    {
        Movies* temp = Head;
        while (temp != NULL)
        {
            if (temp->get_Title() == title)
            {
                cout << "Searching movie:" << endl;
                cout << "Title:" << temp->get_Title() << endl << "Film category:" << temp->get_Category() << endl << "Year of production:" << temp->get_Year() << endl << "Main actor:" << temp->get_Actor() << endl << "Director of production:" << temp->get_Director() << endl << "Rating from viewers(from 1 to 10)" << temp->get_Score() << endl << endl;
            }
            temp = temp->next;
        }
    }
}

void List::find_Category(Movies*& Head, string& category)
{
    if (Head != NULL)
    {
        Movies* temp = Head;
        while (temp != NULL)
        {
            if (temp->get_Category() == category)
            {
                cout << "Searching movie:" << endl;
                cout << "Title:" << temp->get_Title() << endl << "Film category:" << temp->get_Category() << endl << "Year of production:" << temp->get_Year() << endl << "Main actor:" << temp->get_Actor() << endl << "Director of production:" << temp->get_Director() << endl << "Rating from viewers(from 1 to 10)" << temp->get_Score() << endl << endl;
            }
            temp = temp->next;
        }
    }
}

void List::find_Year(Movies*& Head, int& year)
{
    if (Head != NULL)
    {
        Movies* temp = Head;
        while (temp != NULL)
        {
            if (temp->get_Year() == year)
            {
                cout << "Searching movie:" << endl;
                cout << "Title:" << temp->get_Title() << endl << "Film category:" << temp->get_Category() << endl << "Year of production:" << temp->get_Year() << endl << "Main actor:" << temp->get_Actor() << endl << "Director of production:" << temp->get_Director() << endl << "Rating from viewers(from 1 to 10)" << temp->get_Score() << endl << endl;
            }
            temp = temp->next;
        }
    }
}

void List::find_Actor(Movies*& Head, string& actor)
{
    if (Head != NULL)
    {
        Movies* temp = Head;
        while (temp != NULL)
        {
            if (temp->get_Actor() == actor)
            {
                cout << "Searching movie:" << endl;
                cout << "Title:" << temp->get_Title() << endl << "Film category:" << temp->get_Category() << endl << "Year of production:" << temp->get_Year() << endl << "Main actor:" << temp->get_Actor() << endl << "Director of production:" << temp->get_Director() << endl << "Rating from viewers(from 1 to 10)" << temp->get_Score() << endl << endl;
            }
            temp = temp->next;
        }
    }
}

void List::find_Director(Movies*& Head, string& director)
{
    if (Head != NULL)
    {
        Movies* temp = Head;
        while (temp != NULL)
        {
            if (temp->get_Director() == director)
            {
                cout << "Searching movie:" << endl;
                cout << "Title:" << temp->get_Title() << endl << "Film category:" << temp->get_Category() << endl << "Year of production:" << temp->get_Year() << endl << "Main actor:" << temp->get_Actor() << endl << "Director of production:" << temp->get_Director() << endl << "Rating from viewers(from 1 to 10)" << temp->get_Score() << endl << endl;
            }
            temp = temp->next;
        }
    }
}

void List::find_Score(Movies*& Head, int& score)
{
    if (Head != NULL)
    {
        Movies* temp = Head;
        while (temp != NULL)
        {
            if (temp->get_Score() == score)
            {
                cout << "Searching movie:" << endl;
                cout << "Title:" << temp->get_Title() << endl << "Film category:" << temp->get_Category() << endl << "Year of production:" << temp->get_Year() << endl << "Main actor:" << temp->get_Actor() << endl << "Director of production:" << temp->get_Director() << endl << "Rating from viewers(from 1 to 10)" << temp->get_Score() << endl << endl;
            }
            temp = temp->next;
        }
    }
}

void List::add_Score(Movies*& Head,string&title ,int& score)
{
    if (Head != NULL)
    {
        Movies* temp = Head;
        while (temp != NULL)
        {
            if (temp->get_Title() == title)
            {
                score = (temp->get_Score() + score)/2;
                temp->set_Score(score);
            }
            temp = temp->next;
        }
    }
}

void List::find_Review_Title(Review*& Head_Review, string& title)
{
    if (Head_Review != NULL)
    {
        Review* temp = Head_Review;
        while (temp != NULL)
        {
            if (temp->get_Title() == title)
            {
                cout << "***************************************************************************" << endl;
                cout << "Nick:" << temp->get_Nick() << endl << "Comment:" << temp->get_Comment() << endl << "His/her score:" << temp->get_Score() << endl;
                cout << "***************************************************************************" << endl;
            }
            temp = temp->next;
        }
    }
}

void List::delete_Comment(Review*& Head_Review)
{
    string nick;
    getline(cin, nick);
    if (Head_Review != NULL)
    {
        Review* temp = Head_Review;
        Review* previous;
        while (temp != NULL)
        {
            ;
        }
    }
}

void List::find_Review_Nick(Review*& Head_Review, string& nick)
{
    if (Head_Review != NULL)
    {
        Review* temp = Head_Review;
        while (temp != NULL)
        {
            if (temp->get_Nick() == nick)
            {
                cout << "***************************************************************************" << endl;
                cout <<"Title: "<< temp->get_Title() << endl <<"Comment:"<< temp->get_Comment() << endl;
                cout << "***************************************************************************" << endl;
            }
            temp = temp->next;
        }
    }
}

void File::load_information(string&file,Movies*&Head,List*&list)
{
    ifstream open(file);
    if (open)
    {
        string title_file;
        string category_file;
        int year_file;
        string actor_file;
        string director_file;
        int score_file;
        while (open)
        {
            getline(open, title_file);
            getline(open, category_file);
            open >> year_file;
            open.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(open, actor_file);
            getline(open, director_file);
            open >> score_file;
            open.ignore(numeric_limits<streamsize>::max(), '\n');
            //!title_file.empty() || !category_file.empty() || !actor_file.empty() || !director_file.empty()
            if (!title_file.empty())
            {
                list->addNode(title_file, category_file, year_file, actor_file, director_file, score_file, Head);
            }
        }
        open.close();
    }
}

void File::save_information(string& file, Movies*& Head)
{
    ofstream open(file);
    if (open)
    {
        if (Head != NULL)
        {
            Movies* temp = Head;
            while (temp != NULL)
            {
                open << temp->get_Title() << endl << temp->get_Category() << endl << temp->get_Year() << endl << temp->get_Actor() << endl << temp->get_Director() << endl << temp->get_Score() << endl;
                temp = temp->next;
            }
            
        }
        open.close();
    }
}

void File::load_reviews(string& file, Review*& Head_Review, List*& list)
{
    ifstream open(file);
    if (open)
    {
        string title_file;
        string nick_file;
        string comment_file;
        int score_file;
        while (open)
        {
            getline(open, title_file);
            getline(open, nick_file);
            getline(open,comment_file);
            open >> score_file;
            open.ignore(numeric_limits<streamsize>::max(), '\n');
            if (!title_file.empty())
            {
                list->addNode_Review(title_file, nick_file, comment_file, score_file, Head_Review);
            }
        }
        open.close();
    }
}

void File::save_Reviews(string& file, Review*& Head_Review)
{
    ofstream open(file);
    if (open)
    {
        if (Head_Review != NULL)
        {
            Review*& temp = Head_Review;
            while (temp != NULL)
            {
                open << temp->get_Title() << endl  << temp->get_Nick() << endl << temp->get_Comment() << endl << temp->get_Score() << endl;
                temp = temp->next;
            }
        }
        open.close();
    }
}

void Menu::change(string& word)
{
    transform(word.begin(), word.end(), word.begin(), ::toupper);
}

void Menu::add_Movie(Movies*&Head,List*&list)
{
    string title_main;
    string category_main;
    int year_main;
    string actor_main;
    string director_main;
    int score_main;
    cout << "Write new title:";
    getline(cin, title_main);
    Menu::change(title_main);
    if (list->check_Title(title_main,Head)==true)
    {
        cout << "Write category:" << endl;
        getline(cin, category_main);
        Menu::change(category_main);
        cout << "Write year:" << endl;
        cin >> year_main;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Write main actor:" << endl;
        getline(cin, actor_main);
        Menu::change(actor_main);
        cout << "Write director:" << endl;
        getline(cin, director_main);
        Menu::change(director_main);
        cout << "Write score(from 1 to 10):" << endl;
        cin >> score_main;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (score_main >= 1 && score_main <= 10)
        {
            cout << "Your movie added!" << endl;
            list->addNode(title_main, category_main, year_main, actor_main, director_main, score_main, Head);
        }
        else
        {
            cout << "You write wrong number, try again!" << endl;
        }

    }
    else
    {
        cout << "Title is already exist in our datebase!" << endl << endl;
    }
}

void Menu::edit_Movie(Movies*& Head, List*& list)
{
    string title_main;
    string category_main;
    int year_main;
    string actor_main;
    string director_main;
    int score_main;
    cout << "Write title which you want to edit something:";
    getline(cin, title_main);
    if (list->check_Title(title_main,Head) == false)
    {
        cout << "Write new category:";
        getline(cin, category_main);
        change(category_main);
        cout << "Write new year:";
        cin >> year_main;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Write new actor:";
        getline(cin, actor_main);
        change(actor_main);
        cout << "Write new director:";
        getline(cin, director_main);
        change(director_main);
        list->edit_Information(title_main, category_main, year_main, actor_main, director_main,Head);
    }
    else
    {
        cout << "Title is not excist in this datebase, please try again!" << endl;
    }
}

void Menu::find_By(Movies*& Head, List*& list)
{
    cout << "Write parameter:" << endl;
    string parameter;
    getline(cin, parameter);
    change(parameter);
    if (parameter == "TITLE")
    {
        cout << "Please write TITLE you want to find :" << endl;
        string find_title;
        getline(cin, find_title);
        change(find_title);
        list->find_Title(Head, find_title);
    }
    else if (parameter == "CATEGORY")
    {
        cout << "Please write CATEGORY you want to find :" << endl;
        string find_category;
        getline(cin, find_category);
        change(find_category);
        list->find_Category(Head, find_category);
    }
    else if (parameter == "YEAR")
    {
        cout << "Please write YEAR you want to find :" << endl;
        int find_year;
        cin >> find_year;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        list->find_Year(Head, find_year);
    }
    else if (parameter == "ACTOR")
    {
        cout << "Please write ACTOR you want to find :" << endl;
        string find_actor;
        getline(cin, find_actor);
        change(find_actor);
        list->find_Actor(Head, find_actor);
    }
    else if (parameter == "DIRECTOR")
    {
        cout << "Please write DIRECTOR you want to find :" << endl;
        string find_director;
        getline(cin, find_director);
        change(find_director);
        list->find_Director(Head, find_director);
    }
    else if (parameter == "SCORE")
    {
        cout << "Please write SCORE(from 1-10) you want to find :" << endl;
        int find_score;
        cin >> find_score;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        list->find_Score(Head, find_score);
    }
}

void Menu::add_Review(Movies*&Head,Review*& Head_Review, List*& list,string&nick)
{
    cout << "Write title which you want to comment:" << endl;
    string title_review;
    getline(cin, title_review);
    Menu::change(title_review);
    if (list->check_Title(title_review,Head) == false)
    {
        string comment_review;
        int score_review;
        getline(cin, comment_review);
        cin >> score_review;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (score_review >= 1 && score_review <= 10)
        {
            list->addNode_Review(title_review, nick, comment_review, score_review, Head_Review);
            list->add_Score(Head, title_review,score_review);
            cout << "Your comment has been added!" << endl;
        }
        else
        {
            cout << "You write wrong number to score, your comment hasn't been added, please try again!" << endl;
        }
    }
    else
    {
        cout << "Title not exist in our datebase!" << endl;
    }
}

void Menu::show_Reviews(Review*&Head_Review, List*& list)
{
    list->show_Comments(Head_Review);
}

void Menu::find_Reviews_Title(Movies*& Head,Review*& Head_Review, List*& list)
{
    string title_find;
    cout << "Write a title about which you would like to read the comments:";
    getline(cin, title_find);
    Menu::change(title_find);
    if (list->check_Title(title_find, Head) == false)
    {
        cout << endl<<"This is all comments about movie: " << title_find << endl << endl;
        list->find_Review_Title(Head_Review,title_find);
    }
    else
    {
        cout << "This title not exist in our datebase!" << endl;
    }
}

void Menu::add_Score(Movies*& Head,List*&list)
{
    string title_addScore;
    cout << "Write title which you want to add score:";
    getline(cin, title_addScore);
    change(title_addScore);
    if (list->check_Title(title_addScore, Head) == false)
    {
        int score_addScore;
        cout << "Write your score(from 1 to 10):";
        cin >> score_addScore;
        if (score_addScore >= 1 && score_addScore <= 10)
        {
            list->add_Score(Head, title_addScore, score_addScore);
        }
        else
        {
            cout << "You write wrong number to score, your comment hasn't been added, please try again!" << endl;
        }
    }
    else
    {
        cout << "Title is not exist in our datebase!" << endl;
    }

}

void Menu::find_Review_Nick(Review*& Head_Review,List*&list)
{
    string nick_find;
    cout << "Write nick to find his/her comment:";
    getline(cin, nick_find);
    cout << endl << "This is all comment write by " << nick_find << endl;
    list->find_Review_Nick(Head_Review, nick_find);
}

Account::Account(string nick)
{
    this->nick = nick;
}

string Account::get_Nick() { return nick; }

void Account::log_in(string& nick, Account*& wsk)
{
    Movies* Head = NULL;
    Review* Head_Review = NULL;
    List* list = new List();
    string file = "movies.txt";
    string file2 = "comment.txt";
    File::load_information(file, Head,list);
    File::load_reviews(file2, Head_Review, list);
    if (nick=="ADMIN")
    {
        string password_main;
        Admin admin(nick,"ADMIN");
        cin >> password_main;
        if (password_main=="ADMIN")
        {
            wsk = &admin;
            wsk->Menu(Head, Head_Review, list, file, file2);
        }
        else
        {
            cout << "Wrong password, try again!" << endl;
            log_in(nick, wsk);
        }
    }
    else
    {
        User user(nick);
        wsk = &user;
        wsk->Menu(Head, Head_Review, list, file, file2);
    }
}

string User::get_Nick() { return nick; }

string Admin::get_Nick() { return nick; }

string Admin::get_Password() { return password; }

void User::Menu(Movies*& Head, Review*& Head_Review, List*& list, string& file, string& file2)
{
    cout << "THIS IS MENU FOR USER!" << endl;
    cout << "CHOOSE YOUR OPTION : \n 1.ADD NEW MOVIE \n 2.ADD REVIEW ABOUT FILM \n 3.FIND COMMENT BY TITLE \n 4.ADD SCORE \n 5. SHOW ALL MOVIES ";
    string nick_menu = get_Nick();
    int choose;
    cin >> choose;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (choose)
    {
    case 1:
        Menu::add_Movie(Head, list);
        Menu(Head, Head_Review, list, file, file2);
        //zapis do pliku
        break;
    case 2:
        Menu::add_Review(Head, Head_Review, list,nick_menu);
        File::save_Reviews(file2, Head_Review);
        Menu(Head, Head_Review, list, file, file2);
        break;
    case 3:
        Menu::find_Reviews_Title(Head, Head_Review, list);
        Menu(Head, Head_Review, list, file, file2);
        break;
    case 4:
        Menu::add_Score(Head,list);
        Menu(Head, Head_Review, list, file, file2);
        //zapis do pliku
        break;
    case 5:
        list->show_Movies(Head);
        Menu(Head, Head_Review, list, file, file2);
        break;
    case 6:
        //szukanie filmu po ...
        break;
    }
}

void Admin::Menu(Movies*& Head, Review*& Head_Review, List*& list, string& file, string& file2)
{
    cout << "THIS IS MENU FOR ADMIN !" << endl;
    cout << "CHOOSE YOUR OPTION : \n 1.ADD NEW MOVIE \n 2.EDIT MOVIE \n 3.ADD COMMENT \n 4.SHOW COMMENT \n 5.SHOW ALL MOVIES \n 6.FIND COMMENT BY NICK ";
    string nick_menu=get_Nick();
    int choose;
    cin >> choose;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (choose)
    {
    case 1:
        Menu::add_Movie(Head, list);
        //zapis do pliku
        break;
    case 2:
        Menu::edit_Movie(Head, list);
        Menu(Head, Head_Review, list, file, file2);
        //zapis do pliku
        break;
    case 3:
        Menu::add_Review(Head,Head_Review,list,nick_menu);
        File::save_Reviews(file2, Head_Review);
        Menu(Head, Head_Review, list, file, file2);
        break;
    case 4:
        Menu::show_Reviews(Head_Review,list);
        Menu(Head, Head_Review, list, file, file2);
        break;
    case 5:
        list->show_Movies(Head);
        Menu(Head, Head_Review, list, file, file2);
        break;
    case 6:
        Menu::find_Review_Nick(Head_Review, list);
        Menu(Head, Head_Review, list, file, file2);
        //szukanie komentarzu po nicku
        break;
    }
}

