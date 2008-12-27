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
#define SCORE_SERVER_SEND_URL @"http://cocoslive.appspot.com/post-score"


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

/** send the scores to the server */
-(BOOL) sendScore: (NSDictionary*) dict;

@end

/** CocosLiveConnection protocol */
@protocol CocosLiveConnection
-(void) scoreRequestOk:(id) sender;
-(void) scoreRequestFail:(id) sender;
@end
