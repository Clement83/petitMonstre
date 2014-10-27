#if !defined (ResolutionAttack_H)
#define ResolutionAttack_H


#include "IFightState.h"
#include <Gamebuino.h>
#include "IContexte.h"


class ResolutionAttack : public IFightState
{
  public:
    virtual void Init();
    virtual void Update(Gamebuino gb, IContexte * ctx);
    virtual void Draw(Gamebuino gb, IContexte * ctx);
    virtual bool NeedChangeState();
    virtual IFightState * NewState();
  protected:
  	bool isChangeState;
  private : 
  	void ResolutionOfAttack(IContexte *ctx);
      void Attack(Monster *att, Monster *def);
      uint8_t nbFrameAnnim;
      bool attackOk;
      int8_t GetWidthBarreVie(uint8_t pourcentVie, uint8_t tailleMaxPx);

};
#endif 

