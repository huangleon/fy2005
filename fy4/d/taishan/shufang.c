// Room: shufang.c --- by MapMaker

inherit ROOM;

void create()
{
    set("short", "̤ɯի");

	set("long", @LONG
��������޹�ɽׯ���鷿��.��������һ���Ŷ�����ܣ����϶��������飬Ҳ
��֪�ж�����,������һ����̴ľ�����������������Ƕ�����׷��ŵ���̨��ͲҲ
����̾���.����������һֻ��ͭ�Ŷ�������̴�㣬���ǵ���ͷ���������³�һ��
�����̡�
LONG);

	//{{ --- by MapMaker
	set("type","indoors");
	set("exits",([
	"west":__DIR__"dating",
	]) );
        set("objects", ([
                __DIR__"npc/shenbijun" : 1,
        ]) );
        set("indoors", "taishan");
	set("coor/x",10);
	set("coor/y",70);
	set("coor/z",150);
	//}}

	setup();
	replace_program(ROOM);
}
