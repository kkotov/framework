#ifndef BasicReader_h
#define BasicReader_h

#include "AppFramework/AppParameter.h"
#include "AppFramework/AppModule.h"
#include "AppFramework/AppResult.h"
#include "AppFramework/AppEvent.h"

#include "TBranch.h"

#include "DataFormats/VertexReco/interface/Vertex.h"

class BasicReader : public AppModule {
private:
        TBranch*  brho;
        double    rho;

        TBranch*  bvtx;
        std::vector<reco::Vertex> vertices;
        double vx, vy, vz;

protected:
        AppResult beginJob(AppEvent& event);
        AppResult beginRun(AppEvent& event){ return AppResult(); }
        AppResult event (AppEvent& event);
        AppResult endRun(AppEvent& event){ return AppResult(); }
        AppResult endJob(AppEvent& event){ return AppResult(); }

public:

        BasicReader(const char *nm, const char *descr):AppModule(nm,descr){}
	virtual ~BasicReader(void){}
};


#endif
