
inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
С��������ס�ң�����ͨ������ƽ������������ͨ�������ש���ĺ�Ժ��ס
��Ҳ�Ǻ���ͨ���˼ҡ������ǿ����ճԷ��ģ��п�С�ӻ��̵ģ����ģ������ģ�
��ľ�ģ�Ҳ�е��ǳ��걼�����������ԭ�������ˡ�
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"house2",
		"north": __DIR__"mroad4",
		"south": __DIR__"mroad5",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("coor/x",-20);
	set("coor/y",-40);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
