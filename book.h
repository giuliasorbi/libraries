#ifndef LIB_BOOK_H
#define LIB_BOOK_H

class Book {
public:
    Book( std::string title, std::string author);
    Book( const Book& other );
    Book( Book&& other );
    void get_info() const;
    Book& operator = ( const Book& other );
    Book& operator = ( Book&& other );

    std::string title() const { return m_title; }
    std::string author() const { return m_author; }

private:
    std::string m_author;
    std::string m_title;
};

#endif