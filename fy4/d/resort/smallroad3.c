
inherit ROOM;

void create()
{
        set("short", "��С��");
        set("long", @LONG
�����µı�����ǡ�˲���ɽ��һ��ɽ��С·������������ɽ�����죬���Ե�é
�ݸߴ���ߣ���ס����⣬ɽ���е�һ�ж��Ե���ɭ�İ���ż����������Ұ�޵�Х
�С����˿�����Է���������������㡣
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"smallroad2",
  "north" : __DIR__"smallroad4",
]));
        set("outdoors", "resort");

	set("coor/x",40);
	set("coor/y",-40);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

