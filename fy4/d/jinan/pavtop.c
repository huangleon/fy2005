#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
    set("short", "��ˮͤ��");
	set("long", @LONG
�������£��ⶥ��ϼ�����ĵ���ˮСͤ��ֹ�������������˴���ɫ���Ǿ�
����ƥ��վ��ͤ������������������������⾰ɫ�������У���������Զ��
����ˮ�������뵡�
LONG
	);
	set("exits", ([ 
  "down" : __DIR__"bridge4",
]));
        set("objects", ([
//        __DIR__"npc/song" : 1,
// �ؼ���..
//        __DIR__"npc/thief" : 1,
// �����..
                        ]) );
	set("coor/x",100);
	set("coor/y",120);
    set("outdoors", "jinan");
	set("coor/z",100);
	setup();
	set("no_fly", 1);
	set("max_lv",120);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"bottom");
	if (!exitroom)
		exitroom = load_object(__DIR__"bottom");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"�����ͻȻһ�գ���ͨһ��ˤ�����䳺����ĺ�ˮ�С�\n"NOR);
	}
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

