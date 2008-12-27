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

// Server URL
#define SCORE_SERVER_REQUEST_URL @"http://cocoslive.appspot.com/get-scores"

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


@interface ScoreServerRequest : NSObject {
	
	/// game name, used as a login name.
	NSString	*gameName;

	/// delegate instance of fetch score
	id			delegate;

	// data received
	NSMutableData *receivedData;
}

/** creates a ScoreServerRequest server with a game name*/
+(id) serverWithGameName:(NSString*) name delegate:(id)delegate;

/** initializes a ScoreServerRequest with a game name*/
-(id) initWithGameName:(NSString*) name delegate:(id)delegate;

/** request scores from server using a predefined query. This is an asyncronous request.
 * limit: a number between 1 and 1000
 * order: can be kQueryOrderAsc or kQueryOrderDesc
 * flags: can be kQueryFlagByCountry (fetches only scores from country)
 * category: an NSString. For example: 'easy', 'medium', 'type1'... When requesting scores, they can be filtered by this field.
 */
-(BOOL) requestScores: (tQueryType) type limit:(int)limit offset:(int)offset order:(tQueryOrder)order flags:(tQueryFlags)flags category:(NSString*)category;

/** request scores from server using a predefined query. This is an asyncronous request.
 * limit: a number between 1 and 1000
 * order: can be kQueryOrderAsc or kQueryOrderDesc
 * flags: can be kQueryFlagByCountry (fetches only scores from country)
 */
-(BOOL) requestScores: (tQueryType) type limit:(int)limit offset:(int)order order:(tQueryOrder)order flags:(tQueryFlags)flags;

/** parse the received JSON scores and convert it to objective-c objects */
-(NSArray*) parseScores;
@end