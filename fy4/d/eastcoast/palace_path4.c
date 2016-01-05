#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "��ã����·");
    set("long", @LONG
ɽ��Խ��Խ�ߣ�����Խ��ԽŨ����Χ�ľ�����Ũ�����������֡�Ũ���е�ˮ
����͸��������ѣ������Ҳ�񱻱����������Χ�ˡ��⡭������ͨ�����õļ�;��
����ͨ�������Ĳ���֮·��
LONG
    );
    set("exits", ([ 
	"eastup" : __DIR__"palace_path5",
	"westdown" : __DIR__"palace_path3",
      ]));
    set("outdoors", "palace");
    set("coor/x",160);
    set("coor/y",0);
    set("coor/z",20);
    setup();
}

void init()
{
    if (!random(2))
    {
	message("vision",WHT"\n��������������������ƺ�������������\n\n"NOR, this_object());
	add_action("do_north", "go");
	add_action("do_look", "look");
    }
}



int do_north(string arg)
{
    object room, me;
    if (arg == "north") {
		me = this_player();
		if (!room= find_object("/d/cyan/enterance"))
		    room=load_object("/d/cyan/enterance");
		me->move(room);
		REWARD_D->riddle_done( me, "��ϼ֮��",10,1);		
		return 1;
    }
    return 0;
}


int do_look(string arg)
{
    object me;
    me = this_player();

    if (arg!="north" && arg!="����")
	return 0; 
    tell_object(me,WHT"���������������������������������ԼԼ����ɽ·��\n"NOR);      
    return 1;
}  
