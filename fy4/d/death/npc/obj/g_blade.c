#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create() {
    set_name(HIC"�������µ�"NOR, ({ "qinglong blade","blade" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        	set("value", 100);
		set("material", "iron");
        	set("long", "һ�������ɣ���ʮ���صĴ󵶣�ʮ�ַ�����\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	
	::init_blade(10);
}
