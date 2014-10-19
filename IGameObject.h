#if !defined (IGameObject_H)
#define IGameObject_H

#include <Gamebuino.h>

class IGameObject
{
  public:
    virtual void Init();
    virtual void Update(Gamebuino gb);
    virtual void Draw(Gamebuino gb);
};

#endif