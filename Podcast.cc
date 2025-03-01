#include "Podcast.h"

Podcast::Podcast(const string & t, const string & h):title(t),host(h){}

Podcast::~Podcast(){
    for(int i=0;i<episodes.getSize();i++){
		delete episodes[i];
	}
}

bool Podcast::equals(const string &t) const{
    return t==title;
}

Episode* Podcast::get(int index) const{
    if(index<0 || index>=episodes.getSize()){
        cerr<<"Podcast: Out of Bounds"<<endl;
        exit(1);
    }
    return episodes[index];
}

int Podcast::getSize() const{
    return episodes.getSize();
}

void Podcast::print(ostream &os) const{
    os<<"Title: "<<title<<endl;
    os<<"Host: "<<host<<endl<<endl;
}

void Podcast::printWithEpisodes(ostream& os) const{
    print(os);
    for(int i=0;i<episodes.getSize();i++){
        episodes[i]->print(os);
        os<<endl<<endl;
    }
}

void Podcast::add(Episode* e){
    episodes+=e;
}

ostream& operator<<(ostream& os, const Podcast& podcast){
    podcast.print(os);
    return os;
}
