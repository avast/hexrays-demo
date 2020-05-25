
#ifndef HEXRAYS_DEMO_DECOMPILER_H
#define HEXRAYS_DEMO_DECOMPILER_H

#include <pro.h>

#include "function.h"

/**
 * Decomiler mock.
 */
class Decompiler
{
	public:
		/// Decompile the function contianing the given \p ea.
		static Function* decompile(ea_t ea);
};

#endif
