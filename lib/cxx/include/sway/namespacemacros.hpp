#ifndef SWAY_NAMESPACEMACROS_HPP
#define SWAY_NAMESPACEMACROS_HPP

#define NAMESPACE_BEGIN(NAME) namespace NAME {  // depricated
#define NAMESPACE_END() }  // depricated

#define NS_BEGIN(NAME) namespace NAME {
#define NS_BEGIN_SWAY() NS_BEGIN(sway)
#define NS_END() }

#define NS_SHORT_GENERIC(NAME) using namespace NAME;
#define NS_SHORT_SWAY() NS_SHORT_GENERIC(sway)
#define NS_SHORT(SEQ) NS_SHORT_GENERIC(sway::SEQ)

#define NS_ALIAS_GENERIC(ALIAS, NAME) namespace ALIAS = NAME;
#define NS_ALIAS(ALIAS, SEQ) NS_ALIAS_GENERIC(ALIAS, sway::SEQ)

#endif  // SWAY_NAMESPACEMACROS_HPP
