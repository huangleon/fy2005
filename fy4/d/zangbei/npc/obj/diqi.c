#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("����", ({ "diqi" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����ֵĵ���������ȥ����ͷ�ˡ�\n");
		set("value", 1);
		set("material", "paper");
		set("kuaihuo",1);
	}
	::init_item();
}
