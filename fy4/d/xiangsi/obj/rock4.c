// annie 07.2003
// dancing_faery@hotmail.com
//������
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("ʯ��", ({ "ʯ��" , "��", "����","ɽ��"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
//		set("long", "ʯ��������ǣ�\n[34mɽ��Ħ����\nˮ�����Ž�\n����������\n����Ψ��ɽˮ��\n���뿪��ɫ����\n�㿰Ϊ��������\n\n[32m");
		set("long", "ʯ��������ǣ�\n\n"MAG"��������ˮ����ɽ\n����������������\n���������ࡡ��Զ\n���������塡����\n��������һ������\n����������������\n���������ġ�����\n\n"NOR);
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

