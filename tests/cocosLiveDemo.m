//
// cocos live demo
// a cocos2d example
//

#import <UIKit/UIKit.h>

// cocos import
#import "cocoslive.h"

// local import
#import "cocosLiveDemo.h"

// CLASS IMPLEMENTATIONS
@implementation AppController

-(void) applicationDidFinishLaunching:(UIApplication*)application
{
	ScoreServer *server = [ScoreServer serverWithGameName:@"SapusTongue" gameKey:@"AABBCCDDEEFF" delegate:nil];
	
	NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithCapacity:2];
	
	[dict setObject:@"100" forKey:@"score"];
	[dict setObject:@"'=&<>><//\\\\'" forKey:@"name"];
	
	[server sendScore:dict];
}
@end
