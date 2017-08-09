#ifndef LIB_BOOK_H
#define LIB_BOOK_H

class Category;

class Book {
public:
    Book(int i);
    Book( std::string title, std::string author);
    Book( const Book& other );
    Book( Book&& other );
    Book& operator = ( const Book& other );
    Book& operator = ( Book&& other );

    std::string title() const { return m_title; }
    std::string author() const { return m_author; }

    void set_category( Category*  category );
    Category* category() const { return m_category; }

    void show() const; 

private:
    std::string m_author;
    std::string m_title;
    Category* m_category;
};

#endif