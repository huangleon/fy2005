#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����ɳѨ");
	set("long", @LONG
������һ�������ܶ������ܺںڵģ���Լ���Կ�����Χ��ʯ�ܲ���������һ��
��������һ�����Ӵ�����������Լ��������ˮ������˵������Ȼ�����Լ��
ֻ��Ϊ�ڽ������һ�㰵��Ĺ�â���������������ĵ�ɳˮ����
LONG
	);
	set("exits", ([ 
  		"down" : __DIR__"sandriver1",
  		"east" : __DIR__"dongd1",		
	]));
	set("no_fly",1);
	set("objects", ([
	]) );
	set("indoors", "quicksand");
	set("coor/x",-1060);
	set("coor/y",-20);
	set("coor/z",-10);
	setup();
}


int valid_enter(object me) {
	tell_object(me, HIR"\n������һ�꣬�Ծ��ط��֣����ﾹȻ��һ���޴�Ŀն���
���ܹ�ʯ��ᾣ�����һ�ֲ���֮�С� \n\n"NOR);
	return 1;
}