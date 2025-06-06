/****************************************************************************
Copyright (c) 2010-2012  cocos2d-x.org
Copyright (c) 2011 ForzeField Studios S.L.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#ifndef __CCMOTION_STREAK_H__
#define __CCMOTION_STREAK_H__

#include "../base_nodes/CCNode.h"
#include "../include/CCProtocols.h"
#include "../include/ccTypes.h"
#include "../textures/CCTexture2D.h"
#ifdef EMSCRIPTEN
    #include "../base_nodes/CCGLBufferedNode.h"
#endif // EMSCRIPTEN

NS_CC_BEGIN

/**
 * @addtogroup misc_nodes
 * @{
 */

/** MotionStreak.
 Creates a trailing path.
 */
class CC_DLL CCMotionStreak :
    public CCNodeRGBA,
    public CCTextureProtocol
#ifdef EMSCRIPTEN
    ,
    public CCGLBufferedNode
#endif // EMSCRIPTEN
{
    GEODE_FRIEND_MODIFY
public:
    /**
     * @js ctor
     */
    CCMotionStreak();
    GEODE_CUSTOM_CONSTRUCTOR_COCOS(CCMotionStreak, CCNodeRGBA)
    /**
     * @js NA
     * @lua NA
     */
    virtual ~CCMotionStreak();

    /** creates and initializes a motion streak with fade in seconds, minimum segments, stroke's
     * width, color, texture filename */
    static CCMotionStreak* create(
        float fade, float minSeg, float stroke, ccColor3B const& color, char const* path
    );
    /** creates and initializes a motion streak with fade in seconds, minimum segments, stroke's
     * width, color, texture */
    static CCMotionStreak* create(
        float fade, float minSeg, float stroke, ccColor3B const& color, CCTexture2D* texture
    );

    /** initializes a motion streak with fade in seconds, minimum segments, stroke's width, color
     * and texture filename */
    bool initWithFade(
        float fade, float minSeg, float stroke, ccColor3B const& color, char const* path
    );
    /** initializes a motion streak with fade in seconds, minimum segments, stroke's width, color
     * and texture  */
    bool initWithFade(
        float fade, float minSeg, float stroke, ccColor3B const& color, CCTexture2D* texture
    );

    /** color used for the tint */
    void tintWithColor(ccColor3B colors);

    /** Remove all living segments of the ribbon */
    void reset();

    /** Override super methods */
    virtual void setPosition(CCPoint const& position);
    virtual void draw();
    virtual void update(float delta);

    /* Implement interfaces */
    virtual CCTexture2D* getTexture(void);
    virtual void setTexture(CCTexture2D* texture);
    /**
     * @js NA
     */
    virtual void setBlendFunc(ccBlendFunc blendFunc);
    /**
     * @js NA
     */
    virtual ccBlendFunc getBlendFunc(void);
    virtual GLubyte getOpacity(void);
    virtual void setOpacity(GLubyte opacity);
    virtual void setOpacityModifyRGB(bool bValue);
    virtual bool isOpacityModifyRGB(void);

    // @note RobTop Addition
    void resumeStroke();
    // @note RobTop Addition
    void stopStroke();

	// @note RobTop Addition
    void enableRepeatMode(float);

	// @note RobTop Addition
    bool getDontOpacityFade() const;
	// @note RobTop Addition
    void setDontOpacityFade(bool);

	// @note RobTop Addition
    float getM_fMaxSeg() const;
	// @note RobTop Addition
    void setM_fMaxSeg(float);

    // @note RobTop Addition
	void setStroke(float);
    // @note RobTop Addition
	void updateFade(float);


    /** When fast mode is enabled, new points are added faster but with lower precision */
    inline bool isFastMode() {
        return m_bFastMode;
    }

    inline void setFastMode(bool bFastMode) {
        m_bFastMode = bFastMode;
    }

    inline bool isStartingPositionInitialized() {
        return m_bStartingPositionInitialized;
    }

    inline void setStartingPositionInitialized(bool bStartingPositionInitialized) {
        m_bStartingPositionInitialized = bStartingPositionInitialized;
    }

public:
    bool m_bFastMode;
    bool m_bStartingPositionInitialized;
    bool m_bStroke;
    /** texture used for the motion streak */
    CCTexture2D* m_pTexture;
    ccBlendFunc m_tBlendFunc;

    float m_fStroke;
    float m_fFadeDelta;
    float m_fMinSeg;

    unsigned int m_uMaxPoints;
    unsigned int m_uNuPoints;
    unsigned int m_uPreviousNuPoints;

    /** Pointers */
    CCPoint* m_pPointVertexes;
    float* m_pPointState;

    // Opengl
    ccVertex2F* m_pVertices;
    GLubyte* m_pColorPointer;
    ccTex2F* m_pTexCoords;

    // @note RobTop Addition
    bool m_bRepeatMode;
    // @note RobTop Addition
    float m_fRepeatSpeed;
    // @note RobTop Addition
    float m_fRepeatTime;
    // @note RobTop Addition
    bool m_idk;
    // @note RobTop Addition
    float m_fMaxSeg;
    // @note RobTop Addition
    bool m_bDontOpacityFade;
    // @note RobTop Addition
    CCPoint m_tPositionR;
};

// end of misc_nodes group
/// @}

NS_CC_END

#endif //__CCMOTION_STREAK_H__
