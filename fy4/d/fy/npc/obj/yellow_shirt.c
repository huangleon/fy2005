// pink_cloth.c

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(YEL"��ɫ�Ķ���"NOR, ({ "yellow shirt", "shirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ɫ�Ĳ��������Ǽ�ϥ�� \n");
		set("unit", "��");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}

