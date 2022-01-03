#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include"Tree.h"
#include"Node.h"
#include"Tree.cpp"

using namespace std;



int main()
{
    /*Tree<int> TreeInt;
    Node<int>* leaf = TreeInt.getRoot();
    TreeInt.insert(10, leaf);
    TreeInt.insert(5, leaf);
    TreeInt.insert(9, leaf);
    TreeInt.insert(8, leaf);
    TreeInt.findElement(10, leaf);
    cout<<TreeInt.returnCountLevels(leaf)<<endl;
    cout<<TreeInt.returnCountElements(leaf)<<endl;
    TreeInt.deleteElement(10, leaf);
    TreeInt.findElement(10, leaf);
    cout << TreeInt.returnCountLevels(leaf) << endl;
    cout << TreeInt.returnCountElements(leaf) << endl;*/
   
    Tree<char> TreeChar;
    Node<char>* leafChar = TreeChar.getRoot('b');
    TreeChar.insert('a', *leafChar);
    TreeChar.insert('c', *leafChar);
    TreeChar.insert('d', *leafChar);
    /*TreeChar.findElement('d', leafChar);
    cout << TreeChar.returnCountLevels(leafChar) << endl;
    cout << TreeChar.returnCountElements(leafChar) << endl;*/
    TreeChar.deleteElement('c', leafChar);
    /*TreeChar.findElement('d', leafChar);
    cout << TreeChar.returnCountLevels(leafChar) << endl;
    cout << TreeChar.returnCountElements(leafChar) << endl;*/

    /*Tree<string> TreeString;
    Node<string>* leafString = TreeString.getRoot();
    TreeString.insert("cos", leafString);
    TreeString.insert("ala", leafString);
    TreeString.insert("dom", leafString);
    TreeString.insert("ela", leafString);
    TreeString.findElement("dom", leafString);
    cout << TreeString.returnCountLevels(leafString) << endl;
    cout << TreeString.returnCountElements(leafString) << endl;
    TreeString.deleteElement("dom", leafString);
    TreeString.findElement("dom", leafString);
    cout << TreeString.returnCountLevels(leafString) << endl;
    cout << TreeString.returnCountElements(leafString) << endl;*/
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    return 0;
}


