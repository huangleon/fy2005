// Room: grass2.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "����ƺ");

	set("long", @LONG
������һ�鷼��ƺ���̲����𣬺������裬�����˱ǣ����˸е�ʮ����⡣��
�����˾���һͷ�ɵ���ȥ���úõ�ȥ˯һ����������ż��Ҳ�������˻��ߡ�
LONG
	);
	set("type","grassland");
	set("outdoors", "fugui");
	set("exits",([
		"east":__DIR__"grass3",
		"west":__DIR__"grass1",
	]) );
	set("objects",([
		__DIR__"npc/girl" : 1,
		__DIR__"npc/snake" : 1,
	    __DIR__"obj/greengrass" : 1,
       	]) );
	set("coor/x",10);
	set("coor/y",230);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
