#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include "Episode.h"


class Search{
    public:
     // Virtual destructor to ensure proper cleanup of derived class objects
        virtual ~Search() = default;
        virtual bool matches(const Episode*) const=0;
        virtual void print(ostream& ost) const=0; 

        // Overloaded stream insertion operator
        friend std::ostream& operator<<(std::ostream& os, const Search& search) {
            search.print(os); // Use polymorphism to call the appropriate print function
            return os;
        }
};

class H_Search: public virtual Search{
    public:
        H_Search(const string& h):host(h){};

        virtual bool matches(const Episode* ep) const{
            if (ep) {
                return ep->getHost() == host; // Compare host with the member variable
            }
            return false;
        }

        virtual void print(ostream& ost) const{
            ost << "Search By Host: "<<host<<endl;
        }
    private:
        string host;
};

class C_Search: public virtual Search{
    public:
        C_Search(const string& c):category(c){};
        virtual bool matches(const Episode* ep) const{
            if (ep) {
                return ep->getCategory() == category; // Compare host with the member variable
            }
            return false;
        }
        virtual void print(ostream& ost) const{
            ost << "Search By Category: "<<category<<endl;
        }
    private:
        string category;
};


class HorC_Search:public H_Search,public C_Search{    
    public:
        HorC_Search(const string& h,const string& c):host(h),category(c),H_Search(h),C_Search(c){};
        virtual bool matches(const Episode* ep) const{
            if(ep){
                return ep->getHost()==host || ep->getCategory()==category;
            }
            return false;
        }
        virtual void print(ostream& ost) const{
            ost << "Matches an Episode with host: " << host<< " or category: " << category;
        }
    private:
        string category;
        string host;
};

#endif

