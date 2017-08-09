#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "book.h"
#include "category.h"


Category::Category( const Category& other )
    : m_name(other.m_name),
      m_description(other.m_description),
      m_books(other.m_books)
{
    std::cout << "copy category\n" ;
}

Category::Category( Category&& other )
    : m_name(std::move(other.m_name)),
      m_description(std::move(other.m_description)),
      m_books(std::move(other.m_books))
{
    std::cout << "move category\n" ;
    for ( auto& book : m_books ) {
        book.second.set_category( this );
    }
}

Category::Category( const std::string& name, const std::string& description )
    : m_name(name),
      m_description(description),
      m_books({})
{
    std::cout << "---- Create category " << name << " ----\n";
}

Category& Category::operator = ( const Category& other ) {
    std::cout << "copy operator category\n" ;
    m_name = other.m_name;
    m_description = other.m_description;
    m_books = other.m_books;
    return *this;
}

Category& Category::operator = ( Category&& other ) {
    std::cout << "move operator category\n" ;
    m_name = std::move( other.m_name );
    m_description = std::move( other.m_description );
    m_books = std::move( other.m_books );
    return *this;
}

void Category::add_book( Book&& b ) {
    b.set_category( this );
    m_books.insert( std::pair<std::string, Book>( b.title(), std::move(b) ) );
}

void Category::show_books() const {
    for( const auto& b : m_books) { 
        b.second.show();
        //std::cout <<"Title: \"" <<  b.first << "\", Author\"" << b.second.author() << "\", Category:\"" << m_name << "\"\n";
    }
}

void Category::append_books( const std::map<std::string, Book>& new_books) {
    m_books.insert( new_books.begin() , new_books.end() );
}