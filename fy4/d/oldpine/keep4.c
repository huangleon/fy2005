#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", "����կ����");
        set("long", @LONG
һ�������������Դ���������������������������ÿ�������Ͳ���һ��ȼ��
�Ļ�ѡ���������ȥ����һ��ת�ۣ�ת�ۺ���������ɽ�����ˣ�����ҪС�����
Ϊ�ϡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "north" : __DIR__"keep3",
                "east" : __DIR__"keep5",
        ]));
        set("coor/x",80);
	set("coor/y",-20);
	set("coor/z",20);
	setup();
	set("no_fly", 1);
	set("max_lv",25);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"keep3");
	if (!exitroom)
		exitroom = load_object(__DIR__"keep3");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv"))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"���н����������㰵�Գ�˼����óȻ���£�����������������\n��Ȼ���ϴ�������Ҳû�б�Ҫð�ն��¡�\n"NOR);
	}
}

