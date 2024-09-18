#include <iostream> // Input and output
#include <string> // String
#include <fstream> // File handling
#include <sstream> // String stream
#include <iomanip> // Make display look better

using namespace std; // Standard namespace

class Videos{ // Class Videos
    protected: 
        string id; //Attributes the will be inherited by the derived classes
        string name;
        string lenght;
        string genre;
        string rating;
        string comments;
    public:
    Videos(){}; 
    Videos(string i, string n, string g, string l, string r, string c){ // Constructor
        id = i;
        name = n;
        genre = g;
        lenght = l;
        rating = r;
        comments = c;
    }  
    virtual void displaylabels(){ // Virtual function to display the labels of the table
        cout << "ID" << setw(35) << "Name" << setw(10) << "Genre" << setw(10) << "Lenght" << setw(10) << "Rating" << setw(15) << "Comments" << endl;
        } 
    virtual void displaynames(){ // Virtual function to display the names of the videos
        cout << id << setw(34) << name << setw(10) << genre << setw(10) << lenght << setw(10) << rating << setw(16) << comments << endl;
        }
};

class Movies:public Videos{
    public:
    Movies(){};
    Movies(string i, string n, string g, string l, string r, string c):Videos(i, n, g, l, r, c){}; // Constructor that inherits the attributes of the base class

    Movies find(Movies m[], string name){ // Function to find a movie by name
        for (int i = 0; i < 30; i++) {
            if (m[i].name == name) {
                return m[i];
            }
        }
        return m[0];
    }
    string getid(){ // Getters and setters
        return id;
    }
    string getname(){
        return name;
    }
    string getlenght(){
        return lenght;
    }
    string getgenre(){
        return genre;
    }
    string getrating(){
        return rating;
    }
    string getcomments(){
        return comments;
    }
    void setrating(string r){
        rating = r;
    }
    void setcomments(string c){
        comments = c;
    }

};

class Series:public Videos{
    public:
    Series(){};
    Series(string i, string n, string l, string g, string r, string c):Videos(i, n, l, g, r, c){}; // Constructor that inherits the attributes of the base class

    Series find(Series s[], string n){ // Function to find a series by name
        for (int i = 0; i < 29; i++) {
            if (s[i].name == n) {
                return s[i];
            }
        }
        return s[0];
    }
    string getid(){ // Getters and setters
        return id;
    }
    string getname(){
        return name;
    }
    string getlenght(){
        return lenght;
    }
    string getgenre(){
        return genre;
    }
    string getrating(){
        return rating;
    }
    string getcomments(){
        return comments;
    }
    void setrating(string r){
        rating = r;
    }
    void setcomments(string c){
        comments = c;
    }
};




int option; // Variables
string genre;
string name;
Movies f;
Movies *ptrm; // Pointers
Series *ptrs; 


int main(){ 
ifstream m; 
m.open("movies.csv"); // Open the file and change the path
string line, value;
string row[6];
int i,j;
Movies *mov = new Movies[30]; // Create an object of the class Movies
j = 0;
while (getline(m, line)){ // Read the file
    stringstream ss(line);
    i = 0;
    while (getline(ss, value, ',')){ // Split the line
        row[i] = value;
        i++;
    }
    mov[j] = Movies(row[0], row[1], row[2], row[3], row[4], row[5]); // Create an object of the class Movies
    j++;
}
m.close();

ifstream s;
s.open("series.csv"); // Open the file and change the path
Series *ser = new Series[29]; // Create an object of the class Series
j = 0;
while (getline(s, line)){ // Read the file
    stringstream ss(line);
    i = 0;
    while (getline(ss, value, ',')){ // Split the line
        row[i] = value;
        i++;
    }
    ser[j] = Series(row[0], row[1], row[2], row[3], row[4], row[5]); // Create an object of the class Series
    j++;
}
s.close();


while (option != 12){
    cout << "Select the option you want to perform: " << endl; // Menu
    cout << "1. Display all Videos" << endl;
    cout << "2. Display all Movies" << endl;
    cout << "3. Display all Movies by Genre" << endl;
    cout << "4. Search Movie by Name" << endl;
    cout << "5. Evaluate Movie" << endl;
    cout << "6. Save changes to the Movies File" << endl;
    cout << "7. Display all Series" << endl;
    cout << "8. Display all Series by Genre" << endl;
    cout << "9. Search Series by Name" << endl;
    cout << "10. Evaluate Series" << endl;
    cout << "11. Save changes to the Series File" << endl;
    cout << "12. Exit" << endl;
    if (!(cin >> option)){ // Validate the input
        cout << "The option is not valid" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    else if (option < 1 || option > 12){ 
        cout << "The option is not valid" << endl;
    }
    else
    cin.ignore();

    if (option == 1){ // Show all the videos
        cout << "Movies" << endl;
        mov[0].displaylabels();
        for (int i = 0; i < 30; i++){ // Loop to display all the movies
            mov[i].displaynames(); 
        }
        cout << endl;
        cout <<endl;
        cout << "Series" << endl;
        ser[0].displaylabels();
        for (int i = 0; i < 29; i++){ // Loop to display all the series
            ser[i].displaynames();
        }
        cout << endl;
        cout <<endl;
    }
    else if (option == 2){ // Show all the movies
        cout << "Movies" << endl;
        mov[0].displaylabels();
        for (int i = 0; i < 30; i++){ // Loop to display all the movies
             mov[i].displaynames();
            }
        cout << endl;
        cout <<endl;
    }
    else if (option == 3){ // Show all the movies by genre
        cout << "Enter the genre you want to search: ";
        cin >> genre;
        cin.ignore();
        while (genre != "Action" && genre != "Drama" && genre != "Mystery"){ // Validate the input
            cout << "The genre is not valid" << endl;
            cout << "Enter the genre you want to search: ";
            cin >> genre;
            cin.ignore();
        }
        cout << "Movies" << endl; // Display the movies
        mov[0].displaylabels();
        for (int i = 0; i < 30; i++){
            if (mov[i].getgenre() == genre){ // Loop to display the movies by genre
                mov[i].displaynames();
            }
        }
        cout << endl;
        cout <<endl;
    }
    else if (option == 4){ // Search a movie by name
        cout << "Enter the name of the movie you want to search: ";
        getline(cin, name); // Get the input
        if (mov[0].find(mov, name).getname() == name){ // Validate the input
            cout << "Movies" << endl;
            mov[0].displaylabels();
            mov[0].find(mov, name).displaynames();
        }
        else{
            cout << "The movie was not found" << endl;
        }
        cout << endl;
        cout <<endl;
    }
    else if (option == 5){ // Evaluate a movie
        cout << "Enter the name of the movie you want to evaluate: ";
        getline(cin, name); // Get the input
        ptrm = mov;
        while (ptrm[0].find(ptrm, name).getname() != name){ // Validate the input
            cout << "The movie was not found" << endl;
            cout << "Enter the name of the movie you want to evaluate: ";
            getline(cin, name);
        }
        for (int i = 0; i < 30; i++){ // Loop to evaluate the movie
            if (ptrm[i].getname() == name){
                cout << "Enter the rating: ";
                string rating;
                cin >> rating;
                cin.ignore();
                cout << "Enter the comments: ";
                string comments;
                cin >> comments;
                cin.ignore();
                ptrm[i].setrating(rating);
                ptrm[i].setcomments(comments);
            }
        }
    }
    else if (option == 6){ // Save the changes to the file
    ofstream m;
    m.open("/Users/eduardo/Library/CloudStorage/Dropbox/Programacion/C++/Object oriented Program/Final Proyect OOP/movies.csv"); // Open the file
    for (int i = 0; i < 30; i++){
        if (i < 29){ // Loop to save the changes
            m << mov[i].getid() << "," << mov[i].getname() << "," << mov[i].getgenre() << "," << mov[i].getlenght() << "," << mov[i].getrating() << "," << mov[i].getcomments() << endl;
        }
        else{
            m << mov[i].getid() << "," << mov[i].getname() << "," << mov[i].getgenre() << "," << mov[i].getlenght() << "," << mov[i].getrating() << "," << mov[i].getcomments();
        }
    }
    m.close();
    cout << "The changes were saved" << endl;
    cout << endl;
    cout <<endl;
    }
    else if (option == 7){ // Show all the series
        cout << "Series" << endl;
        ser[0].displaylabels();
        for (int i = 0; i < 29; i++){ // Loop to display all the series
            ser[i].displaynames();
        }
        cout << endl;
        cout <<endl;
    }
    else if (option == 8){ // Show all the series by genre
        cout << "Enter the genre you want to search: ";
        cin >> genre;
        cin.ignore();
        while (genre != "Action" && genre != "Drama" && genre != "Mystery"){ // Validate the input
            cout << "The genre is not valid" << endl;
            cout << "Enter the genre you want to search: ";
            cin >> genre;
            cin.ignore();
        }
        cout << "Series" << endl;
        ser[0].displaylabels(); 
        for (int i = 0; i < 29; i++){ // Loop to display the series by genre
            if (ser[i].getgenre() == genre){
                ser[i].displaynames();
            }
        }
        cout << endl;
        cout <<endl;
    }
    else if (option == 9){ // Search a series by name
        cout << "Enter the name of the series you want to search: ";
        getline(cin, name);
        if (ser[0].find(ser, name).getname() == name){ // Validate the input
            cout << "Series" << endl;
            ser[0].displaylabels();
            ser[0].find(ser, name).displaynames(); // Display the series
        }
        else{
            cout << "The series was not found" << endl;
        }
        cout << endl;
        cout <<endl;
    }
    else if (option == 10){ // Evaluate a series
        cout << "Enter the name of the series you want to evaluate: ";
        getline(cin, name);
        ptrs = ser;
        while (ptrs[0].find(ptrs, name).getname() != name){ // Validate the input
            cout << "The series was not found" << endl;
            cout << "Enter the name of the series you want to evaluate: ";
            getline(cin, name);
        }
        for (int i = 0; i < 29; i++){
            if (ptrs[i].getname() == name){ // Loop to evaluate the series
                cout << "Enter the rating: ";
                string rating;
                cin >> rating;
                cin.ignore();
                cout << "Enter the comments: ";
                string comments;
                cin >> comments;
                cin.ignore();
                ptrs[i].setrating(rating);
                ptrs[i].setcomments(comments);
            }
        }
    }
    else if (option == 11){ // Save the changes to the file
    ofstream s;
    s.open("/Users/eduardo/Library/CloudStorage/Dropbox/Programacion/C++/Object oriented Program/Final Proyect OOP/series.csv"); // Open the file
    for (int i = 0; i < 29; i++){
        if (i < 28){
            s << ser[i].getid() << "," << ser[i].getname() << "," << ser[i].getgenre() << "," << ser[i].getlenght() << "," << ser[i].getrating() << "," << ser[i].getcomments() << endl;
        }
        else{
            s << ser[i].getid() << "," << ser[i].getname() << "," << ser[i].getgenre() << "," << ser[i].getlenght() << "," << ser[i].getrating() << "," << ser[i].getcomments();
        }
    }
    s.close();
    cout << "The changes were saved" << endl;
    cout << endl;
    cout <<endl;
    }
    else if (option < 12){ 
        cout << "The option is not valid" << endl;
    }
    else if (option == 12){
        break;
    }
}

delete [] ser;
delete [] mov;
cout << "Goodbye" << endl;
return 0;
}