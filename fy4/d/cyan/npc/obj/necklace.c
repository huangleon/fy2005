#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
	set_name("ʯ����", ({ "necklace" }) );
	set_weight(100000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "stone");
		set("unit", "��");
		set("long", "һ�����Ӵ��ʯ�������ɵĹҴ���\n");
		set("value",1);
	}
	::init_neck();
}

