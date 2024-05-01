#include <iostream>

class Node {
public:
    char name[50];
    Node* children[10];
    int childCount;

    Node(const char* name) {
        int i;
        for (i = 0; name[i] != '\0'; i++) {
            this->name[i] = name[i];
        }
        this->name[i] = '\0';
        childCount = 0;
    }

    void addChild(Node* child) {
        children[childCount++] = child;
    }

    void print(int level = 0) {
        for(int i = 0; i < level; i++)
            std::cout << " ";
        std::cout << name << std::endl;
        for(int i = 0; i < childCount; i++) {
            children[i]->print(level + 1);
        }
    }
};

int main() {
    char bookName[50];
    std::cout << "Enter the name of the book: ";
    std::cin.getline(bookName, 50);
    Node* book = new Node(bookName);

    int numChapters;
    std::cout << "Enter the number of chapters: ";
    std::cin >> numChapters;
    std::cin.ignore();

    for(int i = 0; i < numChapters; i++) {
        char chapterName[50];
        std::cout << "Enter the name of chapter " << i+1 << ": ";
        std::cin.getline(chapterName, 50);
        Node* chapter = new Node(chapterName);

        int numSections;
        std::cout << "Enter the number of sections in chapter " << i+1 << ": ";
        std::cin >> numSections;
        std::cin.ignore();

        for(int j = 0; j < numSections; j++) {
            char sectionName[50];
            std::cout << "Enter the name of section " << j+1 << " in chapter " << i+1 << ": ";
            std::cin.getline(sectionName, 50);
            Node* section = new Node(sectionName);

            int numSubsections;
            std::cout << "Enter the number of subsections in section " << j+1 << " of chapter " << i+1 << ": ";
            std::cin >> numSubsections;
            std::cin.ignore();

            for(int k = 0; k < numSubsections; k++) {
                char subsectionName[50];
                std::cout << "Enter the name of subsection " << k+1 << " in section " << j+1 << " of chapter " << i+1 << ": ";
                std::cin.getline(subsectionName, 50);
                section->addChild(new Node(subsectionName));
            }

            chapter->addChild(section);
        }

        book->addChild(chapter);
    }

    book->print();  

    return 0;
}
    