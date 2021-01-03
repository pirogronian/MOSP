
#pragma once

#include <cassert>
#include <limits>
#include <vector>
#include <Corrade/Utility/Debug.h>

namespace MOSP
{
    namespace Utils
    {
        template<class VType>
        class AutoIndexer
        {
        public:
            static constexpr std::size_t InvalidIndex = std::numeric_limits<std::size_t>::max();
        protected:
            std::vector<VType*> m_vector;
            std::size_t m_firstFreeSlot{InvalidIndex};
            std::size_t m_freeSlots{0};

            bool m_unique{false};

            void updateFirstFreeSlot()
            {
                assert(m_freeSlots > 0);
                --m_freeSlots;
                if (m_freeSlots == 0)
                {
                    m_firstFreeSlot = InvalidIndex;
                    return;
                }
                for(std::size_t i = m_firstFreeSlot + 1; i < m_vector.size(); i++)
                    if (m_vector[i] == nullptr)
                    {
                        m_firstFreeSlot = i;
                        return;
                    }
                assert(("Cannot find free slot, while its number is not zero!", false));
            }
        public:
            std::size_t firstFreeSlot() const { return m_firstFreeSlot; }
            std::size_t freeSlots() const { return m_freeSlots; }
            std::size_t size() const { return m_vector.size(); }
            bool unique() const { return m_unique; }
            void setUnique(bool u) { m_unique = u; }
            bool contains(std::size_t i) const
            {
                return i < m_vector.size() && m_vector[i] != nullptr;
            }
            std::size_t indexOf(const VType *v) const
            {
                for(int i = 0; i < m_vector.size(); i++)
                    if (m_vector[i] == v)  return i;
                return InvalidIndex;
            }
            std::size_t add(VType *v)
            {
                if (m_unique && indexOf(v) != InvalidIndex)  return InvalidIndex;

                if (m_firstFreeSlot != InvalidIndex)
                {
                    auto i = m_firstFreeSlot;
                    m_vector[i] = v;
                    updateFirstFreeSlot();
                    return i;
                }
                else
                {
                    m_vector.push_back(v);
                    return m_vector.size() - 1;
                }
                assert(("Should not be there!", false));
            }
            bool remove(std::size_t i)
            {
                if (contains(i))
                {
                    if (i == m_vector.size() - 1)
                    {
                        m_vector[i] = nullptr;
                        m_vector.resize(i);
                    }
                    else
                    {
                        m_vector[i] = nullptr;
                        ++m_freeSlots;
                        if (m_firstFreeSlot == InvalidIndex || m_firstFreeSlot > i)
                            m_firstFreeSlot = i;
                    }
                    return true;
                }
                return false;
            }
            VType *get(std::size_t i) const
            {
                return m_vector[i];
            }
        };
        template<class VType>
        Corrade::Utility::Debug& operator<<(Corrade::Utility::Debug& out, const AutoIndexer<VType>& ai)
        {
            out << "Size:" << ai.size() << "\nFirs free slot:" << ai.firstFreeSlot() << "\nFreeSlots:" << ai.freeSlots() << "\n";
            if (ai.size() > 0)
            {
                for(size_t i = 0; i < ai.size(); i++)
                    out << "[" << i << "] => " << ai.get(i) << "\n";
            }
        }
    }
}
