
inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
��ɽҰ���ﱾû��·���ߵ��˶��ˣ������ӡ��ѹ����һ����һ����ͨ�е�
С·��˳��ɽ�н�Ϊƽ̹�ش�����������չ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"mfoot",
  "west" : __DIR__"mroad2",
]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/trader" : 2,
        ]) );

	set("coor/x",-1120);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

