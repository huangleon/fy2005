// cloth.c
//

#include <armor.h>

inherit HEAD;
#include <ansi.h>
void create()
{
    set_name(HIW"����"NOR, ({ "hada" }) );
    set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");

        set("long","һ�������ʥĸ֮ѩ�Ĺ���ǲ������͸������Ŀ��˵����\n");
		set("material", "cloth");
		set("value", 7);
		set("armor_prop/armor", 1);
	}
	::init_head();
}
