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
	ScoreServer *server = [[ScoreServer alloc] initWithGameName:@"SapusTongue" gameKey:@"945fe3ede5de5ae8f45461b46fd954ba" delegate:nil];

	NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithCapacity:2];
	
	[dict setObject: [NSNumber numberWithInt:888845] forKey:@"usr_score"];
	
	[server sendScore:dict];
	[server release];
}

-(void) testRequest
{
	ScoreServerRequest *request = [[ScoreServerRequest alloc] initWithGameName:@"SapusTongue" delegate:self];
	[request requestScores:0 limit:25 offset:0 order:0 flags:0];
}

-(void) scoreRequestOk: (id) sender
{
	NSLog(@"score request OK");
	
//	NSArray *scores = [sender parseScores];	
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
