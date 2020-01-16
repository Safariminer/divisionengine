#include "Action.h"

namespace UltraEd
{
    CAction::CAction() :
        m_actions(),
        m_position(0)
    { }

    void CAction::Undo()
    {
        if (m_position > 0)
        {
            m_position--;
            m_actions[m_position][0]();
        }
    }

    void CAction::Redo()
    {
        if (m_position < m_actions.size())
        {
            m_actions[m_position][1]();
            m_position++;
        }
    }

    void CAction::Add(function<void()> undo, function<void()> redo)
    {
        // Clear redo history when adding new action and not at head.
        while (m_actions.size() != m_position)
        {
            m_actions.pop_back();
        }

        m_actions.push_back({ undo, redo });
        m_position = m_actions.size();
    }
}