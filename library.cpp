#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "book.h"
#include "category.h"
#include "library.h"


Library::Library ( std::string name )
    : m_name(name),
      m_categories({})
{}


void Library::add_category ( const Category& c ) {
    std::cout << "Add category COPYYYYYYY\n";
    if( ( m_categories.find( c.name() ) ) == m_categories.end() ) {
        m_categories.insert ( std::pair<std::string, Category>( c.name(), c ) );
    }
}

void Library::add_category ( Category&& c ) {
    std::cout << "Add category MOVE\n";
    if( ( m_categories.find( c.name() ) ) == m_categories.end() ) {
        m_categories.insert( std::pair<std::string, Category>( c.name(), std::move(c) ) );
    }
    else{
        std::cout << "category \"" << c.name() << "\" FOUND "<< " in \"" << m_name << "\" \n\n" ;
        // m_categories.at( c.name() ).append_books( c.books() );
        for( auto book : c.books() ) {
            m_categories.at( c.name() ).add_book(std::move( book.second ));
        }
    }
}


void Library::add_book ( Book&& b, const std::string& category ) {
    if( ( m_categories.find( category ) ) == m_categories.end() ) {
        std::cout << "Cannot add book \""<< b.title() << "\": Category \"" << category << "\" isn't in \"" << m_name << "\" library \n";
    }
    else {
        m_categories.at(category).add_book( std::move( b ) );
    }
}


void Library::show() const {
    std::cout  << m_name << " LIBRARY INFO: \n";
    for( const auto& category : m_categories ) {
        category.second.show_books();
    }
}


std::string Library::search_book_category ( const std::string& title ) {
    for( const auto& category : m_categories ) {
        for( const auto& book : category.second.books() ) {
            if( title == book.first ){
                return category.first;
            }
        }
    }
    return "Book not found.";
}


void Library::change_book_category( const std::string& title, const std::string& new_category ) {
    std::cout << "change_book_category \"" << title << "\" to \"" << new_category << "\"\n";
    std::string old_cat = this->search_book_category( title );

    if( old_cat == "Book not found.") {
        std::cout << old_cat << " Cannot change category.\n";
    } 
    else {
        if( old_cat != new_category ) {
            m_categories.at( new_category ).add_book( std::move ( m_categories.at( old_cat ).book( title ) ) );
            m_categories.at( new_category ).book( title ).set_category( &m_categories.at( new_category ) );
            m_categories.at( old_cat ).delete_book( title );
        }
    }
}


void Library::move_category( const std::string& category, Library& dest ) {
    std::cout << "\n\nmove_category \"" << category << "\" to \"" << dest.name() << "\"\n";
   
    // if( ( dest.categories().find( category ) ) == dest.categories().end() ) {
    //     std::cout <<"category NOT FOUND " << " in " << dest.name() <<" \n\n";
    //     // dest.add_category( std::move( m_categories.at( category ) ) );
    //     dest.add_category( Category(std::move( m_categories.at( category ) ) ));
    // }
    // else {
    //     std::cout <<"category FOUND "<< " in " << dest.name() <<" \n\n" ;
    //     // dest.m_categories.at( category ).append_books( m_categories.at( category ).books() );
    //     for(  auto book : m_categories.at(category).books() ) {
    //         dest.m_categories.at(category).add_book(std::move(book.second));
    //         //std::cout << book.second.title();
    //     }

    // }
    dest.add_category(std::move(m_categories.at(category)));
    m_categories.erase( category );

}

 void Library::delete_category( std::string category ) {
    std::cout << "delete_category \"" << category << "\" of \"" << m_name << "\"\n";
    for( auto book : m_categories.at( category ).books() ) {
        if( ( m_categories.find("uncategorized") ) == m_categories.end() ) {
            this->add_category( Category("uncategorized", "uncategorized books") );
        }
        book.second.set_category( &m_categories.at( "uncategorized") );
        m_categories.at("uncategorized").add_book( std::move(book.second) );

    }
    m_categories.erase(category);

 }