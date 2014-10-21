#if !defined (IGameObject_H)
#define IGameObject_H

#include <Gamebuino.h>
#include "IContexte.h"

class IGameObject
{
  public:
    virtual void Init();
    virtual IContexte * Update(Gamebuino gb, IContexte *ctx);
    virtual void Draw(Gamebuino gb, IContexte *ctx);
};

#endif