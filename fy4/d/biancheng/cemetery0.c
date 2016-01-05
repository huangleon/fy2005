#include <ansi.h>

inherit ROOM;
string *names=({
	__DIR__"cemetery1",
	__DIR__"cemetery2",
	__DIR__"cemetery3",
} );


void create()
{
        set("short", "�س�");
        set("long", @LONG
��ɫ��ɭ����Ҳ���䣬Զ���ߵ�������ص���ĺ��澹��һƬ�ޱ��޼ʵĻķء�
��Ȼ�ǰ��죬�ķؼ���Ȼ��������Ҳ��Ȼ���Թ����ˡ����������������Ե�����
�谵������У�һֻ��Ӱ�����������������������������������м������硣����
Ҳ����ɽ����ˮ����Ұ���ķء�
LONG
        );
        set("outdoors", "biancheng");
        set("objects", ([
        	__DIR__"npc/oldman":	1,
	]) );
        set("coor/x",-70);
	set("coor/y",10);
	set("coor/z",0);
	set("map","zbwest");
	set("no_lu_letter",1);
	setup();
}

void reset()
{
	int i,j;
	string temp;
	::reset();
	for (i=0;i<=2;i++)
	{
		j=random(3);
		temp=names[j];
		names[j]=names[i];
		names[i]=names[j];
		names[i]=temp;
	}
	set("exits", ([
		"north" : names[0],
		"south" : names[1],
		"east" : __DIR__"temple",
		"west" : names[2],
	]));
}


int valid_leave(object me, string dir) {
	
	object oldman;
	
	if (dir=="south" || dir =="north" || dir =="west")
	if (!REWARD_D->check_m_success(me,"ɨ����ʬ")
		&& !REWARD_D->riddle_check(me,"ɨ����ʬ")
		&& oldman=present("oldman",this_object())) {
		return notify_fail(oldman->name()+"��ס��˵���ص��й����ǲ�Ҫȥ�ĺá�\n");
	}
	return 1;
}

	
	