#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "СϪ��");
        set("long", @LONG
������佻�Ϫ�����룬������ǳ��ˮ���ļ���Ϫˮ�и�ɫ�ͷ׵Ļ�������Ϫˮ
���������ʡ�����С��ż��Ծ���ָ���ˮ�У�ȦȦˮ��������������г��Ϫ�档
LONG
        );
	set("outdoors","wolfmount");
        set("objects", ([
                	__DIR__"npc/fish" :3,
        	]) );
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",-5);
	setup();
}

void init()
{
	if(interactive(this_player()))
		call_out("do_flush",7,this_player());
	
}

void do_flush(object me)
{
	object room;

        if(!me || environment(me) != this_object())
                return;
	message_vision(HIY"Ϫˮ���������ö࣬$N��æ��ס�����������ϰ�������\n"NOR,me);
	room= load_object(__DIR__"brook2");
	me->move(room);
}