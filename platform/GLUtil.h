/*
 * ===========================================================================
 *
 *       Filename:  GLUtil.h
 *
 *    Description:  GL utilities and definitions
 *
 *        Version:  1.0
 *        Created:  08/12/2010 06:07:01 PM
 *
 *         Author:  Will Dietz (WD), w@wdtz.org
 *        Company:  dtzTech
 *
 * ===========================================================================
 */

#ifndef _GL_UTIL_H_
#define _GL_UTIL_H_

#include <SDL.h>
#include <SDL_opengles.h>
#include "Types.h"

extern void GL_Init();
extern void GL_InitTexture();
extern void updateOrientation();
extern void SDL_DrawSurfaceAsGLTexture( SDL_Surface * s, float * coords );

/*-----------------------------------------------------------------------------
 *  GL variables
 *-----------------------------------------------------------------------------*/
extern GLuint texture;
extern GLuint controller_tex ;

// Handle to a program object
extern GLuint programObject;

// Attribute locations
extern GLint  positionLoc;
extern GLint  texCoordLoc;

// Sampler location
extern GLint samplerLoc;

extern float portrait_vertexCoords[];
extern float land_l_vertexCoords[];
extern float land_r_vertexCoords[];

extern void GL_Init();
extern void GL_InitTexture(int w, int h);
extern void updateOrientation();
extern void GL_RenderPix(u8 * pix,int w, int h);

extern int GL_GetNativeWidth();
extern int GL_GetNativeHeight();

// Some-what generalized layered texture rendering
typedef struct
{
  GLuint texture;
  float * vertexCoords;
  float * textureCoords;
} GLLayer;

extern void drawLayers(GLLayer *layers, unsigned count);

enum orientation
{
    ORIENTATION_PORTRAIT,    // default mode, portrait
    ORIENTATION_LANDSCAPE_R, // landscape, keyboard on right
    ORIENTATION_LANDSCAPE_L  // landscape, keyboard on left
};

extern int orientation;
extern int gl_filter;

#endif // _GL_UTIL_H_
