// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "�Ųt��̨");
    set("long", @LONG
���ϲ��ƵĹŲt��̨����ҰһƬ������ӭ�ӱ������𣬸��Ӵ������֣�ֻ
��������һ�������׹�����ãã����Ԩ�����Ʋ����Σ�����ͬ�ã����뵱��
����꣬������������˵Ĳ���һ��ҵ�뵹������¥����ʱ�������ѱ�����
���ĵ�һ����Ȼ��
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/shri":1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"down" : __DIR__"peak3",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-60);
	set("coor/y",30);
	set("coor/z",100);
	setup();
}

void init()
{
	add_action("do_west","go");
}

int do_west(string arg)
{
	object me = this_player();
	int i;
	if (arg != "west")
		return 0;
	if (me->query("combat_exp") < 1000000)
	{
		tell_object(me,WHT"����t��̨�¿�����ֻ������������������������ֹס�Ų���\n"NOR);
		return 1;
	}

	if (me->is_fighting())
		message_vision("$N��������ԣ�����������������t��̨����ȥ��\n",me);
	else
		message_vision("$N����һ�����������۾���������t��̨����ȥ��\n",me);

	i=me->query_skill("move");
	if (me->is_fighting())
		i=i*3/4;
	tell_object(me,HIW"\n���İ���������ӹ����Ĵ������ϵļ�����Ŵ̹ǵĺ��⣬������ᵽ��ɤ�������\n"NOR);
	me->perform_busy(3);
    me->set_temp("disable_inputs",1);
	me->add_temp("block_msg/all",1);
   	me->delete("timer/lifesave");	// �仨��ˮһ��ȥ:p
	me->move("/obj/void");
	me->set_temp("last_damage_from","����ϼɽ�����Ծ��ˡ�");
	call_out("jump_down",6,me,i);

	return 1;


}


int jump_down(object me,int i)
{
	object room;
	if(!objectp(me)) return 1;
  	if (me->is_ghost()) return 1;

	if (me->query_temp("block_msg/all")>=1)
	me->add_temp("block_msg/all",-1);
    me->set_temp("disable_inputs",0);
	if (i < random(250))	// 250 enable move��100%��ȫ
	{
		tell_object(me,HIR"\n\n��Ȼ��һ���ʹ����������£������м��е������ˣ�����\n\n"NOR);
		me->die();	
		return 1;
	}

	REWARD_D->riddle_done(me,"��ϼ֮��",15,1);

	room=find_object(__DIR__"bottom1");
	if(!objectp(room)) 
        room = load_object(__DIR__"bottom1"); 

	tell_object(me,HIR"\n\n��Ȼ��һ���ʹ����������£������м��е������ˣ�����\n\n"NOR);
	me->unconcious();
	me->move(room);
	message("vision",me->name()+"�������������ˤ�˸��߻���أ���ͷת��\n"NOR,environment(me),me);
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


