// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����Ħ��������Ե����Ҿ��������������ҵ����壬ɽ�嶸���������ɮ����
���й�������ɽ�����󣬰�����������������֮�������ʺϲ�����
LONG
        );
        set("exits", ([ 
  "eastdown" : __DIR__"damo",
]));
        set("outdoors", "songshan");
	set("coor/x",63);
	set("coor/y",26);
	set("coor/z",20);
	set("objects", ([
                __DIR__"npc/lama1" : 1,
       ]) );
	setup();
        replace_program(ROOM);
}
