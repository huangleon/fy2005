#include <armor.h>
inherit CLOTH;

void create()
{
    set_name("ī���廨����", ({ "green robe","robe", }) );

	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "
ī���廨����������һ������ü��Ŀ�㣬��Ŀ��ã��·��Ǹ���ɫ��Ů��
��ϸһ�������Ǹ�����������צӼ��Ĺ��ޡ�\n");
		set("material", "cloth");
		set("value", 1000);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
