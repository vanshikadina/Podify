#ifndef PODIFY_H
#define PODIFY_H

#include "Podcast.h"
#include "Array.h"
#include "Episode.h"
#include "Search.h"

class Podify {
    private:
        Array<Podcast*> podcasts;
    public:
        ~Podify();
        void addPodcast(Podcast*);
        void addEpisode(Episode*,const string&);
        const Array<Podcast*>& getPodcasts() const;
        Podcast* getPodcast(int index) ;
        Podcast* getPodcast(const string&);
        void getEpisodes(const Search& search,Array<Episode*>& output)const;
 };
#endif