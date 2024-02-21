#include <iostream>

using namespace std;

template<typename  t>
struct Node
{
    t value;
    Node<t>* next;
    Node<t>* before;
    int col;
    int row;
    Node(t value){
        this->value=value;
        this->next=NULL;
        this->before=NULL;
        this->col=-1;
        this->row=-1;
    }

};

template<typename  t>
class Doubly{
private:
    typedef Node<t>* pos;
    pos first;
    pos last;
    int lenght;
public:
    Doubly();
    ~Doubly();
    int getLenght();
    Node<t>* getFirst();
    Node<t>* getLast();
    bool isEmpty();
    void Next(pos &nodo);
    void Before(pos &nodo);
    t* get(pos nodo);
    void deleteNodo(pos nodo);
    void insert(t &value,pos nodo,bool before=1){
        pos newNode= new Node<t>(value);
        if(isEmpty()){
            first=newNode;
            last=newNode;
            lenght++;
            return;
        }
        if(before){
            newNode->next=nodo;
            newNode->before=nodo->before;
            if (nodo->before!=NULL)
            {
                nodo->before->next=newNode;
            }else{
                first=newNode;
            }
            nodo->before=newNode;
            lenght++;
            return;

        }else{
        
            newNode->next=nodo->next;
            newNode->before=nodo;
            if(nodo->next != NULL){
                nodo->next->before=newNode;
            }else{
                last=newNode;
            }
            nodo->next=newNode;
            lenght++;
            return;
            
        }
    }

     //Funcion extra para la estructura
    Node<t>* getNode(int index){
        if(index <= 0 || index > this->lenght) return NULL;
        pos temp=getFirst();
        for (int i = 1; i < index; i++)
        {
            this->Next(temp);
        }
        return temp;
    }
    Node<t>* getNodeForValue(int value){
        pos temp=getFirst();
        while (temp != NULL)
        {
            if(temp->value == value) return temp;
            this->Next(temp);
        }
        
        return NULL;
    };

    bool isRepeatValue(t value){
        pos temp=this->getFirst();
        while (temp != NULL)
        {
            if(temp->value==value) return true;
            this->Next(temp);
        }
        return false;
    }

    void printVartices(){
        pos temp=getFirst();
        while (temp != NULL)
        {
            cout<<"vertice: "<<temp->value<<" index: "<<temp->row<<endl;
            this->Next(temp);
        }
        
    }

};

template<typename  t>
Doubly<t>::Doubly(){
    first=NULL;
    last=NULL;
    lenght=0;
};

template<typename  t>
Doubly<t>::~Doubly(){
    while (!(isEmpty()))
    {
        deleteNodo(getFirst());
    } 
};

template<typename  t>
Node<t>* Doubly<t>::getFirst(){
    return first;
}

template<typename  t>
Node<t>* Doubly<t>::getLast(){
    return last;
}

template<typename  t>
int Doubly<t>::getLenght(){
    return lenght;
}

template<typename  t>
bool Doubly<t>::isEmpty(){
    return lenght==0;
}

template<typename  t>
t* Doubly<t>::get(pos nodo){
    if(nodo == NULL) return NULL;
    return &nodo->value;
}

template<typename  t>
void Doubly<t>::Next(pos &nodo){
    if(nodo != NULL) nodo=nodo->next;
}

template<typename  t>
void Doubly<t>::Before(pos &nodo){
    if(nodo != NULL) nodo=nodo->before;
}

template<typename  t>
void Doubly<t>::deleteNodo(pos nodo){
    if(nodo == NULL) return;
    if(nodo== getFirst()){
        first=first->next;
        if(first != NULL)first->before=NULL;
        delete nodo;
        lenght--;
        return;
    }

    if(nodo==getLast()){
        last=last->before;
        if(last!= NULL) last->next=NULL;
        delete nodo;
        lenght--;
        return;
    }
    nodo->before->next=nodo->next;
    nodo->next->before=nodo->before;

    delete nodo;
    lenght--;

}
