
#include "Object.h"

using namespace MOSP::SceneGraph;

Object::~Object()
{
    m_indexer.remove(m_id);
}

MOSP::Utils::AutoIndexer<Object> Object::m_indexer;

