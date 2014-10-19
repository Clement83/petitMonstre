#if !defined (CoreExplore_H)
#define CoreExplore_H


#include "ICoreGame.h"
#include <Gamebuino.h>

class CoreExplore : public ICoreGame
{
  public:
    virtual void Init();
    virtual void Update(Gamebuino gb);
    virtual void Draw(Gamebuino gb);
  	virtual bool NeedChangeState();
  	virtual ICoreGame * NewState();
};
#endif
