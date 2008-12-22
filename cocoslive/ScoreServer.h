/* cocos2d for iPhone
 *
 * http://code.google.com/p/cocos2d-iphone
 *
 * Copyright (C) 2008 Ricardo Quesada
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the 'cocos2d for iPhone' license.
 *
 * You will find a copy of this license within the cocos2d for iPhone
 * distribution inside the "LICENSE" file.
 *
 */


#import <UIKit/UIKit.h>

// for MD5 signing
#import <CommonCrypto/CommonDigest.h>

// Score Server protocol version
#define SCORE_SERVER_PROTOCOL_VERSION @"1.0"

// Server URL
#define SCORE_SERVER_URL @"http://localhost:8080/post-score"

/** Type of predefined Query */
typedef enum {
	kQueryIgnore,
	kQueryDay,
	kQueryWeek,
	kQueryMonth,
	kQueryAllTime,
} tQueryType;

/** Flags that can be added to the query */
typedef enum {
	kQueryFlagIgnore = 0,
	kQueryFlagByCountry = 1 << 1,
} tQueryFlags;

/** Order can be Asc or Desc */
typedef enum {
	kQueryOrderAsc = 0,
	kQueryOrderDesc = 1,
} tQueryOrder;


@interface ScoreServer : NSObject {
	/// game key. secret shared with the server.
	/// used to sign the values to prevent spoofing.
	NSString	*gameKey;
	
	/// game name, used as a login name.
	NSString	*gameName;

	/// delegate instance of fetch score
	id			delegate;

	// data received
	NSMutableData *receivedData;
	
	// values to send in the POST
	NSMutableArray *bodyValues;
	
	CC_MD5_CTX		md5Ctx;
}

/** creates a cocos server with a game name and a game key */
+(id) serverWithGameName:(NSString*) name gameKey:(NSString*) key delegate:(id)delegate;

/** initializes a cocos server with a game name and a game key */
-(id) initWithGameName:(NSString*) name gameKey:(NSString*) key delegate:(id)delegate;

/** fetch scores from server using a predefined query:
 * limit: a number between 1 and 1000
 * order: can be kQueryOrderAsc or kQueryOrderDesc
 * flags: can be kQueryFlagByCountry (fetches only scores from country)
 */
-(void) fetchScores: (tQueryType) type limit:(int)l order:(tQueryOrder)order flags:(tQueryFlags)flags;

/** send the scores to the server */
-(BOOL) sendScore: (NSDictionary*) dict;

@end

/** CocosLiveConnection protocol */
@protocol CocosLiveConnection
-(void) scoreRequestOk:(id) sender;
-(void) scoreRequestFail:(id) sender;
@end
