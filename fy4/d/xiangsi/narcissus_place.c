#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
	set("short", "����������");
        set("long", @LONG
��������ɽ�ϵı���һ�棬���겻������ֱ�䣬���еı���Ȯ�������
�������˺ϱ�����ϸ��Ҳֻ����Сָ���������������ϼ���������Խ��ԽŨ��
��������һ������������Ƭ�̱�ᶳ����
LONG
        );
        set("objects", ([
//        __DIR__"npc/song" : 1,
// �ؼ���..
//        __DIR__"npc/thief" : 1,
// �����..
                        ]) );
	
	set("exits",([
		"down":	__DIR__"icecave",
	]) );
	
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",60);
	setup();
	set("no_fly", 1);
	set("max_lv",115);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"icecave");
	if (!exitroom)
		exitroom = load_object(__DIR__"icecave");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,WHT"����ϡϡ������£���ס�����ȥ·��\n"NOR);
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

