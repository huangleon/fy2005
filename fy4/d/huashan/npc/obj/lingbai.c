#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
    set_name(CYN"�һ�ľ��"NOR, ({ "taohua mupai","mupai" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ���һ�ľ������ƣ������Ͽ������ŵ��̻���\n");
		set("value", 1000);
		set("material", "wood");
	}
    ::init_dagger(1);
}
