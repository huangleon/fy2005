// ; annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��̶");
        set("long", @LONG
̶��ɲ�����״������ɫ��̶ˮ�������ף�̶�ߺ����̹ǣ�һ����������ˮ��
����̶��������һ�㱡���İ�ɫ������̶�ߵ�ʯͷ�������ˣ�ʯ���г���һЩ��
֪����ֲ�
LONG
        );
	set("exits", ([ 
		"down" : __DIR__"jiulong",
	]));

	set("item_desc", ([
		"ʯ��": "ʯ���д����Ÿ�����ɫ��С�ݣ�����һ���ʺ���Ѫ��ʮ������עĿ��pick����
�ں�ɫС�ݱ߻�������С���ӣ���Ȼ���˴�����������ʲô����\n",
		"ֲ��": "ʯ���д����Ÿ�����ɫ��С�ݣ�����һ���ʺ���Ѫ��ʮ������עĿ��pick����
�ں�ɫС�ݱ߻�������С���ӣ���Ȼ���˴�����������ʲô����\n",
		"flower": "ʯ���д����Ÿ�����ɫ��С�ݣ�����һ���ʺ���Ѫ��ʮ������עĿ��pick����
�ں�ɫС�ݱ߻�������С���ӣ���Ȼ���˴�����������ʲô����\n",
	]) );

    set("outdoors", "huangshan");
	set("coor/x",-50);
	set("coor/y",40);
	set("coor/z",20);
	setup();
}


void init()
{
	add_action("do_pick", "pick");
}


int do_pick(string arg)
{
   	object me, tea;
	int i;

   	me = this_player();
	if (!query("flower"))
		return notify_fail("С���Ѿ�����ժ���ˡ�\n");
	tea = new(__DIR__"obj/grass");
	message_vision(CYN"$N������ʯ���в���һ��С�ݡ�\n"NOR,me);
	tea->move(me);
	delete("flower");
	return 1;
}

void reset()
{
	::reset();
	if (NATURE_D->get_season() < 3)	// ���Ķ���
		set("flower",1);
}

