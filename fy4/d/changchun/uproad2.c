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
        set("exits", ([ 
	  	"northwest" : __DIR__"uproad1",
  		"eastup" : __DIR__"uproad3",
	]));
        set("outdoors", "tieflag");
	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",10);
	setup();
}
