#ifndef SWAY_KEYWORDS_HPP
#define SWAY_KEYWORDS_HPP

#define DFLT_DTOR(objclass) ~objclass() = default

#define DFLT_DTOR_VIRTUAL(objclass) virtual DFLT_DTOR(objclass)

#define PURE_VIRTUAL(...) virtual __VA_ARGS__ = 0

#define MTHD_VIRTUAL(...) virtual __VA_ARGS__

#define MTHD_OVERRIDE(...) MTHD_VIRTUAL(__VA_ARGS__ override)

#endif  // SWAY_KEYWORDS_HPP
