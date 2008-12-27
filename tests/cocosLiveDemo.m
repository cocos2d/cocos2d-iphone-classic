//
// cocos live demo
// a cocos2d example
//

#import <UIKit/UIKit.h>

// cocos import
#import "cocoslive.h"

// local import
#import "cocosLiveDemo.h"

@interface AppController (Private)
-(void) testRequest;
-(void) testPost;
@end

// CLASS IMPLEMENTATIONS
@implementation AppController

-(void) testPost
{
	ScoreServerPost *server = [[ScoreServerPost alloc] initWithGameName:@"TestGame" gameKey:@"dad2817f628dca0f8fe29d9b84f701ec" delegate:nil];

	NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithCapacity:2];
	
	// usr_ are fields that can be modified. user fields
	[dict setObject: [NSNumber numberWithInt:7280] forKey:@"usr_score"];
	// usr_ are fields that can be modified. user fields
	[dict setObject: [NSNumber numberWithInt:1200] forKey:@"usr_speed"];
	// usr_ are fields that can be modified. user fields
	[dict setObject: [NSNumber numberWithInt:122] forKey:@"usr_angle"];
	// usr_ are fields that can be modified. user fields
	[dict setObject: @"Tito" forKey:@"usr_playername"];
	// usr_ are fields that can be modified. user fields
	[dict setObject: [NSNumber numberWithInt:0] forKey:@"usr_playertype"];

	// cc_ are fields that cannot be modified. cocos fields
	// [dict setObject: @"" forKey:@"cc_category"];
	
	[server sendScore:dict];
	[server release];
}

-(void) testRequest
{
	ScoreServerRequest *request = [[ScoreServerRequest alloc] initWithGameName:@"SapusTongue" delegate:self];
	[request requestScores:kQueryMonth limit:25 offset:0 order:kQueryOrderDesc flags:kQueryFlagIgnore];
}

-(void) scoreRequestOk: (id) sender
{
	NSLog(@"score request OK");
	
	NSArray *scores = [sender parseScores];	
	NSLog(@"%@", scores);
	[sender release];

}

-(void) scoreRequestFail: (id) sender
{
#if DEBUG
	NSLog(@"score request fail");
#endif
	[sender release];
}


-(void) applicationDidFinishLaunching:(UIApplication*)application
{
	[self testPost];
	[self testRequest];
}
@end
