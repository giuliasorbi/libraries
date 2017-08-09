#ifndef LIB_CATEGORY_H
#define LIB_CATEGORY_H

#include <map>
#include "book.h"

class Category {
    
public:
    Category( const std::string& name, const std::string& description );
    Category( const Category& other );
    Category( Category&& other );
    Category& operator = (const Category& other );
    Category& operator = ( Category&& other );
    void add_book( Book&& b );
    const std::map<std::string, Book>& books() const { return m_books; }
    Book book( const std::string& title ) const { return m_books.at(title); }
    void show_books() const;
    void delete_book( const std::string& title ) { m_books.erase(title); }
    void append_books( const std::map<std::string, Book>& new_books);

    std::string name() const { return m_name; }
    std::string desc() const { return m_description; }

private:
    std::string m_name;
    std::string m_description;
    std::map<std::string, Book> m_books; // <title book, Book>

};

#endif