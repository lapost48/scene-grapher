#ifndef SCENE_H
#define SCENE_H

#include <string>


class Scene
{   
public:
    Scene();
    ~Scene();

    void setFilename(std::string value);
    std::string getFilename();

    Scene* getNext();
    void setNext(Scene* value);

private:
    std::string m_filename;
    Scene* m_pNextScene;
};

#endif // SCENE_H
