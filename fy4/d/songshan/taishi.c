// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "̫����");
        set("long", @LONG
�����߽����׵�ʯ�ڣ�����ɽ���������б�����Ϊ��ã�ʱ������ϵ�һ����
������С�����̫�����ǡ��������֣����к����������ΰ�����ģ�����������
���໭����ʮ������Ǿ����屦��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"zhongyue", 
]));
        set("outdoors", "songshan");
	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
	set("objects", ([
                __DIR__"obj/shique" : 1,
                __DIR__"npc/xian1" : 1,
       ]) );
	setup();
        replace_program(ROOM);
}
