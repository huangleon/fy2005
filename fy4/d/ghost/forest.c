#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ԭʼ����");
	set("long", @LONG
�ޱ��޼ʵĴ�����һƬ�ڰ����������ҵ��չ�Ҳ����͸�����ܵ���Ҷ���ڰ���
�����˸�ʽ������Σ�գ�ÿһ�ֶ����������������ڴ�������ʧ�˷��򣬼��ʾ���
�����������û��ָ���Ļ��������Ŀ�������΢����΢�ġ�
LONG
	);
	set("exits", ([
		"north" : __DIR__"forest2",
		"south" : __DIR__"forest1",
		"east" : __DIR__"forest5",
		"west" : __DIR__"forest6",
	]));
	set("outdoors", "ghost");
        set("NONPC",1);
	set("coor/x",-90);
	set("coor/y",40);
	set("coor/z",10);
	setup();
}

void init(){
	object me,c;
	me = this_player();
	if(c=present("hitch hiker's guide",me))
	{
		if (c->query("oops") == 1)
		{
			if (REWARD_D->check_m_success(me,"����ɽׯ"))
			{
				tell_object(me, HIG"��ǰ��ɫ�ƺ���Щ��Ϥ���㷭������̽��ָ�ϣ�һ˲���Ȼ����\n\n"NOR);
				tell_object(me, HIG"һ��ַ紵��������̽��ָ�ϻ���ƬƬ��������ȥ��\n\n"NOR);
				me->set_temp("marks/know_ghost", 1);
				destruct(c);
			}
		}
	}
	
	if(me->query_temp("marks/know_ghost")){
		tell_object(me, HIG"��ǰ��ɫ�ƺ���Щ��Ϥ������ϡ�ǵ����Ϸ��ĸߴ�������ɽ�¡�\n\n"NOR);
		add_action("do_southup", "go");
	}

}


int do_southup(string arg){
	object room;
	object me=this_player();
	
	if (arg == "southup")
	if(me->query_temp("marks/know_ghost")) {
		message("vision", me->name()+"΢һ��������һ�·���������ɽ��֮�����˼��¾Ͳ����ˡ�\n", 
				environment(me), me);	
		tell_object(me, HIG"\n��ǰ��Ȼһ����һ��ɽ�³�������ǰ��\n"NOR);
		room = find_object(__DIR__"forest9");
		if(!objectp(room)){
			room = load_object(__DIR__"forest9");
		}
		me->move(room);
		message("vision", me->name()+"�Ӵ���֮�����˳�����\n", environment(me), me);
		return 1;
	}
	return 0;
}

