#ifndef PODCASTPLAYER_H
#define PODCASTPLAYER_H

#include "Episode.h"
#include <fstream>

class PodcastPlayer{
    public:
        virtual ~PodcastPlayer() = default;
        virtual void play(const Episode& m,ostream& ost) const=0;
};

class AudioPlayer:public PodcastPlayer{
    public:
        virtual void play(const Episode& m,ostream& ost) const{
            ost << "Playing Audio: " << m.getAudio() << endl;
        }
};

class VideoPlayer:public AudioPlayer{
    public:
        virtual void play(const Episode& m,ostream& ost) const{
            AudioPlayer::play(m, ost);
            // Open and read the video file
            ifstream videoFile(m.getVideoFile());
            if (!videoFile.is_open()) {
                ost << "Error: Unable to open video file: " << m.getVideoFile() << endl;
                return;
            }

            ost << "Playing Video from file: " << m.getVideoFile() << endl;

            string line;
    
            while (getline(videoFile, line)) {
                ost << line << endl;
            }

            videoFile.close();
        }
};

#endif