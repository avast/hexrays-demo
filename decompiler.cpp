
#include <map>

#include "context.h"
#include "decompiler.h"

/**
 * Representation of function:
 *    int __cdecl ack(int a1, int a2)
 *    {
 *       int v3; // eax
 *
 *       if ( !m )
 *         return n + 1;
 *       if ( !n )
 *         return ack(m - 1, 1);
 *       v3 = ack(m, n - 1);
 *       return ack(m - 1, v3);
 *    }
 */
Function fnc_ack =
{
	"ack",
	0x804851C,
	0x8048577,
	{
		// int __cdecl ack(int a1, int a2)
		{Token::Kind::TYPE, 0x804851C, "int"},
		{Token::Kind::WHITE_SPACE, 0x804851C, " "},
		{Token::Kind::LITERAL_SYM, 0x804851C, "__cdecl"},
		{Token::Kind::WHITE_SPACE, 0x804851C, " "},
		{Token::Kind::ID_FNC, 0x804851C, "ack"},
		{Token::Kind::PUNCTUATION, 0x804851C, "("},
		{Token::Kind::TYPE, 0x804851C, "int"},
		{Token::Kind::WHITE_SPACE, 0x804851C, " "},
		{Token::Kind::ID_ARG, 0x804851C, "m"},
		{Token::Kind::PUNCTUATION, 0x804851C, ","},
		{Token::Kind::WHITE_SPACE, 0x804851C, " "},
		{Token::Kind::TYPE, 0x804851C, "int"},
		{Token::Kind::WHITE_SPACE, 0x804851C, " "},
		{Token::Kind::ID_ARG, 0x804851C, "n"},
		{Token::Kind::PUNCTUATION, 0x804851C, ")"},
		{Token::Kind::NEW_LINE, 0x804851C, "\n"},
		// {
		{Token::Kind::PUNCTUATION, 0x804851C, "{"},
		{Token::Kind::NEW_LINE, 0x804851C, "\n"},
		//   int v3; // eax
		{Token::Kind::WHITE_SPACE, 0x804851C, "  "},
		{Token::Kind::TYPE, 0x804851C, "int"},
		{Token::Kind::WHITE_SPACE, 0x804851C, " "},
		{Token::Kind::ID_VAR, 0x804851C, "v3"},
		{Token::Kind::PUNCTUATION, 0x804851C, ";"},
		{Token::Kind::WHITE_SPACE, 0x804851C, " "},
		{Token::Kind::COMMENT, 0x804851C, "// eax"},
		{Token::Kind::NEW_LINE, 0x804851C, "\n"},
		//
		{Token::Kind::NEW_LINE, 0x804851C, "\n"},
		//   if ( !m )
		{Token::Kind::WHITE_SPACE, 0x8048526, "  "},
		{Token::Kind::KEYWORD, 0x8048526, "if"},
		{Token::Kind::WHITE_SPACE, 0x8048526, " "},
		{Token::Kind::PUNCTUATION, 0x8048526, "("},
		{Token::Kind::WHITE_SPACE, 0x8048526, " "},
		{Token::Kind::OPERATOR, 0x8048526, "!"},
		{Token::Kind::ID_ARG, 0x8048526, "m"},
		{Token::Kind::WHITE_SPACE, 0x8048526, " "},
		{Token::Kind::PUNCTUATION, 0x8048526, ")"},
		{Token::Kind::NEW_LINE, 0x8048526, "\n"},
		//     return n + 1;
		{Token::Kind::WHITE_SPACE, 0x804852B, "    "},
		{Token::Kind::KEYWORD, 0x804852B, "return"},
		{Token::Kind::WHITE_SPACE, 0x804852B, " "},
		{Token::Kind::ID_ARG, 0x804852B, "n"},
		{Token::Kind::WHITE_SPACE, 0x804852B, " "},
		{Token::Kind::OPERATOR, 0x804852B, "+"},
		{Token::Kind::WHITE_SPACE, 0x804852B, " "},
		{Token::Kind::LITERAL_INT, 0x804852B, "1"},
		{Token::Kind::PUNCTUATION, 0x804852B, ";"},
		{Token::Kind::NEW_LINE, 0x804852B, "\n"},
		//   if ( !n )
		{Token::Kind::WHITE_SPACE, 0x8048534, "  "},
		{Token::Kind::KEYWORD, 0x8048534, "if"},
		{Token::Kind::WHITE_SPACE, 0x8048534, " "},
		{Token::Kind::PUNCTUATION, 0x8048534, "("},
		{Token::Kind::WHITE_SPACE, 0x8048534, " "},
		{Token::Kind::OPERATOR, 0x8048534, "!"},
		{Token::Kind::ID_ARG, 0x8048534, "n"},
		{Token::Kind::WHITE_SPACE, 0x8048534, " "},
		{Token::Kind::PUNCTUATION, 0x8048534, ")"},
		{Token::Kind::NEW_LINE, 0x8048534, "\n"},
		//     return ack(m - 1, 1);
		{Token::Kind::WHITE_SPACE, 0x8048547, "    "},
		{Token::Kind::KEYWORD, 0x8048547, "return"},
		{Token::Kind::WHITE_SPACE, 0x8048547, " "},
		{Token::Kind::ID_FNC, 0x8048547, "ack"},
		{Token::Kind::PUNCTUATION, 0x8048547, "("},
		{Token::Kind::ID_ARG, 0x8048544, "m"},
		{Token::Kind::WHITE_SPACE, 0x8048544, " "},
		{Token::Kind::OPERATOR, 0x8048544, "-"},
		{Token::Kind::WHITE_SPACE, 0x8048544, " "},
		{Token::Kind::LITERAL_INT, 0x8048539, "1"},
		{Token::Kind::PUNCTUATION, 0x8048539, ","},
		{Token::Kind::WHITE_SPACE, 0x8048539, " "},
		{Token::Kind::LITERAL_INT, 0x804853C, "1"},
		{Token::Kind::PUNCTUATION, 0x804853C, ")"},
		{Token::Kind::PUNCTUATION, 0x804853C, ";"},
		{Token::Kind::NEW_LINE, 0x804853C, "\n"},
		//   v3 = ack(m, n - 1);
		{Token::Kind::WHITE_SPACE, 0x804855E, "  "},
		{Token::Kind::ID_VAR, 0x804855E, "v3"},
		{Token::Kind::WHITE_SPACE, 0x804855E, " "},
		{Token::Kind::OPERATOR, 0x804855E, "="},
		{Token::Kind::WHITE_SPACE, 0x804855E, " "},
		{Token::Kind::ID_FNC, 0x804855E, "ack"},
		{Token::Kind::PUNCTUATION, 0x804855E, "("},
		{Token::Kind::ID_ARG, 0x804855B, "m"},
		{Token::Kind::PUNCTUATION, 0x804855B, ","},
		{Token::Kind::WHITE_SPACE, 0x804855B, " "},
		{Token::Kind::ID_ARG, 0x8048554, "n"},
		{Token::Kind::WHITE_SPACE, 0x8048554, " "},
		{Token::Kind::OPERATOR, 0x8048554, "-"},
		{Token::Kind::WHITE_SPACE, 0x8048554, " "},
		{Token::Kind::LITERAL_INT, 0x8048551, "1"},
		{Token::Kind::PUNCTUATION, 0x8048551, ")"},
		{Token::Kind::PUNCTUATION, 0x8048551, ";"},
		{Token::Kind::NEW_LINE, 0x8048551, "\n"},
		//   return ack(m - 1, v3);
		{Token::Kind::WHITE_SPACE, 0x8048575, "  "},
		{Token::Kind::KEYWORD, 0x8048575, "return"},
		{Token::Kind::WHITE_SPACE, 0x8048575, " "},
		{Token::Kind::ID_FNC, 0x8048570, "ack"},
		{Token::Kind::PUNCTUATION, 0x8048570, "("},
		{Token::Kind::ID_ARG, 0x804856D, "m"},
		{Token::Kind::WHITE_SPACE, 0x804856D, " "},
		{Token::Kind::OPERATOR, 0x804856D, "-"},
		{Token::Kind::WHITE_SPACE, 0x804856D, " "},
		{Token::Kind::LITERAL_INT, 0x8048566, "1"},
		{Token::Kind::PUNCTUATION, 0x8048566, ","},
		{Token::Kind::WHITE_SPACE, 0x8048566, " "},
		{Token::Kind::ID_VAR, 0x8048569, "v3"},
		{Token::Kind::PUNCTUATION, 0x8048569, ")"},
		{Token::Kind::PUNCTUATION, 0x8048569, ";"},
		{Token::Kind::NEW_LINE, 0x8048569, "\n"},
		// }
		{Token::Kind::PUNCTUATION, 0x8048576, "}"},
		// Do not add new line at the end.
		// For whatever reason, the last line is not displayed if the max
		// place's X coordinate isn't 0.
		// So always put only one token at the last line.
	}
};

/**
 * Representation of function:
 *    int __cdecl main(int argc, const char **argv, const char **envp)
 *    {
 *      int v4; // [esp+14h] [ebp-Ch]
 *      int v5; // [esp+18h] [ebp-8h]
 *      int v6; // [esp+1Ch] [ebp-4h]
 *
 *      v6 = 0;
 *      v5 = 0;
 *      v4 = 0;
 *      __isoc99_scanf(\"%d %d\", &v5, &v4);
 *      v6 = ack(v5, v4);
 *      printf("ackerman( %d , %d ) = %d\n", v5, v4, v6);
 *      return v6;
 *    }
 */
Function fnc_main =
{
	"main",
	0x8048577,
	0x80485F6,
	{
		// int __cdecl main(int argc, const char **argv, const char **envp)
		{Token::Kind::TYPE, 0x8048577, "int"},
		{Token::Kind::WHITE_SPACE, 0x8048577, " "},
		{Token::Kind::LITERAL_SYM, 0x8048577, "__cdecl"},
		{Token::Kind::WHITE_SPACE, 0x8048577, " "},
		{Token::Kind::ID_FNC, 0x8048577, "main"},
		{Token::Kind::PUNCTUATION, 0x8048577, "("},
		{Token::Kind::TYPE, 0x8048577, "int"},
		{Token::Kind::WHITE_SPACE, 0x8048577, " "},
		{Token::Kind::ID_ARG, 0x8048577, "argc"},
		{Token::Kind::PUNCTUATION, 0x8048577, ","},
		{Token::Kind::WHITE_SPACE, 0x8048577, " "},
		{Token::Kind::TYPE, 0x8048577, "const char"},
		{Token::Kind::WHITE_SPACE, 0x8048577, " "},
		{Token::Kind::OPERATOR, 0x8048577, "*"},
		{Token::Kind::OPERATOR, 0x8048577, "*"},
		{Token::Kind::ID_ARG, 0x8048577, "argv"},
		{Token::Kind::PUNCTUATION, 0x8048577, ","},
		{Token::Kind::WHITE_SPACE, 0x8048577, " "},
		{Token::Kind::TYPE, 0x8048577, "const char"},
		{Token::Kind::WHITE_SPACE, 0x8048577, " "},
		{Token::Kind::OPERATOR, 0x8048577, "*"},
		{Token::Kind::OPERATOR, 0x8048577, "*"},
		{Token::Kind::ID_ARG, 0x8048577, "envp"},
		{Token::Kind::PUNCTUATION, 0x8048577, ")"},
		{Token::Kind::NEW_LINE, 0x8048577, "\n"},
		// {
		{Token::Kind::PUNCTUATION, 0x8048577, "{"},
		{Token::Kind::NEW_LINE, 0x8048577, "\n"},
		//  int v4; // [esp+14h] [ebp-Ch]
		{Token::Kind::WHITE_SPACE, 0x8048577, "  "},
		{Token::Kind::TYPE, 0x8048577, "int"},
		{Token::Kind::WHITE_SPACE, 0x8048577, " "},
		{Token::Kind::ID_VAR, 0x8048577, "v4"},
		{Token::Kind::PUNCTUATION, 0x8048577, ";"},
		{Token::Kind::WHITE_SPACE, 0x8048577, " "},
		{Token::Kind::COMMENT, 0x8048577, "// [esp+14h] [ebp-Ch]"},
		{Token::Kind::NEW_LINE, 0x8048577, "\n"},
		//  int v5; // [esp+18h] [ebp-8h]
		{Token::Kind::WHITE_SPACE, 0x8048577, "  "},
		{Token::Kind::TYPE, 0x8048577, "int"},
		{Token::Kind::WHITE_SPACE, 0x8048577, " "},
		{Token::Kind::ID_VAR, 0x8048577, "v5"},
		{Token::Kind::PUNCTUATION, 0x8048577, ";"},
		{Token::Kind::WHITE_SPACE, 0x8048577, " "},
		{Token::Kind::COMMENT, 0x8048577, "// [esp+18h] [ebp-8h]"},
		{Token::Kind::NEW_LINE, 0x8048577, "\n"},
		//  int v6; // [esp+1Ch] [ebp-4h]
		{Token::Kind::WHITE_SPACE, 0x8048577, "  "},
		{Token::Kind::TYPE, 0x8048577, "int"},
		{Token::Kind::WHITE_SPACE, 0x8048577, " "},
		{Token::Kind::ID_VAR, 0x8048577, "v6"},
		{Token::Kind::PUNCTUATION, 0x8048577, ";"},
		{Token::Kind::WHITE_SPACE, 0x8048577, " "},
		{Token::Kind::COMMENT, 0x8048577, "// [esp+1Ch] [ebp-4h]"},
		{Token::Kind::NEW_LINE, 0x8048577, "\n"},
		//
		{Token::Kind::NEW_LINE, 0x8048577, "\n"},
		//  v6 = 0;
		{Token::Kind::WHITE_SPACE, 0x8048580, "  "},
		{Token::Kind::ID_VAR, 0x8048580, "v6"},
		{Token::Kind::WHITE_SPACE, 0x8048580, " "},
		{Token::Kind::OPERATOR, 0x8048580, "="},
		{Token::Kind::WHITE_SPACE, 0x8048580, " "},
		{Token::Kind::LITERAL_INT, 0x8048580, "0"},
		{Token::Kind::PUNCTUATION, 0x8048580, ";"},
		{Token::Kind::NEW_LINE, 0x8048580, "\n"},
		//  v5 = 0;
		{Token::Kind::WHITE_SPACE, 0x8048588, "  "},
		{Token::Kind::ID_VAR, 0x8048588, "v5"},
		{Token::Kind::WHITE_SPACE, 0x8048588, " "},
		{Token::Kind::OPERATOR, 0x8048588, "="},
		{Token::Kind::WHITE_SPACE, 0x8048588, " "},
		{Token::Kind::LITERAL_INT, 0x8048588, "0"},
		{Token::Kind::PUNCTUATION, 0x8048588, ";"},
		{Token::Kind::NEW_LINE, 0x8048588, "\n"},
		//  v4 = 0;
		{Token::Kind::WHITE_SPACE, 0x8048590, "  "},
		{Token::Kind::ID_VAR, 0x8048590, "v4"},
		{Token::Kind::WHITE_SPACE, 0x8048590, " "},
		{Token::Kind::OPERATOR, 0x8048590, "="},
		{Token::Kind::WHITE_SPACE, 0x8048590, " "},
		{Token::Kind::LITERAL_INT, 0x8048590, "0"},
		{Token::Kind::PUNCTUATION, 0x8048590, ";"},
		{Token::Kind::NEW_LINE, 0x8048590, "\n"},
		//  __isoc99_scanf(\"%d %d\", &v5, &v4);
		{Token::Kind::WHITE_SPACE, 0x80485AF, "  "},
		{Token::Kind::ID_FNC, 0x80485AF, "__isoc99_scanf"},
		{Token::Kind::PUNCTUATION, 0x80485AF, "("},
		{Token::Kind::LITERAL_STR, 0x80485A8, "\"%d %d\""},
		{Token::Kind::PUNCTUATION, 0x80485A8, ","},
		{Token::Kind::WHITE_SPACE, 0x80485A8, " "},
		{Token::Kind::OPERATOR, 0x80485A4, "&"},
		{Token::Kind::ID_VAR, 0x80485A4, "v5"},
		{Token::Kind::PUNCTUATION, 0x80485A4, ","},
		{Token::Kind::WHITE_SPACE, 0x80485A4, " "},
		{Token::Kind::OPERATOR, 0x804859C, "&"},
		{Token::Kind::ID_VAR, 0x804859C, "v4"},
		{Token::Kind::PUNCTUATION, 0x804859C, ")"},
		{Token::Kind::PUNCTUATION, 0x804859C, ";"},
		{Token::Kind::NEW_LINE, 0x804859C, "\n"},
		//  v6 = ack(v5, v4);
		{Token::Kind::WHITE_SPACE, 0x80485C8, "  "},
		{Token::Kind::ID_VAR, 0x80485C8, "v6"},
		{Token::Kind::WHITE_SPACE, 0x80485C8, " "},
		{Token::Kind::OPERATOR, 0x80485C8, "="},
		{Token::Kind::WHITE_SPACE, 0x80485C8, " "},
		{Token::Kind::ID_FNC, 0x80485C3, "ack"},
		{Token::Kind::PUNCTUATION, 0x80485C3, "("},
		{Token::Kind::ID_VAR, 0x80485C0, "v5"},
		{Token::Kind::PUNCTUATION, 0x80485C0, ","},
		{Token::Kind::WHITE_SPACE, 0x80485C0, " "},
		{Token::Kind::ID_VAR, 0x80485BC, "v4"},
		{Token::Kind::PUNCTUATION, 0x80485BC, ")"},
		{Token::Kind::PUNCTUATION, 0x80485BC, ";"},
		{Token::Kind::NEW_LINE, 0x80485BC, "\n"},
		//  printf("ackerman( %d , %d ) = %d\n", v5, v4, v6);
		{Token::Kind::WHITE_SPACE, 0x80485EB, "  "},
		{Token::Kind::ID_FNC, 0x80485EB, "printf"},
		{Token::Kind::PUNCTUATION, 0x80485EB, "("},
		{Token::Kind::LITERAL_STR, 0x80485E4, "\"ackerman( %d , %d ) = %d\\n\""},
		{Token::Kind::PUNCTUATION, 0x80485E4, ","},
		{Token::Kind::WHITE_SPACE, 0x80485E4, " "},
		{Token::Kind::ID_VAR, 0x80485E0, "v5"},
		{Token::Kind::PUNCTUATION, 0x80485E0, ","},
		{Token::Kind::WHITE_SPACE, 0x80485E0, " "},
		{Token::Kind::ID_VAR, 0x80485DC, "v4"},
		{Token::Kind::PUNCTUATION, 0x80485DC, ","},
		{Token::Kind::WHITE_SPACE, 0x80485DC, " "},
		{Token::Kind::ID_VAR, 0x80485D8, "v6"},
		{Token::Kind::PUNCTUATION, 0x80485D8, ")"},
		{Token::Kind::PUNCTUATION, 0x80485D8, ";"},
		{Token::Kind::NEW_LINE, 0x80485D8, "\n"},
		//  return v6;
		{Token::Kind::WHITE_SPACE, 0x80485F4, "  "},
		{Token::Kind::KEYWORD, 0x80485F4, "return"},
		{Token::Kind::WHITE_SPACE, 0x80485F4, " "},
		{Token::Kind::ID_VAR, 0x80485F4, "v6"},
		{Token::Kind::PUNCTUATION, 0x80485F4, ";"},
		{Token::Kind::NEW_LINE, 0x80485F4, "\n"},
		// }
		{Token::Kind::PUNCTUATION, 0x80485F5, "}"},
		// Do not add new line at the end.
		// For whatever reason, the last line is not displayed if the max
		// place's X coordinate isn't 0.
		// So always put only one token at the last line.
	}
};

using Functions = std::map<ea_t, Function>;
Functions functions = {
	{fnc_ack.getStart(), fnc_ack},
	{fnc_main.getStart(), fnc_main}
};

Function* Decompiler::decompile(ea_t ea)
{
	Function* ret = nullptr;
	auto it = functions.upper_bound(ea);

	if (it == functions.begin())
	{
		// Before the first -> no function.
		ret = nullptr;
	}
	else if (it == functions.end() && !functions.empty())
	{
		// After the last -> check the last function.
		auto& last = functions.rbegin()->second;
		ret = last.ea_inside(ea) ? &last : nullptr;
	}
	else if (it != functions.end())
	{
		// In the middle -> check the previous.
		--it;
		auto& prev = it->second;
		ret = prev.ea_inside(ea) ? &prev : nullptr;
	}

	if (ret)
	{
		demo_msg("Decompiler::decompile(%a): %s\n",
				ea,
				ret->toString().c_str()
		);
	}
	else
	{
		demo_msg("Decompiler::decompile(%a): cannot decompile\n", ea);
	}

	return ret;
}
