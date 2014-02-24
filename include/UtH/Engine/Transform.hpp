#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <UtH/Engine/Component.hpp>

namespace uth
{
	class Transform : public Component
	{
	public:
		Transform(const std::string name = "Transform");
		~Transform();

		void Move(umath::vector2 offset);
		void Move(float offsetX, float offsetY);

		void SetPosition(umath::vector2 position);
		void SetPosition(float posX, float posY);
		const umath::vector2 GetPosition() const;

		void SetSize(umath::vector2 size);
		void SetSize(float width, float height);
		const umath::vector2 GetSize() const;

		void SetRotation(float angle);
		float GetRotation();
		void Rotate(float angle);

		umath::matrix4& GetTransform();

		umath::vector2 position;
		umath::vector2 size;
		float angle;

	private:
		void updateTransform();

		umath::matrix4 m_modelTransform;

	};
}

#endif