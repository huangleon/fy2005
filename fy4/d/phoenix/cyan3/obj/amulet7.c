#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
	set_name("��ڵ�����", ({ "necklace" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "stone");
		set("unit", "��");
		set("long", "һ��������������ڵ���������֪�������չ������˶����ꡣ\n");
		set("armor_prop/perception",8);
		set("value",0);
	}
	::init_neck();
}

