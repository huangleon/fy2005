#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
  set("short","ի����Ժ");
  set("long",@LONG
һ��ի����Ժ���ޱ����˵ķ����������˱Ƕ��������������ˮ���۾�գ
Ҳ��գ�ض��ż���¯���ϵĴ����ԭ���ز������ֳ���֮�£���Ҳ������˷�
����ζ��
LONG
  );
  set("exits",([
            "east" :__DIR__"zhaitang",
               ]));
	set("coor/x",-40);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
	set("no_fly", 1);
	set("max_lv",95);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"zhaitang");
	if (!exitroom)
		exitroom = load_object(__DIR__"zhaitang");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"��ʦ����ի����Ժ����������óȻ�����ƺ���ʧ�����ݡ�\n"NOR);
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

