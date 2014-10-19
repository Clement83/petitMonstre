#if !defined (CoreGame_H)
#define CoreGame_H


#include "IGameObject.h"
#include "ICoreGame.h"
#include <Gamebuino.h>

class CoreGame : public IGameObject
{
  public:
    virtual void Init();
    virtual void Update(Gamebuino gb);
    virtual void Draw(Gamebuino gb);
  private:
  	ICoreGame *currentCoreState;// Game mode; fight mode, ....
};
#endif 
