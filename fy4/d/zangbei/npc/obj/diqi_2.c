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
		set("long", "һ��ո�µ�̩���㳡������Ǯ���������͵�����ȥ�Ƿ��ˡ�\n");
		set("value", 1);
		set("material", "paper");
		set("taian",1);
	}
	::init_item();
}
