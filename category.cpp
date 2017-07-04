#include <iostream>
#include <string>
#include <vector>

#include "book.h"
#include "category.h"


Category::Category( const Category& other ) {
    std::cout << "copy category\n" ;
    m_name = other.m_name;
    m_description = other.m_description;
}

Category::Category( Category&& other ) {
    std::cout << "move category\n" ;
    m_name = std::move( other.m_name );
    m_description = std::move( other.m_description );
}

Category::Category( const std::string& name, const std::string& description ) {
    m_name = name;
    m_description = description;
    std::cout << "---- Create category " << name << " ----\n";
}

Category& Category::operator = ( const Category& other ) {
    std::cout << "copy operator category\n" ;
    m_name = other.m_name;
    m_description = other.m_description;
    return *this;
}

Category& Category::operator = ( Category&& other ) {
    std::cout << "move operator category\n" ;
    m_name = std::move( other.m_name);
    m_description = std::move( other.m_description);
    return *this;
}