// cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
          set_name(WHT"�����ѥ"NOR, ({ "whiteboots" }) );
      set_weight(900);
         if( clonep() )
      set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "˫");
		set("long", "��Ь�����ݣ���ȥ���\n");
		set("value", 1000);
	}
	::init_boots();
}
