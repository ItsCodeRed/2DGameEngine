#include "Component.h"

void Component::Start()
{
	entity = dynamic_cast<Entity*>(parent);
}
