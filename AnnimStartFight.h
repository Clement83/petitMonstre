#if !defined (AnnimStartFight_H)
#define AnnimStartFight_H


#include "IFightState.h"
#include <Gamebuino.h>


class AnnimStartFight : public IFightState
{
  public:
    virtual void Init();
    virtual IContexte * Update(Gamebuino gb, IContexte * ctx);
    virtual void Draw(Gamebuino gb, IContexte * ctx);

    virtual bool NeedChangeState();
    virtual IFightState * NewState();
  protected:
  	bool isChangeState;
  private:
   int nbFrameAnnim;
   bool isWhite;

};
#endif 
