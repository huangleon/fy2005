// Tie@fengyun
#include <room.h>

inherit ROOM;
void create()
{
    set("short", "ʯ�ﾡͷ");
    set("long", @LONG
ʯ�ﲻ��ܿ쵽�˾�ͷ��һ�¸�ǽ��סȥ·��ǽ���е�խ�ţ�ǽ����һ[33m����[32m��
һ����ϡϡ��С�ӹ��ӹ�����������ʱ����ʱ�ģ�һ��������Ѫˮ�ı����ӹ�����
������ɢ������������ζ��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"stone1",
	"northeast" : __DIR__"sroom",
	"east" : __DIR__"ansheng",
      ]));
	set("item_desc", ([
	"����":"һ�������ѾõĹ��������Ѿ�ʧȥ����(enter)������;����������\n",
	]) );
    set("objects", ([
		//__DIR__"npc/newsman" : 1,
      ]));
    set("outdoors", "fengyun");
    set("coor/x",240);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fyeast");
    setup();

}

void init()
{
	add_action("do_north", "enter");
}



int do_north(string arg)
{
    object room, me;
		me = this_player();
		if (!room= find_object("/d/fycycle/road6"))
			room=load_object("/d/fycycle/road6");
		tell_object(me,"\n���������������ܿ���֮�裬������������ô�������Ѷ���������ʲô��\n");
		me->ccommand("emote �ٺ�һЦ��һ��������������򹷶���ȥ��\n");
		me->move(room);
		me->ccommand("emote �ӳ�ǽ��һ��С���������С������ذϹ����Ǻ����˹�����");
		if (!REWARD_D->check_m_success(me,"��������"))
				REWARD_D->riddle_done(me,"��������",1,1);
		me->set_temp("body_print", "��������մ���˺����ˮ�����εδ����������䣬\n�������ö��İ���");

		return 1;
}


/*

// this code work only if npc cannot be arrested.
int invalid_leave(object me)
{
    object ob;
    if(  me->query_temp("answer_questions") <= 3 ) 
    {
	me->delete_temp("score");
	me->delete_temp("answer_questions");
	me->delete_temp("num_question");
	me->delete_temp("in_ask");
	if(ob=present("news man", this_object()))
	{
	    ob->set("in_test",0);
	}
    }
    return 0;
}
*/