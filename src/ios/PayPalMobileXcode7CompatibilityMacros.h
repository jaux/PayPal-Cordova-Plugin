/**
 * The following preprocessor macros can be used to adopt the new nullability annotations and generics
 * features available in Xcode 7, while maintaining backwards compatibility with earlier versions of
 * Xcode that do not support these features.
 *
 * Originally taken from https://github.com/magicalpanda/MagicalRecord/blob/master/MagicalRecord/Core/MagicalRecordXcode7CompatibilityMacros.h
 */

#ifndef PayPalMobileXcode7CompatibilityMacros_h
#define PayPalMobileXcode7CompatibilityMacros_h

#if __has_feature(nullability)
#define PPM_ASSUME_NONNULL_BEGIN NS_ASSUME_NONNULL_BEGIN
#define PPM_ASSUME_NONNULL_END NS_ASSUME_NONNULL_END
#define PPM_nullable nullable
#define PPM_nonnull nonnull
#define __PPM_nullable __nullable
#define __PPM_nonnull __nonnull
#else
#define PPM_ASSUME_NONNULL_BEGIN
#define PPM_ASSUME_NONNULL_END
#define PPM_nullable
#define PPM_nonnull
#define __PPM_nullable
#define __PPM_nonnull
#endif

#if __has_feature(objc_generics)
#define PPM_GENERIC(class, ...) class<__VA_ARGS__>
#define PPM_GENERIC_TYPE(type) type
#define __PPM_kindof(class) __kindof class
#else
#define PPM_GENERIC(class, ...) class
#define PPM_GENERIC_TYPE(type) id
#define __PPM_kindof(class) id
#endif

#define PPM_NSArrayOfNSManagedObjects PPM_GENERIC(NSArray, __PPM_kindof(NSManagedObject) *) *

#endif /* PayPalMobileXcode7CompatibilityMacros_h */
