// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "С����");
        set("long", @LONG
һ��СС��������ɽ�ƶ�����������Ű����죬�����˼���������Ž��գ���
�ܼž������������ﴫ���ĳ���ĺ�ĵ��������Դ�����Զ��Զ��վ�������ſ�����
�ܹ�����ֻ��ɽ��ˮ�㣬����һ�޷�ɽˮ����
LONG
        );
    set("exits", ([ 
 		"southdown" : __DIR__"mroad3",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan" : 1,
	]));    

    set("outdoors", "huangshan");
	set("coor/x",-40);
	set("coor/y",20);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
