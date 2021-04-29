#include "scene.h"

Scene::Scene()
{
    m_pNextScene = nullptr;
}

Scene::~Scene()
{
    if (m_pNextScene != nullptr)
    {
        delete m_pNextScene;
        m_pNextScene = nullptr;
    }
}

std::string Scene::getFilename()
{
    return m_filename;
}

void Scene::setFilename(std::string value)
{
    m_filename = value;
}

Scene* Scene::getNext()
{
    return m_pNextScene;
}

void Scene::setNext(Scene *value)
{
    m_pNextScene = value;
}
