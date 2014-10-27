#if !defined (ICoreGame_H)
#define ICoreGame_H


#include "IGameObject.h"
#include <Gamebuino.h>
#include "IContexte.h"

class ICoreGame : public IGameObject
{
  public:
    virtual void Init();
    virtual void Update(Gamebuino gb, IContexte *ctx);
    virtual void Draw(Gamebuino gb, IContexte *ctx);
    virtual bool NeedChangeState();
    virtual ICoreGame * NewState();
  protected:
  	bool isChangeState;

};
#endif 

