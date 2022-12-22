#pragma once
#include <string>
#include <iostream>

class Book{
    public:
        std::string title, author, category;
        int pagesNumb;
        bool wasBorrowed;

        Book():Book("", "", "", 0, false){};
        Book(std::string newTitle, std::string newAuthor, std::string newCategory, int newPagesNumb, bool newWasBorrowed):
            title(newTitle), author(newAuthor), category(newCategory), pagesNumb(newPagesNumb), wasBorrowed(newWasBorrowed){};
        Book(const Book &parent){
            title = parent.title;
            author = parent.author;
            category = parent.category;
            pagesNumb = parent.pagesNumb;
            wasBorrowed = parent.wasBorrowed;
        }

        friend std::ostream& operator<<(std::ostream& stream, const Book& dispBook){
            stream << dispBook.title << " - " << dispBook.author << " - " << dispBook.category
                    << ". " << dispBook.pagesNumb << " pages, ";
            if(dispBook.wasBorrowed){
                stream << "borrowed";
            }else{
                stream << "in library";
            }
            return stream;
        }
};