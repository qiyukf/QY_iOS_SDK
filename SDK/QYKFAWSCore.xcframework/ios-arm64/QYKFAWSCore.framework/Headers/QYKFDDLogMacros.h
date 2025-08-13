// Software License Agreement (BSD License)
//
// Copyright (c) 2010-2016, Deusty, LLC
// All rights reserved.
//
// Redistribution and use of this software in source and binary forms,
// with or without modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
// * Neither the name of Deusty nor the names of its contributors may be used
//   to endorse or promote products derived from this software without specific
//   prior written permission of Deusty, LLC.

// Disable legacy macros
#ifndef QYKFDD_LEGACY_MACROS
    #define QYKFDD_LEGACY_MACROS 0
#endif

#import "QYKFDDLog.h"

/**
 * Whether async should be used by log messages, excluding error messages that are always sent sync.
 **/
#ifndef QYKFDD_LOG_ASYNC_ENABLED
    #define QYKFDD_LOG_ASYNC_ENABLED YES
#endif

/**
 * These are the two macros that all other macros below compile into.
 * These big multiline macros makes all the other macros easier to read.
 **/
#define QYKFDD_LOG_MACRO(isAsynchronous, lvl, flg, ctx, atag, fnct, frmt, ...) \
     [QYKFDDLog log : isAsynchronous                                     \
             level : lvl                                                \
              flag : flg                                                \
           context : ctx                                                \
              file : __FILE__                                           \
          function : fnct                                               \
              line : __LINE__                                           \
               tag : atag                                               \
            format : (frmt), ## __VA_ARGS__]

#define LOG_MACRO_TO_QYKFDDLOG(ddlog, isAsynchronous, lvl, flg, ctx, atag, fnct, frmt, ...) \
        [ddlog log : isAsynchronous                                     \
             level : lvl                                                \
              flag : flg                                                \
           context : ctx                                                \
              file : __FILE__                                           \
          function : fnct                                               \
              line : __LINE__                                           \
               tag : atag                                               \
            format : (frmt), ## __VA_ARGS__]

/**
 * Define version of the macro that only execute if the log level is above the threshold.
 * The compiled versions essentially look like this:
 *
 * if (logFlagForThisLogMsg & ddLogLevel) { execute log message }
 *
 * When LOG_LEVEL_DEF is defined as ddLogLevel.
 *
 * As shown further below, Lumberjack actually uses a bitmask as opposed to primitive log levels.
 * This allows for a great amount of flexibility and some pretty advanced fine grained logging techniques.
 *
 * Note that when compiler optimizations are enabled (as they are for your release builds),
 * the log messages above your logging threshold will automatically be compiled out.
 *
 * (If the compiler sees LOG_LEVEL_DEF/ddLogLevel declared as a constant, the compiler simply checks to see
 *  if the 'if' statement would execute, and if not it strips it from the binary.)
 *
 * We also define shorthand versions for asynchronous and synchronous logging.
 **/
#define QYKFDD_LOG_MAYBE(async, lvl, flg, ctx, tag, fnct, frmt, ...) \
        do { QYKFDD_LOG_MACRO(async, lvl, flg, ctx, tag, fnct, frmt, ##__VA_ARGS__); } while(0)

#define LOG_MAYBE_TO_QYKFDDLOG(ddlog, async, lvl, flg, ctx, tag, fnct, frmt, ...) \
        do { LOG_MACRO_TO_QYKFDDLOG(ddlog, async, lvl, flg, ctx, tag, fnct, frmt, ##__VA_ARGS__); } while(0)

/**
 * Ready to use log macros with no context or tag.
 **/
#define QYKFDDLogError(frmt, ...)   QYKFDD_LOG_MAYBE(NO,                [QYKFDDLog sharedInstance].logLevel, QYKFDDLogFlagError,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define QYKFDDLogWarn(frmt, ...)    QYKFDD_LOG_MAYBE(QYKFDD_LOG_ASYNC_ENABLED, [QYKFDDLog sharedInstance].logLevel, QYKFDDLogFlagWarning, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define QYKFDDLogInfo(frmt, ...)    QYKFDD_LOG_MAYBE(QYKFDD_LOG_ASYNC_ENABLED, [QYKFDDLog sharedInstance].logLevel, QYKFDDLogFlagInfo,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define QYKFDDLogDebug(frmt, ...)   QYKFDD_LOG_MAYBE(QYKFDD_LOG_ASYNC_ENABLED, [QYKFDDLog sharedInstance].logLevel, QYKFDDLogFlagDebug,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define QYKFDDLogVerbose(frmt, ...) QYKFDD_LOG_MAYBE(QYKFDD_LOG_ASYNC_ENABLED, [QYKFDDLog sharedInstance].logLevel, QYKFDDLogFlagVerbose, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define QYKFDDLogErrorToQYKFDDLog(ddlog, frmt, ...)   LOG_MAYBE_TO_QYKFDDLOG(ddlog, NO,                [QYKFDDLog sharedInstance].logLevel, QYKFDDLogFlagError,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define QYKFDDLogWarnToQYKFDDLog(ddlog, frmt, ...)    LOG_MAYBE_TO_QYKFDDLOG(ddlog, QYKFDD_LOG_ASYNC_ENABLED, [QYKFDDLog sharedInstance].logLevel, QYKFDDLogFlagWarning, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define QYKFDDLogInfoToQYKFDDLog(ddlog, frmt, ...)    LOG_MAYBE_TO_QYKFDDLOG(ddlog, QYKFDD_LOG_ASYNC_ENABLED, [QYKFDDLog sharedInstance].logLevel, QYKFDDLogFlagInfo,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define QYKFDDLogDebugToQYKFDDLog(ddlog, frmt, ...)   LOG_MAYBE_TO_QYKFDDLOG(ddlog, QYKFDD_LOG_ASYNC_ENABLED, [QYKFDDLog sharedInstance].logLevel, QYKFDDLogFlagDebug,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define QYKFDDLogVerboseToQYKFDDLog(ddlog, frmt, ...) LOG_MAYBE_TO_QYKFDDLOG(ddlog, QYKFDD_LOG_ASYNC_ENABLED, [QYKFDDLog sharedInstance].logLevel, QYKFDDLogFlagVerbose, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

