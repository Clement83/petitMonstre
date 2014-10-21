#if !defined (ChoiceMonster_H)
#define ChoiceMonster_H


#include "IFightState.h"
#include <Gamebuino.h>


class ChoiceMonster : public IFightState
{
  public:
    virtual void Init();
<<<<<<< HEAD
    virtual IContexte * Update(Gamebuino gb, IContexte * ctx);
=======
    virtual IContexte Update(Gamebuino gb, IContexte ctx);
>>>>>>> origin/master
    virtual void Draw(Gamebuino gb, IContexte ctx);
    virtual bool NeedChangeState();
    virtual IFightState * NewState();
  protected:
  	bool isChangeState;

};
#endif 
