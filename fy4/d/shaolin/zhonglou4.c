// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
���������������ϣ�˿�첻¶����Ϊ�ڴ˹�����һ��������Ԫ��ĵز�����
���еزؾ��������Ĵ�˫�䣬̻ǰ�أ�������װ����֮�ϡ�����ׯ�ϡ�
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"zhonglou5",
  "down" : __DIR__"zhonglou3",
]));
		        set("objects", ([
                __DIR__"npc/monk53_sentry" : 1,   
       ]) );
	set("coor/x",20);
	set("coor/y",-60);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
