// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
	set("short", "����С��");
    set("long", @LONG
���������ߵĲݵػ��У�����һ��·�̾�����������˴��ĺ�ˮ�ȷ���
�����峺�����л��ɼ���������Ϻ�ζ���ֻ��ԭ��ʮ�ְ����ľ�ɫ��һ������
����һ��վ�ں��߳���һ����ֽɡ��������������������ˡ�
LONG
NOR
        );
	set("objects", ([
	]));
	set("exits",([
  		"eastup" : __DIR__"peak11",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",-70);
	setup();

	set("no_fly", 1);
	set("max_lv",105);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"peak11");
	if (!exitroom)
		exitroom = load_object(__DIR__"peak11");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"��һ�²�����һ�¡����������˰ɡ�\n"NOR);
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


