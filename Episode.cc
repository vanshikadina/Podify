#include "Episode.h"

Episode::Episode(const string& p, const string& h, const string& e, const string & c, const string & a, const string & v):
podacastTitle(p),host(h),episodeTitle(e),category(c),audio(a),videoFile(v){}

string Episode::getPodCastTitle() const{
    return podacastTitle;
}

string Episode::getHost() const{
    return host;
}

string Episode::getEpisodeTitle() const{
    return episodeTitle;
}

string Episode::getCategory() const{
    return category;
}

string Episode::getAudio() const{
    return audio;
}

string Episode::getVideoFile() const{
    return videoFile;
}

void Episode::print(ostream & os) const{
    os<<"Podcast Title: "<<podacastTitle<<endl;
    os<<"Host: "<<host<<endl;
    os<<"Episode Title: "<<episodeTitle<<endl;
    os<<"Category: "<<category<<endl;
}

ostream& operator<<(ostream& os, const Episode & episode){
    episode.print(os);
    return os;
}