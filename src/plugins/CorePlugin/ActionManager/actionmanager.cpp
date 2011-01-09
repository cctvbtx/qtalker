#include "actionmanager.h"
#include "../uniqueidmanager.h"
#include "menuactioncontainer.h"
#include "menubaractioncontainer.h"
#include "action.h"
using namespace CorePlugin;
ActionManager* ActionManager::m_instance = 0;
ActionManager::ActionManager()
{
}
IActionContainer* ActionManager::createMenu(const ID &id)
{
    if(UniqueIDManager::instance()->hasUID(id))
    {
        qWarning()<<QObject::tr("%1 UID Already Have").arg(id);
        return 0;
    }
    UniqueIDManager::instance()->insertUID(id);
    IActionContainer* container = new MenuActionContainer(id,0);
    this->m_containers.insert(
            UniqueIDManager::instance()->getUID(id),
            container
            );
    return container;
}
IActionContainer* ActionManager::createMenuBar(const ID &id)
{
    if(UniqueIDManager::instance()->hasUID(id))
    {
        qWarning()<<QObject::tr("%1 UID Already Have").arg(id);
        return 0;
    }
    UniqueIDManager::instance()->insertUID(id);
    IActionContainer* container = new MenuBarActionContainer(id,0);
    this->m_containers.insert(
            UniqueIDManager::instance()->getUID(id),
            container
            );
    return container;
}
void ActionManager::init()
{
    static ActionManager man;
    m_instance= &man;
}
Action* ActionManager::createAction(const ID &id)
{
    UniqueIDManager* man = UniqueIDManager::instance();
    if(man->hasUID(id))
    {
        qWarning()<<QObject::tr("%1 UID Already Have").arg(id);
        return 0;
    }
    man->insertUID(id);
    Action* act = new Action(id);
    this->m_actions.insert(
            man->getUID(id),
            act
            );
    return act;
}