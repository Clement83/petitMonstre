#if !defined (CoreFight_H)
#define CoreFight_H

#include "ICoreGame.h"
#include "IFightState.h"
#include <Gamebuino.h>
#include "IContexte.h"

class CoreFight : public ICoreGame
{
  public:
    virtual void Init();
    virtual void Update(Gamebuino gb, IContexte *ctx);
    virtual void Draw(Gamebuino gb, IContexte *ctx);
    virtual bool NeedChangeState();
    virtual ICoreGame * NewState();
  private:
    IFightState *currentCoreState;
};
#endif

