inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������������˶ڻ�����ʳ��ĵط�����Ц���˰참�󣬰����ĳ������ʷ���
�ͼ���ʬ��ĵط��������������ԣ��紩�����룬�����������������Ӷ�������
�ɵġ�����ֻ����������ǲ�Ӭ�ļ��ڣ��ƻ���һȺ��Ӭչ����裬�������졣
LONG
        );
        set("exits", ([ 
		"north": __DIR__"house3b",
	]));
	set("objects", ([
        	__DIR__"npc/tangda" : 1,
        	__DIR__"npc/liner" : 1,
        ]) );

        set("item_desc", ([
	
	 ]));
	set("coor/x",0);
	set("coor/y",-60);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
