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
        	AREA_TIEFLAG"npc/qinggirl1" : 1,
        ]) );
        set("exits", ([ 
	  	"southeast" : __DIR__"uproad2",
  		"southwest" : __DIR__"uproad0",
	]));
        set("outdoors", "tieflag");
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",10);
	setup();
}
