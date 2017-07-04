
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "book.h"
#include "category.h"
#include "library.h"


Library::Library ( std::string name ) {
    m_name = name;
    m_categories = {};
    m_books = {};
}


void Library::add_category ( const Category& c ) {
    std::cout << "Add category COPYYYYYYY\n";

    if( ( m_books.find( c.name() ) ) == m_books.end() ) {
        m_categories.push_back( c );
        m_books.insert ( std::pair<std::string, std::vector<Book>>( c.name(), {}) );
    }
    // else
    // {
    //     std::cout << "Category " << c.name() << " is already in " << m_name << " library\n";
    // }
    
}

void Library::add_category ( Category&& c ) {
    std::cout << "Add category MOVE\n";
   

    if( ( m_books.find(c.name()) ) == m_books.end() ) {
        std::string key = c.name();
        m_categories.push_back( std::move(c) );
        m_books.insert ( std::pair<std::string, std::vector<Book>>( key, {}) );
    }

    
}


void Library::add_book ( Book&& b, const std::string& category ) {
    // auto search = m_books.find( category );
    if( ( m_books.find(category) ) == m_books.end() ) {
        std::cout << "Cannot add book \""<< b.title() << "\": Category \"" << category << "\" isn't in \"" << m_name << "\" library \n";
    }
    else {
        m_books[category].push_back( std::move(b) );
    }
}


void Library::show() const {
    std::cout  << m_name << " LIBRARY INFO: " << m_books.size() <<"\n";
    for( const auto& category : m_books ) {
        for ( const auto& b : category.second ) {
            std:: cout << "Title: \"" <<  b.title() << "\" - Author: \"" << b.author() << "\" - Category: \"" << category.first << "\"\n";
        }
    }
    
}


std::string Library::search_book_category ( const std::string& title ) {
    for( const auto& category : m_books ) {
        for( const auto& book : category.second ) {
            if( title == book.title() ){
                return category.first;
            }

        }
    }
    return "Book not found.";
}


void Library::change_book_category( const std::string& title, const std::string& new_category ) {
   
    std::string old_cat = this->search_book_category( title );
    if( old_cat == "Book not found.") {
        std::cout << old_cat << " Cannot change category.\n";
    } 
    else 
    {
        if( old_cat != new_category ) {
            for( auto i = 0; i < m_books[ old_cat ].size(); i++ ) {
                if( title == m_books[ old_cat ][i].title() ) {
                    std::cout << "START \n";
                    this-> add_book( std::move( m_books[ old_cat ][i] ) , new_category );
                    std::cout << "ADDEDD \n";
                    m_books[ old_cat ].erase( m_books[ old_cat ].begin() + i  );
                    std::cout << "END \n";
                    break;
                }
            }

        }

    }
}

void Library::delete_category( const std::string& category ) {
    for( auto i = 0; i < m_categories.size(); i++ ) {
        if( m_categories[i].name() == category ) {
            m_categories.erase( m_categories.begin() + i  );
            break;
        }
    }
    m_books.erase( category );
}


void Library::move_category( const std::string& category, Library& dest ) {
    std::cout << "move_category \"" << category << "\" to \"" << dest.name() << "\"\n";
    for( auto& c  : m_categories ){
        if( c.name() == category ) {
            dest.add_category( std::move(c) ); 
            break;
        }
    }

    std::cout <<"ADDED CATEGORY\n";
 
    for( auto& b : m_books[ category ] ) {
        dest.add_book( std::move( b ), category );
    }
    this -> delete_category( category );
    // dest.show();


}