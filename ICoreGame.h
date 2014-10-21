#if !defined (ICoreGame_H)
#define ICoreGame_H


#include "IGameObject.h"
#include <Gamebuino.h>

class ICoreGame : public IGameObject
{
  public:
    virtual void Init();
    virtual IContexte * Update(Gamebuino gb, IContexte *ctx);
    virtual void Draw(Gamebuino gb, IContexte *ctx);
    virtual bool NeedChangeState();
    virtual ICoreGame * NewState();
  protected:
  	bool isChangeState;

};
#endif 
