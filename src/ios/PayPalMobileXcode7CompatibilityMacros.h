/**
 * The following preprocessor macros can be used to adopt the new nullability annotations and generics
 * features available in Xcode 7, while maintaining backwards compatibility with earlier versions of
 * Xcode that do not support these features.
 *
 * Originally taken from https://gist.github.com/smileyborg/d513754bc1cf41678054
 */

#if __has_feature(nullability)
#   define PPM_ASSUME_NONNULL_BEGIN      NS_ASSUME_NONNULL_BEGIN
#   define PPM_ASSUME_NONNULL_END        NS_ASSUME_NONNULL_END
#   define PPM_NULLABLE                  nullable
#   define PPM_NONNULL                   nonnull
#   define _PPM_NULLABLE                __nullable
#   define _PPM_NONNULL                 __nonnull
#else
#   define PPM_ASSUME_NONNULL_BEGIN
#   define PPM_ASSUME_NONNULL_END
#   define PPM_NULLABLE
#   define PPM_NONNULL
#   define _PPM_NULLABLE
#   define _PPM_NONNULL
#endif

#if __has_feature(objc_generics)
#   define PPM_GENERICS(class, ...)      class<__VA_ARGS__>
#   define PPM_GENERICS_TYPE(type)       type
#else
#   define PPM_GENERICS(class, ...)      class
#   define PPM_GENERICS_TYPE(type)       id
#endif
