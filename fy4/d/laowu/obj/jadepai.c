
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("��ɲ��" , ({ "luosha" , "pai"}) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��ɲ���ϵ���ħ������������ֻ�����ʺ�����˵㡣\n");
		set("fake", 1);
		set("value", 100);
	}
}



