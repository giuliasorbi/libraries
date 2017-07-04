#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "book.h"
#include "category.h"
#include "library.h"

int main() {
    Library giulia( "My library" );

    giulia.add_category(Category("romance", "lots of romances"));
    giulia.add_category(Category("action", "lots of actions"));
    giulia.add_category(Category("children", "lots of children"));

    giulia.add_book(Book("title1", "author1"), "action");
    giulia.add_book(Book("title2", "author2"), "action");
    giulia.add_book(Book("title3", "author3"), "children");

    std::cout << "----------------------------\n";
    giulia.show();
    std::cout << "----------------------------\n";


    // da sistemare
    Library federico( "Federico's library" );
   
    federico.add_category(Category("action", "lots of actions"));
    federico.add_category(Category("cs", "lots of computers"));
    federico.add_book(Book("title4", "author4"), "cs");
    federico.add_book(Book("title5", "author5"), "cs");
    federico.add_book(Book("title6", "author6"), "action");

    std::cout << "----------------------------\n";
    federico.show();
    std::cout << "----------------------------\n";

    /////////////////// CHANGE BOOK CATEGORY /////////////////////////////
    federico.change_book_category( "title4", "action" );
    federico.show();
    ////////////////////////////////////////////////////////////////////


    ///////////// MOVE CATEGORY TO OTHER LIBRARY ///////////////////////
    // giulia.move_category( "children", federico );
    // std::cout << "----------------------------\n";
    // giulia.show();
    // std::cout << "----------------------------\n";
    // federico.show();
    // std::cout << "----------------------------\n";
    ////////////////////////////////////////////////////////////////////


    return 0;

}