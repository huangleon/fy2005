inherit ROOM;
void create()
{
 set("short", "���ں��ߵĴ�");
 set("long", @LONG
�󺣣�һ���޼ʵĴ󺣡����߲���һ�Ҵ������ɵ���Φ������׵ķ���������
������ʵ�������ľ�ʣ�����һ�ְ�����Ѹ�١����һ����ĸо���������ã���
ˮտ������Ÿ���ɵ��Դ�Φ�们�����������ഺ�Ļ��֡�
LONG);
	set("exits", ([ 
	  "west" : __DIR__"lin2",
	  ]));
	set("objects", ([
		  AREA_BAT"npc/chu": 1,
		  AREA_BAT"npc/lihong": 1,
	 ]) );
	set("coor/x",1020);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
 	replace_program(ROOM);
}
