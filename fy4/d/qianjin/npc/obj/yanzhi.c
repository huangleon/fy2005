
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"��֬"NOR, ({ "yanzhi" , "��֬"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�ʺ���Ѫ���ϵ���֬\n");
		set("value", 1000);
	}
}



