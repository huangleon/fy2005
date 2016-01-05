#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(CYN"���ľƺ�«" NOR,({"wine"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "wood");
		set("long",CYN"һ�����ľƺ�«������װ�ľ���ɫ���ڣ������������ζ��û�С�\n"NOR);
		}
    ::init_item();
}

void init()
{
	if(this_player()==environment())
		add_action("do_drink","drink");
}

int do_drink(string arg)
{
	object me;
	me = this_player();
	if (!arg)
		return notify_fail("��Ҫ��ʲô��\n");
    if (arg != "wine")
		return notify_fail("��Ҫ��ʲô��\n");
	if (query("used")) 
		return notify_fail(this_object()->name()+"�Ѿ����ȹ��ˡ�\n");
    message_vision(HIG"$N������ľƺ�«������һ��ڹֵֹľơ�\n"NOR,me);
    message_vision(HIC"\n$N���ö�����ȴ�����Ȼȼ���˶ѻ𣬲���һ�ſڣ�һ���Ƽ����������\n"NOR,me);
	if (REWARD_D->riddle_check(me,"������Թ") == 8)
	    environment(this_player())->wine_notify(me);
	set("used",1);
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
