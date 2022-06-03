
#include <iostream>

using std::string;


class Movie {
public:
    string title;
    int prouctionYear;
    int rating;
    int number_of_viewers;
    Movie(string t, int p, int r, int n) {
        this->title = t;
        this->prouctionYear = p;
        this->rating = r;
        this->number_of_viewers = n;
        std::cout << "Creating a movie with name " << t;
    }
    void print() {
        std::cout << "\n Movie name: " << this->title << ", \n Production year: " << this->prouctionYear << ",\n Rating: " << this->rating << ",\n Number of viewers: " << this->number_of_viewers << "\n";
    }
    ~Movie() {
        
    };
};

void incr(int& x, int value);

int main()
{
    int i = 10; // simple or ordinary variable with value.
    int* x = &i; //x pointer is assigned to the address of the variable i
    //print the value of x
    std::cout << "\nOriginal value of x1: " << *x;
    //pass the reference of x through the function with the value to increment to it
    incr(*x, 8);
    //print the final value of x
    std::cout << "\nAfter increment by 8, x2: " << *x;

    //Another task 

    string title;
    int prouctionYear;
    int rating;
    int number_of_viewers;
    Movie* myMovies[2];
    for (int i = 0; i < 3; i++) {
        std::cout << "\n\nEnter the movie " << i + 1 << " details\n\n";

        std::cout << "Enter the name of the movie: ";
        std::cin >> title;
        std::cout << "Enter the movie production year: ";
        std::cin >> prouctionYear;
        int c = 1;
        rating = -1;
        while (rating > 10 || rating < 0) {
            if (c > 1) {
                std::cout << "Rating must be between 0-10\n";
            }
            std::cout << "Enter the movie rating: ";
            std::cin >> rating;
            c++;
        }
        c = 1;
        std::cout << "Enter the number of viewers: ";
        std::cin >> number_of_viewers;
        myMovies[i] = new Movie(title, prouctionYear, rating, number_of_viewers);
    }
    std::cout << "\n\n\n";
    for (int i = 0; i < 3; i++) 
    {
        myMovies[i]->print();
    }
    
    exit(3);
}

//A function incr(x, delta) accepting a reference to an integer variable xand an integerr value delta, incrementing x by value.
void incr(int& x, int delta) {
    x = x + delta;
}