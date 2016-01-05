#include <armor.h>
inherit HEAD;

void create()
{
	set_name("¿í´óµÄ¶·óÒ", ({ "hat" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¶¥");
		set("long","Öñ±àµÄ¶·óÒ£¬óÒÑØºÜ¿í´ó¡£\n");
		set("value", 100);
		set("material", "wood");
		set("armor_prop/armor", 5);
	}
	::init_head();
}


