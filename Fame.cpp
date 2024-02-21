#include <iostream>
#include <fstream>
#include "Estructuras/Doubly.h"
//lista doblemente enlazada
using namespace std;

class Dirt_Roads
{
private:
    int len_dungueons;
    int power_aventurer;
    int len_conections;
    Doubly<int> Dungeons;
    int** roads;
public:
    Dirt_Roads(/* args */){
        this->len_conections=0;
        this->power_aventurer=0;
        this->len_dungueons=0;
    }
    ~Dirt_Roads(){
        this->deleteRoads();
    }

    int getLenDungeons(){
        return this->len_dungueons;
    }

    void setLenDungeons(int value){
        this->len_dungueons=value;
    }

    int getPowerAventurer(){
        return this->power_aventurer;
    }

    void setPowerAventurer(int value){
        this->power_aventurer=value;
    }

    int getLenConections(){
        return this->len_conections;
    }

    int setLenConections(int value){
        this->len_conections=value;
    }

    void createRoads(int n){
        this->roads= new int*[n];
        for (int i = 0; i < n; i++){
            this->roads[i]=new int[n];
            for (int j = 0; j < n; j++){
                this->roads[i][j]=0;
            } 
        }
    }

    void deleteRoads(){
        for (int i = 0; i < this->getLenDungeons(); i++)
        {
            delete[] this->roads[i];
        }
        delete[] this->roads;
    }

    void setRoadsValue(int row,int col,int value){
        this->roads[row][col]=value;
    }

    int getRoadsValue(int row,int col){
        return this->roads[row][col];
    }

    void inputFill(int &index,ifstream &file,int &res){
            int input;
            file>>input;
            res=input;
            if(!(this->Dungeons.isRepeatValue(input))){
                this->Dungeons.insert(input,this->Dungeons.getLast(),0);
                this->Dungeons.getLast()->row=index;
                this->Dungeons.getLast()->col=index;
                index++;
            }

    }

    void inputGraph(string name){
        ifstream file(name.c_str());
        int input,arg,index=0,n=-1,m=-1;
    
        if (file.is_open())
        {

           if (!(file.eof()))
           {
                file>>input;
                this->setLenDungeons(input);
                file>>input;
                this->setPowerAventurer(input);
                file>>input;
                this->setLenConections(input);
                this->createRoads(this->getLenDungeons());
                
                for (int i = 0; i < this->getLenConections(); i++)
                {
                    this->inputFill(index,file,n);  
                    this->inputFill(index,file,m);
                    file>>input;
                    this->setRoadsValue(this->Dungeons.getNodeForValue(n)->row,this->Dungeons.getNodeForValue(m)->col,input);
                }
           }
           
            file.close();
        }
        
    }

    void printRoads(){
        this->Dungeons.printVartices();
        for (int i = 0; i < getLenDungeons(); i++)
        {
            for (int j = 0; j < getLenDungeons(); j++)
            {
                cout<<getRoadsValue(i,j)<<" ";
            }
            cout<<endl;
        }
        
    }
    
};

    


int main(int argc, char const *argv[])
{
    Dirt_Roads A;
    string a="output.txt";
    A.inputGraph(a);
    A.printRoads();
  
    return 0;
}
