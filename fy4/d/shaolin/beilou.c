// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
һ��שʯ������С¥�������ﶫ�У�������¥����¥��������ͨ��һͨΪ����
���񱮡���Ϊ����������һͨΪ��Сɽ��ʦ��ʵ�������ϱ�ɽǽ��Ƕ�а׾��׵�ʫ
����Ǭ¡���������������䡰�������������¾���ɽ�ۡ��˵���۷塣
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"yeeast",
  "east" : __DIR__"zhonglou",
  "west" : __DIR__"dianjiao",
]));
        set("outdoors", "shaolin");
	set("coor/x",10);
	set("coor/y",-60);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
