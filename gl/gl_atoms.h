#ifndef GL_ATOMS_H
#define GL_ATOMS_H

enum GLFixedAtoms
{
    UR_ATOM_ADD   = 230,
    UR_ATOM_SIZE  = 252,
    UR_ATOM_LOOP  = 271,
    UR_ATOM_REPEAT= 292,
    UR_ATOM_TEXT  = 335,
    UR_ATOM_WAIT  = 375,
#ifdef __ANDROID__
    UR_ATOM_CLOSE = 386,
    UR_ATOM_WIDTH = 400,
#else
    UR_ATOM_CLOSE = 404,
    UR_ATOM_WIDTH = 419,
#endif
    UR_ATOM_HEIGHT,
    UR_ATOM_AREA,
    UR_ATOM_RECT,
    UR_ATOM_RASTER,
    UR_ATOM_TEXTURE,
    UR_ATOM_GUI_STYLE,
    UR_ATOM_VALUE,
    UR_ATOM_ELEM,
    UR_ATOM_FOCUS,
    UR_ATOM_RESIZE,
    UR_ATOM_KEY_DOWN,
    UR_ATOM_KEY_UP,
    UR_ATOM_MOUSE_MOVE,
    UR_ATOM_MOUSE_UP,
    UR_ATOM_MOUSE_DOWN,
    UR_ATOM_MOUSE_WHEEL,
    UR_ATOM_ROOT,
    UR_ATOM_PARENT,
    UR_ATOM_CHILD,
    UR_ATOM_AMBIENT,
    UR_ATOM_DIFFUSE,
    UR_ATOM_SPECULAR,
    UR_ATOM_POS,
    UR_ATOM_SHADER,
    UR_ATOM_VERTEX,
    UR_ATOM_NORMAL,
    UR_ATOM_FRAGMENT,
    UR_ATOM_DEFAULT,
    UR_ATOM_DYNAMIC,
    UR_ATOM_STATIC,
    UR_ATOM_STREAM,
    UR_ATOM_LEFT,
    UR_ATOM_RIGHT,
    UR_ATOM_CENTER,
    UR_ATOM_RGB,
    UR_ATOM_RGBA,
    UR_ATOM_DEPTH,
    UR_ATOM_CLAMP,
    UR_ATOM_NEAREST,
    UR_ATOM_LINEAR,
    UR_ATOM_MIN,
    UR_ATOM_MAG,
    UR_ATOM_MIPMAP,
    UR_ATOM_GRAY,
    UR_ATOM_BURN,
    UR_ATOM_COLOR,
    UR_ATOM_TRANS,
    UR_ATOM_SPRITE,
    UR_ATOM_ONCE,
    UR_ATOM_PING_PONG,
    UR_ATOM_PONG,
    UR_ATOM_COLLIDE,
    UR_ATOM_FALL,
    UR_ATOM_INTEGRATE,
    UR_ATOM_ATTACH,
    UR_ATOM_ANCHOR,
    UR_ATOM_BINARY,
    UR_ATOM_ACTION,
    UR_ATOM_FACE
};

#endif
