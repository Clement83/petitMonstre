#if !defined (Player_H)
#define Player_H

#include "IGameObject.h"
#include <Gamebuino.h>

class Player : public IGameObject
{
  public:
    virtual void Init();
    virtual IContexte * Update(Gamebuino gb, IContexte *ctx);
    virtual void Draw(Gamebuino gb, IContexte *ctx);
};

#endif