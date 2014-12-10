#ifndef TriggerReader_h
#define TriggerReader_h

#include "AppFramework/AppParameter.h"
#include "AppFramework/AppModule.h"
#include "AppFramework/AppResult.h"
#include "AppFramework/AppEvent.h"

#include "AnObjects/Trigger.h"

class TriggerReader : public AppModule {
private:
        Trigger result;

        AppResult beginJob(AppEvent& event){ return AppResult(); }
        AppResult beginRun(AppEvent& event);
        AppResult event (AppEvent& event);
        AppResult endRun(AppEvent& event){ return AppResult(); }
        AppResult endJob(AppEvent& event){ return AppResult(); }

public:
	//virtual const METCollection& getMETs(void){ return muons; }

        TriggerReader(const char *nm, const char *descr):AppModule(nm,descr){}
	virtual ~TriggerReader(void){}
};


#endif
