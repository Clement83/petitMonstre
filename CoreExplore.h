#if !defined (CoreExplore_H)
#define CoreExplore_H


#include "ICoreGame.h"
#include <Gamebuino.h>
#include "IContexte.h"

class CoreExplore : public ICoreGame
{
  public:
    virtual void Init();
    virtual void Update(Gamebuino gb, IContexte *ctx);
    virtual void Draw(Gamebuino gb, IContexte *ctx);

  	virtual bool NeedChangeState();
  	virtual ICoreGame * NewState();
};
#endif

