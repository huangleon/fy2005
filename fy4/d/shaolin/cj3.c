// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit DOOR_ROOM;
void create()
{
        set("short", "�ؾ�¥");
        set("long", @LONG
ר�����������书�������������ɵ��书������м��أ�������ɮ���ڿ��ޣ�
�ݴ�ÿ�˼�ͨ���գ���������һ�����ţ�Ҳδ���д˹������벩��������鼮��
ֻ�еõ���λ��ɮ�Ĵ��ࡣ��������ľ�ţ��ź�¥��ͨ����¥��
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"cj4",
  "down": __DIR__"cj2",
]));
        set("objects", ([
                __DIR__"npc/monk20c" : 3,
                __DIR__"obj/slayedman2" : 2,
       ]) );
	set("coor/x",0);
	set("coor/y",100);
	set("coor/z",40);
	set("no_lu_letter",1);
	setup();
	create_door("up","door", "ľ��", "down", DOOR_CLOSED);

}

int valid_leave(object me,string dir)
{
        object ob;
	if(userp(me) && dir == "up" && ob=present("shaolin monk",this_object()))
	{
	message_vision("$N��$n�����ؾ�¥�����ֽ���,��ֹ��!\n",ob,me);
	return notify_fail("");
	}
	return ::valid_leave(me, dir);
}
