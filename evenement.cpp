//
// Created by lunde on 2020/11/1.
//

#include<sstream>
#include "evenement.h"


using namespace TIME;
using namespace std;

ostream& operator<<(ostream& f, const Evt& e){
    e.afficher(f);
    return f;
}

void Agenda::afficher(std::ostream& f) const {

    for(vector<Evt *>::const_iterator it = events.begin() ;
        it != events.end() ;
        it++) {
        (*it)->afficher(f);
    }

}

Evt1j* Evt1j::clone() const { return new Evt1j(*this); }
Evt1jDur* Evt1jDur::clone() const { return new Evt1jDur(*this); }
Rdv* Rdv::clone() const { return new Rdv(*this); }
EvtPj* EvtPj::clone() const { return new EvtPj(*this); }


Agenda& Agenda::operator<<(Evt& e) {
    events.push_back(e.clone());
    return *this;
}

Agenda::~Agenda() {
    for (unsigned int i = 0; i < events.size(); i++) delete events[i];
}


std::string Evt1j::toString() const{
    std::stringstream f;
    f<<"***** Evt ********"<<"\n";
    f<<"Date="<<getDate()<<" objet="<<getDescription()<<"\n";
    return f.str();
}
std::string Evt1jDur::toString() const{
    std::stringstream f;
    f<<Evt1j::toString()<<"debut="<<debut<<" duree="<<duree<<"\n";
    return f.str();
}
std::string Rdv::toString() const{
    std::stringstream f;
    f<<Evt1jDur::toString()<<"personne="<<personne<<" lieu="<<lieu<<"\n";
    return f.str();
}

std::string TIME::EvtPj::toString() const{
    std::stringstream f;
    f<<"***** Evt ********"<<"\n";
    f<<"Date debut="<<getDateDebut()<<" Date fin="
     <<getDateFin()<<" objet="<<getDescription()<<"\n";
    return f.str();
}
