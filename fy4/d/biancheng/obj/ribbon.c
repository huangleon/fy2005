#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create() {
	set_name(YEL"��˿��"NOR, ({ "ribbon"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�����Ļ�˿����\n");
		set("unit", "��");
		set("value", 50);
		set("wear_msg", "$N����ذ�һ��$nϵ�������ϡ�\n");
		set("unwield_msg", "$N����ذ�$n�������Ͻ���������\n");
	}
	::init_wrists();
}

