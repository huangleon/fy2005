// ; annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���幬�ܵ�");
	set("long", @LONG
��̧���ۣ������Լ�����һ����խ����֮�У����������ߣ���ȴ��һ
�����¡��������ڶ�����ʯ����������֮���ָб��������ľ�ͷ�����ȸߴ��
ʯ�ţ��˿��������պ��ţ���ס�����ȥ·��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"south" : __DIR__"secretpath2",
]));
	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",-10);
	set("no_fly",1);

   	set("item_desc", ([
		"gate":  "��������ʯ�ţ������������쳣��̵Ļ����������������������ܴ򿪡�\n",
		"door":  "��������ʯ�ţ������������쳣��̵Ļ����������������������ܴ򿪡�\n",
		"ʯ��":  "��������ʯ�ţ������������쳣��̵Ļ����������������������ܴ򿪡�\n",
        ]) );
	setup();
}


void init()
{
	object room,me;
	object *olist;
	int i;
	me = this_player();
	if (userp(me))
	{
		room = this_object();
		// =5: ��room2
		// =x���ѽ���? ��room1
		if (REWARD_D->riddle_check(me,"��������") == 5 
			|| REWARD_D->riddle_check(me,"��������") == 7 
			|| REWARD_D->check_m_success(me,"��������") == 1)
			call_out("do_drop",15,me,room);
		else
			call_out("do_knockout",15,me,room);
	}
	return;
}

void do_knockout(object me,object room)
{
	if (!me || environment(me) != room || me->is_fighting())
		return;
	message_vision(CYN"\nһ�ŷ����׹�ķ�ֽ��Ȼ������$N���ϣ�$N����Ӱ���ڿ�����ģ������\n\n"NOR,me);
	me->move(load_object("/d/taoguan/taoguan"));
	message_vision(CYN"\n����ǰ�Ŀ�����Ȼ��ʼ���󲨶���һ��ģ�������������Ĵ���������ֳ���������\n\n"NOR,me);
}


void do_drop(object me,object room)
{
	if (!me || environment(me) != room || me->is_fighting())
		return;
	message_vision(CYN"\n$N��ʯ�ű�����ȥ��\n\n"NOR,me);
	tell_object(me,CYN"���Ȼ����ʯ�ű��Ͼ���һ�����ڣ����Ƽ�Ӳ��ʯͷ��ȴ����̽����ȥ��
��������һȨ�⣬�ӻ���ǽ����̤�˽�ȥ��\n\n"NOR);
	if ( /**/!/**/random(3) /* || load_object(__DIR__"dimroom")->usr_in() || load_object(__DIR__"fog")->usr_in()*/)
		me->move(load_object("/d/taoguan/taoguan"));
	else
		me->move(load_object("/d/taoguan/dimroom2"));
	message_vision(CYN"\n$N�������޵Ļ�Ӱǽ�����˹�����\n\n"NOR,me);
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

