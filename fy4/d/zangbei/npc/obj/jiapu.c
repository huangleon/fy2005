#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("����", ({ "jiapu" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��Ѧ�ҵļ��ס�\n");
		set("value", 1);
		set("material", "paper");
	}
	::init_item();
}
