// cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
    	set_name(YEL"���ɫ��ȹ"NOR, ({ "long skirt","skirt" }) );
    	set_weight(300);
		if( clonep() )
			set_default_object(__FILE__);
		else {
		set("unit", "��");
	        set("long", "һ�����ɫ��ȹ��������΢΢���е���Ƥ�ɰ���\n");
	        set("value", 40);
			set("material", "cloth");
	        set("armor_prop/armor", 1);
		set("female_only", 1);
	}
	::init_cloth();
}
