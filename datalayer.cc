#include "datalayer.hh"

using namespace std;

extern vector<Robot *> robotList;

Datalayer::Datalayer(int l, int w):length(l),width(w){
    layer=new int*[w+1];
    for(int i=0; i<=w;i++){
        layer[i]=new int[l+1];
    }
    for(int i=1; i<l; i++){                      //mark the boundary!
        layer[0][i-1]=1000;
        layer[w-1][i]=3000;
    }
    for(int i=1; i<w; i++){
        layer[i][0]=4000;
        layer[i-1][l-1]=2000;
    }
    for(int i=1; i<l-1; i++)
        for(int j=1; j<w-1; j++)
            layer[j][i]=0;
}

Datalayer::~Datalayer(){
    delete [] layer;
}

void Datalayer::changeLen(int l){
    length=l;
}

void Datalayer::changeWid(int w){
    width=w;
}

int Datalayer::getLength() const{
    return length;
}

int Datalayer::getWidth() const{
    return width;
}

void Datalayer::clearData(){
    for(int i=1; i<length-1; i++)
        for(int j=1; j<width-1; j++)
            layer[j][i]=0;
    for(int i=1; i<length; i++){                      //mark the boundary!
        layer[0][i-1]=1000;
        layer[width-1][i]=3000;
    }
    for(int i=1; i<width; i++){
        layer[i][0]=4000;
        layer[i-1][length-1]=2000;
    }
}

void Datalayer::loadData(){

    for(auto i=robotList.begin();i<robotList.end();i++){
        vector<int> detect;
        double r=(*i)->getAlert();
        for(int x=(*i)->getX()-r;x<=(*i)->getX()+r;x++)
            for(int y=(*i)->getY()-sqrt(r*r-(x-(*i)->getX())*(x-(*i)->getX()));
                y<=(*i)->getY()+sqrt(r*r-(x-(*i)->getX())*(x-(*i)->getX()));y++)
            {
                if(y>=0&&y<400&&x>=0&&x<400)
                if(layer[y][x]==0)
                    layer[y][x]=(*i)->getID()*10+1;
                else{
                    int j;
                    for(j=0; j<detect.size();j++)
                    {
                        if(layer[y][x]==detect[j]) break;
                    }
                    if(j==detect.size()){
                        (*i)->capture(layer[y][x]/10);
                        detect.push_back(layer[y][x]/10);
                    }
                }
            }
    }
    for(auto i=robotList.begin();i<robotList.end();i++){
        double r=(*i)->getRadius();
        for(int x=(*i)->getX()-r;x<=(*i)->getX()+r;x++)
            for(int y=(*i)->getY()-sqrt(r*r-(x-(*i)->getX())*(x-(*i)->getX()));
                y<=(*i)->getY()+sqrt(r*r-(x-(*i)->getX())*(x-(*i)->getX()));y++)
                if(y>=0&&y<400&&x>=0&&x<400)
                layer[y][x]=(*i)->getID()*10+1;
    }
}
