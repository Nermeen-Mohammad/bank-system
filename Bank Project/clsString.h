#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class clsString
{
private:
	string _Value;

public:
	clsString()
	{
		_Value = "";
	}

	clsString(string value)
	{
		_Value = value;
	}

	void SetString(string value)
	{
		_Value = value;
	}

	string GetString()
	{
		return _Value;
	}

	__declspec(property(get = GetString, put = SetString)) string Value;


	static int CountWords(string x)
	{
		int CountWords = 0;
		string delim = " "; //delimiter

		short pos = 0;
		string sWord;

		// use find() function to get the position of the delimiters 
		while ((pos = x.find(delim)) != std::string::npos) {
			sWord = x.substr(0, pos);// store the wor
			if (sWord != "") {
				CountWords++;
			}
			x.erase(0, pos + delim.length());/* erase() until positon and move to next word. */

		}

		return ++CountWords;

	}

	int CountWords()
	{
		return CountWords(_Value);
	}

	static string  UpperFirstLetterOfEachWord(string S1)
	{

		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);

			}

			isFirstLetter = (S1[i] == ' ' ? true : false);

		}

		return S1;
	}

	void  UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static int Length(string S)
	{
		return S.length();
	}

	int Length()
	{
		return _Value.length();
	}

	static string  LowerFirstLetterOfEachWord(string S1)
	{

		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = tolower(S1[i]);

			}

			isFirstLetter = (S1[i] == ' ' ? true : false);

		}

		return S1;
	}

	void  LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string S)
	{
		bool IsFirstLetter = true;
		for (int i = 0; i < S.length(); i++)
		{
			S[i] = toupper(S[i]);

		}
		return S;

	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string S)
	{
		bool IsFirstLetter = true;
		for (int i = 0; i < S.length(); i++)
		{
			S[i] = tolower(S[i]);

		}
		return S;

	}

	string 	LowerAllString()
	{
		return 	LowerAllString(_Value);

	}

	static char  InvertLetterCase(char char1)
	{
		return isupper(char1) ? tolower(char1) : toupper(char1);
	}

	static string  InvertAllLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}

	void  InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	enum enWhatToCount {
		SmallLetters = 1, CapitalLetters
		= 2, All = 3
	};

	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{


		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				Counter++;


			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				Counter++;


		}

		return Counter;

	}

	static int CountCapitalLetters(string S)
	{
		int CapitalCounter = 0;
		for (int i = 0; i < S.length(); i++) {
			if (isupper(S[i]))
				CapitalCounter++;
		}
		return CapitalCounter;
	}

	int CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static int CountSmallLetters(string S)
	{
		int SmallCounter = 0;
		for (int i = 0; i < S.length(); i++) {
			if (islower(S[i]))
				SmallCounter++;
		}
		return SmallCounter;
	}

	int CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static bool IsVowel(char ch)
	{
		ch = tolower(ch);
		return ((ch == 'a') || (ch == 'u') || (ch == 'i') || (ch == 'e') || (ch == 'o'));
	}

	static int CountVowels(string X)
	{
		int counter = 0;
		for (int i = 0; i < X.length(); i++) {

			if (IsVowel(X[i]))
				counter++;

		}
		return counter;
	}

	int CountVowels()
	{
		return CountVowels(_Value);
	}

	static short CountSpecificLetter(string S, char X, bool MatchCase = true)
	{
		int Counter = 0;
		for (int i = 0; i < S.length(); i++)
		{
			if (MatchCase)
			{
				if (S[i] == X)
					Counter++;
			}
			else
			{
				if (tolower(S[i]) == tolower(X));
				Counter++;
			}
		}
		return Counter;
	}

	short CountSpecificLetter(char X, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, X, true);
	}

	static string TrimLeft(string x)
	{
		for (int i = 0; i < x.length(); i++)
		{
			if (x[i] != ' ')
				return x.substr(i, x.length() - 1);
		}
		return "";
	}

	string TrimLeft()
	{
		return  TrimLeft(_Value);
	}

	static string TrimRight(string x)
	{
		for (int i = x.length() - 1; i >= 0; i--)
		{
			if (x[i] != ' ')
			{
				return x.substr(0, i + 1);
			}
		}
		return ""; // if the input string = just spaces
	}

	string TrimRight()
	{
		return TrimRight(_Value);
	}

	static string Trim(string x)
	{
		return (TrimLeft(TrimRight(x)));
	}

	string Trim()
	{
		return Trim(_Value);
	}

	static string RemovePunctuations(string s1)
	{
		string s2 = "";
		for (int i = 0; i < s1.length(); i++)
		{
			if (!ispunct(s1[i]))
				s2 += s1[i];

		}
		return s2;
	}

	string RemovePunctuations()
	{
		return  RemovePunctuations(_Value);
	}

	static string ReplaceWord(string s1, string stringToReplace, string ReplaceTo)
	{
		short pos = s1.find(stringToReplace);
		while (pos != std::string::npos) {
			s1.replace(pos, stringToReplace.length(), ReplaceTo);
			pos = s1.find(stringToReplace);
		}
		return s1;
	}

	string ReplaceWord(string stringToReplace, string ReplaceTo)
	{
		return ReplaceWord(_Value, stringToReplace, ReplaceTo);
	}

	static vector <string> Split(string x, string delim)
	{
		vector <string> vString;


		short pos = 0;
		string word = "";
		while ((pos = x.find(delim)) != std::string::npos)
		{
			word = x.substr(0, pos);
			if (word != "")
			{
				vString.push_back(word);
			}


			x.erase(0, pos + delim.length());

		}

		if (x != "") {
			vString.push_back(x);
		}
		return vString;
	}

	vector <string> Split(string delim)
	{
		return Split(_Value, delim);
	}

	static string JoinString(vector <string> sVector, string delim)
	{
		string NewString = "";
		for (int i = 0; i < sVector.size(); i++)
		{
			NewString += sVector[i] + delim;
		}
		return NewString.substr(0, NewString.length() - delim.length());
	}

	static string JoinString(string array[], string delim, int ArrayLength)
	{
		string NewString = "";
		for (int i = 0; i < ArrayLength; i++)
		{
			NewString += array[i] + delim;
		}
		return NewString.substr(0, NewString.length() - delim.length());
	}

	static string ReverseWordsInString(string s)
	{
		vector <string> vec;
		string s2 = "";
		vec = Split(s, " ");

		vector <string>::iterator it = vec.end();
		while (it != vec.begin())
		{
			--it;
			s2 += *it + " ";
		}
		s2 = s2.substr(0, s2.length() - 1);
		return s2;
	}

	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}


};

