inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������ȴ����Χ�Ĳ�ͬ���м�������棬��һ������ɽˮ���㼸�ϲ�ɽ��ͭ
¯�����������������������������Щ���棬���������ʫ�塣�������Ϸ�������
ʱ�¹��ӣ�һ���ܺм������͡�����¥������ڿ���˼��������Щ������Ϊ��ӭ��
��ͬ���˵�Ʒζ��
LONG
        );
        set("exits", ([ 
		"west": __DIR__"redhouse0",
	]));
        set("item_desc", ([
	
	 ]));
        set("objects", ([
        	__DIR__"npc/lady1":	1,
        ]));
	set("coor/x",-70);
	set("coor/y",-50);
	set("coor/z",10);
	set("map","taiping");
	setup();
}
