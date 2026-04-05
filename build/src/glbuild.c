#include "compat.h"
#include "glbuild.h"
#include "baselayer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#if defined USE_OPENGL

#ifdef RENDERTYPESDL
# include "sdlayer.h"
#endif

GLenum BuildGLError;
void BuildGLErrorCheck(void)
{
    volatile GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR)
    {
        BuildGLError = err; // set a watchpoint/breakpoint here
    }
}

#if defined DYNAMIC_GL

#ifdef _WIN32
wglCreateContextProcPtr wglCreateContext;
wglDeleteContextProcPtr wglDeleteContext;
wglGetProcAddressProcPtr wglGetProcAddress;
wglMakeCurrentProcPtr wglMakeCurrent;

wglSwapBuffersProcPtr wglSwapBuffers;
wglChoosePixelFormatProcPtr wglChoosePixelFormat;
wglDescribePixelFormatProcPtr wglDescribePixelFormat;
wglGetPixelFormatProcPtr wglGetPixelFormat;
wglSetPixelFormatProcPtr wglSetPixelFormat;
#endif

glClearColorProcPtr glClearColor;
glClearProcPtr glClear;
glColorMaskProcPtr glColorMask;
glAlphaFuncProcPtr glAlphaFunc;
glBlendFuncProcPtr glBlendFunc;
glCullFaceProcPtr glCullFace;
glFrontFaceProcPtr glFrontFace;
glPolygonOffsetProcPtr glPolygonOffset;
glPolygonModeProcPtr glPolygonMode;
glEnableProcPtr glEnable;
glDisableProcPtr glDisable;
glGetDoublevProcPtr glGetDoublev;
glGetFloatvProcPtr glGetFloatv;
glGetIntegervProcPtr glGetIntegerv;
glPushAttribProcPtr glPushAttrib;
glPopAttribProcPtr glPopAttrib;
glGetErrorProcPtr glGetError;
glGetStringProcPtr glGetString;
glHintProcPtr glHint;
glDrawBufferProcPtr glDrawBuffer;
glReadBufferProcPtr glReadBuffer;
glScissorProcPtr glScissor;
glClipPlaneProcPtr glClipPlane;

// Depth
glDepthFuncProcPtr glDepthFunc;
glDepthMaskProcPtr glDepthMask;
//glDepthRangeProcPtr glDepthRange;

// Matrix
glMatrixModeProcPtr glMatrixMode;
glOrthoProcPtr glOrtho;
glFrustumProcPtr glFrustum;
glViewportProcPtr glViewport;
glPushMatrixProcPtr glPushMatrix;
glPopMatrixProcPtr glPopMatrix;
glLoadIdentityProcPtr glLoadIdentity;
glLoadMatrixfProcPtr glLoadMatrixf;
glLoadMatrixdProcPtr glLoadMatrixd;
glMultMatrixfProcPtr glMultMatrixf;
glMultMatrixdProcPtr glMultMatrixd;
glRotatefProcPtr glRotatef;
glScalefProcPtr glScalef;
glTranslatefProcPtr glTranslatef;

// Drawing
glBeginProcPtr glBegin;
glEndProcPtr glEnd;
glVertex2fProcPtr glVertex2f;
glVertex2iProcPtr glVertex2i;
glVertex3fProcPtr glVertex3f;
glVertex3dProcPtr glVertex3d;
glVertex3fvProcPtr glVertex3fv;
glVertex3dvProcPtr glVertex3dv;
glRectiProcPtr glRecti;
glColor3fProcPtr glColor3f;
glColor4fProcPtr glColor4f;
glColor4ubProcPtr glColor4ub;
glTexCoord2dProcPtr glTexCoord2d;
glTexCoord2fProcPtr glTexCoord2f;
glTexCoord2iProcPtr glTexCoord2i;
glNormal3fProcPtr glNormal3f;

// Lighting
glShadeModelProcPtr glShadeModel;
glLightfvProcPtr glLightfv;

// Raster funcs
glReadPixelsProcPtr glReadPixels;
glRasterPos4iProcPtr glRasterPos4i;
glDrawPixelsProcPtr glDrawPixels;
glPixelStoreiProcPtr glPixelStorei;

// Texture mapping
glTexEnvfProcPtr glTexEnvf;
glGenTexturesProcPtr glGenTextures;
glDeleteTexturesProcPtr glDeleteTextures;
glBindTextureProcPtr glBindTexture;
glTexImage2DProcPtr glTexImage2D;
glCopyTexImage2DProcPtr glCopyTexImage2D;
glCopyTexSubImage2DProcPtr glCopyTexSubImage2D;
glTexSubImage2DProcPtr glTexSubImage2D;
glTexParameterfProcPtr glTexParameterf;
glTexParameteriProcPtr glTexParameteri;
glGetTexParameterivProcPtr glGetTexParameteriv;
glGetTexLevelParameterivProcPtr glGetTexLevelParameteriv;
glTexGenfvProcPtr glTexGenfv;

// Fog
glFogfProcPtr glFogf;
glFogiProcPtr glFogi;
glFogfvProcPtr glFogfv;

// Display Lists
glNewListProcPtr glNewList;
glEndListProcPtr glEndList;
glCallListProcPtr glCallList;
glDeleteListsProcPtr glDeleteLists;

// Vertex Arrays
glEnableClientStateProcPtr glEnableClientState;
glDisableClientStateProcPtr glDisableClientState;
glVertexPointerProcPtr glVertexPointer;
glNormalPointerProcPtr glNormalPointer;
glTexCoordPointerProcPtr glTexCoordPointer;
glDrawArraysProcPtr glDrawArrays;
glDrawElementsProcPtr glDrawElements;

// Stencil Buffer
glClearStencilProcPtr glClearStencil;
glStencilOpProcPtr glStencilOp;
glStencilFuncProcPtr glStencilFunc;

#endif

#if defined DYNAMIC_GLEXT

glBlendEquationProcPtr glBlendEquation;

glTexImage3DProcPtr glTexImage3D;
glCompressedTexImage2DARBProcPtr glCompressedTexImage2DARB;
glGetCompressedTexImageARBProcPtr glGetCompressedTexImageARB;

// GPU Programs
glGenProgramsARBProcPtr glGenProgramsARB;
glBindProgramARBProcPtr glBindProgramARB;
glProgramStringARBProcPtr glProgramStringARB;
glDeleteProgramsARBProcPtr glDeleteProgramsARB;

// Multitexturing
glActiveTextureARBProcPtr glActiveTextureARB;
glClientActiveTextureARBProcPtr glClientActiveTextureARB;
glMultiTexCoord2dARBProcPtr glMultiTexCoord2dARB;
glMultiTexCoord2fARBProcPtr glMultiTexCoord2fARB;

// Frame Buffer Objects
glGenFramebuffersEXTProcPtr glGenFramebuffersEXT;
glBindFramebufferEXTProcPtr glBindFramebufferEXT;
glFramebufferTexture2DEXTProcPtr glFramebufferTexture2DEXT;
glCheckFramebufferStatusEXTProcPtr glCheckFramebufferStatusEXT;
glDeleteFramebuffersEXTProcPtr glDeleteFramebuffersEXT;

// Vertex Buffer Objects
glGenBuffersARBProcPtr glGenBuffersARB;
glBindBufferARBProcPtr glBindBufferARB;
glDeleteBuffersARBProcPtr glDeleteBuffersARB;
glBufferDataARBProcPtr glBufferDataARB;
glBufferSubDataARBProcPtr glBufferSubDataARB;
glMapBufferARBProcPtr glMapBufferARB;
glUnmapBufferARBProcPtr glUnmapBufferARB;

// ARB_buffer_storage
glBufferStorageProcPtr glBufferStorage;

// ARB_map_buffer_range
glMapBufferRangeProcPtr glMapBufferRange;

// Occlusion queries
glGenQueriesARBProcPtr glGenQueriesARB;
glDeleteQueriesARBProcPtr glDeleteQueriesARB;
glIsQueryARBProcPtr glIsQueryARB;
glBeginQueryARBProcPtr glBeginQueryARB;
glEndQueryARBProcPtr glEndQueryARB;
glGetQueryivARBProcPtr glGetQueryivARB;
glGetQueryObjectivARBProcPtr glGetQueryObjectivARB;
glGetQueryObjectuivARBProcPtr glGetQueryObjectuivARB;

// Shader Objects
glDeleteObjectARBProcPtr glDeleteObjectARB;
glGetHandleARBProcPtr glGetHandleARB;
glDetachObjectARBProcPtr glDetachObjectARB;
glCreateShaderObjectARBProcPtr glCreateShaderObjectARB;
glShaderSourceARBProcPtr glShaderSourceARB;
glCompileShaderARBProcPtr glCompileShaderARB;
glCreateProgramObjectARBProcPtr glCreateProgramObjectARB;
glAttachObjectARBProcPtr glAttachObjectARB;
glLinkProgramARBProcPtr glLinkProgramARB;
glUseProgramObjectARBProcPtr glUseProgramObjectARB;
glValidateProgramARBProcPtr glValidateProgramARB;
glUniform1fARBProcPtr glUniform1fARB;
glUniform2fARBProcPtr glUniform2fARB;
glUniform3fARBProcPtr glUniform3fARB;
glUniform4fARBProcPtr glUniform4fARB;
glUniform1iARBProcPtr glUniform1iARB;
glUniform2iARBProcPtr glUniform2iARB;
glUniform3iARBProcPtr glUniform3iARB;
glUniform4iARBProcPtr glUniform4iARB;
glUniform1fvARBProcPtr glUniform1fvARB;
glUniform2fvARBProcPtr glUniform2fvARB;
glUniform3fvARBProcPtr glUniform3fvARB;
glUniform4fvARBProcPtr glUniform4fvARB;
glUniform1ivARBProcPtr glUniform1ivARB;
glUniform2ivARBProcPtr glUniform2ivARB;
glUniform3ivARBProcPtr glUniform3ivARB;
glUniform4ivARBProcPtr glUniform4ivARB;
glUniformMatrix2fvARBProcPtr glUniformMatrix2fvARB;
glUniformMatrix3fvARBProcPtr glUniformMatrix3fvARB;
glUniformMatrix4fvARBProcPtr glUniformMatrix4fvARB;
glGetObjectParameterfvARBProcPtr glGetObjectParameterfvARB;
glGetObjectParameterivARBProcPtr glGetObjectParameterivARB;
glGetInfoLogARBProcPtr glGetInfoLogARB;
glGetAttachedObjectsARBProcPtr glGetAttachedObjectsARB;
glGetUniformLocationARBProcPtr glGetUniformLocationARB;
glGetActiveUniformARBProcPtr glGetActiveUniformARB;
glGetUniformfvARBProcPtr glGetUniformfvARB;
glGetUniformivARBProcPtr glGetUniformivARB;
glGetShaderSourceARBProcPtr glGetShaderSourceARB;

// Vertex Shaders
glVertexAttrib1dARBProcPtr glVertexAttrib1dARB;
glVertexAttrib1dvARBProcPtr glVertexAttrib1dvARB;
glVertexAttrib1fARBProcPtr glVertexAttrib1fARB;
glVertexAttrib1fvARBProcPtr glVertexAttrib1fvARB;
glVertexAttrib1sARBProcPtr glVertexAttrib1sARB;
glVertexAttrib1svARBProcPtr glVertexAttrib1svARB;
glVertexAttrib2dARBProcPtr glVertexAttrib2dARB;
glVertexAttrib2dvARBProcPtr glVertexAttrib2dvARB;
glVertexAttrib2fARBProcPtr glVertexAttrib2fARB;
glVertexAttrib2fvARBProcPtr glVertexAttrib2fvARB;
glVertexAttrib2sARBProcPtr glVertexAttrib2sARB;
glVertexAttrib2svARBProcPtr glVertexAttrib2svARB;
glVertexAttrib3dARBProcPtr glVertexAttrib3dARB;
glVertexAttrib3dvARBProcPtr glVertexAttrib3dvARB;
glVertexAttrib3fARBProcPtr glVertexAttrib3fARB;
glVertexAttrib3fvARBProcPtr glVertexAttrib3fvARB;
glVertexAttrib3sARBProcPtr glVertexAttrib3sARB;
glVertexAttrib3svARBProcPtr glVertexAttrib3svARB;
glVertexAttrib4NbvARBProcPtr glVertexAttrib4NbvARB;
glVertexAttrib4NivARBProcPtr glVertexAttrib4NivARB;
glVertexAttrib4NsvARBProcPtr glVertexAttrib4NsvARB;
glVertexAttrib4NubARBProcPtr glVertexAttrib4NubARB;
glVertexAttrib4NubvARBProcPtr glVertexAttrib4NubvARB;
glVertexAttrib4NuivARBProcPtr glVertexAttrib4NuivARB;
glVertexAttrib4NusvARBProcPtr glVertexAttrib4NusvARB;
glVertexAttrib4bvARBProcPtr glVertexAttrib4bvARB;
glVertexAttrib4dARBProcPtr glVertexAttrib4dARB;
glVertexAttrib4dvARBProcPtr glVertexAttrib4dvARB;
glVertexAttrib4fARBProcPtr glVertexAttrib4fARB;
glVertexAttrib4fvARBProcPtr glVertexAttrib4fvARB;
glVertexAttrib4ivARBProcPtr glVertexAttrib4ivARB;
glVertexAttrib4sARBProcPtr glVertexAttrib4sARB;
glVertexAttrib4svARBProcPtr glVertexAttrib4svARB;
glVertexAttrib4ubvARBProcPtr glVertexAttrib4ubvARB;
glVertexAttrib4uivARBProcPtr glVertexAttrib4uivARB;
glVertexAttrib4usvARBProcPtr glVertexAttrib4usvARB;
glVertexAttribPointerARBProcPtr glVertexAttribPointerARB;
glEnableVertexAttribArrayARBProcPtr glEnableVertexAttribArrayARB;
glDisableVertexAttribArrayARBProcPtr glDisableVertexAttribArrayARB;
glGetVertexAttribdvARBProcPtr glGetVertexAttribdvARB;
glGetVertexAttribfvARBProcPtr glGetVertexAttribfvARB;
glGetVertexAttribivARBProcPtr glGetVertexAttribivARB;
glGetVertexAttribPointervARBProcPtr glGetVertexAttribPointervARB;
glBindAttribLocationARBProcPtr glBindAttribLocationARB;
glGetActiveAttribARBProcPtr glGetActiveAttribARB;
glGetAttribLocationARBProcPtr glGetAttribLocationARB;

// Debug Output
#ifndef __APPLE__
glDebugMessageControlARBProcPtr glDebugMessageControlARB;
glDebugMessageCallbackARBProcPtr glDebugMessageCallbackARB;
#endif

#ifdef _WIN32
wglSwapIntervalEXTProcPtr wglSwapIntervalEXT;
wglCreateContextAttribsARBProcPtr wglCreateContextAttribsARB;
#endif

#endif

#if defined DYNAMIC_GLU

// GLU
gluTessBeginContourProcPtr gluTessBeginContour;
gluTessBeginPolygonProcPtr gluTessBeginPolygon;
gluTessCallbackProcPtr gluTessCallback;
gluTessEndContourProcPtr gluTessEndContour;
gluTessEndPolygonProcPtr gluTessEndPolygon;
gluTessNormalProcPtr gluTessNormal;
gluTessPropertyProcPtr gluTessProperty;
gluTessVertexProcPtr gluTessVertex;
gluNewTessProcPtr gluNewTess;
gluDeleteTessProcPtr gluDeleteTess;

gluPerspectiveProcPtr gluPerspective;

gluErrorStringProcPtr gluErrorString;

gluProjectProcPtr gluProject;
gluUnProjectProcPtr gluUnProject;

#endif


#if defined DYNAMIC_GL || defined DYNAMIC_GLEXT || defined DYNAMIC_GLU
# if !defined _WIN32
#  include <dlfcn.h>
# endif
#endif

#if defined DYNAMIC_GL || defined DYNAMIC_GLEXT

#if !defined RENDERTYPESDL && defined _WIN32
static HMODULE hGLDLL;
#endif

char *gldriver = NULL;

static void *getproc_(const char *s, int32_t *err, int32_t fatal, int32_t extension)
{
    void *t;
#if defined RENDERTYPESDL
    UNREFERENCED_PARAMETER(extension);
    t = (void *)SDL_GL_GetProcAddress(s);
#elif defined _WIN32
    if (extension) t = (void *)wglGetProcAddress(s);
    else t = (void *)GetProcAddress(hGLDLL,s);
#else
#error Need a dynamic loader for this platform...
#endif
    if (!t && fatal)
    {
        initprintf("Failed to find %s in %s\n", s, gldriver);
        *err = 1;
    }
    return t;
}
#define GETPROC(s)        getproc_(s,&err,1,0)
#define GETPROCSOFT(s)    getproc_(s,&err,0,0)
#define GETPROCEXT(s)     getproc_(s,&err,1,1)
#define GETPROCEXTSOFT(s) getproc_(s,&err,0,1)

#endif

int32_t loadgldriver(const char *driver)
{
#if defined EDUKE32_GLES
    jwzgles_reset();
#endif

#if defined DYNAMIC_GL || defined DYNAMIC_GLEXT
    int32_t err=0;

#if !defined RENDERTYPESDL && defined _WIN32
    if (hGLDLL) return 0;
#endif

    if (!driver)
    {
#ifdef _WIN32
        driver = "opengl32.dll";
#elif defined EDUKE32_OSX
        driver = "/System/Library/Frameworks/OpenGL.framework/OpenGL";
#elif defined __OpenBSD__
        driver = "ligl.so";
#else
        driver = "ligl.so.1";
#endif
    }

#if defined RENDERTYPESDL && !defined EDUKE32_IOS
    if (SDL_GL_LoadLibrary(driver))
    {
        initprintf("Failed loading \"%s\": %s\n", driver, SDL_GetError());
        return -1;
    }
#elif defined _WIN32
    hGLDLL = LoadLibrary(driver);
    if (!hGLDLL)
    {
        initprintf("Failed loading \"%s\"\n", driver);
        return -1;
    }
#endif
    gldriver = Bstrdup(driver);
#endif

#if defined DYNAMIC_GL
#ifdef _WIN32
    wglCreateContext = (wglCreateContextProcPtr) GETPROC("wglCreateContext");
    wglDeleteContext = (wglDeleteContextProcPtr) GETPROC("wglDeleteContext");
    wglGetProcAddress = (wglGetProcAddressProcPtr) GETPROC("wglGetProcAddress");
    wglMakeCurrent = (wglMakeCurrentProcPtr) GETPROC("wglMakeCurrent");

    wglSwapBuffers = (wglSwapBuffersProcPtr) GETPROC("wglSwapBuffers");
    wglChoosePixelFormat = (wglChoosePixelFormatProcPtr) GETPROC("wglChoosePixelFormat");
    wglDescribePixelFormat = (wglDescribePixelFormatProcPtr) GETPROC("wglDescribePixelFormat");
    wglGetPixelFormat = (wglGetPixelFormatProcPtr) GETPROC("wglGetPixelFormat");
    wglSetPixelFormat = (wglSetPixelFormatProcPtr) GETPROC("wglSetPixelFormat");
#endif

    glClearColor = (glClearColorProcPtr) GETPROC("glClearColor");
    glClear = (glClearProcPtr) GETPROC("glClear");
    glColorMask = (glColorMaskProcPtr) GETPROC("glColorMask");
    glAlphaFunc = (glAlphaFuncProcPtr) GETPROC("glAlphaFunc");
    glBlendFunc = (glBlendFuncProcPtr) GETPROC("glBlendFunc");
    glCullFace = (glCullFaceProcPtr) GETPROC("glCullFace");
    glFrontFace = (glFrontFaceProcPtr) GETPROC("glFrontFace");
    glPolygonOffset = (glPolygonOffsetProcPtr) GETPROC("glPolygonOffset");
    glPolygonMode = (glPolygonModeProcPtr) GETPROC("glPolygonMode");
    glEnable = (glEnableProcPtr) GETPROC("glEnable");
    glDisable = (glDisableProcPtr) GETPROC("glDisable");
    glGetDoublev = (glGetDoublevProcPtr) GETPROC("glGetDoublev");
    glGetFloatv = (glGetFloatvProcPtr) GETPROC("glGetFloatv");
    glGetIntegerv = (glGetIntegervProcPtr) GETPROC("glGetIntegerv");
    glPushAttrib = (glPushAttribProcPtr) GETPROC("glPushAttrib");
    glPopAttrib = (glPopAttribProcPtr) GETPROC("glPopAttrib");
    glGetError = (glGetErrorProcPtr) GETPROC("glGetError");
    glGetString = (glGetStringProcPtr) GETPROC("glGetString");
    glHint = (glHintProcPtr) GETPROC("glHint");
    glDrawBuffer = (glDrawBufferProcPtr) GETPROC("glDrawBuffer");
    glReadBuffer = (glReadBufferProcPtr) GETPROC("glDrawBuffer");
    glScissor = (glScissorProcPtr) GETPROC("glScissor");
    glClipPlane = (glClipPlaneProcPtr) GETPROC("glClipPlane");

    // Depth
    glDepthFunc = (glDepthFuncProcPtr) GETPROC("glDepthFunc");
    glDepthMask = (glDepthMaskProcPtr) GETPROC("glDepthMask");
//    glDepthRange = (glDepthRangeProcPtr) GETPROC("glDepthRange");

    // Matrix
    glMatrixMode = (glMatrixModeProcPtr) GETPROC("glMatrixMode");
    glOrtho = (glOrthoProcPtr) GETPROC("glOrtho");
    glFrustum = (glFrustumProcPtr) GETPROC("glFrustum");
    glViewport = (glViewportProcPtr) GETPROC("glViewport");
    glPushMatrix = (glPushMatrixProcPtr) GETPROC("glPushMatrix");
    glPopMatrix = (glPopMatrixProcPtr) GETPROC("glPopMatrix");
    glLoadIdentity = (glLoadIdentityProcPtr) GETPROC("glLoadIdentity");
    glLoadMatrixf = (glLoadMatrixfProcPtr) GETPROC("glLoadMatrixf");
    glLoadMatrixd = (glLoadMatrixdProcPtr) GETPROC("glLoadMatrixd");
    glMultMatrixf = (glMultMatrixfProcPtr) GETPROC("glMultMatrixf");
    glMultMatrixd = (glMultMatrixdProcPtr) GETPROC("glMultMatrixd");
    glRotatef = (glRotatefProcPtr) GETPROC("glRotatef");
    glScalef = (glScalefProcPtr) GETPROC("glScalef");
    glTranslatef = (glTranslatefProcPtr) GETPROC("glTranslatef");

    // Drawing
    glBegin = (glBeginProcPtr) GETPROC("glBegin");
    glEnd = (glEndProcPtr) GETPROC("glEnd");
    glVertex2f = (glVertex2fProcPtr) GETPROC("glVertex2f");
    glVertex2i = (glVertex2iProcPtr) GETPROC("glVertex2i");
    glVertex3f = (glVertex3fProcPtr) GETPROC("glVertex3f");
    glVertex3d = (glVertex3dProcPtr) GETPROC("glVertex3d");
    glVertex3fv = (glVertex3fvProcPtr) GETPROC("glVertex3fv");
    glVertex3dv = (glVertex3dvProcPtr) GETPROC("glVertex3dv");
    glRecti = (glRectiProcPtr) GETPROC("glRecti");
    glColor3f = (glColor3fProcPtr) GETPROC("glColor3f");
    glColor4f = (glColor4fProcPtr) GETPROC("glColor4f");
    glColor4ub = (glColor4ubProcPtr) GETPROC("glColor4ub");
    glTexCoord2d = (glTexCoord2dProcPtr) GETPROC("glTexCoord2d");
    glTexCoord2f = (glTexCoord2fProcPtr) GETPROC("glTexCoord2f");
    glTexCoord2i = (glTexCoord2iProcPtr) GETPROC("glTexCoord2i");
    glNormal3f = (glNormal3fProcPtr) GETPROC("glNormal3f");

    // Lighting
    glShadeModel = (glShadeModelProcPtr) GETPROC("glShadeModel");
    glLightfv = (glLightfvProcPtr) GETPROC("glLightfv");

    // Raster funcs
    glReadPixels = (glReadPixelsProcPtr) GETPROC("glReadPixels");
    glRasterPos4i = (glRasterPos4iProcPtr) GETPROC("glRasterPos4i");
    glDrawPixels = (glDrawPixelsProcPtr) GETPROC("glDrawPixels");
    glPixelStorei = (glPixelStoreiProcPtr) GETPROC("glPixelStorei");

    // Texture mapping
    glTexEnvf = (glTexEnvfProcPtr) GETPROC("glTexEnvf");
    glGenTextures = (glGenTexturesProcPtr) GETPROC("glGenTextures");
    glDeleteTextures = (glDeleteTexturesProcPtr) GETPROC("glDeleteTextures");
    glBindTexture = (glBindTextureProcPtr) GETPROC("glBindTexture");
    glTexImage2D = (glTexImage2DProcPtr) GETPROC("glTexImage2D");
    glCopyTexImage2D = (glCopyTexImage2DProcPtr) GETPROC("glCopyTexImage2D");
    glCopyTexSubImage2D = (glCopyTexSubImage2DProcPtr) GETPROC("glCopyTexSubImage2D");
    glTexSubImage2D = (glTexSubImage2DProcPtr) GETPROC("glTexSubImage2D");
    glTexParameterf = (glTexParameterfProcPtr) GETPROC("glTexParameterf");
    glTexParameteri = (glTexParameteriProcPtr) GETPROC("glTexParameteri");
    glGetTexParameteriv = (glGetTexParameterivProcPtr) GETPROC("glGetTexParameteriv");
    glGetTexLevelParameteriv = (glGetTexLevelParameterivProcPtr) GETPROC("glGetTexLevelParameteriv");
    glTexGenfv = (glTexGenfvProcPtr) GETPROC("glTexGenfv");

    // Fog
    glFogf = (glFogfProcPtr) GETPROC("glFogf");
    glFogi = (glFogiProcPtr) GETPROC("glFogi");
    glFogfv = (glFogfvProcPtr) GETPROC("glFogfv");

    // Display Lists
    glNewList = (glNewListProcPtr) GETPROC("glNewList");
    glEndList = (glEndListProcPtr) GETPROC("glEndList");
    glCallList = (glCallListProcPtr) GETPROC("glCallList");
    glDeleteLists = (glDeleteListsProcPtr) GETPROC("glDeleteLists");

    // Vertex Arrays
    glEnableClientState = (glEnableClientStateProcPtr) GETPROC("glEnableClientState");
    glDisableClientState = (glDisableClientStateProcPtr) GETPROC("glDisableClientState");
    glVertexPointer = (glVertexPointerProcPtr) GETPROC("glVertexPointer");
    glNormalPointer = (glNormalPointerProcPtr) GETPROC("glNormalPointer");
    glTexCoordPointer = (glTexCoordPointerProcPtr) GETPROC("glTexCoordPointer");
    glDrawArrays = (glDrawArraysProcPtr) GETPROC("glDrawArrays");
    glDrawElements = (glDrawElementsProcPtr) GETPROC("glDrawElements");

    // Stencil Buffer
    glClearStencil = (glClearStencilProcPtr) GETPROC("glClearStencil");
    glStencilOp = (glStencilOpProcPtr) GETPROC("glStencilOp");
    glStencilFunc = (glStencilFuncProcPtr) GETPROC("glStencilFunc");
#endif

//    loadglextensions();
//    loadglulibrary(getenv("BUILD_GLULIB"));

#if defined DYNAMIC_GL || defined DYNAMIC_GLEXT
    if (err) unloadgldriver();
    return err;
#else
    UNREFERENCED_PARAMETER(driver);
    return 0;
#endif
}

int32_t loadglextensions(void)
{
#if defined DYNAMIC_GLEXT
    int32_t err = 0;
#if !defined RENDERTYPESDL && defined _WIN32
    if (!hGLDLL) return 0;
#endif

    glBlendEquation = (glBlendEquationProcPtr) GETPROCEXTSOFT("glBlendEquation");

    glTexImage3D = (glTexImage3DProcPtr) GETPROCEXTSOFT("glTexImage3D");
    glCompressedTexImage2DARB = (glCompressedTexImage2DARBProcPtr) GETPROCEXTSOFT("glCompressedTexImage2DARB");
    glGetCompressedTexImageARB = (glGetCompressedTexImageARBProcPtr) GETPROCEXTSOFT("glGetCompressedTexImageARB");

    // GPU Programs
    glGenProgramsARB = (glGenProgramsARBProcPtr) GETPROCEXTSOFT("glGenProgramsARB");
    glBindProgramARB = (glBindProgramARBProcPtr) GETPROCEXTSOFT("glBindProgramARB");
    glProgramStringARB = (glProgramStringARBProcPtr) GETPROCEXTSOFT("glProgramStringARB");
    glDeleteProgramsARB = (glDeleteProgramsARBProcPtr) GETPROCEXTSOFT("glDeleteProgramsARB");

    // Multitexturing
    glActiveTextureARB = (glActiveTextureARBProcPtr) GETPROCEXTSOFT("glActiveTextureARB");
    glClientActiveTextureARB = (glClientActiveTextureARBProcPtr) GETPROCEXTSOFT("glClientActiveTextureARB");
    glMultiTexCoord2dARB = (glMultiTexCoord2dARBProcPtr) GETPROCEXTSOFT("glMultiTexCoord2dARB");
    glMultiTexCoord2fARB = (glMultiTexCoord2fARBProcPtr) GETPROCEXTSOFT("glMultiTexCoord2fARB");

    // Frame Buffer Objects
    glGenFramebuffersEXT = (glGenFramebuffersEXTProcPtr) GETPROCEXTSOFT("glGenFramebuffersEXT");
    glBindFramebufferEXT = (glBindFramebufferEXTProcPtr) GETPROCEXTSOFT("glBindFramebufferEXT");
    glFramebufferTexture2DEXT = (glFramebufferTexture2DEXTProcPtr) GETPROCEXTSOFT("glFramebufferTexture2DEXT");
    glCheckFramebufferStatusEXT = (glCheckFramebufferStatusEXTProcPtr) GETPROCEXTSOFT("glCheckFramebufferStatusEXT");
    glDeleteFramebuffersEXT = (glDeleteFramebuffersEXTProcPtr) GETPROCEXTSOFT("glDeleteFramebuffersEXT");

    // Vertex Buffer Objects
    glGenBuffersARB = (glGenBuffersARBProcPtr) GETPROCEXTSOFT("glGenBuffersARB");
    glBindBufferARB = (glBindBufferARBProcPtr) GETPROCEXTSOFT("glBindBufferARB");
    glDeleteBuffersARB = (glDeleteBuffersARBProcPtr) GETPROCEXTSOFT("glDeleteBuffersARB");
    glBufferDataARB = (glBufferDataARBProcPtr) GETPROCEXTSOFT("glBufferDataARB");
    glBufferSubDataARB = (glBufferSubDataARBProcPtr) GETPROCEXTSOFT("glBufferSubDataARB");
    glMapBufferARB = (glMapBufferARBProcPtr) GETPROCEXTSOFT("glMapBufferARB");
    glUnmapBufferARB = (glUnmapBufferARBProcPtr) GETPROCEXTSOFT("glUnmapBufferARB");

    // ARB_buffer_storage
    glBufferStorage = (glBufferStorageProcPtr)GETPROCEXTSOFT("glBufferStorage");

    // ARB_map_buffer_range
    glMapBufferRange = (glMapBufferRangeProcPtr)GETPROCEXTSOFT("glMapBufferRange");

    // Occlusion queries
    glGenQueriesARB = (glGenQueriesARBProcPtr) GETPROCEXTSOFT("glGenQueriesARB");
    glDeleteQueriesARB = (glDeleteQueriesARBProcPtr) GETPROCEXTSOFT("glDeleteQueriesARB");
    glIsQueryARB = (glIsQueryARBProcPtr) GETPROCEXTSOFT("glIsQueryARB");
    glBeginQueryARB = (glBeginQueryARBProcPtr) GETPROCEXTSOFT("glBeginQueryARB");
    glEndQueryARB = (glEndQueryARBProcPtr) GETPROCEXTSOFT("glEndQueryARB");
    glGetQueryivARB = (glGetQueryivARBProcPtr) GETPROCEXTSOFT("glGetQueryivARB");
    glGetQueryObjectivARB = (glGetQueryObjectivARBProcPtr) GETPROCEXTSOFT("glGetQueryObjectivARB");
    glGetQueryObjectuivARB = (glGetQueryObjectuivARBProcPtr) GETPROCEXTSOFT("glGetQueryObjectuivARB");

    // Shader Objects
    glDeleteObjectARB = (glDeleteObjectARBProcPtr) GETPROCEXTSOFT("glDeleteObjectARB");
    glGetHandleARB = (glGetHandleARBProcPtr) GETPROCEXTSOFT("glGetHandleARB");
    glDetachObjectARB = (glDetachObjectARBProcPtr) GETPROCEXTSOFT("glDetachObjectARB");
    glCreateShaderObjectARB = (glCreateShaderObjectARBProcPtr) GETPROCEXTSOFT("glCreateShaderObjectARB");
    glShaderSourceARB = (glShaderSourceARBProcPtr) GETPROCEXTSOFT("glShaderSourceARB");
    glCompileShaderARB = (glCompileShaderARBProcPtr) GETPROCEXTSOFT("glCompileShaderARB");
    glCreateProgramObjectARB = (glCreateProgramObjectARBProcPtr) GETPROCEXTSOFT("glCreateProgramObjectARB");
    glAttachObjectARB = (glAttachObjectARBProcPtr) GETPROCEXTSOFT("glAttachObjectARB");
    glLinkProgramARB = (glLinkProgramARBProcPtr) GETPROCEXTSOFT("glLinkProgramARB");
    glUseProgramObjectARB = (glUseProgramObjectARBProcPtr) GETPROCEXTSOFT("glUseProgramObjectARB");
    glValidateProgramARB = (glValidateProgramARBProcPtr) GETPROCEXTSOFT("glValidateProgramARB");
    glUniform1fARB = (glUniform1fARBProcPtr) GETPROCEXTSOFT("glUniform1fARB");
    glUniform2fARB = (glUniform2fARBProcPtr) GETPROCEXTSOFT("glUniform2fARB");
    glUniform3fARB = (glUniform3fARBProcPtr) GETPROCEXTSOFT("glUniform3fARB");
    glUniform4fARB = (glUniform4fARBProcPtr) GETPROCEXTSOFT("glUniform4fARB");
    glUniform1iARB = (glUniform1iARBProcPtr) GETPROCEXTSOFT("glUniform1iARB");
    glUniform2iARB = (glUniform2iARBProcPtr) GETPROCEXTSOFT("glUniform2iARB");
    glUniform3iARB = (glUniform3iARBProcPtr) GETPROCEXTSOFT("glUniform3iARB");
    glUniform4iARB = (glUniform4iARBProcPtr) GETPROCEXTSOFT("glUniform4iARB");
    glUniform1fvARB = (glUniform1fvARBProcPtr) GETPROCEXTSOFT("glUniform1fvARB");
    glUniform2fvARB = (glUniform2fvARBProcPtr) GETPROCEXTSOFT("glUniform2fvARB");
    glUniform3fvARB = (glUniform3fvARBProcPtr) GETPROCEXTSOFT("glUniform3fvARB");
    glUniform4fvARB = (glUniform4fvARBProcPtr) GETPROCEXTSOFT("glUniform4fvARB");
    glUniform1ivARB = (glUniform1ivARBProcPtr) GETPROCEXTSOFT("glUniform1ivARB");
    glUniform2ivARB = (glUniform2ivARBProcPtr) GETPROCEXTSOFT("glUniform2ivARB");
    glUniform3ivARB = (glUniform3ivARBProcPtr) GETPROCEXTSOFT("glUniform3ivARB");
    glUniform4ivARB = (glUniform4ivARBProcPtr) GETPROCEXTSOFT("glUniform4ivARB");
    glUniformMatrix2fvARB = (glUniformMatrix2fvARBProcPtr) GETPROCEXTSOFT("glUniformMatrix2fvARB");
    glUniformMatrix3fvARB = (glUniformMatrix3fvARBProcPtr) GETPROCEXTSOFT("glUniformMatrix3fvARB");
    glUniformMatrix4fvARB = (glUniformMatrix4fvARBProcPtr) GETPROCEXTSOFT("glUniformMatrix4fvARB");
    glGetObjectParameterfvARB = (glGetObjectParameterfvARBProcPtr) GETPROCEXTSOFT("glGetObjectParameterfvARB");
    glGetObjectParameterivARB = (glGetObjectParameterivARBProcPtr) GETPROCEXTSOFT("glGetObjectParameterivARB");
    glGetInfoLogARB = (glGetInfoLogARBProcPtr) GETPROCEXTSOFT("glGetInfoLogARB");
    glGetAttachedObjectsARB = (glGetAttachedObjectsARBProcPtr) GETPROCEXTSOFT("glGetAttachedObjectsARB");
    glGetUniformLocationARB = (glGetUniformLocationARBProcPtr) GETPROCEXTSOFT("glGetUniformLocationARB");
    glGetActiveUniformARB = (glGetActiveUniformARBProcPtr) GETPROCEXTSOFT("glGetActiveUniformARB");
    glGetUniformfvARB = (glGetUniformfvARBProcPtr) GETPROCEXTSOFT("glGetUniformfvARB");
    glGetUniformivARB = (glGetUniformivARBProcPtr) GETPROCEXTSOFT("glGetUniformivARB");
    glGetShaderSourceARB = (glGetShaderSourceARBProcPtr) GETPROCEXTSOFT("glGetShaderSourceARB");

    // Vertex Shaders
    glVertexAttrib1dARB = (glVertexAttrib1dARBProcPtr) GETPROCEXTSOFT("glVertexAttrib1dARB");
    glVertexAttrib1dvARB = (glVertexAttrib1dvARBProcPtr) GETPROCEXTSOFT("glVertexAttrib1dvARB");
    glVertexAttrib1fARB = (glVertexAttrib1fARBProcPtr) GETPROCEXTSOFT("glVertexAttrib1fARB");
    glVertexAttrib1fvARB = (glVertexAttrib1fvARBProcPtr) GETPROCEXTSOFT("glVertexAttrib1fvARB");
    glVertexAttrib1sARB = (glVertexAttrib1sARBProcPtr) GETPROCEXTSOFT("glVertexAttrib1sARB");
    glVertexAttrib1svARB = (glVertexAttrib1svARBProcPtr) GETPROCEXTSOFT("glVertexAttrib1svARB");
    glVertexAttrib2dARB = (glVertexAttrib2dARBProcPtr) GETPROCEXTSOFT("glVertexAttrib2dARB");
    glVertexAttrib2dvARB = (glVertexAttrib2dvARBProcPtr) GETPROCEXTSOFT("glVertexAttrib2dvARB");
    glVertexAttrib2fARB = (glVertexAttrib2fARBProcPtr) GETPROCEXTSOFT("glVertexAttrib2fARB");
    glVertexAttrib2fvARB = (glVertexAttrib2fvARBProcPtr) GETPROCEXTSOFT("glVertexAttrib2fvARB");
    glVertexAttrib2sARB = (glVertexAttrib2sARBProcPtr) GETPROCEXTSOFT("glVertexAttrib2sARB");
    glVertexAttrib2svARB = (glVertexAttrib2svARBProcPtr) GETPROCEXTSOFT("glVertexAttrib2svARB");
    glVertexAttrib3dARB = (glVertexAttrib3dARBProcPtr) GETPROCEXTSOFT("glVertexAttrib3dARB");
    glVertexAttrib3dvARB = (glVertexAttrib3dvARBProcPtr) GETPROCEXTSOFT("glVertexAttrib3dvARB");
    glVertexAttrib3fARB = (glVertexAttrib3fARBProcPtr) GETPROCEXTSOFT("glVertexAttrib3fARB");
    glVertexAttrib3fvARB = (glVertexAttrib3fvARBProcPtr) GETPROCEXTSOFT("glVertexAttrib3fvARB");
    glVertexAttrib3sARB = (glVertexAttrib3sARBProcPtr) GETPROCEXTSOFT("glVertexAttrib3sARB");
    glVertexAttrib3svARB = (glVertexAttrib3svARBProcPtr) GETPROCEXTSOFT("glVertexAttrib3svARB");
    glVertexAttrib4NbvARB = (glVertexAttrib4NbvARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4NbvARB");
    glVertexAttrib4NivARB = (glVertexAttrib4NivARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4NivARB");
    glVertexAttrib4NsvARB = (glVertexAttrib4NsvARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4NsvARB");
    glVertexAttrib4NubARB = (glVertexAttrib4NubARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4NubARB");
    glVertexAttrib4NubvARB = (glVertexAttrib4NubvARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4NubvARB");
    glVertexAttrib4NuivARB = (glVertexAttrib4NuivARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4NuivARB");
    glVertexAttrib4NusvARB = (glVertexAttrib4NusvARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4NusvARB");
    glVertexAttrib4bvARB = (glVertexAttrib4bvARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4bvARB");
    glVertexAttrib4dARB = (glVertexAttrib4dARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4dARB");
    glVertexAttrib4dvARB = (glVertexAttrib4dvARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4dvARB");
    glVertexAttrib4fARB = (glVertexAttrib4fARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4fARB");
    glVertexAttrib4fvARB = (glVertexAttrib4fvARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4fvARB");
    glVertexAttrib4ivARB = (glVertexAttrib4ivARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4ivARB");
    glVertexAttrib4sARB = (glVertexAttrib4sARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4sARB");
    glVertexAttrib4svARB = (glVertexAttrib4svARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4svARB");
    glVertexAttrib4ubvARB = (glVertexAttrib4ubvARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4ubvARB");
    glVertexAttrib4uivARB = (glVertexAttrib4uivARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4uivARB");
    glVertexAttrib4usvARB = (glVertexAttrib4usvARBProcPtr) GETPROCEXTSOFT("glVertexAttrib4usvARB");
    glVertexAttribPointerARB = (glVertexAttribPointerARBProcPtr) GETPROCEXTSOFT("glVertexAttribPointerARB");
    glEnableVertexAttribArrayARB = (glEnableVertexAttribArrayARBProcPtr) GETPROCEXTSOFT("glEnableVertexAttribArrayARB");
    glDisableVertexAttribArrayARB = (glDisableVertexAttribArrayARBProcPtr) GETPROCEXTSOFT("glDisableVertexAttribArrayARB");
    glGetVertexAttribdvARB = (glGetVertexAttribdvARBProcPtr) GETPROCEXTSOFT("glGetVertexAttribdvARB");
    glGetVertexAttribfvARB = (glGetVertexAttribfvARBProcPtr) GETPROCEXTSOFT("glGetVertexAttribfvARB");
    glGetVertexAttribivARB = (glGetVertexAttribivARBProcPtr) GETPROCEXTSOFT("glGetVertexAttribivARB");
    glGetVertexAttribPointervARB = (glGetVertexAttribPointervARBProcPtr) GETPROCEXTSOFT("glGetVertexAttribPointervARB");
    glBindAttribLocationARB = (glBindAttribLocationARBProcPtr) GETPROCEXTSOFT("glBindAttribLocationARB");
    glGetActiveAttribARB = (glGetActiveAttribARBProcPtr) GETPROCEXTSOFT("glGetActiveAttribARB");
    glGetAttribLocationARB = (glGetAttribLocationARBProcPtr) GETPROCEXTSOFT("glGetAttribLocationARB");

    // Debug Output
#ifndef __APPLE__
    glDebugMessageControlARB = (glDebugMessageControlARBProcPtr) GETPROCEXTSOFT("glDebugMessageControlARB");
    glDebugMessageCallbackARB = (glDebugMessageCallbackARBProcPtr) GETPROCEXTSOFT("glDebugMessageCallbackARB");
#endif

#ifdef _WIN32
    wglSwapIntervalEXT = (wglSwapIntervalEXTProcPtr) GETPROCEXTSOFT("wglSwapIntervalEXT");
    wglCreateContextAttribsARB = (wglCreateContextAttribsARBProcPtr) GETPROCEXTSOFT("wglCreateContextAttribsARB");
#endif

    // the following ARB functions are used in POLYMER=0 builds:
    // glActiveTextureARB,
    // glDeleteBuffersARB, glGenBuffersARB, glBindBufferARB,
    // glMapBufferARB, glUnmapBufferARB, glBufferDataARB,
    // glClientActiveTextureARB,
    // glGetCompressedTexImageARB, glCompressedTexImage2DARB

    return err;
#else
    return 0;
#endif
}

int32_t unloadgldriver(void)
{
#if defined DYNAMIC_GL || defined DYNAMIC_GLEXT
#if !defined RENDERTYPESDL && defined _WIN32
    if (!hGLDLL) return 0;
#endif

    DO_FREE_AND_NULL(gldriver);

#if !defined RENDERTYPESDL && defined _WIN32
    FreeLibrary(hGLDLL);
    hGLDLL = NULL;
#endif
#endif

#if defined DYNAMIC_GL
#ifdef _WIN32
    wglCreateContext = (wglCreateContextProcPtr) NULL;
    wglDeleteContext = (wglDeleteContextProcPtr) NULL;
    wglGetProcAddress = (wglGetProcAddressProcPtr) NULL;
    wglMakeCurrent = (wglMakeCurrentProcPtr) NULL;

    wglSwapBuffers = (wglSwapBuffersProcPtr) NULL;
    wglChoosePixelFormat = (wglChoosePixelFormatProcPtr) NULL;
    wglDescribePixelFormat = (wglDescribePixelFormatProcPtr) NULL;
    wglGetPixelFormat = (wglGetPixelFormatProcPtr) NULL;
    wglSetPixelFormat = (wglSetPixelFormatProcPtr) NULL;
#endif

    glClearColor = (glClearColorProcPtr) NULL;
    glClear = (glClearProcPtr) NULL;
    glColorMask = (glColorMaskProcPtr) NULL;
    glAlphaFunc = (glAlphaFuncProcPtr) NULL;
    glBlendFunc = (glBlendFuncProcPtr) NULL;
    glCullFace = (glCullFaceProcPtr) NULL;
    glFrontFace = (glFrontFaceProcPtr) NULL;
    glPolygonOffset = (glPolygonOffsetProcPtr) NULL;
    glPolygonMode = (glPolygonModeProcPtr) NULL;
    glEnable = (glEnableProcPtr) NULL;
    glDisable = (glDisableProcPtr) NULL;
    glGetDoublev = (glGetDoublevProcPtr) NULL;
    glGetFloatv = (glGetFloatvProcPtr) NULL;
    glGetIntegerv = (glGetIntegervProcPtr) NULL;
    glPushAttrib = (glPushAttribProcPtr) NULL;
    glPopAttrib = (glPopAttribProcPtr) NULL;
    glGetError = (glGetErrorProcPtr) NULL;
    glGetString = (glGetStringProcPtr) NULL;
    glHint = (glHintProcPtr) NULL;
    glDrawBuffer = (glDrawBufferProcPtr) NULL;
    glReadBuffer = (glReadBufferProcPtr) NULL;
    glScissor = (glScissorProcPtr) NULL;
    glClipPlane = (glClipPlaneProcPtr) NULL;

    // Depth
    glDepthFunc = (glDepthFuncProcPtr) NULL;
    glDepthMask = (glDepthMaskProcPtr) NULL;
//    glDepthRange = (glDepthRangeProcPtr) NULL;

    // Matrix
    glMatrixMode = (glMatrixModeProcPtr) NULL;
    glOrtho = (glOrthoProcPtr) NULL;
    glFrustum = (glFrustumProcPtr) NULL;
    glViewport = (glViewportProcPtr) NULL;
    glPushMatrix = (glPushMatrixProcPtr) NULL;
    glPopMatrix = (glPopMatrixProcPtr) NULL;
    glLoadIdentity = (glLoadIdentityProcPtr) NULL;
    glLoadMatrixf = (glLoadMatrixfProcPtr) NULL;
    glLoadMatrixd = (glLoadMatrixdProcPtr) NULL;
    glMultMatrixf = (glMultMatrixfProcPtr) NULL;
    glMultMatrixd = (glMultMatrixdProcPtr) NULL;
    glRotatef = (glRotatefProcPtr) NULL;
    glScalef = (glScalefProcPtr) NULL;
    glTranslatef = (glTranslatefProcPtr) NULL;

    // Drawing
    glBegin = (glBeginProcPtr) NULL;
    glEnd = (glEndProcPtr) NULL;
    glVertex2f = (glVertex2fProcPtr) NULL;
    glVertex2i = (glVertex2iProcPtr) NULL;
    glVertex3f = (glVertex3fProcPtr) NULL;
    glVertex3d = (glVertex3dProcPtr) NULL;
    glVertex3fv = (glVertex3fvProcPtr) NULL;
    glVertex3dv = (glVertex3dvProcPtr) NULL;
    glRecti = (glRectiProcPtr) NULL;
    glColor3f = (glColor3fProcPtr) NULL;
    glColor4f = (glColor4fProcPtr) NULL;
    glColor4ub = (glColor4ubProcPtr) NULL;
    glTexCoord2d = (glTexCoord2dProcPtr) NULL;
    glTexCoord2f = (glTexCoord2fProcPtr) NULL;
    glTexCoord2i = (glTexCoord2iProcPtr) NULL;
    glNormal3f = (glNormal3fProcPtr) NULL;

    // Lighting
    glShadeModel = (glShadeModelProcPtr) NULL;
    glLightfv = (glLightfvProcPtr) NULL;

    // Raster funcs
    glReadPixels = (glReadPixelsProcPtr) NULL;
    glRasterPos4i = (glRasterPos4iProcPtr) NULL;
    glDrawPixels = (glDrawPixelsProcPtr) NULL;
    glPixelStorei = (glPixelStoreiProcPtr) NULL;

    // Texture mapping
    glTexEnvf = (glTexEnvfProcPtr) NULL;
    glGenTextures = (glGenTexturesProcPtr) NULL;
    glDeleteTextures = (glDeleteTexturesProcPtr) NULL;
    glBindTexture = (glBindTextureProcPtr) NULL;
    glTexImage2D = (glTexImage2DProcPtr) NULL;
    glCopyTexImage2D = (glCopyTexImage2DProcPtr) NULL;
    glCopyTexSubImage2D = (glCopyTexSubImage2DProcPtr) NULL;
    glTexSubImage2D = (glTexSubImage2DProcPtr) NULL;
    glTexParameterf = (glTexParameterfProcPtr) NULL;
    glTexParameteri = (glTexParameteriProcPtr) NULL;
    glGetTexParameteriv = (glGetTexParameterivProcPtr) NULL;
    glGetTexLevelParameteriv = (glGetTexLevelParameterivProcPtr) NULL;
    glTexGenfv = (glTexGenfvProcPtr) NULL;

    // Fog
    glFogf = (glFogfProcPtr) NULL;
    glFogi = (glFogiProcPtr) NULL;
    glFogfv = (glFogfvProcPtr) NULL;

    // Display Lists
    glNewList = (glNewListProcPtr) NULL;
    glEndList = (glEndListProcPtr) NULL;
    glCallList = (glCallListProcPtr) NULL;
    glDeleteLists = (glDeleteListsProcPtr) NULL;

    // Vertex Arrays
    glEnableClientState = (glEnableClientStateProcPtr) NULL;
    glDisableClientState = (glDisableClientStateProcPtr) NULL;
    glVertexPointer = (glVertexPointerProcPtr) NULL;
    glNormalPointer = (glNormalPointerProcPtr) NULL;
    glTexCoordPointer = (glTexCoordPointerProcPtr) NULL;
    glDrawArrays = (glDrawArraysProcPtr) NULL;
    glDrawElements = (glDrawElementsProcPtr) NULL;

    // Stencil Buffer
    glClearStencil = (glClearStencilProcPtr) NULL;
    glStencilOp = (glStencilOpProcPtr) NULL;
    glStencilFunc = (glStencilFuncProcPtr) NULL;
#endif

#if defined DYNAMIC_GLEXT
    glBlendEquation = (glBlendEquationProcPtr) NULL;

    glTexImage3D = (glTexImage3DProcPtr) NULL;
    glCompressedTexImage2DARB = (glCompressedTexImage2DARBProcPtr) NULL;
    glGetCompressedTexImageARB = (glGetCompressedTexImageARBProcPtr) NULL;

    // GPU Programs
    glGenProgramsARB = (glGenProgramsARBProcPtr) NULL;
    glBindProgramARB = (glBindProgramARBProcPtr) NULL;
    glProgramStringARB = (glProgramStringARBProcPtr) NULL;
    glDeleteProgramsARB = (glDeleteProgramsARBProcPtr) NULL;

    // Multitexturing
    glActiveTextureARB = (glActiveTextureARBProcPtr) NULL;
    glClientActiveTextureARB = (glClientActiveTextureARBProcPtr) NULL;
    glMultiTexCoord2dARB = (glMultiTexCoord2dARBProcPtr) NULL;
    glMultiTexCoord2fARB = (glMultiTexCoord2fARBProcPtr) NULL;

    // Frame Buffer Objects
    glGenFramebuffersEXT = (glGenFramebuffersEXTProcPtr) NULL;
    glBindFramebufferEXT = (glBindFramebufferEXTProcPtr) NULL;
    glFramebufferTexture2DEXT = (glFramebufferTexture2DEXTProcPtr) NULL;
    glCheckFramebufferStatusEXT = (glCheckFramebufferStatusEXTProcPtr) NULL;
    glDeleteFramebuffersEXT = (glDeleteFramebuffersEXTProcPtr) NULL;

    // Vertex Buffer Objects
    glGenBuffersARB = (glGenBuffersARBProcPtr) NULL;
    glBindBufferARB = (glBindBufferARBProcPtr) NULL;
    glDeleteBuffersARB = (glDeleteBuffersARBProcPtr) NULL;
    glBufferDataARB = (glBufferDataARBProcPtr) NULL;
    glBufferSubDataARB = (glBufferSubDataARBProcPtr) NULL;
    glMapBufferARB = (glMapBufferARBProcPtr) NULL;
    glUnmapBufferARB = (glUnmapBufferARBProcPtr) NULL;

    // ARB_buffer_storage
    glBufferStorage = (glBufferStorageProcPtr) NULL;

    // ARB_map_buffer_range
    glMapBufferRange = (glMapBufferRangeProcPtr)NULL;

    // Occlusion queries
    glGenQueriesARB = (glGenQueriesARBProcPtr) NULL;
    glDeleteQueriesARB = (glDeleteQueriesARBProcPtr) NULL;
    glIsQueryARB = (glIsQueryARBProcPtr) NULL;
    glBeginQueryARB = (glBeginQueryARBProcPtr) NULL;
    glEndQueryARB = (glEndQueryARBProcPtr) NULL;
    glGetQueryivARB = (glGetQueryivARBProcPtr) NULL;
    glGetQueryObjectivARB = (glGetQueryObjectivARBProcPtr) NULL;
    glGetQueryObjectuivARB = (glGetQueryObjectuivARBProcPtr) NULL;

    // Shader Objects
    glDeleteObjectARB = (glDeleteObjectARBProcPtr) NULL;
    glGetHandleARB = (glGetHandleARBProcPtr) NULL;
    glDetachObjectARB = (glDetachObjectARBProcPtr) NULL;
    glCreateShaderObjectARB = (glCreateShaderObjectARBProcPtr) NULL;
    glShaderSourceARB = (glShaderSourceARBProcPtr) NULL;
    glCompileShaderARB = (glCompileShaderARBProcPtr) NULL;
    glCreateProgramObjectARB = (glCreateProgramObjectARBProcPtr) NULL;
    glAttachObjectARB = (glAttachObjectARBProcPtr) NULL;
    glLinkProgramARB = (glLinkProgramARBProcPtr) NULL;
    glUseProgramObjectARB = (glUseProgramObjectARBProcPtr) NULL;
    glValidateProgramARB = (glValidateProgramARBProcPtr) NULL;
    glUniform1fARB = (glUniform1fARBProcPtr) NULL;
    glUniform2fARB = (glUniform2fARBProcPtr) NULL;
    glUniform3fARB = (glUniform3fARBProcPtr) NULL;
    glUniform4fARB = (glUniform4fARBProcPtr) NULL;
    glUniform1iARB = (glUniform1iARBProcPtr) NULL;
    glUniform2iARB = (glUniform2iARBProcPtr) NULL;
    glUniform3iARB = (glUniform3iARBProcPtr) NULL;
    glUniform4iARB = (glUniform4iARBProcPtr) NULL;
    glUniform1fvARB = (glUniform1fvARBProcPtr) NULL;
    glUniform2fvARB = (glUniform2fvARBProcPtr) NULL;
    glUniform3fvARB = (glUniform3fvARBProcPtr) NULL;
    glUniform4fvARB = (glUniform4fvARBProcPtr) NULL;
    glUniform1ivARB = (glUniform1ivARBProcPtr) NULL;
    glUniform2ivARB = (glUniform2ivARBProcPtr) NULL;
    glUniform3ivARB = (glUniform3ivARBProcPtr) NULL;
    glUniform4ivARB = (glUniform4ivARBProcPtr) NULL;
    glUniformMatrix2fvARB = (glUniformMatrix2fvARBProcPtr) NULL;
    glUniformMatrix3fvARB = (glUniformMatrix3fvARBProcPtr) NULL;
    glUniformMatrix4fvARB = (glUniformMatrix4fvARBProcPtr) NULL;
    glGetObjectParameterfvARB = (glGetObjectParameterfvARBProcPtr) NULL;
    glGetObjectParameterivARB = (glGetObjectParameterivARBProcPtr) NULL;
    glGetInfoLogARB = (glGetInfoLogARBProcPtr) NULL;
    glGetAttachedObjectsARB = (glGetAttachedObjectsARBProcPtr) NULL;
    glGetUniformLocationARB = (glGetUniformLocationARBProcPtr) NULL;
    glGetActiveUniformARB = (glGetActiveUniformARBProcPtr) NULL;
    glGetUniformfvARB = (glGetUniformfvARBProcPtr) NULL;
    glGetUniformivARB = (glGetUniformivARBProcPtr) NULL;
    glGetShaderSourceARB = (glGetShaderSourceARBProcPtr) NULL;

    // Vertex Shaders
    glVertexAttrib1dARB = (glVertexAttrib1dARBProcPtr) NULL;
    glVertexAttrib1dvARB = (glVertexAttrib1dvARBProcPtr) NULL;
    glVertexAttrib1fARB = (glVertexAttrib1fARBProcPtr) NULL;
    glVertexAttrib1fvARB = (glVertexAttrib1fvARBProcPtr) NULL;
    glVertexAttrib1sARB = (glVertexAttrib1sARBProcPtr) NULL;
    glVertexAttrib1svARB = (glVertexAttrib1svARBProcPtr) NULL;
    glVertexAttrib2dARB = (glVertexAttrib2dARBProcPtr) NULL;
    glVertexAttrib2dvARB = (glVertexAttrib2dvARBProcPtr) NULL;
    glVertexAttrib2fARB = (glVertexAttrib2fARBProcPtr) NULL;
    glVertexAttrib2fvARB = (glVertexAttrib2fvARBProcPtr) NULL;
    glVertexAttrib2sARB = (glVertexAttrib2sARBProcPtr) NULL;
    glVertexAttrib2svARB = (glVertexAttrib2svARBProcPtr) NULL;
    glVertexAttrib3dARB = (glVertexAttrib3dARBProcPtr) NULL;
    glVertexAttrib3dvARB = (glVertexAttrib3dvARBProcPtr) NULL;
    glVertexAttrib3fARB = (glVertexAttrib3fARBProcPtr) NULL;
    glVertexAttrib3fvARB = (glVertexAttrib3fvARBProcPtr) NULL;
    glVertexAttrib3sARB = (glVertexAttrib3sARBProcPtr) NULL;
    glVertexAttrib3svARB = (glVertexAttrib3svARBProcPtr) NULL;
    glVertexAttrib4NbvARB = (glVertexAttrib4NbvARBProcPtr) NULL;
    glVertexAttrib4NivARB = (glVertexAttrib4NivARBProcPtr) NULL;
    glVertexAttrib4NsvARB = (glVertexAttrib4NsvARBProcPtr) NULL;
    glVertexAttrib4NubARB = (glVertexAttrib4NubARBProcPtr) NULL;
    glVertexAttrib4NubvARB = (glVertexAttrib4NubvARBProcPtr) NULL;
    glVertexAttrib4NuivARB = (glVertexAttrib4NuivARBProcPtr) NULL;
    glVertexAttrib4NusvARB = (glVertexAttrib4NusvARBProcPtr) NULL;
    glVertexAttrib4bvARB = (glVertexAttrib4bvARBProcPtr) NULL;
    glVertexAttrib4dARB = (glVertexAttrib4dARBProcPtr) NULL;
    glVertexAttrib4dvARB = (glVertexAttrib4dvARBProcPtr) NULL;
    glVertexAttrib4fARB = (glVertexAttrib4fARBProcPtr) NULL;
    glVertexAttrib4fvARB = (glVertexAttrib4fvARBProcPtr) NULL;
    glVertexAttrib4ivARB = (glVertexAttrib4ivARBProcPtr) NULL;
    glVertexAttrib4sARB = (glVertexAttrib4sARBProcPtr) NULL;
    glVertexAttrib4svARB = (glVertexAttrib4svARBProcPtr) NULL;
    glVertexAttrib4ubvARB = (glVertexAttrib4ubvARBProcPtr) NULL;
    glVertexAttrib4uivARB = (glVertexAttrib4uivARBProcPtr) NULL;
    glVertexAttrib4usvARB = (glVertexAttrib4usvARBProcPtr) NULL;
    glVertexAttribPointerARB = (glVertexAttribPointerARBProcPtr) NULL;
    glEnableVertexAttribArrayARB = (glEnableVertexAttribArrayARBProcPtr) NULL;
    glDisableVertexAttribArrayARB = (glDisableVertexAttribArrayARBProcPtr) NULL;
    glGetVertexAttribdvARB = (glGetVertexAttribdvARBProcPtr) NULL;
    glGetVertexAttribfvARB = (glGetVertexAttribfvARBProcPtr) NULL;
    glGetVertexAttribivARB = (glGetVertexAttribivARBProcPtr) NULL;
    glGetVertexAttribPointervARB = (glGetVertexAttribPointervARBProcPtr) NULL;
    glBindAttribLocationARB = (glBindAttribLocationARBProcPtr) NULL;
    glGetActiveAttribARB = (glGetActiveAttribARBProcPtr) NULL;
    glGetAttribLocationARB = (glGetAttribLocationARBProcPtr) NULL;

    // Debug Output
#ifndef __APPLE__
    glDebugMessageControlARB = (glDebugMessageControlARBProcPtr) NULL;
    glDebugMessageCallbackARB = (glDebugMessageCallbackARBProcPtr) NULL;
#endif

#ifdef _WIN32
    wglSwapIntervalEXT = (wglSwapIntervalEXTProcPtr) NULL;
    wglCreateContextAttribsARB = (wglCreateContextAttribsARBProcPtr) NULL;
#endif
#endif

    return 0;
}

#if defined DYNAMIC_GLU
#if defined _WIN32
static HMODULE hGLUDLL;
#else
static void *gluhandle = NULL;
#endif

char *glulibrary = NULL;

static void *glugetproc_(const char *s, int32_t *err, int32_t fatal)
{
    void *t;
#if defined _WIN32
    t = (void *)GetProcAddress(hGLUDLL,s);
#else
    t = (void *)dlsym(gluhandle,s);
#endif
    if (!t && fatal)
    {
        initprintf("Failed to find %s in %s\n", s, glulibrary);
        *err = 1;
    }
    return t;
}
#define GLUGETPROC(s)        glugetproc_(s,&err,1)
#define GLUGETPROCSOFT(s)    glugetproc_(s,&err,0)
#endif

int32_t loadglulibrary(const char *driver)
{
#if defined DYNAMIC_GLU
    int32_t err=0;

#if defined _WIN32
    if (hGLUDLL) return 0;
#endif

    if (!driver)
    {
#ifdef _WIN32
        driver = "glu32.dll";
#elif defined __APPLE__
        driver = "/System/Library/Frameworks/OpenGL.framework/OpenGL"; // FIXME: like I know anything about Apple.  Hah.
#elif defined __OpenBSD__
        driver = "liglU.so";
#else
        driver = "liglU.so.1";
#endif
    }

#if defined _WIN32
    hGLUDLL = LoadLibrary(driver);
    if (!hGLUDLL)
#else
    gluhandle = dlopen(driver, RTLD_NOW|RTLD_GLOBAL);
    if (!gluhandle)
#endif
    {
        initprintf("Failed loading \"%s\"\n",driver);
        return -1;
    }

    glulibrary = Bstrdup(driver);

    gluTessBeginContour = (gluTessBeginContourProcPtr) GLUGETPROC("gluTessBeginContour");
    gluTessBeginPolygon = (gluTessBeginPolygonProcPtr) GLUGETPROC("gluTessBeginPolygon");
    gluTessCallback = (gluTessCallbackProcPtr) GLUGETPROC("gluTessCallback");
    gluTessEndContour = (gluTessEndContourProcPtr) GLUGETPROC("gluTessEndContour");
    gluTessEndPolygon = (gluTessEndPolygonProcPtr) GLUGETPROC("gluTessEndPolygon");
    gluTessNormal = (gluTessNormalProcPtr) GLUGETPROC("gluTessNormal");
    gluTessProperty = (gluTessPropertyProcPtr) GLUGETPROC("gluTessProperty");
    gluTessVertex = (gluTessVertexProcPtr) GLUGETPROC("gluTessVertex");
    gluNewTess = (gluNewTessProcPtr) GLUGETPROC("gluNewTess");
    gluDeleteTess = (gluDeleteTessProcPtr) GLUGETPROC("gluDeleteTess");

    gluPerspective = (gluPerspectiveProcPtr) GLUGETPROC("gluPerspective");

    gluErrorString = (gluErrorStringProcPtr) GLUGETPROC("gluErrorString");

    gluProject = (gluProjectProcPtr) GLUGETPROC("gluProject");
    gluUnProject = (gluUnProjectProcPtr) GLUGETPROC("gluUnProject");

    if (err) unloadglulibrary();
    return err;
#else
    UNREFERENCED_PARAMETER(driver);
    return 0;
#endif
}

int32_t unloadglulibrary(void)
{
#if defined DYNAMIC_GLU
#if defined _WIN32
    if (!hGLUDLL) return 0;
#endif

    DO_FREE_AND_NULL(glulibrary);

#if defined _WIN32
    FreeLibrary(hGLUDLL);
    hGLUDLL = NULL;
#else
    if (gluhandle) dlclose(gluhandle);
    gluhandle = NULL;
#endif

    gluTessBeginContour = (gluTessBeginContourProcPtr) NULL;
    gluTessBeginPolygon = (gluTessBeginPolygonProcPtr) NULL;
    gluTessCallback = (gluTessCallbackProcPtr) NULL;
    gluTessEndContour = (gluTessEndContourProcPtr) NULL;
    gluTessEndPolygon = (gluTessEndPolygonProcPtr) NULL;
    gluTessNormal = (gluTessNormalProcPtr) NULL;
    gluTessProperty = (gluTessPropertyProcPtr) NULL;
    gluTessVertex = (gluTessVertexProcPtr) NULL;
    gluNewTess = (gluNewTessProcPtr) NULL;
    gluDeleteTess = (gluDeleteTessProcPtr) NULL;

    gluPerspective = (gluPerspectiveProcPtr) NULL;

    gluErrorString = (gluErrorStringProcPtr) NULL;

    gluProject = (gluProjectProcPtr) NULL;
    gluUnProject = (gluUnProjectProcPtr) NULL;
#endif

    return 0;
}


//////// glGenTextures/glDeleteTextures debugging ////////
# if defined DEBUGGINGAIDS && defined DEBUG_TEXTURE_NAMES
static uint8_t *texnameused;  // bitmap
static uint32_t *texnamefromwhere;  // hash of __FILE__
static uint32_t texnameallocsize;

// djb3 algorithm
static inline uint32_t texdbg_getcode(const char *s)
{
    uint32_t h = 5381;
    int32_t ch;

    while ((ch = *s++) != '\0')
        h = ((h << 5) + h) ^ ch;

    return h;
}

static void texdbg_realloc(uint32_t maxtexname)
{
    uint32_t newsize = texnameallocsize ? texnameallocsize : 64;

    if (maxtexname < texnameallocsize)
        return;

    while (maxtexname >= newsize)
        newsize <<= 1;
//    initprintf("texdebug: new size %u\n", newsize);

    texnameused = Xrealloc(texnameused, newsize>>3);
    texnamefromwhere = Xrealloc(texnamefromwhere, newsize*sizeof(uint32_t));

    Bmemset(texnameused + (texnameallocsize>>3), 0, (newsize-texnameallocsize)>>3);
    Bmemset(texnamefromwhere + texnameallocsize, 0, (newsize-texnameallocsize)*sizeof(uint32_t));

    texnameallocsize = newsize;
}

#undef glGenTextures
void texdbg_glGenTextures(GLsizei n, GLuint *textures, const char *srcfn)
{
    int32_t i;
    uint32_t hash = srcfn ? texdbg_getcode(srcfn) : 0;

    for (i=0; i<n; i++)
        if (textures[i] < texnameallocsize && (texnameused[textures[i]>>3]&(1<<(textures[i]&7))))
            initprintf("texdebug %x Gen: overwriting used tex name %u from %x\n", hash, textures[i], texnamefromwhere[textures[i]]);

    glGenTextures(n, textures);

    {
        GLuint maxtexname = 0;

        for (i=0; i<n; i++)
            maxtexname = max(maxtexname, textures[i]);

        texdbg_realloc(maxtexname);

        for (i=0; i<n; i++)
        {
            texnameused[textures[i]>>3] |= (1<<(textures[i]&7));
            texnamefromwhere[textures[i]] = hash;
        }
    }
}

#undef glDeleteTextures
void texdbg_glDeleteTextures(GLsizei n, const GLuint *textures, const char *srcfn)
{
    int32_t i;
    uint32_t hash = srcfn ? texdbg_getcode(srcfn) : 0;

    for (i=0; i<n; i++)
        if (textures[i] < texnameallocsize)
        {
            if ((texnameused[textures[i]>>3]&(1<<(textures[i]&7)))==0)
                initprintf("texdebug %x Del: deleting unused tex name %u\n", hash, textures[i]);
            else if ((texnameused[textures[i]>>3]&(1<<(textures[i]&7))) &&
                         texnamefromwhere[textures[i]] != hash)
                initprintf("texdebug %x Del: deleting foreign tex name %u from %x\n", hash,
                           textures[i], texnamefromwhere[textures[i]]);
        }

    glDeleteTextures(n, textures);

    if (texnameallocsize)
        for (i=0; i<n; i++)
        {
            texnameused[textures[i]>>3] &= ~(1<<(textures[i]&7));
            texnamefromwhere[textures[i]] = 0;
        }
}
# endif  // defined DEBUGGINGAIDS

#endif
