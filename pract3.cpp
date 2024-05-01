#include <iostream>
using namespace std;

const int MAX_CHAPTERS = 100;
const int MAX_SECTIONS = 100;
const int MAX_SUBSECTIONS = 100;

class Node {
public:
    char name[20];
    int cnt;
    Node* ptr[MAX_CHAPTERS];

    Node() {
        cnt = 0;
        for(int i = 0; i < MAX_CHAPTERS; i++) {
            ptr[i] = nullptr;
        }
    }
};

void create() {
    Node* book = new Node;
    cout << "Enter the name of the book: ";
    cin >> book->name;
    cout << "Enter the count of the chapters: ";
    cin >> book->cnt;
    for (int i = 0; i < book->cnt; i++) {
        book->ptr[i] = new Node;
        cout << "Enter the name of the chapter ("<<i+1<<") :";
        cin >> book->ptr[i]->name;
        cout << "Enter the count of the sections: ";
        cin >> book->ptr[i]->cnt;
        for (int j = 0; j < book->ptr[i]->cnt; j++) {
            book->ptr[i]->ptr[j] = new Node;
            cout << "Enter the name of section ("<<j+1<<") :";
            cin >> book->ptr[i]->ptr[j]->name;
            cout << "Enter the count of subsections: ";
            cin >> book->ptr[i]->ptr[j]->cnt;
            for (int k = 0; k < book->ptr[i]->ptr[j]->cnt; k++) {
                book->ptr[i]->ptr[j]->ptr[k] = new Node;
                cout << "Enter the name of subsection("<<k+1<<") :";
                cin >> book->ptr[i]->ptr[j]->ptr[k]->name;
            }
        }
    }
    // Display the book structure
    for (int i = 0; i < book->cnt; i++) {
        cout << "\nChapter :"<<i+1<<" Name :"<<book->ptr[i]->name;
        int seccnt=book->ptr[i]->cnt;
        for (int j = 0; j < seccnt; j++) {
            cout << "\nSection :"<<j+1<<" Name :"<<book->ptr[i]->ptr[j]->name;
            int subseccnt=book->ptr[i]->ptr[j]->cnt;
            for (int k = 0; k <subseccnt; k++) {
                cout << "\nSubsection:"<<k+1<<" Name :"<<book->ptr[i]->ptr[j]->ptr[k]->name<<endl;
            }
        }
    }
}

int main() {
    create();
    return 0;
}
