inherit ITEM;
#include <ansi.h>

void create()
{
    	set_name("������ ��ʮ�˴����ϡ�"+HIM"�ؾ�¥����"NOR+"��һ����ʬ��", ({ "yitie's corpse"}) );
    	set_weight(800000);
    	set_max_encumbrance(400000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "���ֲؾ�¥��������ʮ����δ�²ؾ�¥һ��
Ȼ�������Ѿ����ˣ�ֻʣ��һ��ʬ�徲���������������\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }
