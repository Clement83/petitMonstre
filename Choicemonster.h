#if !defined (ChoiceMonster_H)
#define ChoiceMonster_H


#include "IFightState.h"
#include <Gamebuino.h>
#include "IContexte.h"


class ChoiceMonster : public IFightState
{
  public:
    virtual void Init();
    virtual IContexte * Update(Gamebuino gb, IContexte * ctx);
    virtual void Draw(Gamebuino gb, IContexte * ctx);
    virtual bool NeedChangeState();
    virtual IFightState * NewState();
  protected:
  	bool isChangeState;

};
#endif 
