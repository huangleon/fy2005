// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����ʯ");
        set("long", @LONG
�������ŵ��춼���£����ɿ���һ��ͤͤ������ʯ�ˣ�����һ���װ��Ů����
�ƹ���ʯ������һ��Сʯ��ǡ����֮ͯ�ӣ��⡰С��٪�����á���������ʯ����
�ù��ɡ�ͯ�Ӱݹ�������������㿪ʼ�ˡ��̿�ǧ���������ϵ��ݡ������춼�
�ؿ�����͡��ĵǶ����̡�
LONG
        );
        set("exits", ([ 
  "eastdown"  : __DIR__"mroad3",
  "westup" : __DIR__"yingke",
  "northwest" : __DIR__"tanhai",
]));
        set("objects", ([
        __DIR__"obj/guanyin" : 1,
	__DIR__"obj/xiaotong" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-50);
	set("coor/y",10);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
