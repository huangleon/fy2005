inherit ROOM;

void create()
{
	set("short", "�ӻ���Ƽ�");

	set("long", @LONG
Զɽǰ����ˮ���Ǽ��ӻ���Ƽң���Ȼֻ�Ǹ�СС�ľ���������Ҳ��СС����
�ˡ�СС��ͥԺ����������СС���Ż���СС�����ã���¯���Ƶģ���һ���۾�С
С������СС�����СС��Ů�ˡ�
LONG);

	set("exits",([
        	"east":	__DIR__"xzroad1",
	]) );

        set("indoors", "wudang");
        set("objects", ([
        	__DIR__"npc/xinghua": 1,
        	__DIR__"npc/xusan": 1,
        ]));
	set("coor/x",-10);
	set("coor/y",90);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}
