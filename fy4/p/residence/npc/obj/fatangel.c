#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR+"����ʯ��"+NOR, ({ "dismantle statue","statue" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "stone");
		set("value",50000);
		set("unit", "��");
		set("long","һ��ʯ��ӷ�׷ʳ��ÿ������ø��ֶ�����");
		set("desc_ext","�һټҾ�(dismantle)");
	}
}

void init()
{
	if (environment() == this_player())	
	{
		add_action("do_dismantle","dismantle");
		set("value",0);
	}
}

int do_dismantle(string arg)
{
	if (!arg)
	{
		message_vision(CYN"$N����"+name()+NOR+CYN"�ڿ��л������衣\n"NOR,this_player());
		return 1;
	}
}