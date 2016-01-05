#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "ɽ��");

	set("long", @LONG
������ȥ����ɽׯ��ɽ���ϣ��¿��������������������̣�����������������
�Ĺ��ͼ�����һ̧ͷ���ֿɿ��������������״��������ӥ״�ķ��ݸ߸߷�������
������С�ɽ�����죬�������ƣ������о������Եá�������̽ͷ��ȥ���ѿ���Լ
��������ɽׯ��ͭ����š���������һƬ���֡�
LONG);

	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"west":__DIR__"milin1",
        "southdown":__DIR__"shandao4",
		"northeast":__DIR__"shandao2",
	]) );
	set("objects", ([
    	    __DIR__"npc/whiteant" : 1,
        ]) );

	set("coor/x",0);
	set("coor/y",160);
	set("coor/z",60);
	setup();
}

void init()
{	object ob;
	string outexit;
	if( interactive( ob = this_player()))
	{
		if(query("exits/west")) delete("exits/west");
		outexit = __DIR__"milin"+(string)(1+ random(25))+ ".c";	
		set("exits/west", outexit);
	}
}

int valid_leave(object me, string dir)
{
    	object ob;
        mapping m_family;
        if( userp(me) && dir=="northeast" && ob=present("white ant", this_object()) ) 
        {
            if( !me->query_temp("marks/whiteant")
            	&& !REWARD_D->riddle_check(me,"�ɹ�����/������")
            	&& !REWARD_D->check_m_success(me,"�ɹ�����"))
                 	return notify_fail("������˫��һ�����ߵ�һ����������ɽׯ�ﻹ�����Ǹ��������ߣ�\n\n�����˵Ȼ���ĪҪ���ⷬ��ˮ�ĺá���\n");
		}
	
		if ( dir == "west")
			tell_object(me,HIG"���Ѿ������˸������֣������·�˿�����leaveָ���뿪��\n\n"NOR);
	
		return 1;
}
