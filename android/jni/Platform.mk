LOCAL_PATH := $(call my-dir)
SRC_PATH := ../../src/

include $(CLEAR_VARS)

LOCAL_MODULE    := engine
LOCAL_STATIC_LIBRARIES := android_native_app_glue engine
LOCAL_SHARED_LIBRARIES := libopenal
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../include/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../extlibs/openal/include/

#Math
LOCAL_SRC_FILES := \
$(SRC_PATH)Math/Matrix3.cpp \
$(SRC_PATH)Math/Matrix4.cpp \
$(SRC_PATH)Math/Vector2.cpp \
$(SRC_PATH)Math/Vector3.cpp \
$(SRC_PATH)Math/Vector4.cpp \
$(SRC_PATH)Math/Rectangle.cpp

#Audio
LOCAL_SRC_FILES += \
$(SRC_PATH)Audio/Audio.cpp \
$(SRC_PATH)Audio/Sound.cpp \
$(SRC_PATH)Audio/SoundManager.cpp

#Renderer
LOCAL_SRC_FILES += \
$(SRC_PATH)Renderer/Camera.cpp \
$(SRC_PATH)Renderer/Texture.cpp

#Resources
LOCAL_SRC_FILES += \
$(SRC_PATH)Resources/ResourceManager.cpp

#Platform
LOCAL_SRC_FILES += \
$(SRC_PATH)Platform/Android/FileReader.cpp \
$(SRC_PATH)Platform/Graphics.cpp \
$(SRC_PATH)Platform/HiResTimer.cpp \
$(SRC_PATH)Platform/OGLCheck.cpp \
$(SRC_PATH)Platform/Window.cpp \
$(SRC_PATH)Platform/Android/AndroidWindowImpl.cpp \
$(SRC_PATH)Platform/Input.cpp \
$(SRC_PATH)Platform/Common/InputBase.cpp \
$(SRC_PATH)Platform/Android/InputTouch.cpp

#Core
LOCAL_SRC_FILES += \
$(SRC_PATH)Core/Shader.cpp \
$(SRC_PATH)Core/VertexBuffer.cpp

#Engine
LOCAL_SRC_FILES += \
$(SRC_PATH)Engine/Component.cpp \
$(SRC_PATH)Engine/GameObject.cpp \
$(SRC_PATH)Engine/DefaultScene.cpp \
$(SRC_PATH)Engine/Scene.cpp \
$(SRC_PATH)Engine/SceneManager.cpp \
$(SRC_PATH)Engine/Sprite.cpp \
$(SRC_PATH)Engine/UtHEngine.cpp \
$(SRC_PATH)Engine/Transform.cpp

include $(BUILD_STATIC_LIBRARY)
