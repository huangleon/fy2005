inherit ITEM;
#include <ansi.h>
inherit F_LIQUID;

void create()
{
	set_name(HIB"ҹ�Ɑ"NOR, ({ "twilight cup", "cup" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("long", "һ��ʢ�����ʺ���Ѫ���������Ƶ�ҹ�Ɑ��\n");
		set("unit", "��");
		set("value", 2000);
		set("max_liquid", 10);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "��������",
		"remaining": 5,
		"drunk_apply": 20,
	]) );
}