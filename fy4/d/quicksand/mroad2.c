
inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
��ɽҰ���ﱾû��·���ߵ��˶��ˣ������ӡ��ѹ����һ����һ����ͨ�е�
С·��˳��ɽ�н�Ϊƽ̹�ش�����������չ��������һ�����ʵľ��¡�������һƬ
��ɫ----���ԭ����·�ľ�ͷ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"mroad",
  "west" : AREA_GUANWAI"grassland0",
  "south" : __DIR__"cliff",
]));
        set("outdoors", "quicksand");

	set("coor/x",-1130);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

