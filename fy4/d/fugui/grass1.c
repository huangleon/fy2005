// Room: grass1.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "����ƺ");

	set("long", @LONG
������һ�鷼��ƺ���̲����𣬺������裬�����˱ǣ����˸е�ʮ����⡣��
�����˾���һͷ�ɵ���ȥ���úõ�ȥ˯һ����������ż��Ҳ�������˻��ߡ�������
��ƬС���֣���������һ�����ҡ�
LONG
	);

	set("type","grassland");
	set("outdoors", "fugui");
	set("exits",([
		"east":__DIR__"grass2",
		"west":__DIR__"senling1",
		"north":__DIR__"woshi",
		"southeast":__DIR__"shibanlu4",
	]) );
	
        set("objects",([
		__DIR__"npc/baozi" : 1,
		__DIR__"npc/snake" : 1,
	    __DIR__"obj/greengrass" : 1,
       	]) );
	set("coor/x",0);
	set("coor/y",230);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
