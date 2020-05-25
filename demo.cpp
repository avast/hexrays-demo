
#include "context.h"
#include "decompiler.h"
#include "function.h"
#include "place.h"
#include "ui.h"

plugmod_t* idaapi init(void)
{
	demo_msg("init()\n");
	return new Context();
}

Context::Context()
{
	register_action(function_ctx_ah_desc);
	register_action(variable_ctx_ah_desc);
	register_action(copy2asm_ah_desc);
}

bool idaapi Context::run(size_t)
{
	demo_place_t::registerPlace(PLUGIN);
	hook_event_listener(HT_UI, this);

	ea_t ea = get_screen_ea();
	fnc = Decompiler::decompile(ea);
	if (fnc == nullptr)
	{
		warning("[demo] cannot decompile function @ %a\n", ea);
		return true;
	}

	demo_place_t min(fnc, fnc->min_yx());
	demo_place_t max(fnc, fnc->max_yx());
	demo_place_t cur(fnc, fnc->ea_2_yx(ea));

	static const char title[] = "hexrays demo";
	TWidget* widget = find_widget(title);
	if (widget != nullptr)
	{
		demo_msg("run(%a): switching existing viewer to %s\n",
				ea,
				fnc->toString().c_str()
		);

		set_custom_viewer_range(custViewer, &min, &max);
		jumpto(custViewer, &cur, cur.x(), cur.y());
		bool take_focus = true;
		activate_widget(custViewer, take_focus);
		return true;
	}

	demo_msg("run(%a): creating new viewer for %s\n",
			ea,
			fnc->toString().c_str()
	);

	// Without setting both x and y in render info, the current line gets
	// displayed as the first line in the viewer. Which is not nice because we
	// don't see the context before it. It is better if it is somewhere in the
	// middle of the viewer.
	renderer_info_t rinfo;
	rinfo.rtype = TCCRT_FLAT;
	rinfo.pos.cx = cur.x();
	rinfo.pos.cy = cur.y();

	custViewer = create_custom_viewer(
			title,        // title
			&min,         // minplace
			&max,         // maxplace
			&cur,         // curplace
			&rinfo,       // rinfo
			this,         // ud
			&ui_handlers, // handlers
			this,         // cvhandlers_ud
			nullptr       // parent widget
	);
	set_view_renderer_type(custViewer, TCCRT_FLAT);

	codeViewer = create_code_viewer(custViewer);
	set_code_viewer_is_source(codeViewer);
	display_widget(codeViewer, WOPN_DP_TAB | WOPN_RESTORE);

	return true;
}

Context::~Context()
{
	demo_msg("term()\n");

	unhook_event_listener(HT_UI, this);
	unregister_action(function_ctx_ah_desc.name);
	unregister_action(variable_ctx_ah_desc.name);
	unregister_action(copy2asm_ah_desc.name);
}

plugin_t PLUGIN =
{
	IDP_INTERFACE_VERSION,
	PLUGIN_MULTI,   // plugin flags
	init,           // initialize fnc
	nullptr,        // terminate fnc
	nullptr,        // invoke fnc
	"hexrays demo", // long plugin comment
	"hexrays demo", // multiline plugin help
	"hexrays demo", // the preferred plugin short name
	"Ctrl-Shift-D"  // the preferred plugin hotkey
};
