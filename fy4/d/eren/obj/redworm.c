#include <ansi.h>

inherit ITEM;
void create()
{
	set_name( RED"�����"NOR, ({ "red worm","worm"  }) );
    	set("unit", "��");
    	set("value",5);
	set("fish_bait_real", 1);
	set("fish_bait", 1);
    	set("long","һ����������ĺ���򾡣\n");
    	set_weight(1);
	::init_item();
}
