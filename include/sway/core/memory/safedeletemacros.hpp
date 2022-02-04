#ifndef _SWAY_CORE_MEMORY_SAFEDELETEMACROS_H
#define _SWAY_CORE_MEMORY_SAFEDELETEMACROS_H

/*!
 * \brief
 *    Безопасно удаляет объект и приводит указатель к NULL.
 *
 * \param[in] object
 *    Объект для удаления.
 *
 * \sa
 *    SAFE_DELETE_ARRAY
 */
#undef  SAFE_DELETE
#define SAFE_DELETE(object) if (object != NULL) { delete object; object = NULL; }
 
/*!
 * \brief
 *    Безопасно удаляет массив и приводит указатель к NULL.
 *
 * \param[in] array
 *    Массив для удаления.
 *
 * \sa
 *    SAFE_DELETE
 */
#undef  SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(array) if (array != NULL) { delete[] array; array = NULL; }

#endif // _SWAY_CORE_MEMORY_SAFEDELETEMACROS_H
