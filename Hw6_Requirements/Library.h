//============
/*
 * Jordan Giebas
 * CSE 331
 * Proj06
 * 11/4/2016
 */
//============


#ifndef Library_H
#define Library_H

#include <iostream>
#include <cstdlib>
#include <new>
#include <string>

using namespace std;

struct Book {

    string isbn;
    string title;
    string author;

    Book() = delete;
    Book(string _isbn, string _title, string _author) : isbn(_isbn), title(_title), author(_author) {};

    bool operator<(const Book &other) { return isbn < other.isbn; };
    bool operator==(const Book &other) { return isbn == other.isbn; };
    bool operator!=(const Book &other) { return isbn != other.isbn; };

};

class Library {

    public:

        Library();
        void add(Book);
        void check_in(Book);
        Book *check_out(Book);
        Book *search(Book);
        long available_copies(Book);

    private:

        struct BookNode {

            Book value;
            BookNode *left;
            BookNode *right;
            size_t count = 1;
            BookNode(Book b) : value(b), left(nullptr), right(nullptr) {};

        };

        BookNode *root;
        void add(BookNode *&root_node, BookNode *&new_node);
        BookNode *search(Book, BookNode *root);

};

Library::Library() {

    root = nullptr;

}

/*
 * @pre    : Library in place
 * @param  : BookNode* objects; RootNode, NewNode
 * @post   : Library with added node in correct location
 * @return : Library with added node in correct location
 */
void Library::add( BookNode *&root_node, BookNode *&new_node ) {

    //is the tree empty?? if it is, we need to make the root node, this book.
    //therefore, since our private member vars are 'bookNodes' we will init
    //a bookNode using the parameter and set it as the

    if ( root_node == nullptr ) {

        root_node = new_node;

        cout << "Heavy add method: " << root_node->value.title << endl;

    }

    //now if the tree's not empty, we need to check the left / right pointers
    //of the root node and evaulate where to put the book we're adding

    else if ( new_node->value < root_node->value ) {

        if ( root_node->left == nullptr ) {

            root_node->left = new_node;

        }

        else {

            add( root_node->left, new_node );

        }

    }

    else if ( new_node->value < root_node->value ) {

        if ( root_node->right == nullptr ) {

            root_node->right = new_node;

        }

        else {

            add( root_node->right, new_node );

        }

    }

}

/*
 * @pre    : library constructed
 * @param  : Book object, b
 * @post   : Book added to library
 * @return : Book added to library
 */
void Library::add( Book b ) {

    //first, in order to be a node in our tree
    //you must be of type BookNode, so we will create
    //a book node from the book given through it's constructor

    BookNode bn = BookNode(b);
    BookNode* ptr = &bn;

    //call the private method add that does the heavy lifting
    //encapsulate, hide this from the interface/user
    add( root, ptr );

}

/*
 * @pre    : library available to search
 * @param  : Book obj b, BookNode* obj rt
 * @post   : untouched library
 * @return : BookNode* to book if found, nullptr else
 */
Library::BookNode* Library::search( Book b, BookNode* rt ) {

    //first check to see if the root node, contains the book you desire
    if ( rt->value == b ) {

        return rt;

    }

    //now if it's not the root node, you need to check to see if the book is less than, or greater than
    //the book at the root node. Then put it in the correct spot
    else if ( b < rt->value ) {

        if ( rt->left == nullptr ) {

            return rt->left;

        }

        else {

            search( b, rt->left );

        }

    }

    else if ( b < rt->value ) {

        if ( rt->right == nullptr ) {

            return rt->right;

        }

        else {

            search( b, rt->right );

        }

    }

}

/*
 * @pre    : library
 * @param  : Book obj, b
 * @post   : library untouched
 * @return : Book* obj to book if found, nullptr else
 */
Book* Library::search( Book b ) {

    BookNode* ret_bn = search( b, root );
    Book* ret_ptr = &(*ret_bn).value;

    return ret_ptr;


}

/*
 * @pre    : Library to check from
 * @param  : Book obj, b
 * @post   : Library added a book
 * @return : Count of b++
 */
void Library::check_in( Book b ) {


    BookNode* ptr_bn = search( b, root );

    if ( ptr_bn != nullptr ) {

        ptr_bn->count++;

    }

}

/*
 * @pre    : library
 * @param  : Book obj, b
 * @post   : library, book obj b count --
 * @return : return ptr to book b
 */
Book* Library::check_out( Book b ) {

    BookNode* ptr_bn = search( b, root );

    if ( ptr_bn != nullptr ) {

        cout << "Book does not exist in this library!" << endl;

    }

    else if ( ptr_bn->count == 0 ) {

        cout << "No more available copies of this book!" << endl;

    }

    else if ( ptr_bn->count > 0 ) {

        (*ptr_bn).count--;

        Book temp_b = ptr_bn->value;
        Book* ret_ptr = &temp_b;

        return ret_ptr;

    }

}

/*
 * @pre    : library
 * @param  : book obj b
 * @post   : library untouched
 * @return : count (# of copies) of Book b
 */
long Library::available_copies( Book b ) {

    BookNode *temp = search(b, root);

    if (temp != nullptr) {

        return temp->count;

    }

    else {

        cout << "No copies available" << endl;
        return -1;

    }

}

#endif