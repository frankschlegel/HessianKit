//
//  CWHessianArchiver+Private.h
//  HessianKit
//
//  Copyright 2008 Fredrik Olsson, Jayway AB. All rights reserved.
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License. 
//  You may obtain a copy of the License at 
// 
//  http://www.apache.org/licenses/LICENSE-2.0 
//  
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS, 
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import "CWHessianArchiver.h"

@interface CWHessianArchiver (Private)

-(void)encodeInt:(int)intv forKey:(NSString*)key;
-(void)encodeInteger:(NSInteger)intv forKey:(NSString*)key;

-(void)writeBytes:(const void*)buffer count:(NSInteger)count;
-(void)writeChar:(char)ch;
-(void)writeBool:(BOOL)value;
-(void)writeInt16:(int16_t)value;
-(void)writeInt32:(int32_t)value;
-(void)writeInt64:(int64_t)value;
-(void)writeDouble:(double)value;
-(void)writeDate:(NSDate*)date;
-(void)writeString:(NSString*)string withTag:(char)tag;
-(void)writeData:(NSData*)data withTag:(char)tag;
-(void)writeList:(NSArray*)list;
-(void)writeMap:(NSDictionary*)map;

-(void)writeTypedObject:(id)object;

@end


@interface CWHessianUnarchiver ()

@property(assign, nonatomic) NSInteger offset;
@property(retain, nonatomic) NSDictionary* currentObjectMap;

@end

@interface CWHessianUnarchiver (Private)

-(int)decodeIntForKey:(NSString*)key;
-(NSInteger)decodeIntegerForKey:(NSString*)key;

-(void)readBytes:(void*)buffer count:(NSInteger)count;
-(char)peekChar;
-(char)readChar;
-(int)readLength;
-(BOOL)readBool;
-(int32_t)readInt32;
-(int64_t)readInt64;
-(double)readDouble;
-(NSDate*)readDate;
-(NSString*)readStringWithTag:(char)tag;
-(NSData*)readDataWithTag:(char)tag;
-(NSException*)readFault;
-(NSArray*)readList;
-(NSDictionary*)readMapIsObject:(BOOL)isObject;
-(id)readMap;
-(CWDistantHessianObject*)readRemote;

-(id)readTypedObject;

-(id)readDecodeCandidateForKey:(NSString*)key ofClass:(Class)cls;

@end
