// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��Ժ");
        set("long", @LONG
һ���տ��Ļ���Ժ�ӣ�Ժ�Ӻܴ󣬿���������һ��Сľ�š�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"neiyuan2",
  "south" : __DIR__"neimen",
  "east" : __DIR__"guagua",
  "west" : __DIR__"fanting",
]));
        set("outdoors", "shaolin");
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
