// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
�����������ͻȻ����������ֻ�����ĵ��������˸�ţ��ݽ�һ��ͭ������
�С�����ͭ���ձ��ǡ���
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"zhonglou2",
  "west" : __DIR__"beilou",
]));
        set("objects", ([
                __DIR__"obj/tong" : 1,
                __DIR__"npc/monk5_sentry" : 1,   
       ]) );
	set("coor/x",20);
	set("coor/y",-60);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
