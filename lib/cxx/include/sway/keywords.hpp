#ifndef SWAY_KEYWORDS_HPP
#define SWAY_KEYWORDS_HPP

#define DFLT_DTOR(OBJ_CLASS) ~OBJ_CLASS() = default

#define DFLT_DTOR_VIRTUAL(OBJ_CLASS) virtual DFLT_DTOR(OBJ_CLASS)

#define PURE_VIRTUAL(...) virtual __VA_ARGS__ = 0

#define MTHD_VIRTUAL(...) virtual __VA_ARGS__

#define MTHD_OVERRIDE(...) MTHD_VIRTUAL(__VA_ARGS__ override)

#endif  // SWAY_KEYWORDS_HPP
