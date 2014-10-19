#if !defined (ChoiceMonster_H)
#define ChoiceMonster_H


#include "IFightState.h"
#include <Gamebuino.h>


class ChoiceMonster : public IFightState
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