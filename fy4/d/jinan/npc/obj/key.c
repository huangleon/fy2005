#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("����Կ��", ({ "key" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("material", "iron");
        set("long", "һö�������������ŵ�Կ�ס�\n");
	}
	set("prison_key",1);
	::init_item();
}