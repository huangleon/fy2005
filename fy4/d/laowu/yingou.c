
inherit ROOM;

void create()
{
        set("short", "�����ķ��ֵ�");
        set("long", @LONG
��Ҳ���������ڵƻ����������⡣�ƿ��ţ��Ӵ̹ǵĺ������߽�����ů�紺
�ķ��ӣ�ÿ���˶���������������������г��������˵��̲�ζ����ζ��Ů�˵�֬
���㣬�ٻ����㡣
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"street2",
  "east" : __DIR__"xiao",
]));
        set("objects", ([
        __DIR__"npc/laoshan" : 1,
	__DIR__"npc/li" : 1,
                        ]) );


	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

