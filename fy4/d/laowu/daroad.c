
inherit ROOM;

void create()
{
        set("short", "ˮ�����");
        set("long", @LONG
�⽭�󣬺��涳����һ���ֳ��ֿ��ˮ����������ƻ����٣�����������Ĵ�
����һյյ�ĵƻ����ȼ�𣬵ƻ����ڱ��ϣ����ϵĵƻ��գ����ӿ�����������
һ����ˮ���������˭��һ�ο������־��󣬶�һ����Ŀѣ���ԣ��Ķ���ۡ�
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"downtown",
  "south" : __DIR__"town",
]));
        set("outdoors", "laowu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

