// pink_cloth.c

#include <armor.h>

inherit NECK;

void create()
{
	set_name("����", ({ "botao"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������ף���Լ�а˴�����ȴ�ϸ��\n");
		set("unit", "��");
		set("value", 0);
		set("no_drop",1);
		set("wear_msg", "$N��һ��$n����ͷ�ϡ�\n");
		set("unwield_msg", "$N��$n��ͷ�ϳ���������\n");
	}
	::init_neck();
}
