#ifndef MultiLeap_h
#define MultiLeap_h

#ifdef MULTILEAP_GESTURE_RECOGNITION_EXPORTS
#define MULTILEAP_GESTURE_RECOGNITION_API extern "C" __declspec(dllexport)
#else
#define MULTILEAP_GESTURE_RECOGNITION_API extern "C" __declspec(dllimport)
#endif

MULTILEAP_GESTURE_RECOGNITION_API void printTest();

#endif /* MultiLeap_h */
