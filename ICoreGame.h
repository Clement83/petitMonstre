#if !defined (ICoreGame_H)
#define ICoreGame_H


#include "IGameObject.h"
#include <Gamebuino.h>

class ICoreGame : public IGameObject
{
  public:
    virtual void Init();
    virtual void Update(Gamebuino gb);
    virtual void Draw(Gamebuino gb);
    virtual bool NeedChangeState();
    virtual ICoreGame * NewState();
  protected:
  	bool isChangeState;

};
#endif 
