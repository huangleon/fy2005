#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("���黤��", ({ "amulet"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "һö��ڵĻ����������ʱ��������(exit)ʯ������\n");
		set("value", 1);
		set("lore",1);
		set("no_drop",1); 
		set("no_sell",1);
		set("no_pawn",1);
		set("no_stack",1);
	}
    ::init_item();
}

void init()
{
	add_action("do_exit","exit");
}

int do_exit()
{
	object center;
	if (!environment(this_player())->query("room_num"))
		return notify_fail("���黤��ֻ���ڰ�ɽʯ��������ʹ�á�\n");
	center = find_object("/d/bashan/couplemaze_center");
	if (!center)
		center = load_object("/d/bashan/couplemaze_center");
	if (!center)
		return notify_fail("����#12100��\n");
	center->close_all_path();
	center->kickout_ppl();
	return 1;
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

