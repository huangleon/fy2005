
inherit ROOM;

void create()
{
        set("short", "����ˮ��");
        set("long", @LONG
ˮ�׶��ڱ�������ɶ�ߵ�ˮ�׷ֳ����㣬����һ�������������Ƥë����
�Ǹ�������Ĵ��̣���һ��СС�������ߵ�����һ�㣬������ʳ��ӵĵط��ˣ���
���Ȼ�������Σ����涼���ź�����ձ�����и������µĻ�ͭ��¯��
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"xiao",
]));
        set("objects", ([
        __DIR__"npc/lixia" : 1,
                        ]) );


	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",-10);
	setup();
}

