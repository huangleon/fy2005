
inherit ROOM;

void create()
{
        set("short", "�ȵ�");
        set("long", @LONG
ֻ��������Ȫ��ʯ��������ݣ�������ɽ���ƵĹȵأ���׺��������������һ
�㡣��ľ��ˮ֮�䣬��׺����ධ���ܷ�󣬼�һЩ��ɽ̨ͤ��һ��ʯ��׺�ɵĵ�
·������ͨ��ǰ����
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"house",
  "west" : __DIR__"garden3",
]));
        set("outdoors", "palace");

	set("coor/x",30);
	set("coor/y",50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

