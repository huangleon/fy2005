inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
�ſڹ��Ÿ���������ƣ�д�ţ���ר��ţ���������������÷��������䣬����
��������ģ����϶��ż�Ƭ���ȣ���̨�󼸸��������æµ������İ��ǽ��һ��
����ʮ��ֻ������Ŀ�Ѽ���ռ����ϰ�������к���ÿһ�����ŵĹ˿͡�
LONG
        );
        set("exits", ([ 
	"north": __DIR__"road4",
	]));
        set("objects", ([
        	__DIR__"npc/bosshu":	1,
	]) );
	set("coor/x",-30);
        set("coor/y",-10);
        set("coor/z",0);
	set("map","zbwest");
	setup();
}


int valid_leave(object obj, string dir){
	object hu;
	
	if (dir=="north" && obj->query_temp("marks/wanma/���ƹ�ɱ"))
	if ( hu=present("hu zhanggui",this_object())) {
		tell_object(obj,hu->name()+"�������ڵص�ס�����ȥ·��\n");
		return notify_fail("");
	}	

	return 1;
}


void reset(){
	if (present("yunzhong he",this_object()))	return;
	::reset();
}	