//
//  Source.h
//  MaciASL
//
//  Created by PHPdev32 on 10/1/12.
//  Licensed under GPLv3, full text at http://www.gnu.org/licenses/gpl-3.0.txt
//

@interface SourcePatch : NSObject

/*! \brief The name of the patch or repository
 *
 */
@property (readonly) NSString *name;

/*! \brief The URL of the patch or repository
 *
 */
@property (readonly) NSURL *url;

/*! \brief The patches contained in the repository
 *
 */
@property (readonly) NSDictionary *children;

@end

@interface SourceProvider : SourcePatch

@end

@interface SourceList : NSObject

/*! \brief The current list of patch providers
 *
 */
@property (readonly) NSArray *providers;

/*! \brief The network access queue, to be used by all outgoing calls
 *
 * The queue may be suspended in response to network reachability
 */
@property (readonly) NSOperationQueue *queue;

/*! \brief The shared SourceList
 *
 */
+(SourceList *)sharedList;

/*! \brief Fetches a remote UTF8 string from the given URL
 *
 * \param url The HTTP url from which to retrieve the string
 * \param completionHandler The block which receives the string, or nil, on the main thread
 */
-(void)UTF8StringWithContentsOfURL:(NSURL *)url completionHandler:(void(^)(NSString *))completionHandler;


@end

@interface SrcClassTransformer : NSValueTransformer

@end

/* Source Provider Definition
 Source = {name:<user-defined name>, url:<url without trailing slash>}
 URLs are automatically composed <url>/.maciasl, where .maciasl is the manifest
 A manifest file is a simple list of patch metadata, one patch per line
 Lines are composed like <name>\t<type>\t<url> and separated by newlines (\n)
 The only illegal field characters are tab (\t) and newline (\n)
 Type is one of DSDT or SSDT, but if absent defaults to DSDT for compatibility
 New fields may be added in the future, but <url> will _always_ be last
 Patch URLs will automatically be composed like <source URL>/<patch URL>
 It is recommended that patches start with a comment of the form:
 #Maintained by: <name> for: <site>
*/
