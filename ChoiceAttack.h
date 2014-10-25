#if !defined (ChoiceAttack_H)
#define ChoiceAttack_H


#include "IFightState.h"
#include <Gamebuino.h>
#include "IContexte.h"


class ChoiceAttack : public IFightState
{
  public:
    virtual void Init();
    virtual IContexte * Update(Gamebuino gb, IContexte * ctx);
    virtual void Draw(Gamebuino gb, IContexte * ctx);
    virtual bool NeedChangeState();
    virtual IFightState * NewState();
  protected:
  	bool isChangeState;
  	bool isAttack;

};
#endif 

