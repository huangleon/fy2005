// cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
          set_name(WHT"�ƾɲ�ѥ"NOR, ({ "oldboots" }) );
      set_weight(900);
         if( clonep() )
      set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "˫");
        set("long", "һ˫ϴ�÷��׵��ƾɲ�ѥ��\n");
		set("value", 1000);
	}
	::init_boots();
}
