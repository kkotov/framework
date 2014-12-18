#ifndef Analyser_h
#define Analyser_h
#include "AppFramework/AppParameter.h"
#include "AppFramework/AppModule.h"
#include "AppFramework/AppResult.h"
#include "AppFramework/AppEvent.h"

class Analyser : public AppModule{
private:
    int    run, evt, etr, pfmet170;
    int    numberOfJets, numberOfRecMuons, numberOfGenMuons, numberOfRecElectrons, numberOfGenElectrons;
    double jetPtRec[4], jetEtaRec[4], jetPhiRec[4], jetCSV[4];
    double muPtRec [4], muEtaRec [4], muPhiRec [4], muPfIso[4];
    double muPtGen [4], muEtaGen [4], muPhiGen [4];
    double  wPtGen    ,  wEtaGen    ,  wPhiGen    ;
    double  tPtGen    ,  tEtaGen    ,  tPhiGen    ;
    double  ePtRec [4],  eEtaRec [4],  ePhiRec [4],  ePfIso[4];
    double m3jets, m2jets, met;
    double ZpT, diMuPtRec, diMuPtGen;

    AppResult beginJob(AppEvent& event);
    AppResult beginRun(AppEvent& event){ return AppResult(); }
    AppResult endRun  (AppEvent& event){ return AppResult(); }
    AppResult endJob  (AppEvent& event);

    AppResult event (AppEvent& event);

public:
    Analyser(const char *nm, const char *descr):AppModule(nm,descr){}
    virtual ~Analyser(void){}
};

#endif
