// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;

void create(){
	set_name(HIR"ÒğÉú²İ"NOR, ({"grass" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÖêÆæÒìµÄĞ¡²İ£¬Ò¶°ê°Ë·Ö£¬ÏÊºìÈçÑª¡£\n");
		set("unit", "Öê");
		set("no_drop",1);
		set("real_flower",2);
	}
    ::init_item();
}

