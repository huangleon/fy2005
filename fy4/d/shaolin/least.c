// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ظ���");
        set("long", @LONG
��ľ���ȣ��ϵ�ɷ������������·�����ޱȣ�·���д��һ����һǧһ��
�����������ÿ���������㹻ȫ��ʳ�ã���������������˹��в����㣬���
���ڴˣ����������档
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"changjing",
]));
        set("objects", ([
                __DIR__"obj/daguo" : 1,
       ]) );
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
