#ifndef LIB_CATEGORY_H
#define LIB_CATEGORY_H

class Category {
    
public:
    Category( const std::string& name, const std::string& description );
    Category( const Category& other );
    Category( Category&& other );
    Category& operator = (const Category& other );
    Category& operator = ( Category&& other );

    std::string name() const { return m_name; }
    std::string desc() const { return m_description; }

private:
    std::string m_name;
    std::string m_description;

};


#endif