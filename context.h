
#ifndef HEXRAYS_DEMO_CONTEXT_H
#define HEXRAYS_DEMO_CONTEXT_H

#include <set>

#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>
#include <kernwin.hpp>
#include <moves.hpp>

#include "function.h"
#include "ui.h"

/**
 * Plugin's info messages.
 */
int demo_msg(const char *format, ...);

/**
 * Plugin's global data.
 */
class Context : public plugmod_t, public event_listener_t
{
	// Inherited.
	//
	public:
		virtual bool idaapi run(size_t) override;
		virtual ssize_t idaapi on_event(ssize_t code, va_list va) override;

		Context();
		virtual ~Context();

	// Actions.
	//
	public:
		function_ctx_ah_t function_ctx_ah;
		const action_desc_t function_ctx_ah_desc = ACTION_DESC_LITERAL_PLUGMOD(
				function_ctx_ah_t::actionName,
				function_ctx_ah_t::actionLabel,
				&function_ctx_ah,
				this,
				function_ctx_ah_t::actionHotkey,
				nullptr,
				-1
		);

		variable_ctx_ah_t variable_ctx_ah;
		const action_desc_t variable_ctx_ah_desc = ACTION_DESC_LITERAL_PLUGMOD(
				variable_ctx_ah_t::actionName,
				variable_ctx_ah_t::actionLabel,
				&variable_ctx_ah,
				this,
				variable_ctx_ah_t::actionHotkey,
				nullptr,
				-1
		);

		copy2asm_ah_t copy2asm_ah = copy2asm_ah_t(*this);
		const action_desc_t copy2asm_ah_desc = ACTION_DESC_LITERAL_PLUGMOD(
				copy2asm_ah_t::actionName,
				copy2asm_ah_t::actionLabel,
				&copy2asm_ah,
				this,
				copy2asm_ah_t::actionHotkey,
				nullptr,
				-1
		);

	// Context data.
	//
	public:
		TWidget* custViewer = nullptr;
		TWidget* codeViewer = nullptr;
		/// Currently displayed function.
		Function* fnc = nullptr;
		// Color used by view synchronization.
		bgcolor_t syncColor = 0x90ee90;
};

#endif