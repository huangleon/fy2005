
inherit ROOM;

void create()
{
        set("short", "�鱦��");
        set("long", @LONG
����һ���ƾɵ�С�ꡣר�ž�Ӫ��������������Ƨ�������С�������ȴ�ر�
�á�Ҳ���ǳ������˶�֪�������ն�����׶༪�٣�����������������֣�����
�ǲ���������Ҳ�����⡣
LONG
        );
        set("exits", ([ 
		 "north" : __DIR__"fair2",
	]));
        
        set("objects", ([
                __DIR__"npc/jadeowner" : 1,
        ]) );

	set("coor/x",-1030);
	set("coor/y",-15);
	set("coor/z",0);
	setup();

}

