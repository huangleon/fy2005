#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", BMAG HIW"��ƽ��"NOR);
        set("long", @LONG
ջ��������һƬ��ƺ�����Ĳݵأ��ݵ��ϸǴ���һ��СС��ľ�ݣ������д�
ʯһ�飬��ʯ�ϱ����Ը��͵�ָ�����š���ƽ�ӡ��������֣�����ע�����У�

�������������������Ƚ����º�ǿ�͡�һȭ���
�������������������ٰ����䲻���ˡ�������ƽ

���������������������������񲻿��գ�

LONG
        );
    set("exits", ([ 
  		"southdown" : __DIR__"zhandao",
	]));
    set("outdoors", "huashan");

	set("coor/x",0);
	set("coor/y",35);
	set("coor/z",20);
	setup();
	set("no_fly", 1);
	set("max_lv",137);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"zhandao");
	if (!exitroom)
		exitroom = load_object(__DIR__"zhandao");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"ŭ��������ɽ���Ѿã��ǳ��ǳ���ϲ�����ˣ��ر����и��֣�ȥ��������\n"NOR);
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

