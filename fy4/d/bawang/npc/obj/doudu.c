// By clone 6/2001
// cloth.c
// add some funny stuff :P

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIY"��"+HIR"��"NOR+"С����", ({ "doudu" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����˿��ɵ�С���ǣ��񻢸ڵ�����Ůǿ���Ǵ���ɹ�չ�ԡ�õġ�
�ݿ�֤��������ִ�����ʽӾװ�ı��档\n");
		set("material", "cloth");
		set("value", 100);
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}
