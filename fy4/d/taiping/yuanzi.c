inherit ROOM;
void create()
{
        set("short", "�쾮");
        set("long", @LONG
��԰������һ���¶��ţ��ź���һ���쾮��������Ӷ��ס�Ĳ෿���쾮����
ʮ���ɼ�������ʯ�������滹��Щ����ɹ�ȵĲ��ࡣ����ӻ�ɽ����������ׯԺ
�������У��쾮��ͬ���������롣
LONG
        );
        set("exits", ([ 
		"west": __DIR__"lroad1",
		"east": __DIR__"sroom1",
		"south": __DIR__"sroom2",

	]));
        set("outdoors", "taiping");
	set("item_desc", ([  
	]));
	set("coor/x",80);
	set("coor/y",-80);
	set("coor/z",0);
	set("map","taiping");
	setup();

}
