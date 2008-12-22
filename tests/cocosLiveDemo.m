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
	ScoreServer *server = [ScoreServer serverWithGameName:@"SapusTongue" gameKey:@"945fe3ede5de5ae8f45461b46fd954ba" delegate:nil];
	
	NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithCapacity:2];
	
	[dict setObject: [NSNumber numberWithInt:-1122122] forKey:@"usr_score"];
	
	[server sendScore:dict];
}
@end
