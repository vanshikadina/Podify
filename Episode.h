#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>

using namespace std;

class Episode{

    friend ostream& operator<<(ostream& os,const Episode&);

    public:
        Episode(const string&,const string&,const string&,const string&,const string&,const string&);
        string getPodCastTitle() const;
        string getHost() const;
        string getEpisodeTitle() const;
        string getCategory() const;
        string getAudio() const;
        string getVideoFile() const;
        void print(ostream&) const;

    private:
        string podacastTitle;
        string host;
        string episodeTitle;
        string category;
        string audio;
        string videoFile;
};
#endif