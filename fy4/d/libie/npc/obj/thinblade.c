#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
    	set_name(CYN"����"NOR, ({ "paper dagger","dagger" }) );
    	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��Ӱ���١��������ʡ������硢���緢˿������䱡��ֽ�ĵ����ͽ����ᡣ\n");
        set("value", 4);
        set("level_required", 30);	
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
    	init_dagger(60);
}
