// searoad.c
inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
С·�������۷���ɽ�壬һ·�ϵ�������ɽ���У�����������ͷ׵Ļ��䡣
��ľ�䣬����䣬��ʱ���Ƽ�̨ͤ¥��������Ӱ����������һȺ��Ů����������
����ɽ�С�
LONG
        );
        set("objects",([
        	AREA_TIEFLAG"npc/qinggirl" : 1,
        ]) );
        set("exits", ([ 
	  	"east" : __DIR__"platform",
  		"westdown" : __DIR__"uproad2",
	]));
        set("outdoors", "tieflag");
	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",20);
	setup();
}

