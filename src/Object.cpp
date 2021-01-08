
#include <Magnum/BulletIntegration/Integration.h>

#include "Object.h"

using namespace MOSP;

Object::~Object()
{
    m_indexer.remove(m_id);
}

MOSP::Utils::AutoIndexer<Object> Object::m_indexer;

