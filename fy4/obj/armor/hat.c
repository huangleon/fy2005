#include <armor.h>
inherit HEAD;

void create() {
	set_name("Ã±×Ó", ({ "hat" }) );
	set_weight(6);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¶¥");
		set("value", 0);
		set("material", "cloth");
	}
	::init_head();
}

