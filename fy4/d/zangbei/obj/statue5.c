inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("���ܵ���", ({ "���ܵ���" , "����", "statue"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�ﲨ������Ĵ���Ӷ����հ͡������͡����������ľ��ͣ��ֱ����˴ﲨ��
�ٵ��Ĵ�֧�ɡ���ֱ�Ϊ����������ɡ��̰͸����ɡ����ָ����ɡ���������ɡ�
����������Ǽ�����ľ��͵ġ�\n");
		set("value", 1);
		set("prep","on");
	}
	::init_item();
}

int is_container() { return 1; }


