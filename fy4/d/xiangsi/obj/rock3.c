// annie 07.2003
// dancing_faery@hotmail.com
//������
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("���籮", ({ "���籮" , "�籮", "��"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "���籮�ϱ����ô��ָ�����ţ�\n\n��"HIR"���������޶�������ȥ����·һ��\n\n����������������������Ԫ����Ħ�ϴ��"NOR"\n\n��������鱮�����̵��Ѿ���������ǰ�������ˡ�\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }
