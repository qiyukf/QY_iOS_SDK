#import "QYKFCocoaLumberjack.h"

#define AWSDDLogError(frmt, ...)   QYKFDD_LOG_MAYBE(NO,                [QYKFDDLog sharedInstance].logLevel, QYKFDDLogFlagError,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define AWSDDLogWarn(frmt, ...)    QYKFDD_LOG_MAYBE(QYKFDD_LOG_ASYNC_ENABLED, [QYKFDDLog sharedInstance].logLevel, QYKFDDLogFlagWarning, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define AWSDDLogInfo(frmt, ...)    QYKFDD_LOG_MAYBE(QYKFDD_LOG_ASYNC_ENABLED, [QYKFDDLog sharedInstance].logLevel, QYKFDDLogFlagInfo,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define AWSDDLogDebug(frmt, ...)   QYKFDD_LOG_MAYBE(QYKFDD_LOG_ASYNC_ENABLED, [QYKFDDLog sharedInstance].logLevel, QYKFDDLogFlagDebug,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define AWSDDLogVerbose(frmt, ...) QYKFDD_LOG_MAYBE(QYKFDD_LOG_ASYNC_ENABLED, [QYKFDDLog sharedInstance].logLevel, QYKFDDLogFlagVerbose, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
