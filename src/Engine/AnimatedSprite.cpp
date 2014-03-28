#include <UtH/Engine/AnimatedSprite.hpp>
#include <UtH/Platform/Debug.hpp>
#include <UtH/Engine/GameObject.hpp>
#include <UtH/Platform/HiResTimer.hpp>

using namespace uth;

AnimatedSprite::AnimatedSprite(Texture* texture, const unsigned int frames, 
	const umath::vector2 frameSize, 
	const float fps, const unsigned int firstFrame, 
	const bool reversed, const bool loop) 
	: Sprite(texture, "AnimatedSprite"),
		m_frames(frames),
		m_curFrame(firstFrame),
		m_fps(fps),
		m_firstFrame(firstFrame),
		m_reversed(reversed),
		m_loop(loop),
		m_delay(0.0f)
{
	const umath::vector2 texSize = texture->GetSize();
#ifdef _DEBUG
	if(int(texSize.x) % int(frameSize.x) != 0 || int(texSize.y) % int(frameSize.y) != 0)
	{
		WriteLog("\nBad frame size! texture(%f, %f) frame(%f, %f)", 
			texSize.x, texSize.y, frameSize.x, frameSize.y);
		assert(false);
	}
#endif
	m_frameCountX = texSize.x / frameSize.x;
	m_frameCountY = texSize.y / frameSize.y;
	AnimatedSprite(texture, frames, m_frameCountX, m_frameCountY, fps, firstFrame, reversed, loop);
}

AnimatedSprite::AnimatedSprite(Texture* texture, const unsigned int frames, 
	const unsigned int frameCountX, const unsigned int frameCountY, 
	const float fps, const unsigned int firstFrame, 
	const bool reversed, const bool loop) 
	: Sprite(texture, "AnimatedSprite"),
		m_frames(frames),
		m_curFrame(firstFrame),
		m_frameCountX(frameCountX),
		m_frameCountY(frameCountY),
		m_fps(fps),
		m_firstFrame(firstFrame),
		m_reversed(reversed),
		m_loop(loop),
		m_delay(0.0f)
{
	const int texSizeX = texture->GetSize().x;
	const int texSizeY = texture->GetSize().y;
	
#ifdef _DEBUG
	if(texSizeX % frameCountX != 0 || texSizeY % frameCountY != 0)
	{
		WriteLog("Bad texture size! (%d, %d)\n", texSizeX, texSizeY);
		assert(false);
	}
	if(frames > frameCountX * frameCountY)
	{
		WriteLog("Too many frames! (maximum frame capacity: %d)\n", frameCountX * frameCountY);
		assert(false);
	}
#endif
	// frame size in pixels
	m_frameSize.x = texSizeX / frameCountX;
	m_frameSize.y = texSizeY / frameCountY;
	// frame size in texcoord float
	m_frameSize.width = 1.0f / frameCountX;
	m_frameSize.height = 1.0f / frameCountY;
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::ChangeAnimation(int loopStartFrame, int loopFrames, 
	int startFrame, float fps, bool loop, bool reversed)
{
	
#ifdef _DEBUG
	if(loopFrames == 0)
	{
		WriteLog("0 frame animation? (frame count = 0)\n");
		assert(false);
	}
#endif
	if(startFrame < loopStartFrame)
		m_curFrame = loopStartFrame;
	else
		m_curFrame = startFrame;

	m_frames = loopFrames;
	m_firstFrame = loopStartFrame;
	m_fps = fps;
	m_loop = loop;
	m_frameCount = 0;
	m_reversed = reversed;
	genererateBuffer();
}

void AnimatedSprite::Init()
{
	ChangeAnimation(m_firstFrame,m_frames,m_firstFrame, m_fps, m_loop, m_reversed);

	const umath::vector2 size = umath::vector2(m_frameSize.x, m_frameSize.y);
	parent->transform.SetSize(size);

	testi = false;
}

void AnimatedSprite::Update(float dt)
{
	m_delay += dt;
	
	if (!m_loop)
	{
		if(m_frames == m_frameCount + 1) 
			testi = true;
	}

	if(m_delay > 1.0f / m_fps && !testi)
	{
		m_delay = 0.0f;
		m_frameCount++;

		if(!m_reversed)
		{
			m_curFrame++;
			if (m_curFrame - m_firstFrame >= m_frames)
			{
				m_curFrame -= m_frames;
			}
		}
		else
		{
			m_curFrame--;
			if(m_curFrame < m_firstFrame)
			{
				m_curFrame = m_firstFrame + m_frames;
			}
		}	
		genererateBuffer();
	}
}

void AnimatedSprite::genererateBuffer()
{
	const int X = m_curFrame % m_frameCountX;
	const int Y = m_curFrame/m_frameCountX;

	frame.left = X * m_frameSize.width;
	frame.width = m_frameSize.width;
	frame.top = 1.0f - Y * m_frameSize.height;
	frame.height = -m_frameSize.height;

	m_vertexBuffer.clear();

	m_vertexBuffer.addVertex(Vertex(
		umath::vector3(-0.5f, -0.5f, 0),
		umath::vector2(frame.left, frame.top), 
		m_color));
	m_vertexBuffer.addVertex(Vertex(
		umath::vector3(0.5f, -0.5f, 0),
		umath::vector2(frame.getRight(), frame.top), 
		m_color));
	m_vertexBuffer.addVertex(Vertex(
		umath::vector3(-0.5f, 0.5f, 0),
		umath::vector2(frame.left, frame.getBottom()), 
		m_color));
	m_vertexBuffer.addVertex(Vertex(
		umath::vector3(0.5f, 0.5f, 0),
		umath::vector2(frame.getRight(), frame.getBottom()), 
		m_color));


	m_vertexBuffer.addIndex(0);
	m_vertexBuffer.addIndex(1);
	m_vertexBuffer.addIndex(2);
	m_vertexBuffer.addIndex(1);
	m_vertexBuffer.addIndex(3);
	m_vertexBuffer.addIndex(2);
}