// 2009 FengYun
// Edit by hippo 2009.11
// Т�� ����

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"������"NOR, ({ "ling"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�����˼ҹ��ľ���Ϊ������ֽ���������ĸ�����������\n�ر���\n");
		set("value", 200);
		set("no_split",1);
		set("unit", "��");
		set("no_drop",1);
		set("no_get",1);
		set("no_sell",1);
		set("lore",1);
	}
	::init_item();
}


// by hippo 2009.11

