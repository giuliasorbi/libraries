#include <iostream>
#include <string>
#include <vector>

#include "book.h"
#include "category.h"


Book::Book( std::string title, std::string author ) {
    m_title = title;
    m_author = author;
    std::cout << "---- Create book " << title << " -----\n";
}

Book::Book( const Book& other ) {
    std::cout << "copy book \n";
    m_title = other.m_title;
    m_author = other.m_author;
}

Book::Book( Book&& other ) {
    std::cout << "move book \n";
    m_title = std::move( other.m_title );
    m_author = std::move( other.m_author );
}


Book& Book::operator = ( const Book& other ) {
    std::cout << "copy operator book \n";
    m_title = other.m_title;
    m_author = other.m_author;
    return *this;
}

Book& Book::operator = ( Book&& other ) {
    std::cout << "move operator book \n";
    m_title = std::move( other.m_title );
    m_author = std::move(  other.m_author );
    return *this;
}

