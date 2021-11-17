#ifndef CTest_h
#define CTest_h

#ifdef CTEST_EXPORTS
#define CTEST_API extern "C" __declspec(dllexport)
#else
#define CTEST_API extern "C" __declspec(dllimport)
#endif

//MULTILEAP_GESTURE_RECOGNITION_API void Multileap_RecognitionOnFrame(const LEAP_TRACKING_EVENT* frame, const unsigned deviceId, float deviation, void* context);
CTEST_API void printTest();
CTEST_API void predictionTest();

#endif /* CTest_h */
