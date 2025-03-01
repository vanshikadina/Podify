#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include "Episode.h"
#include "Array.h"
#include <string>

class Podcast{
    
    friend ostream& operator<<(ostream& os,const Podcast&);

    public:
        Podcast(const string&,const string&);
        ~Podcast();
        bool equals(const string&) const;
        Episode* get(int index) const;
        int getSize() const;
        void print(ostream&) const;
        void printWithEpisodes(ostream&) const;
        void add(Episode*);
    private:
        Array<Episode*> episodes;
        string title;
        string host;
};
#endif