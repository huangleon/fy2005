#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", "����կ�");
        set("long", @LONG
һ��������Ż�Ƥ��̺�����ܹ�������Ƥ��¹ͷ�������ż����˹����õ�СС
���ݣ�����һ���Ǿ�Ȼ���Ŵ��������Դ���һ���뷢�԰�ȴ��Ȼ���ó��׺�֮��
�����������ڴ��ϣ��������Ÿ���֪��ʲô���ȹǴ�ڿ�ҧ��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "west" : __DIR__"keep4",
        ]));
        set("coor/x",120);
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
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"���н����������㰵�Գ�˼����óȻ���£�����������������
��Ȼ���ϴ�������Ҳû�б�Ҫð�ն��¡�\n"NOR);
	}
}

