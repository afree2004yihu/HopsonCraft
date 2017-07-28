#ifndef StateBase_H_INCLUDED
#define StateBase_H_INCLUDED

struct Camera;
class Application;
class MasterRenderer;

namespace sf
{
    class Event;
}

namespace State
{
    class Base
    {
        public:
            Base(Application& application);
            virtual ~Base() = default;

            virtual void input  (const sf::Event& e) {}
            virtual void input  (Camera& camera) = 0;

            virtual void update         (Camera& camera, float dt) = 0;
            virtual void fixedUpdate    (Camera& camera, float dt) = 0;

            virtual void draw   (MasterRenderer& renderer) = 0;

            virtual void onOpen() {}

        protected:
            Application* m_application;
    };
}

#endif // StateBase_H_INCLUDED
