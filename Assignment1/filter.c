//
//  filter.c
//  Assignment1
//
//  Created by Daniel Blyme Grundtvig on 10/09/14.
//  Copyright (c) 2014 Daniel Blyme Grundtvig. All rights reserved.
//

#include <stdio.h>
#include "filter.h"

int lowArray[13], highArray[32], derivArray[4], windowArray[30];

int filter(int input){
	int a = input;
	int b = lowPassFilt(a);
	int c = highPassFilt(b);
	int d = derivativeFilt(c);
	int e = squaringFilt(d);
	int f = windowFilt(e);
	return f;
}

int lowPassFilt(int input){
	int pointer;
	int first = 1, output = 0;
	if(first == 1)	{
		lowArray[] = {0};
		pointer = 0;
		first = 0
	}
	lowArray[pointer] = input;

	output = 2 * highArray[loopCheck(highPassFilt.pointer - 1,highArray.size())] - highArray[loopCheck(highPassFilt.pointer - 2, highArray.size()] + 1/32 *(lowArray[pointer] - 2 * lowArray[loopCheck(pointer - 6, lowArray.size())] + lowArray[loopCheck(pointer - 12, lowArray.size())]);
	loopCheck(pointer++, lowArray.size());

	return output;
}

int highPassFilt(int input){
	int pointer;
	int first = 1, output = 0;
	if(first == 1)	{
		highArray[] = {0};
		pointer = 0;
		first = 0
	}
	highArray[pointer] = input;

	output = derivArray[loopCheck(derivativeFilt.pointer - 1, derivArray.size())] - highArray[pointer]/32 + highArray[loopCheck(pointer - 16, highArray.size())] - highArray[loopCheck(pointer - 17, highArray.size())] + (highArray[loopCheck(pointer + 1, highArray.size())])/32;
	loopCheck(pointer++, highArray.size());

	return output;
}

int derivativeFilt(int input){
	int pointer;
	int first = 1, output = 0;;
	if(first == 1)	{
		derivArray[] = {0};
		pointer = 0;
		first = 0
	}
	derivArray[pointer] = input;

	output = 1/8 * (2 * derivArray[pointer] + derivArray[loopCheck(pointer - 1, derivArray.size())] - derivArray[loopCheck(pointer - 3, derivArray.size())] - 2 * derivArray[loopCheck(pointer - 4, derivArray.size())]);
	loopCheck(pointer++, derivArray.size());

	return output;
}

int squaringFilt(int input){
	return input^2;
}

int windowFilt(int input){
	int first = 1, output = 0, N = windowArray.size();
	if(first == 1)	{
		windowArray[] = {0};
		first = 0
	}
	windowArray[pointer] = input;

	for(int i = 0, i < N, i++)	{
		output = output + *windowArray[i];
	}
	output = 1/N * output;

	return output;
}

int loopCheck(int number, int limit)	{
	if(number >= limit)	{
		return number % limit;
	}
	return number;
}
