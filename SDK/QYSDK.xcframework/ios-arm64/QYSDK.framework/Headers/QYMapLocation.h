/**
 * @file QYMapLocation.h
 * @brief 地图目的地信息。
 * @ingroup QYUIConfig
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 地图目的地的不可变数据。
 * @details 经纬度使用 GCJ-02 坐标系，名称与地址分别提供地点标识和详细地址。
 */
@interface QYMapLocation : NSObject

/** @brief 目的地经度，范围为 [-180, 180]，单位为度。 */
@property (nonatomic, assign, readonly) double longitude;
/** @brief 目的地纬度，范围为 [-90, 90]，单位为度。 */
@property (nonatomic, assign, readonly) double latitude;
/** @brief 目的地名称，例如“网易大厦2期”；未提供时为空字符串。 */
@property (nonatomic, copy, readonly) NSString *name;
/** @brief 目的地详细地址，例如“浙江省杭州市滨江区网商路399号”；未提供时为空字符串。 */
@property (nonatomic, copy, readonly) NSString *address;

/**
 * @brief 创建地图目的地信息。
 * @param longitude 目的地经度，GCJ-02 坐标，范围为 [-180, 180]，单位为度。
 * @param latitude 目的地纬度，GCJ-02 坐标，范围为 [-90, 90]，单位为度。
 * @param name 目的地名称；为 nil 时保存为空字符串。
 * @param address 目的地详细地址；为 nil 时保存为空字符串。
 * @return 目的地信息。
 */
- (instancetype)initWithLongitude:(double)longitude latitude:(double)latitude
                             name:(nullable NSString *)name address:(nullable NSString *)address NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
