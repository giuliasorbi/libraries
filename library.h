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
    std::vector<Category> categories() const { return m_categories; }
    std::string search_book_category ( const std::string& title );
    void change_book_category( const std::string& title, const std::string& new_category );
    void delete_category( const std::string& category );
    void move_category( const std::string& category, Library& dest );

private:
    std::string m_name;
    std::vector<Category> m_categories;
    std::map< std::string, std::vector<Book> > m_books;
};

#endif