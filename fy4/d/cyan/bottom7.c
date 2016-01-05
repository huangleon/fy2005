// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;
string look_stone();

void create()
{
	set("short", HIG"��ɣ��ľ"NOR);
    set("long", @LONG
�߽�ɽ�ȣ����̲�ס��ס������ֻ����ǰ��һ�������������ĸ�����
���а�����ϳǴ�С��ռ�����ϰ�ƺ��������ͷ������ֻ��֦Ҷ�ᣬ����
�ظ�������Ƭ��񷣬�����ڸ��ƺ�������ѹ��������ѹס����ĺ�����ʱ��
�·�Ҳ����һɲ��ֹ�����֮����ʣ�µģ�ֻ����һ��ΡΡ��ľ��
LONG
NOR
        );
	set("objects", ([

	__DIR__"obj/treeoftales":1,

	]));
	set("no_fly",1);
	set("no_light",1);
	set("item_desc", ([

	"root":"��ע�⵽һ��������չ��������������һ��СС���š�\n",
	"����":"��ע�⵽һ��������չ��������������һ��СС���š�\n",
	"���ĸ���":"��ע�⵽һ��������չ��������������һ��СС���š�\n",
	"����":"��ע�⵽һ��������չ��������������һ��СС���š�\n",	

	"west":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"east":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"north":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"south":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"��Ӱ":	"������ģ�ʲôҲ���������\n",

	]) );
	set("exits",([
  		"west" : __DIR__"bottom6",
  		"enter" : __DIR__"bottom19",
	]) );

	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",-100);
	setup();
    create_door("enter","door","СС����","out",DOOR_CLOSED);
}
void init()
{
	add_action("do_search", ({"search"}));
	add_action("do_look", ({"look"}));
}

void aaa(object me,object room)
{
	if (!me)	return;
	if (environment(me) != room)
		return ;
	if (me->query_temp("annie/emeraldx") != 99)
		return ;
	if (REWARD_D->riddle_check(me,"�������") != 1)
		return ;

	me->set_temp("annie/emeraldx",0);
	tell_object(me,HIG"\n�㲻���ĵص�ͷ����������С��һ�ۣ�ͻȻ����С�ݸ����б���ѹ���ĺۼ���\n"NOR);
	tell_object(me,HIW"�ƺ���ʲô���������������������\n\n"NOR);
	
	REWARD_D->riddle_set(me,"�������",2);
	return;
}

int do_search(string arg)
{
	object me = this_player(),he;
	object room,item;
	room=find_object(__DIR__"bottom20");
	if (!room)
		room=load_object(__DIR__"bottom20");
	
	me->set_temp("annie/emeraldx",0);

	if (me->is_busy() || me->is_fighting())
	{
		write("��������æ��\n");
		return 1;
	}

	message_vision("$N�ڷ�ɣ��ľ��ĸ�ϵ��������Ѱ������\n",me);

	if (room->usr_in() || random(3) || REWARD_D->riddle_check(me,"�������") != 1)
		tell_object(me,"��Խ���˴���������ȴʲô��û���ҵ���\n");
	else
	{

		if (me->query("annie/gstone") == 1)
		{
			if (!me->query_temp("marks/bottom7_warning")) {
				me->set_temp("marks/bottom7_warning",1);
				tell_object(me,HIG"\n�ݴ��к�Ȼ���̹�һ�����������ȥ��\n\n"NOR);
				tell_object(me,CYN"��ʮ����������ʮ��ô��\n"NOR);
				tell_object(me,HIB"��Ӱ�����������غ���һ�������������һ��Ƥ���ֻ����ɱ�����ˡ�����\n"NOR);
				me->perform_busy(1);
				return 1;
			}
			me->delete_temp("marks/bottom7_warning");					
			tell_object(me,HIB"���ܵ��Ӳ���͸����ɫ��������ȥ����ȴͻȻ����һ��ѣ�Σ�����\n\n"NOR);
			me->move(room);
			if (!present("fiftysix",room))
			{
				he=new(__DIR__"npc/devil");
				if ( me->query("combat_exp")>= 2100000) {
					he->set("combat_exp", me->query("combat_exp"));
					"/feature/nada"->reset_npc(he);
					he->set_skill("feixian-sword",he->query_skill("feixian-sword",1)
						+ F_LEVEL->get_level(he->query("combat_exp"))/6);
					he->set_skill("feixian-steps",he->query_skill("feixian-steps",1)
						+ F_LEVEL->get_level(he->query("combat_exp"))/6);	
				}										
				he->full_me();
				he->move(room);
			}
			me->perform_busy(1);
			return 1;
		}

		tell_object(me,HIG"\n�ݴ��к�Ȼ���̹�һ�����������ȥ��\n"NOR);
		tell_object(me,HIG"Ȼ����ֻ��һ��С�ݣ�¶������ľ����Ѿ��ϳ������أ�����\n\n"NOR);
		me->set_temp("annie/emeraldx",99);
		call_out("aaa",12,me,this_object());
	}

	me->perform_busy(2);
	return 1;
}

int do_look(string arg){
	
	object me = this_player();
	if (REWARD_D->riddle_check(me,"�������")!=2)	return 0;
	if (arg != "grass" && arg!="С��" && arg!="��") return 0;
		me->set_temp("annie/emeraldx",0);
	tell_object(me,HIG"\n�㲻���ĵص�ͷ����������С��һ�ۣ�ͻȻ����С�ݸ����б���ѹ���ĺۼ���\n"NOR);
	tell_object(me,HIW"�ƺ���ʲô���������������������\n\n"NOR);
	
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


