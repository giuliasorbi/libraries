#ifndef LIB_LIBRARY_H
#define LIB_LIBRARY_H

#include "category.h"
#include "book.h"

class Library {
public:
    Library( std::string name );
    void add_book( Book&& b, const std::string& category );
    void add_category ( const Category& c );
    void add_category ( Category&& category );

    void show() const;
    std::string name() const { return m_name; }
    const std::map<std::string, Category>& categories() const { return m_categories; }

    std::string search_book_category ( const std::string& title );
    void change_book_category( const std::string& title, const std::string& new_category );
    void move_category( const std::string& category, Library& dest );

    void delete_category( std::string category );

private:
    std::string m_name;
    std::map<std::string, Category> m_categories; // <category name, Category>
};

#endif