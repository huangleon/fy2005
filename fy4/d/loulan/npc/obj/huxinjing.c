#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
	set_name(RED"��ͭ���ľ�"NOR , ({ "copper plate", "plate" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ͭ���ľ��������Ȼ���Ÿ���һ���֡�\n");
		set("value", 700);
		set("material", "copper");
	}
	::init_neck();
}
