// road.c
// QC'ed by Tie@fy2
inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
���￿�������ɽǧ�𶴣���������ɽ��ɽ�µıؾ�֮·����·����һƬСС
���֣�һ��ʯ��������ʯ�ʡ�һ��С���ڴ���������������Ϊ��¡�������ҪС��
����Ҷ���������������
LONG
        );
        set("exits", ([ 
  		"eastup" : __DIR__"road0",
  		"west" : AREA_JINAN"tanghuai",
	]));
        set("objects", ([
               AREA_TIEFLAG"npc/xiaofan" : 1, 
        ]) );
        set("outdoors", "qianfo");
	set("coor/x",-10);
	set("coor/y",-100);
	set("coor/z",-30);
	setup();
	replace_program(ROOM);
}
