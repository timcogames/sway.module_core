#ifndef SWAY_NAMESPACEMACROS_H
#define SWAY_NAMESPACEMACROS_H

/*!
 * \brief
 *    Открывает область пространства имен.
 *
 * \param name
 *    Имя области пространства имен.
 * 
 * \sa
 *    NAMESPACE_END
 */
#define NAMESPACE_BEGIN(name) namespace name {

/*!
 * \brief
 *    Закрывает область пространства имен.
 *
 * \param name
 *    Имя области пространства имен.
 * 
 * \sa
 *    NAMESPACE_BEGIN
 */
#define NAMESPACE_END(name) }

#endif // SWAY_NAMESPACEMACROS_H
