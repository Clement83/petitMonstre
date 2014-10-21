#if !defined (IFightState_H)
#define IFightState_H

#include <Gamebuino.h>
#include "IGameObject.h"

class IFightState : public IGameObject
{
  public:
    virtual void Init();
    virtual IContexte * Update(Gamebuino gb, IContexte *ctx);
    virtual void Draw(Gamebuino gb, IContexte *ctx);
    virtual bool NeedChangeState();
    virtual IFightState * NewState();
  protected:
  	bool isChangeState;

};
#endif 
