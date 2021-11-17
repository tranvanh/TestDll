#ifndef MultiLeapGestureRecognition_h
#define MultiLeapGestureRecognition_h

#ifdef MULTILEAP_GESTURE_RECOGNITION_EXPORTS
#define MULTILEAP_GESTURE_RECOGNITION_API extern "C" __declspec(dllexport)
#else
#define MULTILEAP_GESTURE_RECOGNITION_API extern "C" __declspec(dllimport)
#endif

//MULTILEAP_GESTURE_RECOGNITION_API void Multileap_RecognitionOnFrame(const LEAP_TRACKING_EVENT* frame, const unsigned deviceId, float deviation, void* context);
MULTILEAP_GESTURE_RECOGNITION_API void Multileap_printTest();
MULTILEAP_GESTURE_RECOGNITION_API void Multileap_PredictionTest();

#endif /* MultiLeapGestureRecognition_h */
