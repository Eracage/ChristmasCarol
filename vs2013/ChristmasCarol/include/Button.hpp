#ifndef BUTTON_H
#define BUTTON_H 

#include <UtH/UtHEngine.hpp>

class Button : public uth::Component
{
public:
	typedef std::function<void()> voidFunc;

	Button(voidFunc onPressFunc, voidFunc onHoverFunc = [](){}, voidFunc notContainedFunc = [](){});
	~Button();
	void Init() override;
	void Update(float dt) override;
private:
	voidFunc m_pressFunc, m_hoverFunc, m_notContained;
};


#endif
