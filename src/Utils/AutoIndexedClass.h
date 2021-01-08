
#pragma once

#include <Utils/AutoIndexer.h>

namespace MOSP
{
    namespace Utils
    {
        template<class T>
        class AutoIndexedClass
        {
        protected:
            static AutoIndexer<T*> m_autoIndex;
            std::size_t m_autoIndexValue;
            AutoIndexedClass() { m_autoIndexValue = m_autoIndex.add(dynamic_cast<T*>(this)); }
            virtual ~AutoIndexedClass() { m_autoIndex.remove(m_autoIndexValue); }
        public:
            std::size_t classAutoIndexValue() const { return m_autoIndexValue; }
        };

        template<class T> AutoIndexer<T*> AutoIndexedClass<T>::m_autoIndex;
    }
}
