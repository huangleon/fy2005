#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name(HIY"�ƽ��"NOR, ({ "golden chainarmor","chainarmor"}) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "gold");
		set("long", "һ����������Ļƽ���ס�\n");
		set("value", 5000);
		set("armor_prop/armor", 8);
	}
	::init_cloth();
}
