#include <iostream>
#include <string>
#include <vector>

#include "book.h"
#include "category.h"
Book::Book( std::string title, std::string author )
    : m_title(title),
      m_author(author),
      m_category(nullptr)
{
     std::cout << "---- Create book " << title << " -----\n";
}

Book::Book( const Book& other )
    : m_title(other.m_title),
      m_author(other.m_author),
      m_category(other.m_category)
{
    std::cout << "copy book \n";
}

Book::Book( Book&& other )
    : m_title(std::move( other.m_title )),
      m_author(std::move( other.m_author )),
      m_category(std::move(other.m_category))
{
    std::cout << "move book \n";
}


Book& Book::operator = ( const Book& other ) {
    std::cout << "copy operator book \n";
    m_title = other.m_title;
    m_author = other.m_author;
    m_category = other.m_category;
    return *this;
}

Book& Book::operator = ( Book&& other ) {
    std::cout << "move operator book \n";
    m_title = std::move( other.m_title );
    m_author = std::move( other.m_author );
    m_category = std::move( other.m_category );
    return *this;
}

void Book::set_category( Category* category ) {
    m_category = category; 
}

void Book::show() const {
    std::cout << "BOOK INFO:\nTitle:\"" << m_title << "\", Author:\"" << m_author << "\", Category: ";
    if( m_category == nullptr ) {
        std::cout << "undefined category, this books insn't in any library\n";
    }
    else
    {
        std::cout << "\"" << m_category->name() << "\"  " << m_category <<  "\n";
    }
}
