
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("ɱ����", ({ "pai" , "ɱ����"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIR "�ʺ���Ѫ��ɱ����\n"NOR);
		set("value", 1000);
	}
	::init_item();
}



