// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ظ�����");
        set("long", @LONG
��ľ���ȣ��ϵ������������쳣���˴����Ⱥͱ𴦲�ͬ������ĳ��ȿ����쳣��
·����������ʯĥ��һ����˶�����󣬾�˵��������ɮ������ʳ������������
ĥ����ĥ��
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"changjing",
]));
        set("objects", ([
                __DIR__"obj/mopan" : 1,
       ]) );
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
