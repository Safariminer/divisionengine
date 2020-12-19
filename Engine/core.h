#ifndef _CORE_H_
#define _CORE_H_

#include "actor.h"
#include "hashtable.h"

#define VECTOR3(X, Y, Z) (vector3) { X, Y, Z }

actor *FindActorByName(const char *name)
{
    nlist *np = lookup(name);
    if (np == NULL) return NULL;
    return vector_get(_UER_Actors, np->gameObjectIndex);
}

void SetActiveCamera(actor *camera)
{
    if (camera != NULL && camera->type == Camera)
    {
        _UER_ActiveCamera = camera;
    }
}

actor *Instantiate(actor *other)
{
    if (other == NULL) return NULL;

    actor *clonedActor = (actor *)malloc(sizeof(actor));
    if (clonedActor)
    {
        memcpy(clonedActor, other, sizeof(*clonedActor));

        vector_add(_UER_Actors, clonedActor);

        return clonedActor;
    }

    return NULL;
}

#endif
