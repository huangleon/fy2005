// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
������������һ������¥�Ľ�������������֮�У���ɫ���߶���������Ұ�ݣ�
һ��Сʯ������ֱͨС¥��ʯ���ϲ�������Ҷ���������������һ�ֲ�������Ϣ��
�����ܵ������ڽڲ��롣
LONG
        );
    set("exits", ([ 
  		"northeast"  : __DIR__"yingke",
		"west" : __DIR__"lianhua",
 		"up" : __DIR__"yuping2",
 		"southeast" : __DIR__"lianrui",
	]));
    set("objects", ([
        __DIR__"npc/wang" : 1,
        __DIR__"npc/monkey1" : 1,
    ]) );

        set("outdoors", "huangshan");
	set("coor/x",-70);
	set("coor/y",-10);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
