// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����������ַ��ɵľ�����ǰ��������һ�ڣ��ش����������ҵ���Ǭ¡��
ס���������ֳơ���ͥ����
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"fangnan",
  "northup" : __DIR__"lixue",
  "east" : __DIR__"kuoran",
  "west" : __DIR__"fangtui",
]));
        set("objects", ([
                __DIR__"npc/master_17_1" : 1,
       ]) );
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
