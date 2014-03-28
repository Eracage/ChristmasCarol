#pragma once
#ifndef RENDERTEXTURE_H_UTH
#define RENDERTEXTURE_H_UTH

#include <UtH/Renderer/RenderTarget.hpp>
#include <UtH/Renderer/Texture.hpp>

namespace uth
{

    class RenderTexture : public RenderTarget
    {
    public:

        RenderTexture();

        ~RenderTexture();


        bool Initialize(const umath::vector2& size, const bool depthBuffer = false);

        umath::vector2 GetSize() const override;

        Texture& GetTexture();

        void Update() const;

    private:

        bool bind() override;

        Texture m_texture;
        unsigned int m_frameBuffer,
                     m_depthBuffer;

    };
}

#endif