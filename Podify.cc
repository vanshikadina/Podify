#include "Podify.h"

Podify::~Podify(){
    for(int i=0;i<podcasts.getSize();i++){
		delete podcasts[i];
	}
}

void Podify::addPodcast(Podcast *p)
{
    podcasts+=p;
}

void Podify::addEpisode(Episode* e,const string& t){
    Podcast* podcast = getPodcast(t); // Ensure this returns a valid pointer
    if (podcast == nullptr) {
        std::cerr << "Error: Podcast not found with title: " << t << std::endl;
        return;
    }
    podcast->add(e);
}

const Array<Podcast *> &Podify::getPodcasts() const{
    return podcasts;
}

Podcast *Podify::getPodcast(int index) {
    if(index<0 || index>=podcasts.getSize()){
        cerr<<"Error: index is out of bounds"<<endl;
        exit(1);
    }
    return podcasts[index];
}

Podcast *Podify::getPodcast(const string & t){
    for(int i=0;i<podcasts.getSize();i++){
        if(podcasts[i]->equals(t)){
            return podcasts[i];
        }
    }
    cerr<<"Error: podcast with this title has not found."<<endl;
    exit(1);
}

void Podify::getEpisodes(const Search &search, Array<Episode*>& output) const{
    for(int i=0;i<podcasts.getSize();i++){
        Podcast* p=podcasts[i];
        for(int j=0;j<p->getSize();j++){
            Episode* episode = p->get(j);
            if(search.matches(episode)){
                output+=episode;
            }
        }
    }
}
