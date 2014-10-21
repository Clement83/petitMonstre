#if !defined (CoreExplore_H)
#define CoreExplore_H


#include "ICoreGame.h"
#include <Gamebuino.h>

class CoreExplore : public ICoreGame
{
  public:
    virtual void Init();
<<<<<<< HEAD
    virtual IContexte * Update(Gamebuino gb, IContexte *ctx);
    virtual void Draw(Gamebuino gb, IContexte *ctx);
=======
    virtual IContexte Update(Gamebuino gb, IContexte ctx);
    virtual void Draw(Gamebuino gb, IContexte ctx);
>>>>>>> origin/master
  	virtual bool NeedChangeState();
  	virtual ICoreGame * NewState();
};
#endif
