inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("��ֽƬ", ({ "paper"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ֽƬ������ϡ���Ա��ϳ��������ơ������¡��������֡�\n");
		set("value", 1);
	}
}



