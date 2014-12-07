#pragma once

#include <UtH\UtHEngine.hpp>

template<typename T, typename T2 = T>

class UpdatingText :
	public uth::Text
{
private:
	std::vector<uth::Texture*> textures;
	float size;
	int origin;
	T& obj;
	std::string textBefore;
	std::string textAfter;
public:
	UpdatingText(const std::string& textBefore, T& updateObject, const std::string& textAfter = "", const std::string& fontPath = "8bitoperator.ttf", const int fontSize = 32)
		: uth::Text("8bitoperator.ttf", fontSize),
		obj(updateObject),
		textBefore(textBefore),
		textAfter(textAfter)
	{
		std::ostringstream os;
		os << textBefore << static_cast<T2>(obj) << textAfter;
		SetText(os.str());
		SetOrigin(7);
	}

	UpdatingText* SetOrigin(const int originPoint)
	{
		origin = originPoint;
		return this;
	}

	void Update(float) override
	{
		std::ostringstream os;
		os << textBefore << static_cast<T2>(obj) << textAfter;
		SetText(os.str());
		parent->transform.SetOrigin(origin);
	}
};

