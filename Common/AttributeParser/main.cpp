#include <iostream>

using namespace std;

int main()
{
    int n;
    int q;

    scanf("%d %d", &n, &q);

    return 0;
}

class Attribute{
    public :
        string name;
        string value;

    Attribute(string name, string value){
        this->name = name;
        this->value = value;
    }
};

class Tag{
private:
    Attribute* attributes;
    Tag* nextTag;

public:
    Tag(Attribute* attributes){
        this->attributes = attributes;
    }

    static Tag ParseTag(string input){

    }
};

class TagStack{
private:
    Tag *tags;
    int capacity;
    int offset;

    ExpandCapacity(){
        this->capacity =  2 * capacity;
        Tag *newTags = (Tag*) malloc (capacity);;

        std::copy(this->tags, this->tags + offset, newTags);
        free(tags);

        this->tags = newTags;
    }

public:
    TagStack(int capacity){
        tags = new Tag[capacity];
        offset = 0;
        this->capacity = capacity;
    }

    TagStack(){
        TagStack(8);
    }

    Add(Tag attr){
        tags[offset++] = attr;

        if(offset == capacity){
            ExpandCapacity();
        }
    }

    int GetCount(){
        return this->offset;
    }

    Tag GetAttribute(int position){
        if(position >= this->offset || position < 0){
             throw std::invalid_argument("Position must be in valid range!");
        }

        return this->tags[position];
    }

};
