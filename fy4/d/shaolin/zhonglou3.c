// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
�����������������ת����Ϊ����ǽ��֮�϶����˸�СС��������ǰ�����
����ͬ��ǽ�ϱڻ��������䣬����ɮ���������»��ƣ��������ǵ������֡�
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"zhonglou4",
  "down" : __DIR__"zhonglou2",
]));
		        set("objects", ([
                __DIR__"npc/monk52_sentry" : 1,   
       ]) );
	set("coor/x",20);
	set("coor/y",-60);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
