#if !defined (CoreGame_H)
#define CoreGame_H


#include "IGameObject.h"
#include "ICoreGame.h"
#include <Gamebuino.h>

class CoreGame : public IGameObject
{
  public:
    virtual void Init();
    virtual IContexte * Update(Gamebuino gb, IContexte *ctx);
    virtual void Draw(Gamebuino gb, IContexte *ctx);
  private:
  	ICoreGame *currentCoreState;// Game mode; fight mode, ....
};
#endif 
