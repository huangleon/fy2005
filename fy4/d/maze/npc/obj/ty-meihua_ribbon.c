#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create() {
	set_name(HIG"׺��÷����ɴ��"NOR, ({ "ribbon"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��׺��÷����ɴ������߰ߵ�㽦�ż����ʺ��Ѫ����\n");
		set("unit", "��");
		set("value", 0);
		set("wear_msg", "$N����ذ�һ��$nϵ�������ϡ�\n");
		set("unwield_msg", "$N����ذ�$n�������Ͻ���������\n");
	}
	::init_wrists();
}

