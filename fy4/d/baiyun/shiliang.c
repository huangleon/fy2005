//sinny@fengyun.com 

#include <ansi.h>

inherit ROOM;
void create()
{
    set("short", HIB"ŭ��ʯ��"NOR);
    set("long", @LONG
��ʯ���ϸ����죬�¾��̺����������ب��ŭ����������֮�䣬�·����֮����
�˶��ϣ����������з����ǳ�Ҳ����ȥ���溣���š�ŭ�����Σ��·�һ�����˾Ϳ�
����ǧ��ʯ����Ϊ촷ۡ�
LONG
    );
    set("exits", 
      ([ 
	"west" : __DIR__"pailangya",
	"east" : __DIR__"nujiao",
      ]));
    set("objects", 
      ([ 
	//	     __DIR__"obj/sand" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",20);
    set("coor/y",-30);
    set("coor/z",0);
    setup();
}

/*
int valid_leave(object me, string dir)
{
    object room;
    object ob;

    if(userp(me))
	if (random(3)>0)
	    if (random(10)>-1)
	    {
		room = load_object(__DIR__"huangsha1");
		message_vision(HIB"\nŭ�����£���羢����$N����һ�����ģ�����һ�������˾���󺣡���\n\n"NOR,me);
		me->unconcious();
		me->move(room);
		return notify_fail(" ");
	    }

    return 1;
}

*/