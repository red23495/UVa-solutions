#include<bits/stdc++.h>

using namespace std;

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);

struct Book{
    string title;
    string author;
    Book(){}
    Book(string s){
        int pos = 0;
        for(int i = 1; i < s.length(); i++){
            if(s[i] == '\"'){
                pos = i;
                break;
            }
        }
        title = s.substr(0,pos+1);
        author = s.substr(pos+5);
    }
    bool operator < (Book rhs) const{
        if(author < rhs.author){
            return true;
        }else if(author == rhs.author){
            return title < rhs.title;
        }
        return false;
    }
};

map<string,int> Dictionary;

struct Container{
    Book book;
    int id;
    bool available;
    Container(Book b, int _id){
        book = b;
        id = _id;
        available = true;
        Dictionary[b.title] = _id;
    }
    void Borrow(){
        available = false;
    }
};


struct Shelve{
    vector<Container> books;
    Shelve(vector<Book> v){
        sort(v.begin(),v.end());
        for(int i = 0; i < v.size(); i++){
            books.push_back(Container(v[i],i));
        }
    }
    void Take(int id){
        books[id].Borrow();
    }
    int Before(int id){
        if(id == 0) return -1;
        int bef = id - 1;
        if(books[bef].available) return bef;
        return Before(bef);
    }

    void Place(int id){
        int bef = Before(id);
        books[id].available = true;
        if(bef == -1) cout << "Put " << books[id].book.title << " first\n";
        else cout << "Put " << books[id].book.title << " after " << books[bef].book.title << endl;
    }

    void PlaceReturnStack(vector<int>& stk){
        //cout << stk.size() << endl;
        sort(stk.begin(),stk.end());
        for(int i = 0; i < stk.size(); i++){
            Place(stk[i]);
        }
        stk.clear();
        cout << "END\n";
    }
};

vector<int> ReturnStack;

int main(){
    FASTIO
    string s;
    vector<Book> v;
    while(getline(cin,s) && s != "END"){
        v.push_back(Book(s));
    }
    Shelve shlf(v);
    while(cin >> s && s != "END"){
        while(cin.peek() == 10 || cin.peek() == ' ') cin.ignore();
        string s1;
        switch(s[0]){
        case 'B':
            getline(cin,s1);
            shlf.Take(Dictionary[s1]);
            break;
        case 'R':
            getline(cin,s1);
            ReturnStack.push_back(Dictionary[s1]);
            break;
        case 'S':
            shlf.PlaceReturnStack(ReturnStack);
            break;
        }
    }
    return 0;
}
