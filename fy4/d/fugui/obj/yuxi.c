#include <ansi.h>
#include <armor.h>

inherit ITEM;

void create()
{
	set_name(HIY"�ƴ�����"NOR, ({ "yuxi"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("long", "��˵�е��ƴ�����������\n");
		set("unit", "��");
		set("value", 500);
		set("thief_obj",1);
	}
	::init_item();
}

