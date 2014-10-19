#if !defined (IFightState_H)
#define IFightState_H

#include <Gamebuino.h>
#include "IGameObject.h"

class IFightState : public IGameObject
{
  public:
    virtual void Init();
    virtual void Update(Gamebuino gb);
    virtual void Draw(Gamebuino gb);
    virtual bool NeedChangeState();
    virtual IFightState * NewState();
  protected:
  	bool isChangeState;

};
#endif 
