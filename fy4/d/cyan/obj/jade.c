#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
	set_name("��а����", ({ "jade" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "stone");
		set("unit", "��");
		set("long", "һ��ͨ���׵����壬��˵�����˷ⷨ�ļӳ֣����Ա�а��\n");
		set("armor_prop/perception",5);
	}
	::init_neck();
}

