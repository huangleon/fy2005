// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "���¥");
        set("long", @LONG
ֻ��һ��ɽǽ�������š��徲�������������ȷ��ƣ����̺͸������������µ�
ʯ��ͨ�����Сɽǽ���쵽���۱����ȥ�ɼ��ڶ������š�������������������
���ױʡ�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"tianwang",
  "northup" : __DIR__"daxiong",
  "east" : __DIR__"beilou",
  "west" : __DIR__"gulou",
]));
        set("objects", ([
                __DIR__"npc/monk_float" : 2,
       ]) );
	set("coor/x",0);
	set("coor/y",-60);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
